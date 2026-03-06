// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/InversionNumber/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1030881（InversionNumber）

// 順列とは限らない非負整数値配列Aの転倒数計算O(Max(A)+N log Max(A))
template <typename INT> ll InversionNumber( const vector<INT>& A );
// Max(A)が大きい場合は座標圧縮を併用する。

// 順列Pの極小基本互換表示の濃度計算O(N log N)
template <typename INT> inline ll LeastAdjacentSwapCount( const vector<INT>& P );
