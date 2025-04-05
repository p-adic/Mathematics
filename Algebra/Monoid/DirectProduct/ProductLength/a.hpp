// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/ProductLength/a.hpp

#pragma once
#include "../a.hpp"

// �l�ƒ������Ǘ����郂�m�C�h�B
// ���a�Əꍇ�̐����Ǘ����郂�m�C�h�ł͂Ȃ����Ƃɒ��ӁB
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

