// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include <vector>

// 1+i�Ԗڂ̑f����Ԃ�
const uint& GetPrime( const uint& i ) noexcept;

// i<N�̎���1+i�Ԗڂ̑f����Ԃ�
template <uint N>
const uint& GetPrimeBounded( const uint& i );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
void SetPrimeFactorisation( const uint& n , vector<uint>& P , vector<uint>& exponent );
// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
void SetPrimeFactorisation( const uint& n , vector<uint>& P , vector<uint>& exponent , vector<uint>& P_power );

// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <uint N>
void SetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] );
// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <uint N>
void SetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] , uint ( &P_power )[N] );

// 1+i�Ԗڂ̑f���ȏ�̑��قȂ�f���L���̘a�ŕ\���Ȃ��ŏ��̔񕉐�����Ԃ�
uint GetKloveSequence( const uint& i ) noexcept;

// GCD��LCM��../Mod/CRT/a_Body.hpp�Œ�`
