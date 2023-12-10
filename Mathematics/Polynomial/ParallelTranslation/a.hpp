// c:/Users/user/Documents/Programming/Mathematics/Polynomial/ParallelTranslation/a.hpp

#pragma once
#include "../a.hpp"

// O(deg(f) log deg(f))��f(x)��f(x+t)�ɕϊ�����B
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
