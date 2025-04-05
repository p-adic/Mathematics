// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/DirectProduct/a.hpp

#pragma once
#include "../a.hpp"
#include "../../DirectProduct/a.hpp"

template <typename GROUP0 , typename GROUP1 , typename TYPE = pair<typename GROUP0::type,typename GROUP1::type>>
class DirectProductGroup :
  virtual public VirtualGroup<TYPE> ,
  public DirectProductMonoid<GROUP0,GROUP1>
{

public:
  inline DirectProductGroup( GROUP0 G0 , GROUP1 G1 );

  inline TYPE Transfer( const TYPE& t );

};
