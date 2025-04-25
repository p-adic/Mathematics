// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序モノイド構造である。
// を満たす場合にのみサポート。
// valueの非空連続部分積（右総乗）の最大値をO(N)で求める。
template <typename U , typename MONOID> U AbstractIntervalCostfreeUnboundedValueSumKnapsack( MONOID M , const vector<U>& value , const bool& non_empty = true );
template <typename INT> inline INT IntervalCostfreeUnboundedValueSumKnapsack( const vector<INT>& value , const bool& non_empty = true );
