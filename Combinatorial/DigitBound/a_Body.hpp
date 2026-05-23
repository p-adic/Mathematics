// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/DigitBound/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT MaxDigitBoundedNumber( INT n_max , const int& B , const int& d )
{

  assert( n_max >= 0 && B > 1 && d >= 0 );
  INT power = 1;
  const INT div = n_max / B ;

  while( power <= div ){

    power *= B;

  }

  INT a = 0;

  while( power > 0 ){

    INT c = n_max / power;

    if( c <= d ){

      c *= power;
      a += c;
      n_max -= c;
      power /= B;

    } else {

      a += d * ( power + ( power - 1 ) / ( B - 1 ) );
      power = 0;

    }

  }

  return a;

}

template <typename INT>
INT CountDigitBoundedNumber( INT n_max , const int& B , int d )
{

  n_max = MaxDigitBoundedNumber( move( n_max ) , B , d++ );
  INT a = 1 , power = 1;

  while( true ){

    a += ( n_max % B ) * power;
    n_max /= B;

    if( n_max > 0 ){

      power *= d;

    } else {

      break;
      
    }

  }

  return a;

}
