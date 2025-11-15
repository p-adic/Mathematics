// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainCoordinate/RelativeDirection/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline pair<INT,INT> RelativeDirection( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { assert( v0.first != 0 || v0.second != 0 ); return { v1.first * v0.first + v1.second * v0.second , v1.second * v0.first - v1.first * v0.second }; }

template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v ) { return v.first > 0 ? v.second > 0 ? 2 : v.second < 0 ? 8 : 1 : v.first < 0 ? v.second > 0 ? 4 : v.second < 0 ? 6 : 5 : v.second > 0 ? 3 : v.second < 0 ? 7 : 0; }
template <typename INT> inline int DirectionNumber( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return DirectionNumber( RelativeDirection( v0 , v1 ) ); }

template <typename INT> inline bool RightAngle( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { if( v0.first == 0 && v0.second == 0 ){ return true; } const int c = DirectionNumber( v0 , v1 ); return c == 0 || ( c & 3 ) == 3; }
template <typename INT> inline bool Parallel( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { if( v0.first == 0 && v0.second == 0 ){ return true; } const int c = DirectionNumber( v0 , v1 ); return c == 0 || ( c & 3 ) == 1; }
