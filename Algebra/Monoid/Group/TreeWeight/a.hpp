// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/TreeWeight/a.hpp

#pragma once
#include "../a.hpp"

// 根付き木の{頂点数,根からの距離の総和,2点集合間の距離の総和（重複なし）}を管理。
template <typename INT0 , typename INT1 , typename INT2 , typename U = Tuple<INT0,INT1,INT2>>
class TreeWeightGroup :
  virtual public VirtualGroup<U> ,
  public PointedSet<U>
{

  public:
    inline TreeWeightGroup( const INT0& zero0 , const INT1& one1 , const INT2& zero2 );

    // 根の結合に対応する演算。
    inline U Product( U u0 , const U& u1 );
    inline U Transfer( const U& u );

    // 根の親（辺の重みw）を追加する操作に対応する演算。
    inline U Extend( U u , const INT2& w = 1 );
    // 根の親（辺の重みw）を追加する操作の逆に対応する演算。
    inline U Cut( U u , const INT2& w = 1 );

};
