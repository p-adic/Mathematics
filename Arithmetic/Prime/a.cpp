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

      // L + L(1-1/p_0) + L(1-1/p_0)(1-1/p_1) + ... 
      // \approx (L/log L)^2
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

  assert( n > 0 );

  if( n == 1 ){

    return false;

  }

  constexpr int T = 20;
  vector<int> P = {2,3,5,7,11,13,17,19,23,29};
  const int T_half = P.size();

  for( auto& p : P ){

    if( n == p ){

      return true;

    }

    if( n % p == 0 ){

      return false;

    }

  }

  for( int t = T_half ; t < T ; t++ ){

    P.push_back( GetRand( P[T_half - 1] + 1 , n - 1 ) );

  }
  
  int u = n - 1 , v = 0;
  
  while( ( u & 1 ) < 1 ){

    u >>= 1;
    ++v;

  }

  for( int t = 0 ; t < T ; t++ ){

    ll m = 1 , s = P[t];
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
