// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/DirrectSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename GROUP> inline DirectSumGroup<U,GROUP>::DirectSumGroup( GROUP G , const int& index , const int& dim ) : PointedSet<pair<int,vector<U>>>( { -1 , {} } ) , m_G( move( G ) ) , m_dim( max( 2 , dim ) ) , m_p_index( &index ) { static_assert( is_same_v<inner_t<GROUP>,U> ); }

template <typename U , typename GROUP> inline pair<int,vector<U>> DirectSumGroup<U,GROUP>::Transfer( const pair<int,vector<U>>& v ) { pair<int,vector<U>> answer = v; for( auto& v : answer.second ){ v = m_G.Inverse( v ); } return answer; }

template <typename U , typename GROUP>
pair<int,vector<U>> DirectSumGroup<U,GROUP>::Product( pair<int,vector<U>> v0 , const pair<int,vector<U>>& v1 )
{
  
  auto& [v10,v11] = v1;

  if( v11.empty() ){

    assert( v10 == -1 );

  } else {
    
    auto& [v00,v01] = v0;

    if( *m_p_index == -1 ){

      if( v01.empty() ){
        
        assert( v00 == -1 );
        v0 = v1;

      } else {

        if( v00 != -1 ){

          assert( 0 <= v00 && v00 < m_dim && v01.size() == 1 );
          U u = move( v01[0] );
          v01 = vector<U>( m_dim , m_G.One() );
          v01[v00] = move( u );
          v00 = -1;

        }

        if( v10 == -1 ){
            
          for( int i = 0 ; i < m_dim ; i++ ){

            v01[i] = m_G.Product( move( v01[i] ) , v11[i] );

          }

        } else {

          assert( 0 <= v10 && v10 < m_dim && v11.size() == 1 );
          v01[v10] = m_G.Product( move( v01[v10] ) , v11[0] );

        }

      }

    } else {
        
      if( v01.empty() ){

        assert( v00 == -1 );
        v00 = *m_p_index;
        v01 = {m_G.One()};

      }

      assert( v00 == *m_p_index && v01.size() == 1 );

      if( v10 == -1 ){

        v01[0] = m_G.Product( move( v01[0] ) , v11[*m_p_index] );

      } else {
          
        assert( 0 <= v10 && v10 < m_dim && v11.size() == 1 );

        if( v10 == *m_p_index ){

          v01[0] = m_G.Product( move( v01[0] ) , v11[0] );
            
        }
          
      }

    }
  }

  return move( v0 );

}

template <typename U , typename GROUP> inline pair<int,vector<U>> DirectSumGroup<U,GROUP>::Wrap( const int& index , const U& u ) const noexcept { return {index,{u}}; }
