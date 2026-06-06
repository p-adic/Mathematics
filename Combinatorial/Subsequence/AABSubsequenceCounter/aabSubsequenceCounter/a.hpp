// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/AABSubsequenceCounter/aabSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// aabCount = tuple<int,ll,ll,ll>‚Å
// {a‚ÌŒÂ”,b‚ÌŒÂ”,ab‚ÌŒÂ”,ba‚ÌŒÂ”,aab‚ÌŒÂ”‚Ì‘˜a}‚ğŠÇ—
class aabSubsequenceCounterOperator
{

public:
  // O(1)
  static aabCount Product( aabCount v0 , const aabCount& v1 );

};

// (1) s=="aab"
// ‚ğ–‚½‚·•”•ª•¶š—ñs‚ÌŒÂ”‚ğŠÇ—‚·‚éƒ‚ƒmƒCƒh
class aabSubsequenceCounter :
  public AbstractMonoid<aabCount,aabCount(*)(aabCount,const aabCount&)>
{

public:
  inline aabSubsequenceCounter();

};
