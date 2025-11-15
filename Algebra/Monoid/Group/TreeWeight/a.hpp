// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/TreeWeight/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1133941 (LineWeight,Product)
// https://yukicoder.me/submissions/1133936 (Extend, LineExtend, Product)

// 根付き木の{頂点数,根からの距離の総和,2点集合間の距離の総和（重複なし）}を管理。
template <typename INT0 , typename INT1 , typename INT2 , typename U = Tuple<INT0,INT1,INT2>>
class TreeWeightGroup :
  virtual public VirtualGroup<U> ,
  public PointedSet<U>
{

public:
  inline TreeWeightGroup( const INT0& one0 , const INT1& zero1 , const INT2& zero2 );

  // 根の結合に対応する演算。
  inline U Product( U u0 , const U& u1 );
  inline U Transfer( const U& u );

  // 根の親（辺の重みw）を1つ追加する操作に対応する演算。
  inline U Extend( U u , const INT2& w = 1 );
  // 根の親（辺の重みw）を1つ追加する操作の逆に対応する演算。
  inline U Cut( U u , const INT2& w = 1 );

  // 頂点数Nの直線の答え{N,sum_{i=0}^{N-1} abs{i-root},sum_{i=1}^{N-1}i*(N-i)}
  // をO(1)で求める。
  template <typename INT> inline U LineWeight( const INT& N , const INT& root );
  // 木が個々の辺のデータでなく直線グラフの貼り合せデータで与えられる時に用いる。
  // 根を変更できないので、適宜直線を分割しつつどこが現在の根かを管理しながら端から順に処理する。

  // 根の親（辺の重みw）をN個追加する操作に対応する演算。
  template <typename INT> inline U LineExtend( U u , const INT2& w , const INT& N );

};
