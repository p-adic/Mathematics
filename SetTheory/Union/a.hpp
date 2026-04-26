// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Union/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1161722 (K=1,2)

// VECはint型の集合を管理できる型。

// 要件
// - 任意のs in Sに対しsはN未満の非負整数からなる集合である。
// を満たす場合のみサポート。N未満の各非負整数iをわたり、i in sを満たすsの個数の最大値をKとおく。

// O(NK 2^K(log N + K) + #S + sum_{s in S} #s)でN未満の各非負整数iに対し
// answer[i]にi in sを満たすsの和集合の要素数を格納する。
template <typename VEC> vector<int> UnionCardinality( const int& N , const vector<VEC>& S );
