// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "../a.hpp"

// f��g�ƌ݂��ɑf�ł���ꍇ�ɂ̂݃T�|�[�g�B
// O(deg(f) deg(g))��f mod g�̋t�����v�Z�B
template <typename T>
Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g );
