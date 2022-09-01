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

// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <uint N>
void SGetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] );

// 1+i�Ԗڂ̑f���ȏ�̑��قȂ�f���L���̘a�ŕ\���Ȃ��ŏ��̔񕉐�����Ԃ�
uint GetKloveSequence( const uint& i ) noexcept;
