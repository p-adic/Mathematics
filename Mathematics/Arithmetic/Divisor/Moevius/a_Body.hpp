// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Moevius/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename INT> int MoeviusFunction( const INT& n ) noexcept
{

  vector<INT> P{} , exponent{};
  SetPrimeFactorisation( n , P , exponent );
  const int length = P.size();

  for( int i = 0 ; i < length ; i++ ){

    if( exponent[i] > 1 ){

      return 0;

    }

  }

  return length % 2 == 0 ? 1 : -1;

}

template <typename PE , typename INT>
int MoeviusFunction( const PE& pe , INT n ) noexcept
{

  const int& length = pe.length();
  int answer = 1;
  int i = 0;

  while( i < length && n > 1 ){

    auto& p = pe[i++];

    if( n % p == 0 ){

      if( ( n /= p ) % p == 0 ){

	return 0;

      }

      answer *= -1;

    }

  }

  return n == 1 ? answer : answer *= -1;

}

template <typename LD , typename INT>
int Moevius( const LD& ld , INT n )
{

  int answer = 1;
  
  while( n > 1 ){

    auto& p = ld[n];

    if( ( n /= p ) % p == 0 ){

      return 0;

    }

    answer *= -1;

  }

  return answer;

}
