// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FPS/Composition/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/938613 (メビウス変換)

// 以下次数の上限をDとし、断りのない限り乗算の計算量をO(D log D)とする。

// 一般の合成f(g(x))（乗算がO(D^2)ならO(D^{5/2})、O(D log D)ならO(D^2)）
// R. P. Brent and H. T. Kung, Fast Algorithms for Manipulating Formal Power Series, Journal of the Association for Computing Machinery, Vol. 25, No. 4 (1978), pp 581--595.
// をもとに実装。
template <typename T> FormalPowerSeries<T> Composite( const FormalPowerSeries<T>& f  , const FormalPowerSeries<T>& g );

// 合成f(exp(tx))をN次で打ち切る（O(D(log N)^2 + N(log N))）
template <typename T> FormalPowerSeries<T> ExponentialComposition( const int& N , const Polynomial<T>& f , const T& t );
// 合成f((a exp(tx)+b)/(c exp(tx) + d))をN次で打ち切る（O(D((log D)+(log N)^2) + N(log N))）
template <typename T> FormalPowerSeries<T> MoeviusExponentialComposition( const int& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t );

// 合成f(t log(1+x))をN次で打ち切る（O(O((D+N)(log (D+N))^2))）
template <typename T> FormalPowerSeries<T> LogarithmComposition( const int& N , Polynomial<T> f , const T& t );
// b==d!=0の場合に合成f(t log((ax+b)/(cx+d)))をN次で打ち切る（O(O((D+N)(log (D+Nx))^2))）
template <typename T> FormalPowerSeries<T> MoeviusLogarithmComposition( const int& N , Polynomial<T> f , T a , T b , T c , const T& t );

// メビウス変換f((ax+b)/(cx+d))をN次で打ち切る（O(D(log D)+N(log N))）
template <typename T> FormalPowerSeries<T> MoeviusComposition( const int& N , Polynomial<T> f , T a , T b , T c , T d );
