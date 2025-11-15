// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Intersection/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Polytope/Area/a_Body.hpp"
#include "../../Distance/L1/a_Body.hpp"

template <typename INT> inline bool Online( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon ) { return sign( Area<ll>( x0 , y0 , x1 , y1 , z , w ) , epsilon ) == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z , w , epsilon ); }
template <typename INT , template <typename...> typename PAIR> inline bool Online( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const INT& epsilon ) { return Online( get<0>( v0 ) , get<1>( v0 ) , get<0>( v1 ) , get<1>( v1 ) , get<0>( v2 ) , get<1>( v2 ) , epsilon ); }

template <typename INT> inline int IntersectionType( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 , const INT& epsilon ) { const int sign00 = sign( Area<ll>( x0 , y0 , x1 , y1 , z0 , w0 ) , epsilon ) , sign01 = sign( Area<ll>( x0 , y0 , x1 , y1 , z1 , w1 ) , epsilon ) , sign10 = sign( Area<ll>( z0 , w0 , z1 , w1 , x0 , y0 ) , epsilon ) , sign11 = sign( Area<ll>( z0 , w0 , z1 , w1 , x1 , y1 ) , epsilon ); return sign00 * sign01 < 0 && sign10 * sign11 < 0 ? 1 : ( ( sign00 == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z0 , w0 , epsilon ) ) || ( sign01 == 0 && L1_LongestEdge( x0 , y0 , x1 , y1 , z1 , w1 , epsilon ) ) || ( sign10 == 0 && L1_LongestEdge( z0 , w0 , z1 , w1 , x0 , y0 , epsilon ) ) || ( sign11 == 0 && L1_LongestEdge( z0 , w0 , z1 , w1 , x1 , y1 , epsilon ) ) ) ? 0 : -1; }
template <typename INT , template <typename...> typename PAIR> inline int IntersectionType( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const PAIR<INT,INT>& v3 , const INT& epsilon ) { return IntersectionType( get<0>( v0 ) , get<1>( v0 ) , get<0>( v1 ) , get<1>( v1 ) , get<0>( v2 ) , get<1>( v2 ) , get<0>( v3 ) , get<1>( v3 ) , epsilon ); }
