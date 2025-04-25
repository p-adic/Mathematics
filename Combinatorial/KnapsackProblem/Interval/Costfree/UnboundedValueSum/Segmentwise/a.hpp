// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/Segmentwise/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序モノイド構造である。
// を満たす場合にのみサポート。
// 各iに対し、reversed?[i,N):[0,i]に含まれるvalueの(non_empty?非空:空でもよい)区間の
// 部分積（右総乗）の最大値を合計O(N)でanswer[i]に格納する。
template <typename U , typename MONOID> vector<U> AbstractIntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( MONOID M , const vector<U>& value , const bool& non_empty = true , const bool& reversed = false );
template <typename INT> inline vector<INT> IntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( const vector<INT>& value , const bool& non_empty = true , const bool& reversed = false );
