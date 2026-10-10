// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linf/a.hpp

#pragma once

// L∞ノルム（O(1)）
template <typename INT> inline INT Linfty( const INT& x , const INT& y );
template <typename INT, template <typename...> typename PAIR> inline INT Linfty( const PAIR<INT,INT>& v );

// L∞距離（O(1)）
template <typename INT> inline INT Linfty_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT , template <typename...> typename PAIR> inline INT Linfty_Distance( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 );
