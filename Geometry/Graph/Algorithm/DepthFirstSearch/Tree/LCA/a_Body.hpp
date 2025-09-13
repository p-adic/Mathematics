// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/LCA/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFST> inline AncestorDoubling<DFST>::AncestorDoubling( DFST& dfst ) : m_p_dfst{ &m_dfst } , m_size( m_p_dfst->size() ) , m_doubling( 1 , vector<int>( m_size , -1 ) ) {}

template <typename DFST>
int AncestorDoubling<DFST>::Ancestor( int i , int n )
{

  assert( 0 <= i && i < m_size );
  int d = 0;
  
  while( i != -1 && n != 0 ){

    ( n & 1 ) == 1 ? i = Get( d )[i] ) : i;
    d++;
    n >>= 1;

  }

  return i;

}

template <typename DFST>
tuple<int,int,int> AncestorDoubling<DFST>::LCA( int i , int j )
{

  int i_prev = -1 , j_prev = -1;
  const int diff = m_p_dfst->Depth( i ) - m_p_dfst->Depth( j );

  if( diff > 0 ){

    i = m_p_dfst->Parent( i_prev = Ancestor( i , diff - 1 ) );

  } else if( diff < 0 ){

    j = m_p_dfst->Parent( j_prev = Ancestor( j , - diff - 1 ) );

  }

  if( i != j ){

    int d = int( m_doubling.size() ) - 1;
  
    while( Get( d )[i] != Get( d )[j] ){

      Get( ++d );

    }

    while( --d >= 0 ){

      if( m_doubling[d][i] != m_doubling[d][j] ){

        i = m_doubling[d][i];
        j = m_doubling[d][j];

      }

    }

    i = m_p_dfst->Parent( i_prev = i );
    j = m_p_dfst->Parent( j_prev = j );
    assert( i == j );

  }
  
  return {i,i_prev,j_prev};

}

template <typename DFST>
const vector<int>& AncestorDoubling<DFST>::Get( const int& d )
{

  assert( d >= 0 );
  int digit = m_doubling.size();
  
  while( digit <= d ){

    m_doubling.push_back( vector<int>( m_size , -1 ) );

    for( int i = 0 ; i < m_size ; i++ ){

      if( m_doubling[digit-1][i] != -1 ){
        
        m_doubling[digit][i] = m_doubling[digit-1][m_doubling[digit-1][i]];

      }

    }

    digit++;
    
  }

  return m_doubling[d];


}
