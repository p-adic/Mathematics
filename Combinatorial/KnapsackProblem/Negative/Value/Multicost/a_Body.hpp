// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Multicost/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Arithmetic/Iteration/a_Body.hpp"

template <typename U , typename COMM_MONOID>
U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<int>& cost1 , const int& cost1_sum_bound )
{

  const int N = value.size();
  assert( N == int( cost0.size() ) && N == int( const1.size() ) );
  vector dp( cost0_sum_bound + 1 , vector( cost1_sum_bound + 1 , exceptional ) );
  U answer = dp[0][0] = M.One();
  
  for( int i = 0 ; i < N ; i++ ){

    for( int w0 = cost0_sum_bound ; w0 >= cost0[i] ; w0-- ){

      for( int w1 = cost1_sum_bound ; w1 >= cost1[i] ; w1-- ){

        U temp = M.Product( dp[w0-cost0[i]][w1-cost1[i]] , value[i] );
        
        if( dp[w0][w1] == exceptional || dp[w0][w1] < temp ){

          SetMax( answer , dp[w0][w1] = move( temp ) );

        }

      }

    }

  }

  return answer;

}


template <typename INT> inline int NegativeValueMulticostKnapsack( const vector<INT>& value , const INT& exceptional , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<int>& cost1 , const int& cost1_sum_bound ) { return AbstractNegativeValueMulticostKnapsack( AdditiveMonoid<INT>() , value , exceptional , cost0 , cost0_sum_bound , cost1 , cost1_sum_bound ); }
