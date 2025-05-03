// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FPS/IteratedArithmetic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// 以下D = 次数の上限、L = fの長さ、N = 打ち切り次数（D<N）とする。

// 有理式の総和のN次で打ち切りO(DL(log N)(1+log N/D))
template <typename T , template <typename...> typename V> V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& RationalSum( V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& f );

// 多項式の総乗のN次で打ち切り（O(DL(log N)(1+log N/D))）
template <typename T , template <typename...> typename V>FormalPowerSeries<T>& Prod( V<FormalPowerSeries<T>>& f );

// Tが標数0またはN以上の体でかつf[0] == 1の場合に多項式のt乗のN次打ち切り。（O(N log N)）
template <typename T> inline FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const T& t );
// Tが標数0またはf.m_N以上の体の場合に多項式のe乗のN次打ち切り。（O(N log N)）
template <typename T , typename INT> FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const INT& e );

// a exp(bx)の総和をN次打ち切り（O(L(log N)^2 + N(log N))）
template <typename T , template <typename...> typename V> FormalPowerSeries<T> ExponentialSum( const int& N , const V<pair<T,T>>& coef );

