// c:/Users/user/Documents/Programming/Mathematics/Polynomial/GCD/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1062302 (ModularInverse)

// O(deg(f) deg(g))��gcd(f,g)���v�Z�B
template <typename T> Polynomial<T> GCD( Polynomial<T> f , Polynomial<T> g )l

// f��g�ƌ݂��ɑf�ł���ꍇ�ɂ̂݃T�|�[�g�B
// O(deg(f) deg(g))��f mod g�̋t�����v�Z�B
template <typename T> Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g );
