// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a.hpp

#pragma once
#include "a_Macro.hpp"

// �P�Ȃ�Q�悾���AT����ł̓I�[�o�[���[�h���Ă�荂���Ȃ��̂ɒu��������
template <typename T> inline T Square( const T& t );

// T(1)����@�I�P�ʌ��ł���ꍇ�̂݃T�|�[�g�B
// t ^ num
template <typename T , typename UINT>
T Power( T t , UINT exponent );

// init * ( t ^ num )
template <typename T , typename UINT>
T Power( T t , UINT exponent , T init );

