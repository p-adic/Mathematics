// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// CumulativeSum�i����̗ݐϘa�Ahttps://yukicoder.me/submissions/1027399�j

// �ȉ�D = �����̏���AL = f�̒����AN = �ł��؂莟���iD<N�j�Ƃ���B

// x^d�̗ݐϘa������0^D+1^D+...+x^D�B�iO(D log D)�j
// �t�@�E���n�[�o�[�̌����Ōv�Z����B
template <typename T , int deg_max> Polynomial<T> MonomialSum( const int& D );
// f(x)�̗ݐϘa������f(0)+...+f(x)�B�iO(D log D)�j
// Lain, https://codeforces.com/blog/entry/98563, Lain's blog, Codeforces, 2021.
// �����ƂɎ����B
template <typename T , int deg_max> Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential = false );
// a��order�K�ݐϘa����B�iO(D log D)�j
template <typename T> vector<T> CumulativeSum( vector<T> a , int order = 1 );
