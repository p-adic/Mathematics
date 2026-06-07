// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/Total/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<INT> TotalGCD( const int& n )
{

  vector<INT> a( n + 1 , 1 );
  int m = n;

  for( int p = 2 ; p <= m ; p++ ){

    int q = 1;

    while( m % p == 0 ){

      m /= p;
      q *= p;

    }

    if( q > 1 ){

      for( int i = 0 ; i <= n ; i++ ){

        int temp = 1;
        
        while( temp < q && i % ( a[i] * temp * p ) == 0 ){

          temp *= p;

        }

        a[i] *= temp;

      }
      
    }

  }

  return a;

}

template <typename T>
vector<vector<T>> InverseImageGCD( const int& n )
{

  auto gcd = TotalGCD<int>( n );
  vector<vector<T>> a( n + 1 );

  for( int i = 0 ; i <= n ; i++ ){

    a[gcd[i]] <<= i;

  }

  return a;

}
