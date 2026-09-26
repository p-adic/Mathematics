// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/IncreasingSubsequence/Disjoint/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1190562 (K = 2)

// Greeneの定理
// https://mathoverflow.net/questions/124633/generalizations-of-greenes-theorem-for-the-robinson-schensted-correspondence
// を参照。

// O(size K log size)でaの連続とは限らない非空単調増加部分列からなる非交叉な高々K組の
// 長さの和の最大値を返す。
// ただしK=-1の時はKをsizeに置き換える。
template <typename T> int LongestDisjointNonStrictlyIncreasingSubsequence( const vector<T>& a , int K = -1 );

