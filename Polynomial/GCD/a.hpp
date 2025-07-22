// c:/Users/user/Documents/Programming/Mathematics/Polynomial/GCD/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1062302 (ModularInverse)

// O(deg(f) deg(g))でgcd(f,g)を計算。
template <typename T> Polynomial<T> GCD( Polynomial<T> f , Polynomial<T> g )l

// fがgと互いに素である場合にのみサポート。
// O(deg(f) deg(g))でf mod gの逆元を計算。
template <typename T> Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g );
