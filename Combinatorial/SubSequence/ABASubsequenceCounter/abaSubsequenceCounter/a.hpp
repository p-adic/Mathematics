// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/abaSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// abaCount = tuple<int,ll,ll,ll>‚Å
// {a‚ÌŒÂ”,b‚ÌŒÂ”,ab‚ÌŒÂ”,ba‚ÌŒÂ”,aba‚ÌŒÂ”‚Ì‘˜a}‚ğŠÇ—
class abaSubsequenceCounterOperator
{

public:
  // O(1)
  static abaCount Product( abaCount v0 , const abaCount& v1 );

};

// (1) s=="aba"
// ‚ğ–‚½‚·•”•ª•¶š—ñs‚ÌŒÂ”‚ğŠÇ—‚·‚éƒ‚ƒmƒCƒh
class abaSubsequenceCounter :
  public AbstractMonoid<abaCount,abaCount(*)(abaCount,const abaCount&)>
{

public:
  inline abaSubsequenceCounter();

};
