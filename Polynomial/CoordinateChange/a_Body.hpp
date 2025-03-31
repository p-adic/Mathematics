// c:/Users/user/Documents/Programming/Mathematics/Polynomial/CoordinateChange/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
void Shift( Polynomial<T>& f , const T& t , const bool& exponential )
{

  f.Reduce();
  const int& size = f.size();
  
  if( size > 0 && t != f.c_zero() ){

    FormalPowerSeries<T> exp_t_transpose{ size * 2 };
    T power_t = f.c_one();
  
    for( int d = 0 ; d < size ; d++ ){

      exp_t_transpose[size - 1 - d] = power_t * T::FactorialInverse( d );
      power_t *= t;

    }

    if( exponential ){

      exp_t_transpose *= f;

      for( int d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1];

      }

    } else {

      for( int d = 0 ; d < size ; d++ ){

	f[d] *= T::Factorial( d );

      }

      exp_t_transpose *= f;

      for( int d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1] * T::FactorialInverse( d );

      }

    }

  }

  return;
  
}

template <typename T>
void AffineTransformation( Polynomial<T>& f , const T& t , const T& u , const bool& exponential )
{

  Shift( f , u , exponential );
  const int& size = f.size();
  T power = f.c_one();

  for( int d = 0 ; d < size ; d++ ){

    f[d] *= power;
    power *= t;

  }

  return;

}

template <typename T>
tuple<Polynomial<T>,T,T,int> MoeviusTransformation( Polynomial<T> f , T a , T b , T c , T d )
{

  const T& zero = f.c_zero();
  const T& one = f.c_one();
  
  if( c == zero ){

    d = one / d;
    AffineTransformation( f , a *= d , b *= d );
    return { move( f ) , zero , one , 0 };

  }
  
  a /= c;
  b -= a * d;
    
  if( b == zero ){

    return { f( a ) , zero , one , 0 };

  }

  b = one / b;
  c *= b;
  d *= b;
  Shift( f , a );
  const int& size = f.size();
  f.Transpose( size );
  AffineTransformation( f , c , d );
  return { move( f ) , move( c ) , move( d ) , size - 1 };

}

