// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP M , const vector<U>& value , const U& value_sum_bound , const int& diff_min , int diff_max ) { return AbstractIntervalKnapsack( AddiiveGroup<int>() , M , value , value_sum_bound , vector<int>( value.size() ) , int( 0 ) , diff_min , move( diff_max ) ); }
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min , int diff_max ) { return AbstractIntervalCostfreeKnapsack( AddiiveGroup<INT>() , value , value_sum_bound , diff_min , move( diff_max ) ); }
