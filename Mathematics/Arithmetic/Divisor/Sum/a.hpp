// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a.hpp

#pragma once

// n_max�ȉ��̊e������n�ɑ΂��Aanswer[n]��d_max�ȉ��̐��̖񐔂�exponential��̑��a��
// �i�[���ĕԂ��B(O(min(n_max,d_max) log exponent + n_max log min(n_max,d_max)))
template <typename INT> vector<INT> DivisorSum( const INT& n_max , const INT& d_max , const int& exponent = 1 );
