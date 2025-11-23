// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Quotient/a.hpp

#pragma once

// ca \equiv gcd(c,base) mod baseを満たすaとgcdの組(a,gcd)を返す。
// ModularInverseとはassertと戻り値だけ異なる関数だが、
// ModularInverseは定数倍高速化のためこの関数を経由させない。
template <typename INT> pair<INT,ll> CoprimeFactorInverse( const ll& base , INT c );

// n \equiv da mod baseを満たす0<=a<baseが存在するならばその最小値を返し、
// 存在しないならば-1を返す。
template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d );
