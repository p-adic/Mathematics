// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/CostOne/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1053123 (CostOneKnapsack)

// cost_sum_boundのサイズがNと等しいとする。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対し0 <= cost_sum_bound[i]である。
// を満たす場合にのみサポート。
// 計算量O(N log min( N , max_i cost_sum_bound[i] ))で
// i番目の項目選択時に選択個数の総和がcost_sum_bound[i]以下である条件下で最終的な
// {価値の総和の最大値,それを実現する選択個数の最小値}を求める。
template <typename U , typename COMM_MONOID> pair<U,int> AbstractValueCostOneKnapsack( COMM_MONOID M , const vector<U>& value , const vector<int>& cost_sum_bound );
template <typename INT> inline pair<INT,int> CostOneKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound );

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換群構造である。
// (2) N未満の各iに対し0 <= cost_sum_bound[i]である。
// を満たす場合にのみサポート。
// 計算量O(N log min( N , max_i cost_sum_bound[i] ))で
// i番目の項目選択時に選択個数の総和がcost_sum_bound[i]以下である条件下で
// {価値の総和の最大値,それを実現する選択個数の最小値}をanswer[i]に格納する。
template <typename U , typename ABEL_GROUP> vector<pair<U,int>> AbstractValueCostOneItemwiseKnapsack( ABEL_GROUP M , const vector<U>& value , const vector<int>& cost_sum_bound );
template <typename INT> inline vector<pair<INT,int>> CostOneItemwiseKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound );
