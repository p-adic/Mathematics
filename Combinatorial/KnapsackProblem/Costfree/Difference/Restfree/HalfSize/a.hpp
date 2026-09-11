// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/Restfree/HalfSize/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1185902 (N=40)

// 入力の範囲内で要件
// (1) exceptionalはvalueの成分N/2個以下の和で表せない。
// を満たす場合にのみサポート。

// 計算量O(N 2^{N/2})で
// 項を２グループに分け、２グループの価値の総和の差であってdif_optに最も近いものを求める。
template <typename INT> inline INT CostfreeHalfSizeDifferenceKnapsack( const vector<INT>& value , const INT& exceptional = -1 , const INT& dif_opt = 0 );
