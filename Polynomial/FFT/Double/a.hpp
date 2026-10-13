// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/Double/a.hpp

#pragma once
// 2^52 ≒ 4.5*10^15精度のFFT。
// - 絶対値2*10^5以下の係数を持つ10^5次以下の多項式同士の積
// - 絶対値2*10^4以下の係数を持つ10^7次以下の多項式同士の積
// などを扱う。
// プロス素数を法とするNTTより定数倍遲いが、次数の融通が利く。

#include <complex>

#include "a_Alias.hpp"

constexpr const cd pij{ 0 , -3.141592653589793 };

template <typename INT> vector<cd> FFT( const vector<INT>& f , int n , int v );
inline void IFFT( vector<cd>& f , const int& n , int v );

template <typename VEC0 , typename VEC1> vector<ll> Convolution( VEC0 f , VEC1 g );
