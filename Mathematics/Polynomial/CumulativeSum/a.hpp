// c:/Users/user/Documents/Programming/Mathematics/Polynomial/CumulativeSum/a.hpp

#pragma once
#include "../a.hpp"

// O(deg(f) log deg(f))�ŗݐϘa������f(0)+...+f(x)���v�Z�B
// Lain, https://codeforces.com/blog/entry/98563, Lain's blog, Codeforces, 2021.
// �����ƂɎ����B
template <typename T , uint deg_max> Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential = false );
