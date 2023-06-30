// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once
#include "../../Prime/Constexpr/a.hpp"

template <typename INT> inline INT EulerFunction( const INT& n );
template <typename INT , INT val_limit , int length_max> inline INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max>
INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent );

// size <= val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max , int size , typename INT2>
vpid MemoriseEulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT2 ( &memory )[size] );

template <typename INT> inline INT CarmichaelFunction( const INT& n );
template <typename INT , INT val_limit , int length_max> inline INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max>
INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// �f���������̎w����exponent�ł���񕉐����Ƃ���Carmichael�֐��̒l���ŏ����{���̑f�����̎w����exponent�Ɋi�[�������B
void CarmichaelTransformation( vector<uint>& exponent );
