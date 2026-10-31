// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/CountSequence/Subsequence/a.hpp

#pragma once
#include "a.hpp"

// O(S.size() T.size())でTと等しいSの（連続とは限らない）部分列の個数を求める。
template <typename INT , typename VEC> INT CountSubsequence( const VEC& S , const VEC& T );

// - Tと等しい連続部分列の個数を求めたい時は代わりに
//   RollingHash::CountContain() (O(S.size()))
// を用いる。

// - 部分列の種類数を求めたい時は部分列DP
//   Distinct/
//   を用いる。
