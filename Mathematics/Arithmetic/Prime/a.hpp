// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"


// 1+i�Ԗڂ̑f����Ԃ�
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<N�̎���1+i�Ԗڂ̑f����Ԃ�
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );
