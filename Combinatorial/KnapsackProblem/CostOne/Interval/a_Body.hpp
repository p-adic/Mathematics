// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/CostOne/Interval/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename GROUP>
vector<int> AbstractCostOneIntervalKnapsack( GROUP M , const vector<U>& value , const U& value_prod_ubound )
{

  const int N = value.size();
  vector<int> answer( N , N );

  if( N > 0 ){
    
    int left = 0 , right = 0;
    U prod = value[0];

    while( left < N ){
      
      while( right + 1 < N && prod < value_prod_ubound ){

        prod = M.Product( move( prod ) , value[++right] );

      }

      if( prod < value_prod_ubound ){

        break;

      }

      answer[left] = right;
      prod = M.Product( M.Inverse( value[left++] ) , prod );

    }

  }

  return answer;

}

template <typename INT> inline vector<int> CostOneIntervalKnapsack( const vector<INT>& value , const INT& value_sum_ubound ) { return AbstractCostOneIntervalKnapsack( AdditiveGroup<INT>{} , value , value_sum_ubound ); }
