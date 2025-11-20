// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorFiber/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Tuple/Wrap/a_Body.hpp"

#include "../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../Arithmetic/Sqrt/a_Body.hpp"

template <typename INT>
vector<T3<INT>> FloorFiber( const INT& n )
{

  assert( n >= 1 );
  // B <= floor( n / i ) <-> B <= n / i <-> i <= n / B <-> i <= floor( n / B )
  const INT B = RoundDownSqrt( n ) , i_max = n / B;
  vector<T3<INT>> answer{};

  for( int i = 1 ; i <= i_max ; i++ ){

    answer.push_back( {n/i,i,i} );

  }

  for( int v = 1 ; v < B ; v++ ){
    // v = floor( n / i ) <-> v <= n / i < v + 1 <-> n / ( v + 1 ) < i <= n / v
    // <-> floor( n / ( v + 1 ) ) < i <= floor( n / v );
    answer.push_back( {v,n/(v+1)+1,n/v} );

  }

  return answer;
  
}

template <typename INTERVAL_SUM , typename INT , typename RET>
RET FloorComposition( INTERVAL_SUM f , const INT& n , const ll& l , const ll& r )
{

  RET answer{};

  for( auto& [v,l_v,r_v] : FloorFiber( n ) ){

    SetMax( l_v , l );
    SetMin( r_v , r );

    if( l_v <= r_v ){
        
      answer += f( v , l_v , r_v );

    }

  }

  return answer;

}
