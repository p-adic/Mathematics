// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/Periodic/a.hpp

#pragma once

// 文字の種類数をCと置く。

// S*Kの連続とは限らない非空部分列と一致する列であって先頭がvalidであるものの種類数を部分列DPと
// 行列累乗でO(S.size()*C+(log K)*C^3)で求める。
template <typename T , typename VEC , typename CHAR , typename VALID> T PeriodicSubsequenceDP( const VEC& S , ll K , const CHAR& zero , const int& C , VALID valid );
