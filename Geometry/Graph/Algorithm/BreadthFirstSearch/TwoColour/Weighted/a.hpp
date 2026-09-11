// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/TwoColour/Weighted/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1185861

// 入力の範囲内で要件
// (1) Gは{true,false}重み付き無向グラフ（自己ループや多重辺なし）の有向化である。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。

// answer[i]
// O(V+E)で(辺の重み?同色:異色)を満たすGの{0,1}塗り分けを
// {{{連結成分0の0},{連結成分0の1}},{{連結成分1の0},{連結成分1の1}},...}
// の形式で出力する。存在しない場合は{}を返す。
template <typename GRAPH , typename T = inner_t<GRAPH>> vector<T2<vector<T>>> WeightedTwoColour( GRAPH& G , const T& not_found );
