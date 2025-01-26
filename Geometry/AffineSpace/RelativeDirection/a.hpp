// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/RelativeDirection/a.hpp

#pragma once

// v0からv1への回る方向（v1 - v0ではない）と等しい方向の点を返す。
template <typename INT> inline pair<INT,INT> RelativeDirection( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
// 0: 原点
// 1: {0}
// 2: (0,90)
// 3: {90}
// 4: (90,180)
// 5: {180}
// 6: (180,270)
// 7: {270}
// 8: (270,360)
template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v );
// v0からv1への回る方向（v1 - v0ではない）を返す。
template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
template <typename INT> inline bool RightAngle( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
template <typename INT> inline bool Parallel( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
