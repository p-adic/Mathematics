// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/Interval/a.hpp

#pragma once
#include "../a.hpp"

template <typename ABEL_GROUP , typename R_SET , typename R = inner_t<ABEL_GROUP> , typename U = inner_t<R_SET>>
class AbstractIntervalRSet :
  public VirtualRSet<pair<R,R>,U> ,
  public R_SET
{

private:
  ABEL_GROUP m_L;

public:
  inline AbstractIntervalRSet( ABEL_GROUP L , R_SET M );

  inline U Action( const pair<R,R>& lr , U u );

};

template <typename R , typename U>
class IntervalModule :
  public AbstractIntervalRSet<AdditiveGroup<R>,Module<R,U>>
{

public:
  inline IntervalModule();
  
};
