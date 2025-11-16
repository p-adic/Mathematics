// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Diameter/LongestPath/a.hpp

#pragma once

// 各点を根として、(distinct_branch?各子ノードの部分木の深さ+1:各葉の深さ)を
// 大きい順にK個格納する。(O(NK))
template <typename DFST> inline vector<vector<int>> LongestPath( DFST& dfst , const int& K , const bool& distinct_branch );
