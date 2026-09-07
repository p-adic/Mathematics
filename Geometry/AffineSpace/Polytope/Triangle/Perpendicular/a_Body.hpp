// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/Triangle/Perpendicular/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Tuple/Wrap/a_Body.hpp"

#include "../Area/a_Body.hpp"
#include "../../../Distance/L2/a_Body.hpp"

inline T3<double> PerpendicularLength( const double& l0 , const double& l1 , const double& l2 ) { const double S = Area( l0 , l1 , l2 ) * 2; return {S/l0,S/l1,S/l2}; }
template <typename PAIR> inline T3<double> PerpendicularLength( const PAIR& v0 , const PAIR& v1 , const PAIR& v2 ) { return PerpendicularLength( L2_Distance( v1 , v2 ) , L2_Distance( v2 , v0 ) , L2_Distance( v0 , v1 ) ); }

inline T3<double> PerpendicularPartition( const double& l0 , const double& l1 , const double& l2 )
{
  // l2^2 - a0^2 = l1^2 - (l0 - a0)^2
  // <=> 2l0a0 - l0^2 + l1^2 - l2^2 = 0
  // <=> a0 = ( l0^2 - l1^2 + l2^2 ) / 2l0
  return { ( l0 * l0 - l1 * l1 + l2 * l2 ) / ( 2 * l0 ) , ( l1 * l1 - l2 * l2 + l0 * l0 ) / ( 2 * l1 ) , ( l2 * l2 - l0 * l0 + l1 * l1 ) / ( 2 * l2 ) };

}

template <typename PAIR> inline T3<double> PerpendicularPartition( const PAIR& v0 , const PAIR& v1 , const PAIR& v2 ) { return PerpendicularPartition( L2_Distance( v0 , v1 ) , L2_Distance( v1 , v2 ) , L2_Distance( v2 , v0 ) ); }
