// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"

#include <vector>

// 1+i�Ԗڂ̑f����Ԃ�
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<N�̎���1+i�Ԗڂ̑f����Ԃ�
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime  const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] );
// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] , INT ( &P_power )[N] );

// GCD��LCM��../Mod/CRT/a_Body.hpp�Œ�`
