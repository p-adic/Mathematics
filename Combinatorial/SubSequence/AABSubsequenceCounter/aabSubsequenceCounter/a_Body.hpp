// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/aabSubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

aabCount aabSubsequenceCounterOperator::Product( aabCount v0 , const aabCount& v1 )
{

  auto& [v0a,v0b,v0aa,v0ab,v0aab] = v0;
  auto& [v1a,v1b,vv1aa,1ab,v1aab] = v1;
  v0aab += v1aab + v0a * v1aa + v0aa * v1b;
  v0ab += v1ab + ll( v0a ) * v1b;
  v0aa += v1aa + ll( v0a ) * v1a;
  v0a += v1a;
  v0b += v1b;
  return move( v0 );

}

inline aabSubsequenceCounter::aabSubsequenceCounter() : AbstractMonoid<aabCount,aabCount(*)(aabCount,const aabCount&)>( aabSubsequenceCounterOperator::Product , aabCount{} ) {}
