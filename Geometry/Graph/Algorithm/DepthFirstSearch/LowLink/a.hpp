// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/LowLink/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1151050 (IsBridge)

#include "../a.hpp"

// GRAPHは辺Edge:N->(N \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) Gは（自己ループと多重辺を持たない）無向グラフである。
// を満たす場合にのみサポート。

// 構築O(V+E)
// 橋判定O(1)
// 関節点判定O(1)
template <typename GRAPH>
class LowLink :
  public DepthFirstSearch<int,GRAPH>
{

private:
  // startの連結成分のサイズ。
  int m_csize;
  // m_ord[t]にtがDFS順で何番目かを格納する。
  vector<int> m_ord;
  // DFS順に頂点を格納する。
  vector<int> m_ord_inv;
  // DFS木に１本だけ辺を加えて得られるループであってtを含むものが存在する時、
  // そのようなループ全体におけるm_ordの最小値をm_link[t]に格納する。
  // 存在しない時、m_ord[t]をm_link[t]に格納する。
  vector<int> m_link;
  // DFS木の子のm_linkの最大値を格納する。
  vector<int> m_child_link;

public:
  // Argはintかlist<int>
  template <typename Arg> inline LowLink( GRAPH& G , Arg starts );

  inline const int& csize() const noexcept;
  inline const int& Ord( const int& t ) const;
  inline const int& Ord_inv( const int& i ) const;
  inline const int& Link( const int& t ) const;

  // 0<=t,u<G.size()である場合に
  // 「tがstartsの連結成分に属しかつ無向辺t->uが存在しかつそれが橋である」の真偽を返す。
  inline bool IsBridge( int t , int u );
  // 0<=t<G.size()である場合に
  // 「tがstartsの連結成分に属しかつtが関節点である」の真偽を返す。
  inline bool IsJoint( const int& t );

};
