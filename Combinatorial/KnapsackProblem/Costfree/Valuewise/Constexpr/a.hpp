// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/Constexpr/a.hpp

#pragma once

template <size_t value_sum_bound , typename INT> bitset<value_sum_bound+1> CostfreePresentabilityConstexprKnapsack( const vector<INT>& value );

// v以下の最大値の取得は今の実装だとO(v)追加で掛ることに注意。
// 動的版を使えば64倍高速化できる。
