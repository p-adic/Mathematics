// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Cumulative/a.hpp

#pragma once
// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum)

// MがTのモノイド構造である場合にのみサポート。
// Tの要素の列のMに関する総乗を分割統治で計算し、その結果を返す。
// V<T>はeraseを持つ必要がある。
template <typename T , template <typename...> typename V , typename MONOID> T MonoidalProd( MONOID M , V<T> f );
template <typename T , template <typename...> typename V> inline T Sum( V<T> f );
template <typename T , template <typename...> typename V> inline T Prod( V<T> f , T unit = 1 );

// 初項l交差dの等差数列のr以下までの総和を取る。
// 0 <= l , r <= 4e9ならばINT = llでオーバーフローを避けられる。
// 0 <= l , r <= 6e9ならばINT = ullでオーバーフローを避けられる。
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d = 1 );
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r );
