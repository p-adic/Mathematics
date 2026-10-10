// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linf/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT Linfty( const INT& x , const INT& y ) { return max( abs( x ) , abs( y ) ); }
template <typename INT, template <typename...> typename PAIR> inline INT Linfty( const PAIR<INT,INT>& v ) { return Linfty( get<0>( v ) , get<1>( v ) ); }

template <typename INT> inline INT Linfty_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return Linfty( x0 - x1 , y0 - y1 ); }
template <typename INT, template <typename...> typename PAIR> inline INT Linfty_Distance( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 ) { return Linfty( get<0>( v0 ) - get<0>( v1 ) , get<1>( v0 ) - get<1>( v1 ) ); }
