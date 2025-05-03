// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FPS/IteratedArithmetic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , template <typename...> typename V>
V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& RationalSum( V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>>& f )
{
  
  DEFINITION_OF_PROD( RationalSum( f ) , EXPRESSION3_FOR_RATIONAL_SUM , t = EXPRESSION2_FOR_RATIONAL_SUM );

}

template <typename T , template <typename...> typename V>
FormalPowerSeries<T>& Prod( V<FormalPowerSeries<T>>& f )
{

  DEFINITION_OF_PROD( Prod( f ) , FormalPowerSeries<T>( 1 , Polynomial<T>::one() ) , t += *itr );

}

template <typename T> inline FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const T& t ) { return Exp( Log( f ) *= t ); }

template <typename T , typename INT>
FormalPowerSeries<T> Power( const FormalPowerSeries<T>& f , const INT& e )
{

  const T& one = Polynomial<T>::c_one();

  if( f[0] == one ){

    return Power( f , T( e ) );

  }

  const T& zero = Polynomial<T>::c_zero();
  const int& size = f.size();
  int v = 0;

  while( v < size ? f[v] == zero : false ){

    v++;

  }

  const INT ve = v * e;
  const int& N = f.GetTruncation();

  if( v == size || ve >= N ){

    return FormalPowerSeries<T>( N );

  }

  FormalPowerSeries<T> g( N - ve );
  const T fv_inv = one / f[v];

  for( int d = v ; d < size ; d++ ){

    g[d - v] = f[d] * fv_inv;

  }
  
  g = Exp( Log( g ) *= T( e ) ) * Power( f[v] , e );
  g.SetTruncation( N );

  for( int d = N - 1 ; d + 1 > ve ; d-- ){

    g[d] = g[d - ve];

  }

  for( int d = 0 ; d < ve ; d++ ){

    g[d] = zero;

  }

  return g;

}

template <typename T , template <typename...> typename V>
FormalPowerSeries<T> ExponentialSum( const int& N , const V<pair<T,T>>& coef )
{

  V<pair<FormalPowerSeries<T>,FormalPowerSeries<T>>> f{};

  for( auto itr = coef.begin() , end = coef.end() ; itr != end ; itr++ ){

    f.push_back( { FormalPowerSeries<T>( N , itr->first ) , FormalPowerSeries<T>( N , 1 ,  - itr->second ) + Polynomial<T>::one() } );

  }

  auto& [g,h] = RationalSum( f );
  g /= h;
  const int& size = g.size();

  for( int d = 0 ; d < size ; d++ ){

    g[d] *= T::FactorialInverse( d );

  }

  return move( g );

}
