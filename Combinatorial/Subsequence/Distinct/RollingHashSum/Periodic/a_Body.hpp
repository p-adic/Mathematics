// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/RollingHashSum/Periodic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Utility/Vector/a_Body.hpp"

template <typename VEC , typename CHAR , typename VALID , typename FUNC , typename T>
T PeriodicSubsequenceRollingHashSum( const VEC& S , ll K , const CHAR& zero , const int& C , VALID valid , FUNC f , const T& base )
{

  assert( K >= 0 );
  const int C2 = ( C + 1 ) * 2 + 1;
  vector D( C2 , vector<T>( C2 ) );

  for( int j = 0 ; j < C2 ; j++ ){
    
    D[j][j] = 1;

  }

  for( auto& c : S ){

    const int j = c - zero;
    assert( j < C );
    auto temp0 = D[C];
    temp0[(C+1)*2] += valid( c ) ? 1 : 0;
    auto temp1 = D[(C+1)+C] * base + temp0 * T{ f( c ) };
    D[C] += temp0 - D[j];
    D[(C+1)+C] += temp1 - D[(C+1)+j];
    D[j] = move( temp0 );
    D[(C+1)+j] = move( temp1 );
    
  }

  auto mul = [&]( const vector<vector<T>>& X , const vector<vector<T>>& Y ){

    const int L = Y[0].size();
    vector a( C2 , vector<T>( L ) );

    for( int i = 0 ; i < C2 ; i++ ){

      for( int j = 0 ; j < C2 ; j++ ){

        for( int k = 0 ; k < L ; k++ ){

          a[i][k] += X[i][j] * Y[j][k];

        }

      }

    }

    return a;
    
  };

  vector dp( C2 , vector<T>( 1 ) );
  dp[(C+1)*2][0] = 1;
  
  while( K > 0 ){

    if( K & 1 ){

      dp = mul( D , dp );

    }

    D = mul( D , D );
    K >>= 1;

  }

  return dp[(C+1)+C][0];
  
}
