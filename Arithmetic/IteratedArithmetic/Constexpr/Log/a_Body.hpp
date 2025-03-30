// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/Constexpr/Log/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline constexpr INT Log( INT N ) { INT answer = 0 , power = 1; while( N > power ){ power <<= 1; answer++; } return answer; }
