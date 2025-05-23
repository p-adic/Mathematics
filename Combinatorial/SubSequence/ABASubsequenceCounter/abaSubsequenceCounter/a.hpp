// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/abaSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// abaCount = tuple<int,ll,ll,ll>Å
// {aÌÂ,bÌÂ,abÌÂ,baÌÂ,abaÌÂÌa}ðÇ
class abaSubsequenceCounterOperator
{

public:
  // O(1)
  static abaCount Product( abaCount v0 , const abaCount& v1 );

};

// (1) s=="aba"
// ð½·ª¶ñsÌÂðÇ·émCh
class abaSubsequenceCounter :
  public AbstractMonoid<abaCount,abaCount(*)(abaCount,const abaCount&)>
{

public:
  inline abaSubsequenceCounter();

};
