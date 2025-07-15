// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemannZeta/a.hpp

#pragma once
// https://atcoder.jp/contests/abc230/submissions/67624908 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// n >= 0かつexponent >= 0の時
// sum( int i = 1 ; i <= n ; i++ ){ floor( n / i ) ^ exponent }
// をO((s(log(s)+1)^{s+2}n(log(s)log(n)+1))^{1/(s+1)})で求める。
template <typename INT1 , typename INT2> ll FloorRiemannZeta( const INT1& n , const INT2& s );

// sum( int i = 1 ; i <= n ; i++ ){ floor( n / i ) }
// をO(√|n|)で求める。
// 特にn>=0の時、xy平面内の第1象限（軸含まず）でxy<=nを満たす格子点(x,y)の個数と一致する。
template <typename INT> inline INT HarmonicFloorSum( const INT& n );

