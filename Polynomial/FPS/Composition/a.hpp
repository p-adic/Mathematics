// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FPS/Composition/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/938613 (���r�E�X�ϊ�)

// �ȉ������̏����D�Ƃ��A�f��̂Ȃ������Z�̌v�Z�ʂ�O(D log D)�Ƃ���B

// ��ʂ̍���f(g(x))�i��Z��O(D^2)�Ȃ�O(D^{5/2})�AO(D log D)�Ȃ�O(D^2)�j
// R. P. Brent and H. T. Kung, Fast Algorithms for Manipulating Formal Power Series, Journal of the Association for Computing Machinery, Vol. 25, No. 4 (1978), pp 581--595.
// �����ƂɎ����B
template <typename T> FormalPowerSeries<T> Composite( const FormalPowerSeries<T>& f  , const FormalPowerSeries<T>& g );

// ����f(exp(tx))��N���őł��؂�iO(D(log N)^2 + N(log N))�j
template <typename T> FormalPowerSeries<T> ExponentialComposition( const int& N , const Polynomial<T>& f , const T& t );
// ����f((a exp(tx)+b)/(c exp(tx) + d))��N���őł��؂�iO(D((log D)+(log N)^2) + N(log N))�j
template <typename T> FormalPowerSeries<T> MoeviusExponentialComposition( const int& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t );

// ����f(t log(1+x))��N���őł��؂�iO(O((D+N)(log (D+N))^2))�j
template <typename T> FormalPowerSeries<T> LogarithmComposition( const int& N , Polynomial<T> f , const T& t );
// b==d!=0�̏ꍇ�ɍ���f(t log((ax+b)/(cx+d)))��N���őł��؂�iO(O((D+N)(log (D+Nx))^2))�j
template <typename T> FormalPowerSeries<T> MoeviusLogarithmComposition( const int& N , Polynomial<T> f , T a , T b , T c , const T& t );

// ���r�E�X�ϊ�f((ax+b)/(cx+d))��N���őł��؂�iO(D(log D)+N(log N))�j
template <typename T> FormalPowerSeries<T> MoeviusComposition( const int& N , Polynomial<T> f , T a , T b , T c , T d );
