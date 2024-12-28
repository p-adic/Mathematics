// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemanZeta/a.hpp

#pragma once
// https://atcoder.jp/contests/abc230/submissions/57700207 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// n >= 0かつexponent >= 0の時
// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) ^ exponent }
// をO(√n)で求める。
template <typename INT> inline INT FloorRiemannZeta( const INT& n , const INT& exponent );

// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) }
// をO(√|n|)で求める。特にn>=0の時、xy平面内の第1象限（軸含まず）でxy<=nを満たす格子点(x,y)の
// 個数と一致する。
template <typename INT> inline INT HarmonicFloorSum( const INT& n );

