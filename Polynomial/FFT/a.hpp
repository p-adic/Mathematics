// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// include展開順:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

template <typename T> inline constexpr const int LimitOfPowerForFFT;

template <typename T> inline const T ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];
template <typename T> inline const T ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];

// 以下要件
// (1) N_input_lim - N_input_start <= two_power
// (2) N_trunc - ( N_shift + N_input_start ) <= two_power
// (3) 任意の整数iに対し、N_input_lim <= i < f.size()ならばf[i] == 0;
// を課す。

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を高速フーリエ変換したものをgと置き、
// fの係数列を長さN_truncの配列
// (f[0],...,f[N_input_start - 1],N_shift個の0,g[0],...)
// に置き換える。
template <typename T>
void CooleyTukey( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const int& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + two_powerの配列
// (f[0],...,f[N_input_start - 1],g[0],...,g[two_power - 1])
// に置き換える。
template <typename T> inline void FFT( vector<T>& f , const int& N_input_start , const int& N_input_lim , const int& two_power , const int& exponent );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を逆高速フーリエ変換したものをgと置き、
// fの係数列を長さN_truncの配列
// (f[0],...,f[N_input_start - 1],N_shift個の0,g[0],...,g[N_trunc-1-N_input_start-N_shift])
// に置き換える。
template <typename T> inline void IFFT( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const T& two_power_inv , const int& exponent );

// Polynomialの特殊化用。
template <typename T> Polynomial<T> FFTConvolution( Polynomial<T> f0 , Polynomial<T> f1 , const int& N_trunc );
template <typename T> Polynomial<T> FFTQuotient( Polynomial<T> f0 , Polynomial<T> f1 );
template <typename T> Polynomial<T> FFTResidue( Polynomial<T> f0 , const Polynomial<T>& f1 );
