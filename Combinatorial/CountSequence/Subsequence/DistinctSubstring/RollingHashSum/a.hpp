// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/CountSequence/Subsequence/DistinctSubsequence/RollingHashSum/a.hpp

#pragma once

// 文字の種類数をCと置く。

// Sの連続とは限らない非空部分列と一致する列であって先頭がvalidであるT=(T[0],...,T[L-1])に対する
// f(T[0])*base^{L-1}+f(T[1])*base^{L-2}+...+f(T[L-1])*base^0の総和を部分列DPで
// O(C+S.size())で求める。
template <typename VEC , typename CHAR , typename VALID , typename FUNC , typename T> T SubsequenceRollingHashSum( const VEC& S , const CHAR& zero , const int& C , VALID valid , FUNC f , const T& base );
