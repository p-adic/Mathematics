// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

template <size_t value_sum_bound , typename INT>
bitset<value_sum_bound+1> CostfreePresentabilityConstexprKnapsack( const vector<INT>& value )
{
  
  bitset<value_sum_bound+1> S = 1;

  for( auto& v : value ){

    S |= ( S << v );

  }

  return S;

}
