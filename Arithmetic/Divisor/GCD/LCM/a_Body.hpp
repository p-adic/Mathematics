// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/LCM/a_Body.hpp

#pragma once
#include "a.hpp"

inline int LCM() { return 1; }

template <typename INT1 , typename...INT2>
INT1 LCM( INT1 b_0 , INT2... args )
{

  b_0 < 0 ? b_0 = -b_0 : b_0;
  const INT1 b_1 = LCM( move( args )... ) , gcd = GCD( b_0 , b_1 );
  return gcd == 0 ? gcd : b_0 / gcd * b_1;

}

template <typename INT , template <typename...> typename V>
INT LCM( V<INT> a )
{

  INT answer = 1;
  
  for( auto& b : a ){

    answer = LCM( move( answer ) , b );

  }

  return answer;

}
