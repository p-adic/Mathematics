// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Sign/a_Body.hpp"

template <typename INT> inline INT L1( const INT& x , const INT& y ) { return abs( x ) + abs( y ); }
template <typename INT> inline INT L1( const pair<INT,INT>& v ) { return L1( v.first , v.second ); }

template <typename INT> inline INT L1_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return L1( x0 - x1 , y0 - y1 ); }
template <typename INT> inline INT L1_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return L1( v0.first - v1.first , v0.second - v1.second ); }

template <typename INT> inline pair<INT,INT> L1_to_Linfty( const INT& x , const INT& y ) { return { x + y , x - y }; }
template <typename INT> inline pair<INT,INT> L1_to_Linfty( const pair<INT,INT>& v ) { return L1_to_Linfty( v.first , v.second ); }
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const INT& x , const INT& y ) { assert( ( x & 1 ) == ( y & 1 ) ); return { ( x + y ) >> 1 , ( x - y ) >> 1 }; }
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const pair<INT,INT>& v ) { return Linfty_to_L1( v.first , v.second ); }

template <typename INT> inline bool L1_LongestEdge( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon ) { return sign( L1_Distance( x0 , y0 , x1 , y1 ) - max( L1_Distance( x0 , y0 , z , w ) , L1_Distance( z , w , x1 , y1 ) ) , epsilon ) >= 0; }
template <typename INT> inline bool L1_LongestEdge( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const INT& epsilon ) { return L1_LongestEdge( v0.first , v0.second , v1.first , v1.second , v2.first , v2.second , epsilon ); }
