// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Centre/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename INT> inline T2<INT> Centre( const INT& N ) { return {(N-1)/2,N/2}; }

