// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FormalPowerSeries/Composition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// MoeviusCompositionにPowerを使う。
// ExponentialCompositionにExponentialSumを使う。
#include "../../IteratedArithmetic/a_Body.hpp"
// LogarithmCompositionにSetPointTreeなどを使う。
#include "../MultipointEvaluation/a_Body.hpp"

template <typename T>
FormalPowerSeries<T> Composite( const FormalPowerSeries<T>& f  , const FormalPowerSeries<T>& g )
{

  const int& N = f.GetTruncation();
  assert( N > 0 && g[0] == Polynomial<T>::c_zero() );
  const int N_minus = N - 1;

  if( N_minus == 0 ){

    return *this;

  }

  const int H = sqrt( N_minus );
  const int K = N_minus / H;
  vector<FormalPowerSeries<T> > g_power( K < 2 ? 2 : K );
  ( g_power[1] = g ).SetTruncation( N );
  
  for( int k = 2 ; k < K ; k++ ){

    g_power[k] = g_power[k-1] * g_power[1];

  }

  vector<FormalPowerSeries<T> > g_power2( H + 1 );
  g_power2[1] = K < 2 ? g_power[1] : g_power[K-1] * g_power[1];

  for( int h = 2 ; h <= H ; h++ ){

    g_power2[h] = g_power2[h-1] * g_power2[1];

  }

  int k = 0;
  int h = 0;
  int n_max = N_minus;
  FormalPowerSeries<T> answer{ N };
  FormalPowerSeries<T> answer_h{ N };

  for( int d = 0 ; d < N ; d++ ){

    for( int n = k ; n <= n_max ; n++ ){

      answer_h[n] += k == 0 ? n == 0 ? f[d] : T{} : f[d] * g_power[k][n];

    }
    
    if( ++k == K || d == N_minus ){

      answer += h == 0 ? answer_h : answer_h *= g_power2[h];
      k = 0;
      h++;
      n_max -= K;
      answer_h = FormalPowerSeries<T>( N );

    }

  }

  return answer;

}

template <typename T>
FormalPowerSeries<T> MoeviusComposition( const int& N , Polynomial<T> f , T a , T b , T c , T d )
{

  const T& zero = Polynomial<T>::c_zero();
  const T& one = Polynomial<T>::c_one();
  
  if( c == zero ){

    d = one / d;
    AffineTransformation( f , a *= d , b *= d );

  } else {
  
    a /= c;
    b -= a * d;
    
    if( b == zero ){

      f = f( a );

    } else {

      b = one / b;
      c *= b;
      d *= b;
      Shift( f , a );
      const int& size = f.size();

      if( size > 0 ){
	
	f.Transpose( size );
	AffineTransformation( f , c , d );
	FormalPowerSeries<T> g{ N };
	g[0] = move( d );
	g[1] = move( c );
	g = Inverse( Power( g , size - 1 ) );
	g *= f;
	f = move( g );

      }

    }

  }

  return FormalPowerSeries<T>( N , f );

}

template <typename T>
FormalPowerSeries<T> ExponentialComposition( const int& N , const Polynomial<T>& f , const T& t )
{

  const int& size = f.size();
  list<pair<T,T>> coef{};
  T temp = Polynomial<T>::c_zero();

  for( int d = 0 ; d < size ; d++ ){

    coef.push_back( { f[d] , temp } );
    temp += t;

  }
  
  return ExponentialSum( N , coef );

}

template <typename T>
FormalPowerSeries<T> MoeviusExponentialComposition( const int& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t )
{

  auto [h,u,v,e] = MoeviusComposition( f , move( a ) , move( b ) , move( c ) , move( d ) );
  FormalPowerSeries<T> g{ ExponentialComposition( N , h , t ) };
  h.resize( 2 );
  h[0] = move( v );
  h[1] = move( u );
  FormalPowerSeries<T> r{ ExponentialComposition( N , h , t ) };
  r = Power( r , e );
  return move( g /= r );
  
}

template <typename T>
FormalPowerSeries<T> LogarithmComposition( const int& N , Polynomial<T> f , const T& t )
{

  const int& f_size = f.size();

  if( f_size == 0 ){

    return FormalPowerSeries<T>( N );
    
  }

  const T& zero = Polynomial<T>::c_zero();
  
  if( t == zero ){

    return FormalPowerSeries<T>( N , f( t ) );
    
  }
  
  // 部分分数分解による復元のためにfの次数分も必要であることに注意。
  const int size = max( f_size , N );
  list<T> point{};
  vector<T> coef{};

  for( int d = 0 ; d < f_size ; d++ ){

    f[d] *= T::Factorial( d );

  }

  for( int d = 1 ; d < size ; d++ ){

    point.push_back( t * T::Inverse( d ) );

  }

  SetPartialFractionDecomposition( size , f , point , coef );
  point.clear();
  f = move( coef );
  const T& one = Polynomial<T>::c_one();
  const T t_inv_minus = -one / t;
  T temp = t_inv_minus;
  
  for( int d = 1 ; d < size ; d++ ){

    f[d] *= temp;
    temp += t_inv_minus;
    
  }
  
  Shift( f , one );
  return FormalPowerSeries<T>( N , move( f ) );

}

template <typename T>
FormalPowerSeries<T> MoeviusLogarithmComposition( const int& N , Polynomial<T> f , T a , T b , T c , const T& t )
{

  const T& zero = Polynomial<T>::c_zero();
  assert( b != zero );
  f = LogarithmComposition( N , move( f ) , t );
  a -= c;
  return MoeviusComposition( N , f , a , zero , c , b );
  
}
