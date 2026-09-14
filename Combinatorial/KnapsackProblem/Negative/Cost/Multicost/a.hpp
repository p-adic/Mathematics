// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Multicost/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1186827

// 2次元コストの片方が非負の場合のナップサック最適化。

// valueの総和をvalue_sum_boundと置く。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) N未満の各iに対しcost0[i]が0以上である。
// (4) 0 <= cost_sum0_boundである。
// (5) cost_sum1_bound < exceptionalである。
// を満たす場合にのみサポート。
// 計算量O(N value_sum_bound cost0_sum_bound)で
// N未満の各iに対し項目iのコストを(cost0[i],cost1[i]) in N^2とした時
// コストの総和(c_0,c_1)が
// - c_0 <= cost0_sum_bound
// - c_1 <= cost1_sum_bound
// を満たす時の価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID> U AbstractHalfNegativeMulticostKnapsack( COMM_MONOID M , const vector<int>& value , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<U>& cost1 , const U& cost1_sum_bound , const U& exceptional );
template <typename INT> inline int HalfNegativeMulticostKnapsack( const vector<int>& value , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<INT>& cost1 , const INT& cost1_sum_bound );

// 2次元コストの両方が非負の場合はO(N cost0_sum_bound cost1_sum_bound)の
// ../../Value/Multicost/
// も使用可。
