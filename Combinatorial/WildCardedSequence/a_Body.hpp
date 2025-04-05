// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/WildCardedSequence/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename INT0 , template <typename...> typename PAIR , typename INT1>
PAIR<U,INT0> WildCardedSequenceSum( const vector<PAIR<U,INT0>>& sum_count , const INT1& base )
{

  PAIR<U,INT0> answer{ 0 , 1 };
  auto& [sum,count] = answer;

  for( auto& [sum_i,count_i] : sum_count ){

    sum = ( sum * base ) * count_i + count * sum_i;
    count = count * count_i;

  }
  
  return answer;

}

