// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// �ȉ�D = �����̏���AL = f�̒����AN = �ł��؂莟���iD<N�j�Ƃ���B

// �������̑��a(O(DL))
template <typename T , template <typename...> typename V> Polynomial<T>& Sum( V<Polynomial<T>>& f );

// �L�����̑��a�iO(DL(log DL)^2)�j
template <typename T , template <typename...> typename V> pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f );
// �L�����̑��a��N���őł��؂�O(DL(log N)(1+log N/D))
template <typename T , template <typename...> typename V> V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& RationalSum( V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& f );

// �������̑���iO(DL(log DL)^2)�j
template <typename T , template <typename...> typename V> Polynomial<T>& Prod( V<Polynomial<T>>& f );
// �������̑����N���őł��؂�iO(DL(log N)(1+log N/D))�j
template <typename T , template <typename...> typename V>TruncatedPolynomial<T>& Prod( V<TruncatedPolynomial<T>>& f );

// ��������e��iO(De(log De)^2)�j
template <typename T> inline Polynomial<T> Power( const Polynomial<T>& f , const uint& e );
// T���W��0�܂���N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�ɑ�������t���N���ł��؂�B
template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t );
// T���W��0�܂���f.m_N�ȏ�̑̂̏ꍇ�ɑ�������e���N���ł��؂�B
template <typename T> TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const uint& e );


// a exp(bx)�̑��a��N���ł��؂�iO(L(log N)^2 + N(log N))�j
template <typename T , template <typename...> typename V> TruncatedPolynomial<T> ExponentialSum( const uint& N , const V<pair<T,T>>& coef );

// f(x)�̗ݐϘa������f(0)+...+f(x)�iO(D log D)�j
// Lain, https://codeforces.com/blog/entry/98563, Lain's blog, Codeforces, 2021.
// �����ƂɎ���
template <typename T , uint deg_max> Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential = false );
