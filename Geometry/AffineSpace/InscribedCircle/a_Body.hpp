// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/InscribedCircle/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Area/a_Body.hpp"
#include "../Distance/L2/a_Body.hpp"

inline double InscribedCircleRadius( const double& l0 , const double& l1 , const double& l2 ) { return Area( l0 , l1 , l2 ) * 2 / ( l0 + l1 + l2 ); }
template <typename INT , template <typename...> typename PAIR> inline double InscribedCircleRadius( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 ) { return InscribedCircleRadius( L2_Distance( v0 , v1 ) , L2_Distance( v1 , v2 ) , L2_Distance( v2 , v0 ) ); }

