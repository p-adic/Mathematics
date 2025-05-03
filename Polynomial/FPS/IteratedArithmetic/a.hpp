// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FPS/IteratedArithmetic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// �ȉ�D = �����̏���AL = f�̒����AN = �ł��؂莟���iD<N�j�Ƃ���B

// �L�����̑��a��N���őł��؂�O(DL(log N)(1+log N/D))
template <typename T , template <typename...> typename V> V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& RationalSum( V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& f );

// �������̑����N���őł��؂�iO(DL(log N)(1+log N/D))�j
template <typename T , template <typename...> typename V>FormalPowerSeries<T>& Prod( V<FormalPowerSeries<T>>& f );

// T���W��0�܂���N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�ɑ�������t���N���ł��؂�B�iO(N log N)�j
template <typename T> inline FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const T& t );
// T���W��0�܂���f.m_N�ȏ�̑̂̏ꍇ�ɑ�������e���N���ł��؂�B�iO(N log N)�j
template <typename T , typename INT> FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const INT& e );

// a exp(bx)�̑��a��N���ł��؂�iO(L(log N)^2 + N(log N))�j
template <typename T , template <typename...> typename V> FormalPowerSeries<T> ExponentialSum( const int& N , const V<pair<T,T>>& coef );

