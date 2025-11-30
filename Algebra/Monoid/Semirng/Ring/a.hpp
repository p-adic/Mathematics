// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946132（Ring）
// https://yukicoder.me/submissions/946198（AbstractRing）

template <typename GROUP , typename MONOID , typename U = inner_t<GROUP>>
class VirtualRing :
  virtual public VirtualSemirng<GROUP,MONOID>
{

public:
virtual U Inverse( const U& u ) = 0;
virtual const U& One() const noexcept = 0;
inline GROUP& AdditiveGroup() noexcept;
inline MONOID& MultiplicativeMonoid() noexcept;

};

template <typename GROUP , typename MONOID , typename U = inner_t<GROUP>>
class AbstractRing :
  virtual public VirtualRing<GROUP,MONOID> ,
  public AbstractSemirng<GROUP,MONOID>
{

public:
inline AbstractRing( GROUP R0 , MONOID R1 );
inline U Inverse( const U& u );
inline const U& One() const noexcept;

};

template <typename U = ll>
class Ring :
  // コンストラクタが非自明なので仮想継承にしない。
  public AbstractRing<AdditiveGroup<U>,MultiplicativeMonoid<U>>
{

public:
inline Ring( U one_U );

};
