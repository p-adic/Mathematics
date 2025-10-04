// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/Odd/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1124648

// 入力の範囲内で要件
// (1) Gは無向グラフ（自己ループや多重辺なし）の有向化である。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。
// O(V+E)でt_startを通る最小の奇閉路を頂点の列として出力する。
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found , const inner_t<GRAPH>& t_start );

// O(V(V+E))で最小の奇閉路を頂点の列として出力する。
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found );
// 自己ループがあればそれが最小、なくて多重辺があっても奇閉路に影響しないので削除してよい。

