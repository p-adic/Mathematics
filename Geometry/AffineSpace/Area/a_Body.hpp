// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Area/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 ) { return ( x1 - x0 ) * ( y2 - y0 ) - ( y1 - y0 ) * ( x2 - x0 ); }
template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 ) { return Area<RET>( get<0>( v0 ) , get<1>( v0 ) , get<0>( v1 ) , get<1>( v1 ) , get<0>( v2 ) , get<1>( v2 ) ); }

inline double Area( const double& l0 , const double& l1 , const double& l2 ) { const double s = ( l0 + l1 + l2 ) / 2; return sqrt( s * ( s - l0 ) ) * sqrt( ( s - l1 ) * ( s - l2 ) ); }

template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const vector<PAIR<INT,INT>>& v ) { RET answer{}; const int& size = v.size(); assert( size > 2 ); for( int i = 2 ; i < size ; i++ ){ answer += Area<RET>( v[0] , v[i-1] , v[i] ); } return answer; }
