// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/Periodic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Vector/a_Body.hpp"

template <typename T , typename VEC , typename CHAR , typename VALID>
T PeriodicSubsequenceDP( const VEC& S , ll K , const CHAR& zero , const int& C , VALID valid )
{

  assert( K >= 0 );
  vector D( C + 2 , vector<T>( C + 2 ) );

  for( int j = 0 ; j < C + 2 ; j++ ){
    
    D[j][j] = 1;

  }

  for( auto& c : S ){

    const int j = c - zero;
    assert( j < C );
    auto temp = D[C];
    temp[C+1] += valid( c ) ? 1 : 0;
    D[C] += temp - D[j];
    D[j] = move( temp );

  }

  auto mul = [&]( const vector<vector<T>>& X , const vector<vector<T>>& Y ){

    const int L = Y[0].size();
    vector a( C + 2 , vector<T>( L ) );

    for( int i = 0 ; i < C + 2 ; i++ ){

      for( int j = 0 ; j < C + 2 ; j++ ){

        for( int k = 0 ; k < L ; k++ ){

          a[i][k] += X[i][j] * Y[j][k];

        }

      }

    }

    return a;
    
  };

  vector dp( C + 2 , vector<T>( 1 ) );
  dp[C+1][0] = 1;
  
  while( K > 0 ){

    if( K & 1 ){

      dp = mul( D , dp );

    }

    D = mul( D , D );
    K >>= 1;

  }

  return dp[C][0];

}
