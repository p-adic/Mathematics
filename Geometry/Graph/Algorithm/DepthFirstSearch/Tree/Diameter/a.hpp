// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Diameter/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1121084

// 直径を与えるパスを表す頂点番号の列を返す。
// 端点は列の両端、中心は列の中央（高々2個）、直径は列の長さ-1で与えられる。
template <typename TREE> vector<int> Diameter( TREE& T );
