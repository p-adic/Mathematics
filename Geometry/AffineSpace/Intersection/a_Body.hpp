// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Intersection/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Area/a_Body.hpp"
#include "../Distance/L1/a_Body.hpp"

template <typename INT> inline bool Online( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon ) { return sign( Area( x0 , y0 , x1 , y1 , z , w ) , epsilon ) == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z , w , epsilon ); }
template <typename INT> inline bool Online( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const INT& epsilon ) { return Online( v0.first , v0.second , v1.first , v1.second , v2.first , v2.second , epsilon ); }

template <typename INT> inline int IntersectionType( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 , const INT& epsilon ) { const int sign00 = sign( Area( x0 , y0 , x1 , y1 , z0 , w0 ) , epsilon ) , sign01 = sign( Area( x0 , y0 , x1 , y1 , z1 , w1 ) , epsilon ) , sign10 = sign( Area( z0 , w0 , z1 , w1 , x0 , y0 ) , epsilon ) , sign11 = sign( Area( z0 , w0 , z1 , w1 , x1 , y1 ) , epsilon ); return sign00 * sign01 < 0 && sign10 * sign11 < 0 ? 1 : ( ( sign00 == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z0 , w0 , epsilon ) ) || ( sign01 == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z1 , w1 , epsilon ) ) || ( sign10 == 0 && L1_LongestEdge( z0 , w0 , z1 , w1 , x0 , y0 , epsilon ) ) || ( sign11 == 0 && L1_LongestEdge( z0 , w0 , z1 , w1 , x1 , y1 , epsilon ) ) ) ? 0 : -1; }
template <typename INT> inline int IntersectionType( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const pair<INT,INT>& v3 , const INT& epsilon ) { return IntersectionType( v0.first , v0.second , v1.first , v1.second , v2.first , v2.second , v3.first , v3.second , epsilon ); }
