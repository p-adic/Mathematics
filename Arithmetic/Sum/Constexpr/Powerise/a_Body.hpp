// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/Constexpr/Powerise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline constexpr INT Powerise( const INT& N ) { INT answer = 1; while( answer < N ){ answer <<= 1; } return answer; }
