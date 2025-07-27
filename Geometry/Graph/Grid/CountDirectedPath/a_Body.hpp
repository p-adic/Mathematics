// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/CountDirectedPath/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename MODINT> inline MODINT CountDirectedGridPath( const int& H , const int& W ) { return MODINT::Combination( H + W - 2 , H - 1 ); }

template <typename INT , typename COND>
INT CountDirectedGridPath( const int& H , const int& W , COND cond )
{

  static_assert( is_invocable_r_v<bool,COND,int,int> );
  assert( H >= 1 && W >= 1 );
  vector<INT> dp( H );
  dp[0] = 1;
  const INT zero = INT{ 0 };

  for( int w = 0 ; w < W ; w++ ){

    for( int h = 0 ; h < H ; h++ ){

      cond( h , w ) ? h > 0 ? dp[h] += dp[h-1] : dp[h] : dp[h] = zero;

    }

  }

  return dp[H-1];

}
