// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/RelativeDirection/a.hpp

#pragma once

// v0����v1�ւ̉������iv1 - v0�ł͂Ȃ��j�Ɠ����������̓_��Ԃ��B
template <typename INT> inline pair<INT,INT> RelativeDirection( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
// 0: ���_
// 1: {0}
// 2: (0,90)
// 3: {90}
// 4: (90,180)
// 5: {180}
// 6: (180,270)
// 7: {270}
// 8: (270,360)
template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v );
// v0����v1�ւ̉������iv1 - v0�ł͂Ȃ��j��Ԃ��B
template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
template <typename INT> inline bool RightAngle( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
template <typename INT> inline bool Parallel( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
