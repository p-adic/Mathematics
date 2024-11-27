// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Composition/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://judge.yosupo.jp/submission/176829 ���s�ړ�
// https://yukicoder.me/submissions/938613 ���r�E�X�ϊ�

// �ȉ������̏����D�Ƃ��A�f��̂Ȃ������Z�̌v�Z�ʂ�O(D log D)�Ƃ���B

// ��ʂ̍���f(g(x))�i��Z��O(D^2)�Ȃ�O(D^{5/2})�AO(D log D)�Ȃ�O(D^2)�j
// R. P. Brent and H. T. Kung, Fast Algorithms for Manipulating Formal Power Series, Journal of the Association for Computing Machinery, Vol. 25, No. 4 (1978), pp 581--595.
// �����ƂɎ����B
template <typename T> TruncatedPolynomial<T> Composite( const TruncatedPolynomial<T>& f  , const TruncatedPolynomial<T>& g );

// f��N-1���܂łőł��؂���g�̔��]g(x^{-1})*x^{N-1}�iO(D+N)�j
template <typename T> void TruncatedReverse( const unt& N , Polynomial<T>& f );
// ���s�ړ�f(x+t)�iO(D log D)�j
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
// �A�t�B���ϊ�f(tx+u)�iO(D log D)�j
template <typename T> void AffineTransformation( Polynomial<T>& f , const T& t , const T& u = Polynomial<T>::c_zero() , const bool& exponential = false );
// ���r�E�X�ϊ�f((ax+b)/(cx+d))��h(x)/(ux+v)^e�̌`�ŕ\������{h,u,v,e}��Ԃ��B�iO((D log D))�j
template <typename T> tuple<Polynomial<T>,T,T,uint> MoeviusComposition( Polynomial<T> f , T a , T b , T c , T d );
// ���r�E�X�ϊ�f((ax+b)/(cx+d))��N���őł��؂�iO(D(log D)+N(log N))�j
template <typename T> TrucatedPolynomial<T> MoeviusComposition( const uint& N , Polynomial<T> f , T a , T b , T c , T d );

// ����f(exp(tx))��N���őł��؂�iO(D(log N)^2 + N(log N))�j
template <typename T> TruncatedPolynomial<T> ExponentialComposition( const uint& N , const Polynomial<T>& f , const T& t );
// ����f((a exp(tx)+b)/(c exp(tx) + d))��N���őł��؂�iO(D((log D)+(log N)^2) + N(log N))�j
template <typename T> TruncatedPolynomial<T> MoeviusExponentialComposition( const uint& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t );

// ����f(t log(1+x))��N���őł��؂�iO(O((D+N)(log (D+N))^2))�j
template <typename T> TruncatedPolynomial<T> LogarithmComposition( const uint& N , Polynomial<T> f , const T& t );
// b==d!=0�̏ꍇ�ɍ���f(t log((ax+b)/(cx+d)))��N���őł��؂�iO(O((D+N)(log (D+Nx))^2))�j
template <typename T> TruncatedPolynomial<T> LogarithmComposition( const uint& N , Polynomial<T> f , T a , T b , T c , const T& t );
