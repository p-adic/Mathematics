// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/Triangle/Angle/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline T3<int> AccuteAngle2( const INT& l02 , const INT& l12 , const INT& l22 ) { return {l02<l12+l22?1:l02>l12+l22?-1:0,l12<l22+l02?1:l12>l22+l02?-1:0,l22<l02+l12?1:l22>l02+l12?-1:0}; }
inline T3<int> AccuteAngle( const double& l0 , const double& l1 , const double& l2 ) { return AccuteAngle2( l0 * l0 , l1 * l1 , l2 * l2 ); }
template <template <typename...> typename PAIR , typename INT> inline T3<int> AccuteAngle( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 ) { return AccuteAngle2( L22_Distance( v1 , v2 ) , L22_Distance( v2 , v0 ) , L22_Distance( v0 , v1 ) ); }

