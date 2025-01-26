// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L2/a.hpp

#pragma once


// L2�m����2��iO(1)�j
template <typename INT> inline INT L22( const INT& x , const INT& y );
template <typename INT> inline INT L22( const pair<INT,INT>& v );

// L2����2��iO(1)�j
template <typename INT> inline INT L22_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT L22_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// L2�m�����iO(1)�j
template <typename INT> inline double L2( const INT& x , const INT& y );
template <typename INT> inline double L2( const pair<INT,INT>& v );

// L2�����iO(1)�j
template <typename INT> inline double L2_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline double L2_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// �O�p�`�̕ӂ�L2�����Ɋւ���Œ�������
template <typename INT> inline bool L2_LongestEdge( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon = 0 );
template <typename INT> inline bool L2_LongestEdge( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const INT& epsilon = 0 );
