// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// ���v�v�Z��O(p_i) = O(i log i)��1+i�Ԗڂ̑f��p_i��Ԃ��B
int GetPrime( const int& i );

// T=20�ȂǂƂ��AO(T log n)�Ō딻�藦��4^{-T}�ɗ}����B
// ��������Z�̌v�Z�ʂ�O(1)�Ƃ݂Ȃ����B
bool MillerRabin( const int& n );
