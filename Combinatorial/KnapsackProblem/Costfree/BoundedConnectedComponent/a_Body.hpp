// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/BoundedConnectedComponent/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../SlidingMinimalisation/a_Body.hpp"

template <typename INT>
INT CostfreeBoundedConnectedComponentKnapsack( const vector<INT>& value , const int& r , const int& l )
{

  const int N = value.size();
  assert( 0 < l );
  INT sum = Sum<INT>( value ) , opt = r < N ? sum : 0;
  vector<INT> sm( N );
  SlidingMinimalisation( [&]( const INT& x , const int& i ) { return i <= r ? value[i] : x + ( i < N ? value[i] : 0 ); } , [&]( const int& i ){ return i < l ? sum : sm[i-l]; } , sm , r - l + 2 );

  for( int i = max( 0 , N - ( r + 1 ) ) ; i < N ; i++ ){

    SetMin( opt , sm[i] );

  }
  
  return sum - opt;

}
