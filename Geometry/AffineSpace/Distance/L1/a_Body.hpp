// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Sign/a_Body.hpp"

template <typename INT> inline INT L1( const INT& x , const INT& y ) { return abs( x ) + abs( y ); }
template <typename INT , template <typename...> typename PAIR> inline INT L1( const PAIR<INT,INT>& v ) { return L1( get<0>( v ) , get<1>( v ) ); }

template <typename INT> inline INT L1_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return L1( x0 - x1 , y0 - y1 ); }
template <typename INT , template <typename...> typename PAIR> inline INT L1_Distance( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 ) { return L1( get<0>( v0 ) - get<0>( v1 ) , get<1>( v0 ) - get<1>( v1 ) ); }

template <typename INT , template <typename...> typename PAIR> inline PAIR<INT,INT> L1_to_Linfty( const INT& x , const INT& y ) { return { x + y , x - y }; }
template <typename INT , template <typename...> typename PAIR> inline PAIR<INT,INT> L1_to_Linfty( const PAIR<INT,INT>& v ) { return L1_to_Linfty( get<0>( v ) , get<1>( v ) ); }
template <typename INT , template <typename...> typename PAIR> inline PAIR<INT,INT> Linfty_to_L1( const INT& x , const INT& y ) { assert( ( x & 1 ) == ( y & 1 ) ); return { ( x + y ) >> 1 , ( x - y ) >> 1 }; }
template <typename INT , template <typename...> typename PAIR> inline PAIR<INT,INT> Linfty_to_L1( const PAIR<INT,INT>& v ) { return Linfty_to_L1( get<0>( v ) , get<1>( v ) ); }

template <typename INT> inline bool L1_LongestEdge( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon ) { return sign( L1_Distance( x0 , y0 , x1 , y1 ) - max( L1_Distance( x0 , y0 , z , w ) , L1_Distance( z , w , x1 , y1 ) ) , epsilon ) >= 0; }
template <typename INT , template <typename...> typename PAIR> inline bool L1_LongestEdge( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const INT& epsilon ) { return L1_LongestEdge( get<0>( v0 ) , get<1>( v0 ) , get<0>( v1 ) , get<1>( v1 ) , get<0>( v2 ) , get<1>( v2 ) , epsilon ); }
