// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemannZeta/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Arithmetic/Iteration/Constexpr/Log/a_Body.hpp"
#include "../../../Arithmetic/Iteration/Truncated/a_Body.hpp"

template <typename INT1 , typename INT2>
ll FloorRiemannZeta( const INT1& n , const INT2& s )
{

  assert( n >= 0 && s > 0 );

  if( n == 0 ){

    return 0;

  }
  
  // (d/dv)(log(s)log(n/v)+1+(log(s)+1)(n/v)^{1/s}+(v+1)(log(s)log(n)+1))
  // = -log(e)log(s)/v-n^{1/s}/(s(log(s)+1)v^{1+1/s})+(log(s)log(n)+1)
  // v \approx (n^{1/s}/(s(log(s)+1)(log(s)log(n)+1)))^{1/(1+1/s)}
  //         = (n/(s(log(s)+1)(log(s)log(n)+1))^s)^{1/(s+1)}
  // -> O((s(log(s)+1)^{s+2}n(log(s)log(n)+1))^{1/(s+1)})
  const int logs = Log( s ) , logn = Log( n );
  const int v_mid = RoundDownRoot( s + 1 , n / TruncatedPower( s * ( logs + 1 ) * ( logs * logn + 1 ) , s , n - 1 ) );
  // floor(n/i^s) >= v_mid
  // <=> n/i^s >= v_mid
  // <=> n/v_mid >= i^s
  // <=> floor(floor(n/v_mid)^{1/s}) >= i
  // O((log(n/v_mid)log(s)+1)))
  const int i_max = RoundDownRoot( s , n / v_mid );
  ll answer = 0;

  // O(i_max(log(s)+1)) = O((n/v_mid)^{1/s}(log(s)+1))
  for( int i = 1 ; i <= i_max ; i++ ){

    answer += n / Power( ll( i ) , s );

  }

  // O((log(n)log(s)+1))
  ll prev = RoundDownRoot( s , n ) , next;

  // O(v_mid(log(n)log(s)+1))
  for( int v = 1 ; v < v_mid ; v++ ){

    // floor(n/i^s)=v
    // <=> v <= n/i^s < v+1
    // <=> n/(v+1) < i^s <= n/v
    // <=> floor(floor(n/(v+1))^{1/s}) < i <= floor(floor(n/v)^{1/s})
    next = RoundDownRoot( s , n / ( v + 1 ) );
    answer += ( prev - next ) * Power( ll( v ) , s );
    prev = next;

  }

  return answer;

}

template <typename INT> inline INT HarmonicFloorSum( const INT& n ){ return n < 0 ? - FloorRiemannZeta( - n - 1 , 1 ) - n : FloorRiemannZeta<INT>( n , 1 ); }

