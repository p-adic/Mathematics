// c:/Users/user/Documents/Programming/Utility/BinarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline constexpr Mid( const INT& l , const INT& r ) { return l + ( ( r - l ) >> 1 ); }

