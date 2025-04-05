// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/a.hpp

#pragma once
#include "../a.hpp"

template <typename MONOID0 , typename MONOID1 , typename TYPE = pair<typename MONOID0::type,typename MONOID1::type>>
class DirectProductMonoid :
  virtual public VirtualMonoid<TYPE> ,
  public PointedSet<TYPE>
{

protected:
  MONOID0 m_M0;
  MONOID1 m_M1;
  TYPE m_one;

public:
  inline DirectProductMonoid( MONOID0 M0 , MONOID1 M1 );

  inline TYPE Product( TYPE t0 , const TYPE& t1 );
  inline const TYPE& Point();

};
