// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a_Body.hpp

#pragma once
// Sum/RationalSum/Prodに使う。
#include "../../Arithmetic/a_Macro.hpp"
#include "a.hpp"

#include "../a_Body.hpp"

// CumulativeSumに使う
#include "../../Combinatorial/BernulliNumber/a_Body.hpp"


template <typename T , template <typename...> typename V>
Polynomial<T>& Sum( V<Polynomial<T>>& f )
{
  
  DEFIINTION_OF_PROD( Sum( f ) , Polynomial<T>::zero() , t += *itr );

}

template <typename T , template <typename...> typename V>
pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f )
{
  
  DEFIINTION_OF_PROD( RationalSum( f ) , EXPRESSION1_FOR_RATIONAL_SUM , t = EXPRESSION2_FOR_RATIONAL_SUM );

}

template <typename T , template <typename...> typename V>
V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& RationalSum( V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& f )
{
  
  DEFIINTION_OF_PROD( RationalSum( f ) , EXPRESSION3_FOR_RATIONAL_SUM , t = EXPRESSION2_FOR_RATIONAL_SUM );

}

template <typename T , template <typename...> typename V>
Polynomial<T>& Prod( V<Polynomial<T>>& f )
{

  DEFIINTION_OF_PROD( Prod( f ) , Polynomial<T>::one() , t += *itr );

}

template <typename T , template <typename...> typename V>
TruncatedPolynomial<T>& Prod( V<TruncatedPolynomial<T>>& f )
{

  DEFIINTION_OF_PROD( Prod( f ) , TruncatedPolynomial<T>( 1 , Polynomial<T>::one() ) , t += *itr );

}

template <typename T>
Polynomial<T> Power( Polynomial<T> f , uint e )
{

  Polynomial<T> answer = Polynomial<T>::one();

  while( e > 0 ){

    ( e & 1 ) == 0 ? answer : answer *= f;
    f *= f;
    e >>= 1;

  }
  
  return answer;

}

template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t ) { return Exp( Log( f ) *= t ); }

template <typename T>
TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const uint& e )
{

  const T& one = Polynomial<T>::c_one();

  if( f[0] == one ){

    return Power( f , T( e ) );

  }

  const T& zero = Polynomial<T>::c_zero();
  const uint& size = f.size();
  uint v = 0;

  while( v < size ? f[v] == zero : false ){

    v++;

  }

  const uint ve = v * e;
  const uint& N = f.GetTruncation();

  if( v == size || ve >= N ){

    return TruncatedPolynomial<T>( N );

  }

  TruncatedPolynomial<T> g( N - ve );
  const T fv_inv = one / f[v];

  for( uint d = v ; d < size ; d++ ){

    g[d - v] = f[d] * fv_inv;

  }
  
  g = Exp( Log( g ) *= T( e ) ) * Power( f[v] , e );
  g.SetTruncation( N );

  for( uint d = N - 1 ; d + 1 > ve ; d-- ){

    g[d] = g[d - ve];

  }

  for( uint d = 0 ; d < ve ; d++ ){

    g[d] = zero;

  }

  return g;

}

template <typename T , template <typename...> typename V>
TruncatedPolynomial<T> ExponentialSum( const uint& N , const V<pair<T,T>>& coef )
{

  V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>> f{};

  for( auto itr = coef.begin() , end = coef.end() ; itr != end ; itr++ ){

    f.push_back( { TruncatedPolynomial<T>( N , itr->first ) , TruncatedPolynomial<T>( N , 1 ,  - itr->second ) + Polynomial<T>::one() } );

  }

  auto& [g,h] = RationalSum( f );
  g /= h;
  const uint& size = g.size();

  for( uint d = 0 ; d < size ; d++ ){

    g[d] *= T::FactorialInverse( d );

  }

  return move( g );

}

template <typename T , uint deg_max>
Polynomial<T> MonomialSum( const uint& D )
{

  assert( D <= deg_max );
  static const BernulliNumberCalculator<T,deg_max+1> B{ false };
  Polynomial<T> answer{};

  for( uint d = 0 ; d <= D + 1 ; d++ ){

    answer[d] = T::Combination( D + 1 , d ) * B[D + 1 - d];

  }

  answer /= T{ D + 1 };
  return answer;

}

template <typename T , uint deg_max>
Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential )
{

  const uint f_size = f.size();

  if( f_size == 0 ){

    return f;

  }
  
  const uint deg = f_size - 1;
  assert( deg <= deg_max );
  const T f0 = f[0];
  const uint deg_half = ( deg + 1 ) / 2;

  if( !exponential ){

    for( uint d = 1 ; d <= deg ; d++ ){

      f[d] *= T::Factorial( d );

    }

  }

  for( uint d = 0 ; d < deg_half ; d++ ){

    swap( f[d] , f[deg - d] );

  }

  f.resize( deg );
  TruncatedPolynomial<T> f_transpose{ f_size , move( f ) };
  static const BernulliNumberCalculator<T,deg_max+1> B{ false };
  static Polynomial<T> g{};
  static uint g_size = 0;
  
  while( deg >= g_size ){

    g[g_size] = B[g_size] * T::FactorialInverse( g_size );
    g_size++;

  }
  
  f_transpose *= g;
  f_transpose.SetTruncation( f_size + 1 );
  const uint f_size_half = ( f_size + 1 ) / 2;
  
  for( uint d = 0 ; d < f_size_half ; d++ ){

    swap( f_transpose[d] , f_transpose[f_size - d] );

  }

  if( !exponential ){

    for( uint d = 1 ; d <= f_size ; d++ ){

      f_transpose[d] *= T::FactorialInverse( d );

    }

  }

  f_transpose[1] += f_transpose[0] = f0;
  return f_transpose;

}

template <typename T>
vector<T> CumulativeSum( vector<T> a , uint order )
{

  const uint size = a.size();

  if( size > 0 ){
    
    TruncatedPolynomial<T> f{ size , move( a ) };
    TruncatedPolynomial<T> g{ size , vector<T>( size , 1 ) };
    f *= Power( g , move( order ) );
    a.resize( size );

    for( uint d = 0 ; d < size ; d++ ){

      a[d] = move( f[d] );

    }

  }
  
  return move( a );

}

