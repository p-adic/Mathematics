// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/TangentLine/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Distance/DivisionPoint/a_Body.hpp"
#include "../../Distance/L2/a_Body.hpp"
#include "../../Line/Equation/a_Body.hpp"

template <typename PAIR>
vector<T3<double>> TangentLineFromPointToCircle( const PAIR& point , const PAIR& centre , const double& radius )
{

  assert( radius > 0.0 );
  const PAIR v = centre - point;
  const double D2 = L22( v ) , d = sqrt( D2 - radius * radius ) , D = sqrt( D2 ) , c = d / D , s = radius / D;
  assert( c > 0.0 );
  vector<T3<double>> answer( 2 );

  for( int i = 0 ; i < 2 ; i++ ){

    const double t = ( i == 0 ? s : -s ) / c;
    PAIR w{ v[O] - t * v[I] , t * v[O] + v[I] };
    answer[i] = LineEquation( point , w += point );

  }

  return answer;

}

template <typename PAIR>
vector<T3<double>> TangentLineFromCircleToCircle( const PAIR& centre0 , const double& radius0 , const PAIR& centre1 , const double& radius1 )
{

  auto p = DivisionPoint( centre0 , centre1 , radius0 , radius1 );
  auto answer = TangentLineFromPointToCircle( p , centre0 , radius0 );

  if( abs( radius0 - radius1 ) < 1e-8 ){

    auto& [c0x,c0y] = centre0;
    auto& [c1x,c1y] = centre1;
    double dx = c0y - c1y , dy = c1x - c0x , D = L2( dx , dy );
    dx /= D;
    dy /= D;
    
    for( int i = 0 ; i < 2 ; i++ ){

      const int sign = i == 0 ? 1 : -1;
      const PAIR q0{ c0x + dx * radius0 * sign , c0y + dy * radius0 * sign } , q1{ c1x + dx * radius1 * sign , c1y + dy * radius1 * sign };
      answer.push_back( LineEquation( q0 , q1 ) );

    }


  } else {

    double r0 = radius0 , r1 = radius1;
    ( radius0 < radius1 ? r0 : r1 ) *= -1;
    auto q = DivisionPoint( centre0 , centre1 , r0 , r1 );

    for( auto& v : TangentLineFromPointToCircle( q , centre0 , radius0 ) ){

      answer.push_back( move( v ) );

    }

  }

  return answer;

}

