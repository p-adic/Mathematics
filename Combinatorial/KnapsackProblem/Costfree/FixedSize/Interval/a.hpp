// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/FixedSize/Interval/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// を満たす場合にのみサポート。

// 計算量O(N log subset_size)で
// 各i<Nに対しanswer[i]に(value[i-interval_size+1],...,value[i])の要素数subset_sizeの
// 部分集合の価値の総和の最大値を格納する。ただしi<interval_size-1||inteval_size<subset_size
// においてはG.zero()を格納する。
template <typename U , typename COMM_GROUP> vector<U> AbstractCostfreeFixedSizeIntervalwiseKnapsack( COMM_GROUP G , const vector<U>& value , const int& interval_size , const int& subset_size );
template <typename INT> inline vector<INT> CostfreeFixedSizeIntervalwiseKnapsack( const vector<INT>& value , const int& interval_size ,  const int& subset_size );
