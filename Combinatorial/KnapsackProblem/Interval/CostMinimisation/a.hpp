// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/CostMinimisation/a.hpp

#pragma once
// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してU1の全順序群構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してU2の全順序群構造である。
// (3) N未満の任意の非負整数iに対し、value[i] < M1.One()でない。
// (4) N未満の任意の非負整数iに対し、cost[i] < M2.One()でない。
// を満たす場合にのみサポート。

// 計算量O(N)で
// valueの区間のみが選択可能である条件下で、answer[l]にvalue_prod_ubound以上の
// ナップサック価値を実現する区間[l,r]のコスト総和の最小値（存在しなければexceptional）を格納する。
template <typename U1 , typename GROUP1 , typename U2 , typename GROUP2> vector<pair<U2,int>> AbstractCostMinimisationIntervalKnapsack( GROUP1 M1 , GROUP2 M2 , const vector<U1>& value , const U1& value_prod_ubound , const vector<U2>& cost , const U2& exceptional );
template <typename INT1 , typename INT2> inline vector<pair<INT2,int>> CostMinimisationIntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost );
