// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/FixedSize/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1185902  (N=40)

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) exceptionalはMの要素N/2個以下の和で表せない。
// を満たす場合にのみサポート。

// 計算量O(N 2^{N/2})で
// 要素数subset_sizeの部分集合の価値の総和のvalue_sum_bound以下の最大値を格納する。
// ただし存在しない場合はexceptionalを返す。
template <typename U , typename COMM_MONOID> U AbstractCostfreeFixedSizeKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const int& subset_size );
template <typename INT> inline INT CostfreeFixedSizeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const INT& exceptional , const int& subset_size );
