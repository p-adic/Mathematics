// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <vector>

template <typename T> inline constexpr const uint LimitOfPowerForFFT;
template <typename T> inline constexpr const uint BorderForFFT;

template <typename T> inline const T ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];
template <typename T> inline const T ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];

// �ȉ��v���F
// (1) N_input_lim - N_in_start <= two_power
// (2) N_output_lim - N_output_start <= two_power
// (3) �C�ӂ̐���i�ɑ΂��AN_input_lim <= i < f.size()�Ȃ��f[i] == 0;

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// �������t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + two_power�̔z��
// (f[0],...,f[N_input_start - 1],g[0],...,g[two_power - 1])
// �ɒu��������B
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const uint& exponent );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// �������t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + N_output_lim�̔z��
// (f[0],...,f[N_input_start - 1],N_output_shift��0,g[N_output_start],...,g[N_output_lim])
// �ɒu��������B
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// ���t�����t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + two_power�̔z��
// (f[0],...,f[N_input_start - 1],,g[0],...,g[two_power - 1])
// �ɒu��������B
template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const T& two_power_inv , const uint& exponent );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// ���t�����t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + N_output_lim�̔z��
// (f[0],...,f[N_input_start - 1],N_output_shift��0,g[N_output_start],...,g[N_output_lim])
// �ɒu��������B
template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const T& two_power_inv , const uint& exponent );

// ����two_power = 2 ^ { exponent }�̔z��
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// �������t�[���G�ϊ��������̂�g�ƒu���A
// f�̌W����𒷂�N_input_start + two_power�̔z��
// (f[0],...,f[N_input_start - 1],N_output_start��0,g[N_output_start],...,g[N_output_lim - 1],0,...)
// �ɒu��������B
template <typename T>
void CooleyTukey( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] );
