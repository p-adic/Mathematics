// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/RollingHashSum/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename VEC , typename CHAR , typename VALID , typename FUNC , typename T>
T SubsequenceRollingHashSum( const VEC& S , const CHAR& zero , const int& C , VALID valid , FUNC f , const T& base )
{

  vector<T> dp0( C ) , dp1( C );
  T sum0{} , sum1{};

  for( auto& c : S ){

    const int j = c - zero;
    assert( j < C );
    T temp0 = sum0 + ( valid( c ) ? 1 : 0 ) , temp1 = sum1 * base + temp0 * f( c );
    sum0 += temp0 - dp0[j];
    sum1 += temp1 - dp1[j];
    dp0[j] = move( temp0 );
    dp1[j] = move( temp1 );

  }

  return sum1;

}
