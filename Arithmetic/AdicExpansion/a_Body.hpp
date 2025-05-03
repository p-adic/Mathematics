// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<int> AdicExpansion( INT n , const int& base )
{

  assert( n >= 0 );
  vector<int> answer{};

  while( n > 0 ){

    answer.push_back( n % base );
    n /= base;

  }

  Reverse( answer );
  return answer;

}
