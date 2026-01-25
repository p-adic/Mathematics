// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IteratedArithmetic/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1141316 (Prod)

#include "a_Macro.hpp"
#include "../a.hpp"

// 以下L = fの長さ、D_sum = 次数の総和とする。

// 多項式の総和は
// ../../Arithmetic/Iteration/
// のSumで良い。

// 次数Nで打ち切る場合は
// ../FPS/Arithmetic/Iteration/
// を用いる。

// 有理式の総和（O(D_sum(log D_sum)(log L))）
template <typename T> pair<Polynomial<T>,Polynomial<T>> RationalSum( list<pair<Polynomial<T>,Polynomial<T>>> f );

// 多項式の総乗（O(D_sum(log D_sum)(log L))）
template <typename T> Polynomial<T> Prod( list<Polynomial<T>> f );


// 以下D = 次数の上限とする。

// 多項式のe乗（O(De(log De)(log e))）
template <typename T> inline Polynomial<T> Power( const Polynomial<T>& f , const int& e );
