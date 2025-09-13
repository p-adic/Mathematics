// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Weighted/LCA/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFST , typename MONOID , typename U> inline WAncestorDoubling<DFSWT,MONOID,U>::WAncestorDoubling( DFST& dfst ) : m_p_dfswt{ &m_dfswt } , m_p_M( m_p_dfswt->Monoid() ) , m_size( m_p_dfswt->size() ) , m_wdoubling( 1 , vector<tuple<int,U,U>>( size , {-1,m_p_M->One(),m_p_M->One()} ) ) { static_assert( is_same_v<MONOID,decldecay_t(m_dfswt.Monoid())> && is_same_v<U,inner_t<MONOID>> ); }

template <typename DFST , typename MONOID , typename U>
pair<int,U> WAncestorDoubling<DFSWT,MONOID,U>::WAncestor( int i , int n , const bool& right )
{

  assert( 0 <= i && i < m_size );
  int d = 0;
  U temp = m_p_M->One();
  
  while( i != -1 && n != 0 ){

    if( ( n & 1 ) == 1 ){

      auto& [j,u_r,u_l] = Get( d )[i];
      i = j;
      temp = right ? m_p_M->Product( temp , u_r ) : m_p_M->Product( u_l , temp );

    }
    
    d++;
    n >>= 1;

  }

  if( i == -1 ){

    temp = m_p_M->One();

  }

  return { i , move( temp ) };

}

template <typename DFST , typename MONOID , typename U>
tuple<int,int,int,U,U> WAncestorDoubling<DFSWT,MONOID,U>::WLCA( int i , int j )
{

  int i_prev = -1 , j_prev = -1;
  const int diff = m_p_dfswt->Depth( i ) - m_p_dfswt->Depth( j );
  U u_ir = m_p_M->One();
  U u_jl = u_ir;

  if( diff > 0 ){

    auto [k,v] = WAncestor( i , diff - 1 , true );
    u_ir = m_p_M->Product( v , m_wprev[k] );
    i = m_p_dfswt->Parent( i_prev = k );

  } else if( diff < 0 ){

    auto [k,v] = WAncestor( j , - diff - 1 , false );
    u_jl = m_p_M->Product( m_wprev[k] , v );
    j = m_p_dfswt->Parent( j_prev = k );

  }

  if( i != j ){

    int d = int( m_doubling.size() ) - 1;
  
    while( get<0>( Get( d )[i] ) != get<0>( Get( d )[j] ) ){

      Get( ++d );

    }

    while( --d >= 0 ){

      auto& [k_i,v_ir,v_il] = m_wdoubling[d][i];
      auto& [k_j,v_jr,v_jl] = m_wdoubling[d][j];

      if( k_i != k_j ){

	i = k_i;
        j = k_j;
	u_ir = m_p_M->Product( move( u_ir ) , v_ir );
	u_jl = m_p_M->Product( v_jl , u_jl );

      }

    }

    u_ir = m_p_M->Product( move( u_ir ) , m_p_dfswt->PrevWeight( i ) );
    u_jl = m_p_M->Product( m_p_dfswt->PrevWeight( j ) , u_jl );
    i = m_p_dfswt->Parent( i_prev = i );
    j = m_p_dfswt->Parent( j_prev = j );
    assert( i == j );

  }
  
  return { i , move( u_ir ) , move( u_jl ) };

}

template <typename DFST , typename MONOID , typename U>
const vector<tuple<int,U,U>>& WAncestorDoubling<DFSWT,MONOID,U>::Get( const int& d )
{

  assert( d >= 0 );
  int digit = m_wdoubling.size();
  const U& one = m_p_M->One();
  
  while( digit <= d ){

    m_wdoubling.push_back( vector( m_size , {-1,one,one} );

    for( int i = 0 ; i < m_size ; i++ ){

      auto& [j,u_ir,u_il] = m_wdoubling[digit][i] = m_wdoubling[digit-1][i];

      if( j != -1 ){
        
	auto& [k,v_jr,v_jl] = m_wdoubling[d-1][j];
	j = k;

        if( j == -1 ){

          u_ir = u_il = one;

        } else {
          
          u_ir = m_p_M->Product( move( u_ir ) , v_jr );
          u_il = m_p_M->Product( v_jl , u_il );

        }

      }

    }

    digit++;
    
  }

  return m_wdoubling[d];


}
