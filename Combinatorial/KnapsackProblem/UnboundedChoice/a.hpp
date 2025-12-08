// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/a.hpp

#pragma once
// verify:
// UnboundedChoiceKnapsack（N,value_max,cost_max,cost_sum_bound）
// https://yukicoder.me/submissions/1139462 (20,10^3,10^3,10^9)

// コストが正ならば選択回数はcost_sum_boundで抑えられ、
// 価値の総和は(max_i value[i])*cost_sum_boundで抑えられるので、
// その場合はBoundedChoiceNegativeValue(Costwise)Knapsack
// と比較して早い方を用いる。

// 入力の範囲内で要件
// (1) N未満の任意の非負整数iに対し0<=value[i]
// (2) N未満の任意の非負整数iに対し0<=cost[i]
// (3) N未満の任意の非負整数iに対しcost[i]=0ならばvalue[i]=0
// (4) 0<=cost_sum_bound
// を満たす場合にのみサポート。

// O(min(N + cost_sum_bound^2,N(sum_i value[i])(max_i cost[i])))で
// 重複を上限なく許して各項目を選択する際にコストの総和cost_sum_bound以下の
// もとで価値の総和の最大値とそれを実現するコストの最小値の組を返す。
template <typename INT1 , typename INT2> inline pair<INT1,INT2> UnboundedChoiceKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound );
