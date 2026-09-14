// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Multicost/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) exceptionalは価値の総和で表せない。
// (3) N未満の各iに対しcost0[i]が0以上である。
// (4) N未満の各iに対しcost1[i]が0以上である。
// (5) 0 <= cost_sum0_boundである。
// (6) 0 <= cost_sum1_boundである。
// を満たす場合にのみサポート。
// 計算量O(N cost0_sum_bound cost1_sum_bound)で
// N未満の各iに対し項目iのコストを(cost0[i],cost1[i]) in N^2とした時
// コストの総和(c_0,c_1)が
// - c_0 <= cost0_sum_bound
// - c_1 <= cost1_sum_bound
// を満たす時の価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID> U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<int>& cost1 , const int& cost1_sum_bound );
template <typename INT> inline int NegativeValueMulticostKnapsack( const vector<INT>& value , const INT& exceptional , const vector<int>& cost0 , const int& cost0_sum_bound , const vector<int>& cost1 , const int& cost1_sum_bound );
