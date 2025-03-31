// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IteratedArithmetic/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// 以下D = 次数の上限、L = fの長さとする。

// 多項式の総和(O(DL))
template <typename T , template <typename...> typename V> Polynomial<T>& Sum( V<Polynomial<T>>& f );

// 有理式の総和（O(DL(log DL)^2)）
template <typename T , template <typename...> typename V> pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f );

// 多項式の総乗（O(DL(log DL)^2)）
template <typename T , template <typename...> typename V> Polynomial<T>& Prod( V<Polynomial<T>>& f );

// 多項式のe乗（O(De(log De)^2)）
template <typename T> inline Polynomial<T> Power( const Polynomial<T>& f , const int& e );

