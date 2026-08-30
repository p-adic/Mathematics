// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/LongestWalk/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972197 (始点／終点指定なし)
// https://yukicoder.me/submissions/1139133 (始点／終点指定あり)

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times U)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) Mがoperator<(const U&,const U&)に関してUの順序モノイド構造である。
// (3) externalは経路長に現れない。
// を満たす場合にのみサポート。

// t_startsのいずれかの頂点を始点としt_finalsのいずれかの頂点を終点とするGの最長歩道を
// O(|V_G|+|E_G|)で計算する。存在しない場合は{external,{}}を返す。
template <typename ACYCLIC_GRAPH , typename MONOID , typename T = inner_t<ACYCLIC_GRAPH> , typename U = inner_t<MONOID>> pair<U,vector<T>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M , const vector<T>& t_starts , const vector<T>& t_finals , U external );

// Gの最長歩道をO(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH , typename MONOID , typename U , typename T = inner_t<ACYCLIC_GRAPH>> inline pair<U,vector<T>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M , U external );
// Gが有向木の場合はDepthFirstSearchOnTree::Depthの最大値で良い。
