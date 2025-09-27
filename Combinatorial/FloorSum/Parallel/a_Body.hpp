// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/Parallel/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/BinarySearch/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"
#include "../../../Utility/Set/Map/a_Body.hpp"

template <typename INT1 , typename INT2 , typename RET> vector<RET> NumeratorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den , vector<RET> coeff )
{

  PARALLEL_FLOOR_SUM_PREP;
  vector<RET> a( N );

  if( coeff.empty() ){

    coeff.resize( M , 1 );

  }

  for( int j = 1 ; j < M ; j++ ){

    coeff[j] += coeff[j-1];

  }
  
  PARALLEL_FLOOR_SUM_BODY( a[i] += n / cc[j] * ( j > 0 ? coeff[j] - coeff[j-1] : coeff[j] ) , a[i] += v * ( j0 >= 0 ? coeff[j] - coeff[j0] : coeff[j] ) );
  return a;

}

template <typename INT1 , typename INT2>
vector<ll> DenominatorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den )
{

  PARALLEL_FLOOR_SUM_PREP;
  vector<ll> a_cc( L ) , a_cc_dif( L + 2 );
  PARALLEL_FLOOR_SUM_BODY( a_cc[j] += n / cc[j] , a_cc_dif[j0+1] += v; a_cc_dif[j+1] -= v );

  for( int j = 0 ; j < L ; j++ ){

    a_cc[j] += a_cc_dif[j] += j > 0 ? a_cc_dif[j-1] : 0;

  }

  vector<ll> answer( M );

  for( int j = 0 ; j < M ; j++ ){

    answer[j] = a_cc[cc_inv[den[j]]];

  }

  return answer;

}
