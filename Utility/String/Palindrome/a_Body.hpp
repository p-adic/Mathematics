// c:/Users/user/Documents/Programming/Utility/String/Palindrome/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../RollingHash/a_Body.hpp"

template <typename STR>
vector<bool> Palindrome( const STR& S , const bool& reversed )
{
  
  const int N = S.size();
  vector answer( N , true );
  RollingHash<MP,ll> rh{};
  auto code = rh.PointwiseEncode( S , reversed );
  auto left = code[0] , right = code[1];

  for( int r = 1 ; r < N ; r++ ){

    left = rh.Concatenate( move( left ) , code[r] );
    right = rh.Concatenate( code[r] , move( right ) );
    answer[reversed ? N - 1 - r : r] = left == right;

  }
  
  return answer;

}
