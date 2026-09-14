// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Multicost/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../ValueSumBound/a_Body.hpp"
#include "../../../../../Arithmetic/Iteration/a_Body.hpp"

template <typename U , typename COMM_MONOID>
U AbstractHalfNegativeMulticostKnapsack( COMM_MONOID M , const vector<int>& value , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<U>& cost1 , const U& cost1_sum_bound , const U& exceptional )
{

  const int value_sum_bound = ValueSumBound( value );
  const int N = value.size();
  assert( N == int( cost0.size() ) && N == int( cost1.size() ) );
  vector dp( value_sum_bound + 1 , vector( cost0_sum_bound + 1 , exceptional ) );
  dp[0][0] = M.One();

  for( int i = 0 ; i < N ; i++ ){

    for( int v = value_sum_bound ; v >= value[i] ; v-- ){

      for( int w0 = cost0_sum_bound ; w0 >= cost0[i] ; w0-- ){

        SetMin( dp[v][w0] , M.Product( dp[v-value[i]][w0-cost0[i]] , cost1[i] ) );

      }

    }

  }

  for( int v = value_sum_bound ; v > 0 ; v-- ){

    for( int w0 = 0 ; w0 <= cost0_sum_bound ; w0++ ){

      if( !( cost1_sum_bound < dp[v][w0] ) ){
        
        return v;

      }

    }

  }

  return 0;
  
}

template <typename INT> inline int HalfNegativeMulticostKnapsack( const vector<int>& value , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<INT>& cost1 , const INT& cost1_sum_bound ) { return AbstractHalfNegativeMulticostKnapsack( AdditiveMonoid<INT>() , value , cost0 , cost0_sum_bound , cost1 , cost1_sum_bound , cost1_sum_bound + 1 ); }

