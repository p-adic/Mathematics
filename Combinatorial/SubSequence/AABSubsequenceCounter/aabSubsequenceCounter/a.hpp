// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/aabSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// aabCount = tuple<int,ll,ll,ll>Å
// {aÌÂ,bÌÂ,abÌÂ,baÌÂ,aabÌÂÌa}ðÇ
class aabSubsequenceCounterOperator
{

public:
  // O(1)
  static aabCount Product( aabCount v0 , const aabCount& v1 );

};

// (1) s=="aab"
// ð½·ª¶ñsÌÂðÇ·émCh
class aabSubsequenceCounter :
  public AbstractMonoid<aabCount,aabCount(*)(aabCount,const aabCount&)>
{

public:
  inline aabSubsequenceCounter();

};
