// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/ShortestPath/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gはトポロジカルソートされた有向グラフ({0,...,V-1},{0,...,V-1}->({0,...,V-1}×...)^{<ω})
// (2) Mは全順序モノイド
// (3) weightは頂点対の重みを返す写像{0,...,V-1}^2->M
// を満たす場合にのみサポート。O(V+E)でstartからの最短経路長と最短経路におけるprevを返す。
template <typename TOPOLOGICAL_SORTED_ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename U = inner_t<MONOID>> vector<pair<U,int>> TopologicalSortedShortestPath( TOPOLOGICAL_SORTED_ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const int& start );

// 入力の範囲内で要件
// (1) Gは非輪状有向グラフ
// (2) Mは全順序モノイド
// (3) weightは頂点対の重みを返す写像
// を満たす場合にのみサポート。O(V+E)でstartからの最短経路長と最短経路におけるprevを返す。
template <typename ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename T = inner_t<ACYCLIC_GRAPH>, typename U = inner_t<MONOID>> vector<pair<U,T>> AcyclicGraphShortestPath( ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const T& start , const T& external_point );
