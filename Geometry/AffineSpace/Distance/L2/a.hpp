// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L2/a.hpp

#pragma once


// L2ノルム2乗（O(1)）
template <typename INT> inline INT L22( const INT& x , const INT& y );
template <typename INT> inline INT L22( const pair<INT,INT>& v );

// L2距離2乗（O(1)）
template <typename INT> inline INT L22_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT L22_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// L2ノルム（O(1)）
template <typename INT> inline double L2( const INT& x , const INT& y );
template <typename INT> inline double L2( const pair<INT,INT>& v );

// L2距離（O(1)）
template <typename INT> inline double L2_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline double L2_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// 三角形の辺のL2距離に関する最長性判定
template <typename INT> inline bool L2_LongestEdge( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon = 0 );
template <typename INT> inline bool L2_LongestEdge( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const INT& epsilon = 0 );
