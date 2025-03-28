// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/abaSubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

abaCount abaSubsequenceCounterOperator::Product( abaCount v0 , const abaCount& v1 )
{

  auto& [v0a,v0b,v0ab,v0ba,v0aba] = v0;
  auto& [v1a,v1b,v1ab,v1ba,v1aba] = v1;
  v0aba += v1aba + v0a * v1ba + v0ab * v1a;
  v0ba += v1ba + ll( v0b ) * v1a;
  v0ab += v1ab + ll( v0a ) * v1b;
  v0a += v1a;
  v0b += v1b;
  return move( v0 );

}

inline abaSubsequenceCounter::abaSubsequenceCounter() : AbstractMonoid<abaCount,abaCount(*)(abaCount,const abaCount&)>( abaSubsequenceCounterOperator::Product , abaCount{} ) {}
