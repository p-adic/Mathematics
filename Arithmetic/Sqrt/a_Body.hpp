// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename INT>
INT RoundDownSqrt( const INT& n )
{

  static_assert( is_same_v<INT,int> || is_same_v<INT,uint> || is_same_v<INT,ll> || is_same_v<INT,ull> );
  assert( n >= 0 );
  
  if( n <= 1 ){

    return n;
    
  }

  constexpr INT r_max = is_same_v<INT,int> ? 46341 : is_same_v<INT,uint> ? 65536 : is_same_v<INT,ll> ? 3037000500 : 4294967296;
  INT l = 1 , r = min( r_max , n );

  while( l < r - 1 ){

    const INT m = ( l + r ) >> 1;
    // m * m <= n‚©”Û‚©‚ð”»’èB
    ( m <= n / m ? l : r ) = m;

  }

  return l;

}

template <typename INT>
INT RoundUpSqrt( const INT& n )
{
  
  static_assert( is_same_v<INT,int> || is_same_v<INT,uint> || is_same_v<INT,ll> || is_same_v<INT,ull> );
  assert( n >= 0 );

  if( n <= 2 ){

    return n;
    
  }

  constexpr INT r_max = is_same_v<INT,int> ? 46341 : is_same_v<INT,uint> ? 65536 : is_same_v<INT,ll> ? 3037000500 : 4294967296;
  const INT n_minus = n - 1;
  INT l = 1 , r = min( r_max , n );

  while( l + 1 < r ){

    const INT m = ( l + r ) >> 1;
    // m * m < n‚©”Û‚©‚ð”»’èB
    ( m <= n_minus / m ? l : r ) = m;

  }

  return r;

}
