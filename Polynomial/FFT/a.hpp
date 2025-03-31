// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// include�W�J��:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

template <typename T> inline constexpr const int LimitOfPowerForFFT;

template <typename T> inline const T ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];
template <typename T> inline const T ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];

// �ȉ��v��
// (1) N_input_lim - N_input_start <= two_power
// (2) N_trunc - ( N_shift + N_input_start ) <= two_power
// (3) �C�ӂ̐���i�ɑ΂��AN_input_lim <= i < f.size()�Ȃ��f[i] == 0;
// ���ۂ��B

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// �������t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_trunc�̔z��
// (f[0],...,f[N_input_start - 1],N_shift��0,g[0],...)
// �ɒu��������B
template <typename T>
void CooleyTukey( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const int& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// �������t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + two_power�̔z��
// (f[0],...,f[N_input_start - 1],g[0],...,g[two_power - 1])
// �ɒu��������B
template <typename T> inline void FFT( vector<T>& f , const int& N_input_start , const int& N_input_lim , const int& two_power , const int& exponent );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// ���t�����t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_trunc�̔z��
// (f[0],...,f[N_input_start - 1],N_shift��0,g[0],...,g[N_trunc-1-N_input_start-N_shift])
// �ɒu��������B
template <typename T> inline void IFFT( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const T& two_power_inv , const int& exponent );

// Polynomial�̓��ꉻ�p�B
template <typename T> Polynomial<T> FFTConvolution( Polynomial<T> f0 , Polynomial<T> f1 , const int& N_trunc );
template <typename T> Polynomial<T> FFTQuotient( Polynomial<T> f0 , Polynomial<T> f1 );
template <typename T> Polynomial<T> FFTResidue( Polynomial<T> f0 , const Polynomial<T>& f1 );
