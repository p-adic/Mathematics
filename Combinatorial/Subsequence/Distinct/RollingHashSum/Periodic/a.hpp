// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/RollingHashSum/Periodic/a.hpp

#pragma once
// verify: https://yukicoder.me/submissions/1168512

// 文字の種類数をCと置く。

// S*Kの連続とは限らない非空部分列と一致する列であって先頭がvalidであるT=(T[0],...,T[L-1])に対する
// f(T[0])*base^{L-1}+f(T[1])*base^{L-2}+...+f(T[L-1])*base^0の総和を部分列DPで
// O(S.size()*C+(log K)*C^3)で求める。
template <typename VEC , typename CHAR , typename VALID , typename FUNC , typename T> T PeriodicSubsequenceRollingHashSum( const VEC& S , ll K , const CHAR& zero , const int& C , VALID valid , FUNC f , const T& base );
