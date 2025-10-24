// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/InversionNumber/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1030881（InversionNumber）

// 順列とは限らない配列Aの転倒数計算O(N log N)
template <typename INT> ll InversionNumber( const vector<INT>& A );

// 順列Pの極小基本互換表示の濃度計算O(N log N)
template <typename INT> inline ll LeastAdjacentSwapCount( const vector<INT>& P );
