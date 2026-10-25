// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/Double/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<cd> FFT( const vector<INT>& f , int n , int v )
{

  vector<cd> a( n , f[0] );
  
  if( n > 1 ){

    n >>= 1;
    v--;
    vector<cd> f0( n ) , f1( n );
    const cd pijn = pij / forward<double>( n );
    
    for( int e = 0 ; e < n ; e++ ){

      f0[e] = f[e] + f[n|e];
      f1[e] = forward<cd>( f[e] - f[n|e] ) * exp( pijn * forward<double>( e ) );

    }

    f0 = FFT( f0 , n , v );
    f1 = FFT( f1 , n , v );
    
    for( int e = 0 ; e < n ; e++ ){

      a[e<<1] = f0[e];
      a[(e<<1)|1] = f1[e];

    }

  }

  return a;

}

inline void IFFT( vector<cd>& f , const int& n , int v ) { for( auto& z : f ){ z = conj( z ); } f = FFT( f , n , move( v ) ); for( auto& z : f ){ z = conj( z ) / forward<double>( n ); } }

template <typename VEC0 , typename VEC1>
vector<ll> Convolution( VEC0 f , VEC1 g )
{
  
  const int L0 = f.size() , L1 = g.size() , L = L0 + L1 - 1;

  if( min( L0 , L1 ) == 0 ){

    return {};

  }
  
  int n = 1 , v = 0;
  while( n < L ){
      
    n <<= 1;
    v++;

  }

  f.resize( n );
  g.resize( n );
  auto Ff = FFT( f , n , v ) , Fg = FFT( g , n , v );

  for( int e = 0 ; e < n ; e++ ){

    Ff[e] *= Fg[e];

  }

  IFFT( Ff , n , v );
  vector<ll> a( n );

  for( int e = 0 ; e < n ; e++ ){

    a[e] = llround( Ff[e].real() );

  }
    
  while( !a.empty() && a.back() == 0 ){

    a.pop_back();

  }

  return a;

}

