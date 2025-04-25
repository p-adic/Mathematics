// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/a.hpp

#pragma once

// diff_max = -1ならばdiff_maxをN - 1に置き換える。
// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換群構造である。
// (2) diff_min <= diff_max < Nである。
// を満たす場合にのみサポート。
// valueの各成分が非負の時は計算量O(N)、一般にはO(N(diff_max - diff_min + 1))で
// 長さdiff_min以上diff_max以下のvalueの連続部分和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP M , const vector<U>& value , const U& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
