// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linf/a.hpp

#pragma once

// L���m�����iO(1)�j
template <typename INT> inline INT Linfty( const INT& x , const INT& y );
template <typename INT> inline INT Linfty( const pair<INT,INT>& v );

// L�������iO(1)�j
template <typename INT> inline INT Linfty_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT Linfty_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
