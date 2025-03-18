// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.cpp

#pragma once
#include "Header.hpp"
#include "a_Body.hpp"

// vectorのpush_backを伴うのでconst参照にしない
int GetPrime( const int& i )
{

  assert( i >= 0 );
  static vector<int> P{ 2 , 3 };
  static int L = 2;

  while( i >= L ){

    int p = P.back();
    bool prime = false;

    while( !prime ){

      p += 2;
      prime = true;
    
      for( auto& q : P ){

        // pが2^31付近でなければオーバーフローしない
        if( !( prime = ( p % q != 0 ) ) || p <= q * q ){

          break;
          
        }

      }

    }

    P.push_back( p );
    L++;

  }

  return P[i];

}

bool MillerRabin( const int& n )
{

  constexpr int T = 20;
  assert( n > 0 );

  if( n == 1 ){

    return false;

  }

  int u = n - 1 , v = 0;
  
  while( ( u & 1 ) < 1 ){

    u >>= 1;
    ++v;

  }

  for( int t = 0 ; t < T ; t++ ){

    ll m = 1 , s = GetRand( 1 , n - 1 );
    int u_copy = u;

    while( u_copy > 0 ){

      ( u_copy & 1 ) == 0 ? m : ( m *= s ) %= n;
      ( s *= s ) %= n;
      u_copy >>= 1;

    }

    if( m != 1 && m != n - 1 ){

      for( int e = 1 ; e < v ; e++ ){

        if( ( ( m *= m ) %= n ) == n - 1 ){

          m = -1;
          break;

        }

      }

      if( m != -1 ){

        return false;

      }

    }

  }
      
  return true;

}
