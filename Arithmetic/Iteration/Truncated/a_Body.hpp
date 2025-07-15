// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Truncated/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2>
ll TruncatedPower( ll n , INT1 e , const INT2& bound )
{

  assert( n >= 0 && e >= 0 && bound >= 0 );

  if( e == 0 ){

    return 1;

  }

  if( n <= 1 ){

    return move( n );

  }

  if( e >= 63 ){

    return bound + 1;

  }

  ll answer = ( e & 1 ) == 0 ? 1 : n;
  e >>= 1;

  while( e > 0 ){

    if( n <= bound / n ){

      n *= n;

    } else {

      return bound + 1;

    }

    if( ( e & 1 ) == 1 ){

      if( answer <= bound / n ){

        answer *= n;

      } else {

        return bound + 1;

      }

    }

    e >>= 1;

  }

  return answer;

}

template <typename INT1 , typename INT2>
INT2 RoundDownRoot( const INT1& e , const INT2& n )
{

  assert( e >= 1 && n >= 0 );

  if( n == 0 || e == 1 ){

    return n;

  }

  int l = 1 , r = n;

  while( l < r - 1 ){

    int m = ( l + r ) >> 1;
    ( TruncatedPower( m , e , n ) <= n ? l : r ) = m;

  }

  return l;

}

