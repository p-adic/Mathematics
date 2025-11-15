// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Sign/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline int sign( const INT& n , const INT& epsilon ) { constexpr bool is_not_double = !is_same_v<INT,double>; assert( is_not_double || epsilon > 0 ); return n < -epsilon ? -1 : epsilon < n ? 1 : 0; }
