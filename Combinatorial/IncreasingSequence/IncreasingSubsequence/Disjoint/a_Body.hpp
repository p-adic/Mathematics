// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/IncreasingSubsequence/Disjoint/a_Body.hpp

#pragma once
#include "a.hpp"

#include "a_Body.hpp"
#include "../../../YoungDiagram/RobinsonSchensted/a_Body.hpp"

template <typename T>
int LongestDisjointNonStrictlyIncreasingSubsequence( const vector<T>& a , int K )
{

  auto [P0,P1] = RobinsonSchenstedKnuth( a , move( K ) );
  int answer = 0;

  for( auto& v : P0 ){

    answer += v.size();

  }

  return answer;

}
