// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/BoundedConnectedComponent/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1192788

// 要件
// (1) N未満の任意の非負整数iに対し0<=value[i]である。
// を満たす場合のみサポート。

// 計算量O(N)で選択項目の連続がr以下かつ非選択項目の間隔がl以上であるような
// 選択方法での価値の総和の最大値を求める。
template <typename INT> INT CostfreeBoundedConnectedComponentKnapsack( const vector<INT>& value , const int& r , const int& l = 1 );
