// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Arithmetic/AdicExpansion/Dynamic/BitSet/a_Body.hpp"

template <typename INT>
DynamicBitSet CostfreePresentabilityKnapsack( const vector<INT>& value , const INT& value_sum_bound )
{

  DynamicBitSet S{ value_sum_bound + 1 };
  S.Set( 0 , 1 );

  for( auto& v : value ){

    S |= ( S << v );

  }

  return S;
  
}
