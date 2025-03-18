// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// ���v�v�Z��O(p_i) = O(i log i)��1+i�Ԗڂ̑f��p_i��Ԃ�
int GetPrime( const int& i );

// T=20�ȂǂƂ��AO(T(log n)^3)�Ō딻�藦��4^{-T}�ɗ}����
bool MillerRabin( const int& n );
