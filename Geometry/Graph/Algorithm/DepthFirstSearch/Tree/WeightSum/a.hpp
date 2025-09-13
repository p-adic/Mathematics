// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/WeightSum/a.hpp

#pragma once

// 根付き木の{頂点数,根からの距離の総和,2点集合間の距離の総和（重複なし）}を木DPで求める。
template <typename TREE , typename PREV_WEIGHT , typename INT> Tuple<int,INT,INT> TreeWeightSum( const TREE& T , PREV_WEIGHT pw , const int& root = 0 );
template <typename TREE , typename INT> inline Tuple<int,INT,INT> TreeWeightSum( const TREE& T , const int& root = 0 );

