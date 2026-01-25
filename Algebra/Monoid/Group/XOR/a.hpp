// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/XOR/a.hpp

#pragma once
#include "../a.hpp"

template <typename U>
class XORGroup :
  virtual public VirtualGroup<U> ,
  public PointedSet<U>
{

public:
  inline XORGroup{ U zero };
  inline U Product( U u0 , const U& u1 );
  inline U Transfer( const U& u );
};

