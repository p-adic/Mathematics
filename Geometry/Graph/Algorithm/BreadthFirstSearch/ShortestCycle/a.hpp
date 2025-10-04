// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gは無向グラフ（自己ループや多重辺なし）の有向化である。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。
// O(V(V+E))で最小の閉路を頂点の列として出力する。
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestCycle( GRAPH& G , const inner_t<GRAPH>& not_found );
// 自己ループがあればそれが最小、なくて多重辺があればそれが最小。
