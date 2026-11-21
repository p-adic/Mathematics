// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Branched/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1167914

#include "../../../a.hpp"

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序可換半群構造である。
// (1) E_Gの値の各成分の第2成分がM.One()以上である。
// が成り立つ場合にのみサポート。

// 架空の始点からいくつかの頂点へ重みつき色つきの有向辺を貼った時に
// 各点への最短経路長を色ごとに、上位length個まで計算する。
// O(length(|V_G|+|E_G| log length |E_G|))
template <typename GRAPH , typename U , typename COMM_SEMIGRP , typename T = inner_t<GRAPH>>
class AbstractBranchedDijkstra
{

private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  COMM_SEMIGRP m_M;

public:
  inline AbstractBranchedDijkstra( GRAPH& G , COMM_SEMIGRP M );

  // TUPLEはtupleなど。Sはoperator<()が全順序である型。
  // 各点への最短径路長を始辺の色ごとに上位length個まで求める。
  template <template <typename...> typename TUPLE , typename S> vector<vector<Pair<U,S>>> GetDistance( const vector<TUPLE<T,U,S>>& t_start , const int& length );
  // S=bool、length=0で通常のダイクストラ法の代替も可能。

};

template <typename GRAPH , typename T = inner_t<GRAPH>>
class BranchedDijkstra :
  public AbstractBranchedDijkstra<GRAPH,ll,AdditiveMonoid<>,T>
{

public:
  inline BranchedDijkstra( GRAPH& G );

};
