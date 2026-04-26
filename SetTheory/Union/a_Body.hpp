// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Union/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Arithmetic/Iteration/a_Body.hpp"
#include "../../Utility/Set/a_Body.hpp"
#include "../../Utility/Vector/a_Body.hpp"

template <typename VEC>
vector<int> UnionCardinality( const int& N , const vector<VEC>& S )
{

  const int M = S.size();
  vector<vector<int>> S_inv( N );

  for( int j = 0 ; j < M ; j++ ){

    for( auto& i : S[j] ){

      S_inv[i] <<= j;

    }

  }

  map<vector<int>,int> count{};
  int K_max = 0;

  for( int i = 0 ; i < N ; i++ ){

    Sort( S_inv[i] , 1 );
    ENUM_SUB( count[t]++ );
    SetMax( K_max , K );

  }

  const int p_max = 1 << K_max;
  vector<int> sign( p_max , -1 );

  for( int s = 1 ; s < p_max ; s++ ){

    sign[s] = -sign[s^(-s&s)];

  }
  
  vector<int> a( N );
  
  for( int i = 0 ; i < N ; i++ ){

    ENUM_SUB( a[i] += sign[s] * count[t] );

  }

  return a;

}
