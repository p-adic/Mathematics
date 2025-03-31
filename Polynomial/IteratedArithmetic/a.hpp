// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IteratedArithmetic/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// �ȉ�D = �����̏���AL = f�̒����Ƃ���B

// �������̑��a(O(DL))
template <typename T , template <typename...> typename V> Polynomial<T>& Sum( V<Polynomial<T>>& f );

// �L�����̑��a�iO(DL(log DL)^2)�j
template <typename T , template <typename...> typename V> pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f );

// �������̑���iO(DL(log DL)^2)�j
template <typename T , template <typename...> typename V> Polynomial<T>& Prod( V<Polynomial<T>>& f );

// ��������e��iO(De(log De)^2)�j
template <typename T> inline Polynomial<T> Power( const Polynomial<T>& f , const int& e );

