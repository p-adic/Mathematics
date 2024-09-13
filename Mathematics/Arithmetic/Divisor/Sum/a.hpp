// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a.hpp

#pragma once

// RET��MP�Ȃǂł��B
// n�ȉ��̊e������i�ɑ΂��Aanswer[i]��m�ȉ���i�̐���d��exponential��̑��a���i�[���ĕԂ��B
// (O(min(n,m) log exponent + n log min(n,m)))
template <typename INT , typename RET> vector<RET> DivisorSum( const INT& n , const INT& m , const int& exponent = 1 );
