// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/Affine/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../../../Arithmetic/Truncated/a_Body.hpp"

template <typename RET , typename INT1 , typename INT2> RET MaximisationIntervalAffine( ll K , const INT1& A , const INT2& P )
{

  if( K == 1 || A == 0 ){

    return max( 0 , A );

  }
  
  if( P == 0 || P == 1 ){

    return  A < 0 ? 0 : RET{ A } * K;

  }
  
  if( P == -1 ){

    return A < 0 ? RET{ -A } * ( K - 1 ) : RET{ A } * K;

  }

  if( A < 0 && P > 0 ){

    return 0;

  }

  ll score = 0;
  const ll P_dif = A < 0 ? -P : P < 0 ? ll( P ) * P : P;
  const ll A_dif = A < 0 ? -A : A;

  for( int k = 0 ; k < K ; k++ ){

    if( ( A < 0 ? ( ( K - k ) & 1 ) == 0 : P < 0 && ( ( K - k ) & 1 ) == 1 ) || TruncatedProduct( score , P_dif , score + A_dif ) < score + A_dif ){

      score += A_dif;

    } else {

      return Power( RET{ P_dif } , ( K - k ) >> ( A > 0 && P < 0 ) , RET{ score } );

    }

  }

 return A < 0 ? RET{ score + A } * ( -P ) : RET( score );

}
