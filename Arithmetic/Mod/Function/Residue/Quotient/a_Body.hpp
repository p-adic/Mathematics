// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Quotient/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
pair<INT,ll> CoprimeFactorInverse( const ll& base , INT c )
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

  return { move( a[0] ) , move( b[0] ) };

}

template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d , const ll& coef , const ll& gcd ) { assert( 0 <= coef && coef < base && ( d % base * coef - gcd ) % base == 0 ); return n % gcd == 0 ? Residue( n / gcd % base * coef , base / gcd ) : -1; }
template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d ) { auto [coef,gcd] = CoprimeFactorInverse( base , d ); return ModularQuotient( base , n , d , coef ,gcd ); }
