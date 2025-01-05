// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/Constexpr/Log/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline constexpr INT Log( INT N ) { INT answer = 0; while( N > 1 ){ N >>= 1; answer++; } return answer; }
