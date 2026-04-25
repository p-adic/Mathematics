// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/CostOne/Interval/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序群構造である。
// (2) N未満の任意の非負整数iに対し、value[i] < M.One()でない。
// を満たす場合にのみサポート。

// 計算量O(N)で
// valueの区間のみが選択可能である条件下で、answer[l]にvalue_prod_ubound以上の
// ナップサック価値を実現する区間[l,r]の右端rの最小値（存在しなければN）を格納する。
template <typename U , typename GROUP> vector<int> AbstractCostOneIntervalKnapsack( GROUP M , const vector<U>& value , const U& value_prod_ubound );
template <typename INT> inline vector<int> CostOneIntervalKnapsack( const vector<INT>& value , const INT& value_sum_ubound );

