// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/ProductLength/a.hpp

#pragma once
#include "../a.hpp"

// 値と長さを管理するモノイド。
// 総和と場合の数を管理するモノイドではないことに注意。
template <typename MONOID , typename INT = int , typename TYPE = typename DirectProductMonoid<MONOID,INT>::type>
class AbstractProductLengthMonoid :
  public DirectProductMonoid<MONOID,AdditiveMonoid<INT>>
{

public:
  inline AbstractProductLengthMonoid( MONOID M );
  static TYPE ProductLength( typename MONOID::type t );
  static inline TYPE SumLength( typename MONOID::type t );
  
};

template <typename U , typename INT = int>
class ProductLengthMonoid :
  public AbstractProductLengthMonoid<MultiplicativeMonoid<U>INT>
{

public:
  inline ProductLengthMonoid( U e_U );
  
};

#include "a_Alias.hpp"

