// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// CumulativeSum（数列の累積和、https://yukicoder.me/submissions/1027399）

// 以下D = 次数の上限、L = fの長さ、N = 打ち切り次数（D<N）とする。

// x^dの累積和多項式0^D+1^D+...+x^D。（O(D log D)）
// ファウルハーバーの公式で計算する。
template <typename T , int deg_max> Polynomial<T> MonomialSum( const int& D );
// f(x)の累積和多項式f(0)+...+f(x)。（O(D log D)）
// Lain, https://codeforces.com/blog/entry/98563, Lain's blog, Codeforces, 2021.
// をもとに実装。
template <typename T , int deg_max> Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential = false );
// aのorder階累積和数列。（O(D log D)）
template <typename T> vector<T> CumulativeSum( vector<T> a , int order = 1 );
