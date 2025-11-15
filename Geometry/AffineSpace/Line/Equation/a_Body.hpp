// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Equation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename T , template <typename...> typename PAIR> inline T3<T> LineEquation( const PAIR<T,T>& p , const PAIR<T,T>& q ) { auto& [px,py] = p; auto& [qx,qy] = q; return { py - qy , qx - px , px * qy - qx * py }; }
