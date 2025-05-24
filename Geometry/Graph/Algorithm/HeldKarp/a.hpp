// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HeldKarp/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/typical-algorithm/submissions/59801372
// https://yukicoder.me/submissions/1088213

#include "../../a.hpp"
#include "../../../../Algebra/Monoid/a.hpp"

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序モノイド構造である。
// (1) E_Gの値の各成分の第2成分がM.One()以上である。
// (2) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 経由点の個数をFと置く。
// 単一始点多経由点全終点最短経路探索O((|V_G| + |E_G|)2^F)
template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
class AbstractHeldKarp :
  public PointedSet<U>
{
private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  COMM_MONOID m_M;

public:
  inline AbstractHeldKarp( GRAPH& G , COMM_MONOID M , const U& infty );
  // revisitable?経由点を再訪できる:できないとして、
  // 経由した点の種類が[factor_count_min,factor_count_max]の範囲に収まる経路内で
  // 最短経路長を求める。
  inline U GetDistance( const T& t_start , const vector<T>& t_factor , const T& t_final , const bool& revisitable , int factor_count_min = -1 , int factor_count_max = -1 );
  vector<U> GetDistance( const T& t_start , const vector<T>& t_factor , const bool& revisitable , int factor_count_min = -1 , int factor_count_max = -1 );

};
template <typename GRAPH , typename U , typename COMM_MONOID> AbstractHeldKarp( GRAPH& G , COMM_MONOID M , const U& infty ) -> AbstractHeldKarp<inner_t<GRAPH>,GRAPH,U,COMM_MONOID>;

template <typename T , typename GRAPH>
class HeldKarp :
  public AbstractHeldKarp<T,GRAPH,ll,AdditiveMonoid<ll>>
{

public:
  inline HeldKarp( GRAPH& G , const ll& infty = 1e18 );

};
template <typename GRAPH , typename...ARGS> HeldKarp( GRAPH& G , const ARGS&... args ) -> HeldKarp<inner_t<GRAPH>,GRAPH>;

// - 頂点0を始点として、頂点0以外の各頂点を一度ずつしか訪問できない場合はrevistable = falseとして
//   vector<int> factor( N - 1 ); FOR( i , 1 , N ){ factor[i-1] = i; }
// - 各頂点を一度ずつしか訪問できない場合はrevistable = falseとして
//   vector<int> factor( N - 1 ); FOR( i , 0 , N ){ factor[i] = i; }
// とする。
