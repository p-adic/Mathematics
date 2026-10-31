// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/CountSequence/IncreasingSubsequence/a.hpp

#pragma once
#include "a_Macro.hpp"

// Tがbool operator<(const T&,const T&)に関して全順序である場合にのみサポート。

// O(size log size)でaの連続とは限らない非空単調増加部分列を数え上げる。
template <typename T> ll CountStrictlyIncreasingSubsequence( const vector<T>& a );
template <typename T> ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a );
template <typename T> ll CountStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod );
template <typename T> ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod );
