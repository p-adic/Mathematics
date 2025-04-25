// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/a_Body.hpp"

template <typename U , typename MONOID>
U AbstractIntervalCostfreeUnboundedValueSumKnapsack( MONOID M , const vector<U>& value , const bool& non_empty )
{

  static_assert( is_same_v<inner_t<MONOID>,U> );
  const int N = value.size();
  const U& one = M.One();

  if( N == 0 ){

    assert( !non_empty );
    return one;

  }

  U temp = value[0] , answer = non_empty ? temp : max( temp , one );

  for( int i = 1 ; i < N ; i++ ){

    temp = M.Product( max( move( temp ) , one ) , value[i] );
    answer = max( move( answer ) , temp );

  }

  return answer;

}

template <typename INT> inline INT IntervalCostfreeUnboundedValueSumKnapsack( const vector<INT>& value , const bool& non_empty ) { return AbstractIntervalCostfreeUnboundedValueSumKnapsack( AdditiveMonoid<INT>() , value , non_empty ); }
