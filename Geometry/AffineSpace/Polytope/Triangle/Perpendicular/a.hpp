// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/Triangle/Perpendicular/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1184874 (PerpendicularPartition)

#include "../../../../../Tuple/Wrap/a.hpp"

// ３辺の長さがl0,l1,l2の三角形の、各辺を底辺とする高さを返す。
// ヘロンの公式で求めるため精度が低いことに注意。
inline T3<double> PerpendicularLength( const double& l0 , const double& l1 , const double& l2 );
// ３頂点の座標がv0,v1,v2の三角形の、各頂点を除いた辺を底辺とする高さを返す。
template <typename PAIR> inline T3<double> PerpendicularLength( const PAIR& v0 , const PAIR& v1 , const PAIR& v2 );

// ３辺の長さが反時計回りにl0,l1,l2である三角形の、各辺が対角からの垂線で分割される左側の
// 符号付き長さを返す。
inline T3<double> PerpendicularPartition( const double& l0 , const double& l1 , const double& l2 );
// ３頂点の座標が反時計回りにv0,v1,v2である三角形の、各頂点の右の辺が対角からの垂線で分割される
// 左側の符号付き長さを返す。
template <typename PAIR> inline T3<double> PerpendicularPartition( const PAIR& v0 , const PAIR& v1 , const PAIR& v2 );
