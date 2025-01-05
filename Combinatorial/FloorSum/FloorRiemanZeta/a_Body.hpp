// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemanZeta/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Arithmetic/Sqrt/a_Body.hpp"
#include "../../../Arithmetic/Sum/a_Body.hpp"

template <typename INT>
INT FloorRiemannZeta( const INT& n , const INT& exponent )
{

  INT i_max = RoundDownSqrt( n );
  INT answer = 0;

  for( INT i = 1 ; i <= i_max ; i++ ){

    answer += ( n / i - n / ( i + 1 ) ) * Power( i , exponent );

  }

  i_max = n / ( i_max + 1 );

  for( INT i = 1 ; i <= i_max ; i++ ){

    answer += Power( n / i , exponent );

  }

  return answer;

}

template <typename INT> inline INT HarmonicFloorSum( const INT& n ){ return n < 0 ? - FloorRiemanZeta<INT>( - n - 1 , 1 ) - n : FloorRiemanZeta<INT>( n , 1 ); }
