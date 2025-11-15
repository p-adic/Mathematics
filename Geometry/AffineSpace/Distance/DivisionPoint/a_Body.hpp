// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/DivisionPoint/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename PAIR , typename T> inline PAIR DivisionPoint( const PAIR& p , const PAIR& q , const T& l , const T& r ) { auto& [px,py] = p; auto& [qx,qy] = q; return { ( px * r + qx * l ) / ( l + r ) , ( py * r + qy * l ) / ( l + r ) }; }

