// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LongestSubsequence/ZigZagSubsequence/a.hpp

#pragma once
#include "../../../Utility/Tuple/Wrap/a.hpp"

// bool operator<(const T&,const T&)が全順序である場合にのみサポート。

// O(A.size())で
// {増減増...型の最長部分列の長さ,減増減...型の最長部分列の長さ}を求める。
template <typename T> T2<int> LongestZigZagSubsequence( const vector<T>& A );
