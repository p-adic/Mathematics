// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/Segmentwise/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/a_Body.hpp"

template <typename U , typename MONOID>
vector<U> AbstractIntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( MONOID M , const vector<U>& value , const bool& non_empty , const bool& reversed )
{

  static_assert( is_same_v<inner_t<MONOID>,U> );
  const int N = value.size();
  const U& one = M.One();
  vector<U> answer( N );

  if( N > 0 ){

    int i , d;

    if( reversed ){

      i = N-1;
      d = -1;

    } else {

      i = 0;
      d = 1;

    }

    U temp = value[i];
    answer[i] = non_empty ? temp : max( temp , one );

    for( int num = 1 ; num < N ; num++ ){

      temp = M.Product( max( move( temp ) , one ) , value[i += d] );
      answer[i] = max( answer[i-d] , temp );

    }

  }

  return answer;

}

template <typename INT> inline vector<INT> IntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( const vector<INT>& value , const bool& non_empty , const bool& reversed ) { return AbstractIntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( AdditiveMonoid<INT>() , value , non_empty , reversed ); }
