// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename VEC , typename CHAR , typename VALID>
T SubsequenceDP( const VEC& S , const CHAR& zero , const int& C , VALID valid )
{

  vector<T> dp( C );
  T sum = 0;

  for( auto& c : S ){

    const int j = c - zero;
    assert( j < C );
    T temp = sum + ( valid( c ) ? 1 : 0 );
    sum += temp - dp[j];
    dp[j] = move( temp );

  }

  return sum;

}

