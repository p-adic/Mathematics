// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/Algebra/SquareSum/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Utility/Tuple/Wrap/a.hpp"

// 入力の範囲内で要件
// (1) RがUの非可換環構造を定める。
// を満たす場合にのみサポート。

// Uの要素からなる多重集合に対する(要素数,総和,二乗和の総和)を管理するU代数構造。
// 多重集合S,Tに対しS cup Tに相当する和と、S+Tに相当する積が定義される。

// VirtualAlgebraで抽象化すると加法群、乗法モノイドそれぞれクラスとして定義しないと
// いけないので抽象化しない。
template <typename RING , typename U = inner_t<RING>>
class SquareAlgebra
{

private:
  RING m_R;

public:
  inline SquareAlgebra( RING R );
  inline const T3<U>& Zero();
  inline const T3<U>& One();
  inline T3<U> Sum( T3<U> v0 , const T3<U>& v1 );
  inline T3<U> Product( T3<U> v0 , const T3<U>& v1 );
  inline T3<U> Action( const U& u , T3<U> v );

};
