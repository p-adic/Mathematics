// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Inverse/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT ModularInverse( const INT& base , ll c )
{

  assert( base > 0 );
  ll a[2] = { 0 , 1 % base };
  INT b[2] = { base , INT( ( c %= base ) < 0 ? c += base : c ) };

  while( b[1] != 0 ){

    const INT q = b[0] / b[1];
    ( a[0] -= q * a[1] % base ) < 0 ? a[0] += base : a[0];
    b[0] -= q * b[1];
    swap( a[0] , a[1] );
    swap( b[0] , b[1] );

  }

  assert( b[0] == 1 && ( a[0] * c - 1 ) % base == 0 );
  return a[0];

}
