// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/Kruscal/MaximumDirectedForest/a.hpp

#pragma once
#include "../../../../../../Utility/Tuple/Wrap/a.hpp"

// GRAPHは無向グラフG=(V_G,E_G)に相当する型。
// MはUの可換群構造。

// 入力の範囲内で要件
// (1) UはMとbool operator<(const U&,const U&)に関して全順序可換群である。
// (2) Aは長さ|V_G|のU値配列である。
// を満たす場合にのみサポート。

// O(|E_G|α(|V_G| + log_2 |E_G|))でGの有向化の部分有向森F全体において
// Fの各有向辺eの始点番号u(e)に対するA[u(e)]のMに関する総和の最大値を考え、そのようなFの
// {選択した有向辺の配列,各頂点の根の配列,総和の最大値}を返す。

// https://yukicoder.me/problems/no/3781/editorial
// をもとに実装。
template <typename GRAPH , typename U , typename ABEL_GROUP , typename T = inner_t<GRAPH>> Tuple<vector<T2<T>>,vector<T>,U> AbstractMaximumDirectedSubforest( ABEL_GROUP M , GRAPH& G , const vector<U>& A );
template <typename GRAPH , typename U , typename T = inner_t<GRAPH>> inline Tuple<vector<T2<T>>,vector<T>,U> MaximumDirectedSubforest( GRAPH& G , const vector<U>& A );
