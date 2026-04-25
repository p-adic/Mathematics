// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/CostMinimisation/Disjoint/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1161587 (CostMinimisationDisjointIntervalKnapsack, K=2)

#include "../../../../../Utility/Tuple/Wrap/a.hpp"

// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してU1の全順序群構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してU2の全順序群構造である。
// (3) N未満の任意の非負整数iに対し、value[i] < M1.One()でない。
// (4) N未満の任意の非負整数iに対し、cost[i] < M2.One()でない。
// を満たす場合にのみサポート。

// 計算量O(NK)で
// valueの区間のみが選択可能である条件下で、value_prod_ubound以上のナップサック価値を実現する区間K個からなる排他的族の和集合のコストの最小化（存在しなければexceptional）を求める。
template <typename U1 , typename GROUP1 , typename U2 , typename GROUP2> pair<U2,vector<T2<int>>> AbstractCostMinimisationDisjointIntervalKnapsack( GROUP1 M1 , GROUP2 M2 , const vector<U1>& value , const U1& value_prod_ubound , const vector<U2>& cost , const int& K , const U2& exceptional );
template <typename INT1 , typename INT2> inline pair<INT2,vector<T2<int>>> CostMinimisationDisjointIntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_ubound , const vector<INT2>& cost , const int& K );
