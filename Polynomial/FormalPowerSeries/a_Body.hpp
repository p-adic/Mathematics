// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FormalPowerSeries/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../FFT/a_Body.hpp"
// includeìWäJèá:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N ) : Polynomial<T>() , m_N( N ) { assert( m_N > 0 ); }
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const FormalPowerSeries<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) {}
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( FormalPowerSeries<T>&& f ) : Polynomial<T>( move( f.m_f ) ) , m_N( f.m_N ) {}
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N , T t ) : Polynomial<T>( move( t ) ) , m_N( N ) { assert( m_N > 0 ); }
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N ) { assert( m_N > 0 ); this->m_size = f.m_size < m_N ? f.m_size : m_N; this->m_f = vector<T>( this->m_size ); for( int i = 0 ; i < this->m_size ; i++ ){ this->m_f[i] = f.m_f[i]; } }
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N , Polynomial<T>&& f ) : Polynomial<T>() , m_N( N ) { if( f.m_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f.m_size > m_N ){ TruncateFinal( m_N ); } } else { this->m_f = vector<T>( m_N ); for( int i = 0 ; i < m_N ; i++ ){ this->m_f[i] = move( f.m_f[i] ); } this->m_size = m_N; } }
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N , vector<T>&& f ) : Polynomial<T>() , m_N( N ) { assert( m_N > 0 ); const int f_size = f.size(); if( f_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f_size > m_N ){ TruncateFinal( m_N ); } } else { this->m_f = vector<T>( m_N ); for( int i = 0 ; i < m_N ; i++ ){ this->m_f[i] = move( f[i] ); }} }
template <typename T> inline FormalPowerSeries<T>::FormalPowerSeries( const int& N , const int& i , T t ) : Polynomial<T>() , m_N( N ) { assert( m_N > 0 ); if( i < m_N ? t != this->c_zero() : false ){ ( *this )[i] = move( t ); }}

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator=( FormalPowerSeries<T> f ) { Polynomial<T>::operator=( move( f.m_f ) ); m_N = f.m_N; return *this; }
template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator=( T n ) { Polynomial<T>::operator=( move( n ) ); return *this; }
template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator=( Polynomial<T> f ) { return operator=( FormalPowerSeries<T>( m_N , move( f ) ) ); }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator+=( const T& t ) { Polynomial<T>::operator+=( t ); return *this; }

template <typename T>
FormalPowerSeries<T>& FormalPowerSeries<T>::operator+=( const Polynomial<T>& f )
{

  const int& size_f = m_N < f.m_size ? m_N : f.m_size;
  const int& size = this->m_size < size_f ? this->m_size : size_f;

  for( int i = 0 ; i < size ; i++ ){

    this->m_f[i] += f.m_f[i];

  }

  for( int i = size ; i < size_f ; i++ ){
    
    this->m_f.push_back( f.m_f[i] );

  }

  this->m_size = this->m_f.size();
  return *this;

}

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator+=( const FormalPowerSeries<T>& f ) { assert( m_N <= f.m_N ); const Polynomial<T>& f_ref = f; return operator+=( f_ref ); }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator-=( const T& t ) { Polynomial<T>::operator-=( t ); return *this; }

template <typename T>
FormalPowerSeries<T>& FormalPowerSeries<T>::operator-=( const Polynomial<T>& f )
{

  const int& size_f = m_N < f.m_size ? m_N : f.m_size;
  const int& size = this->m_size < size_f ? this->m_size : size_f;

  for( int i = 0 ; i < size ; i++ ){

    this->m_f[i] -= f.m_f[i];

  }

  for( int i = size ; i < size_f ; i++ ){
    
    this->m_f.push_back( -f.m_f[i] );

  }

  this->m_size = this->m_f.size();
  return *this;

}

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator-=( const FormalPowerSeries<T>& f ) { assert( m_N <= f.m_N ); const Polynomial<T>& f_ref = f; return operator-=( f_ref ); }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator*=( const T& t ) { Polynomial<T>::operator*=( t ); return *this; }

template <typename T>
FormalPowerSeries<T>& FormalPowerSeries<T>::operator*=( Polynomial<T> f )
{

  *this = FFTConvolution( forward<Polynomial<T>>( *this ) , move( f ) , m_N );
  return *this;
  
}

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator*=( FormalPowerSeries<T> f ) { assert( m_N <= f.m_N ); return operator*=( forward<Polynomial<T>>( f ) ); }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::operator/=( const FormalPowerSeries<T>& f ) { assert( m_N <= f.m_N ); return operator*=( m_N == f.m_N ? Inverse( f ) : Inverse( FormalPowerSeries<T>( m_N , f ) ) ); }

template <typename T> template <typename P> inline FormalPowerSeries<T> FormalPowerSeries<T>::operator+( const P& f ) const { return move( FormalPowerSeries<T>( *this ) += f ); }
template <typename T> inline FormalPowerSeries<T> FormalPowerSeries<T>::operator-() const { return move( FormalPowerSeries<T>( m_N ) -= *this ); }
template <typename T> template <typename P> inline FormalPowerSeries<T> FormalPowerSeries<T>::operator-( const P& f ) const { return move( FormalPowerSeries<T>( *this ) -= f ); }
template <typename T> template <typename P> inline FormalPowerSeries<T> FormalPowerSeries<T>::operator*( const P& f ) const { return move( FormalPowerSeries<T>( *this ) *= f ); }
template <typename T> template <typename P> inline FormalPowerSeries<T> FormalPowerSeries<T>::operator/( const P& f ) const { return move( FormalPowerSeries<T>( *this ) /= f ); }

template <typename T>
FormalPowerSeries<T> FormalPowerSeries<T>::Inverse() const
{

  assert( this->m_size > 0 && this->m_f[0] != this->c_zero() );
  const Polynomial<T>& this_ref = *this;
  int power;
  int power_2 = 1;
  FormalPowerSeries<T> f_inv{ power_2 , this->c_one() / this->m_f[0] };

  while( power_2 < m_N ){

    power = power_2;
    power_2 <<= 1;
    f_inv.SetTruncation( power_2 );
    auto temp = f_inv * this_ref;
    temp[0]--;
    int v = temp.Valuation();
    assert( v == -1 || 1 << v >= power );
    temp *= f_inv;

    for( int i = power ; i < power_2 ; i++ ){

      f_inv[i] -= temp[i];

    }

  }

  f_inv.SetTruncation( m_N );
  return f_inv;
  
}

template <typename T> inline void FormalPowerSeries<T>::SetTruncation( const int& N ) noexcept { if( N < m_N ){ TruncateFinal( N ); } m_N = N; }
template <typename T> inline const int& FormalPowerSeries<T>::GetTruncation() const noexcept { return m_N; }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::TruncateInitial( const int& N ) noexcept { const int& size = N < this->m_size ? N : this->m_size; for( int i = 0 ; i < size ; i++ ){ this->m_f[i] = 0; } return *this; }

template <typename T> inline FormalPowerSeries<T>& FormalPowerSeries<T>::TruncateFinal( const int& N ) noexcept { while( this->m_size > N ){ this->m_f.pop_back(); this->m_size--; } return *this; }

template <typename T>
FormalPowerSeries<T> Differential( const FormalPowerSeries<T>& f )
{

  auto& size = f.size();
  auto& N = f.GetTruncation();
  
  if( size < 1 ){

    return FormalPowerSeries<T>( 1 < N ? N - 1 : 1 );

  }

  vector<T> df( size - 1 );

  for( int i = 1 ; i < size ; i++ ){

    df[i - 1] = f[i] * i;

  }

  return FormalPowerSeries<T>( 1 < N ? N - 1 : 1 , move( df ) );

}

template <typename T>
FormalPowerSeries<T> Differential( const int& n , const FormalPowerSeries<T>& f )
{

  if( n == 0 ){

    return f;

  }

  if( n == 1 ){

    return Differential<T>( f );

  }

  auto& size = f.size();
  auto& N = f.GetTruncation();
  
  if( size < n ){

    return FormalPowerSeries<T>( n < N ? N - n : 1 );

  }

  vector<T> df( size - n );
  T coef = T::Factorial( n ) , numer = n , denom = 0;

  for( int i = n ; i < size ; i++ ){

    df[i - n] = f[i] * coef;
    ( coef *= ++numer ) /= ++denom;

  }

  return FormalPowerSeries<T>( n < N ? N - n : 1 , move( df ) );

}

template <typename T>
FormalPowerSeries<T> ShiftedIntegral( const int& n , const FormalPowerSeries<T>& f , const int& shift ) {

  auto& size = f.size();
  auto& N = f.GetTruncation();
  
  if( size + n < shift ){

    return FormalPowerSeries<T>{ N + n > shift ? N + n - shift : 1 };

  }
  
  vector<T> F( size + n - shift );

  if( n == 0 ){

    for( int i = shift ; i < size ; i++ ){

      F[i - shift] = f[i];

    }

  } else if( n == 1 ){

    T denom = 0;

    for( int i = shift > 0 ? shift - 1 : 0 ; i < size ; i++ ){

      F[i + 1 - shift] = f[i] / ++denom;

    }

  } else {

    T coef = T::FactorialInverse( n ) , numer = 0 , denom = n;

    for( int i = shift > n ? shift - n : 0 ; i < size ; i++ ){

      F[i + n - shift] = f[i] * coef;
      ( coef *= ++numer ) /= ++denom;

    }

  }

  return FormalPowerSeries<T>( N + n - shift , move( F ) );

}

template <typename T> inline FormalPowerSeries<T> Integral( const FormalPowerSeries<T>& f ) { return ShiftedIntegral<T>( 1 , f , 0 ); }

template <typename T> inline FormalPowerSeries<T> Integral( const int& n , const FormalPowerSeries<T>& f ) { return ShiftedIntegral<T>( n , f , 0 ); }

template <typename T>
FormalPowerSeries<T> Exp( const FormalPowerSeries<T>& f )
{

  assert( f[0] == f.c_zero() );
  const int& N = f.GetTruncation();
  int power;
  int power_2 = 1;
  FormalPowerSeries<T> f_exp{ power_2 , f.c_one() };

  while( power_2 < N ){
  
    power = power_2;
    power_2 *= 2;
    f_exp.SetTruncation( power_2 );
    auto temp = Differential<T>( f_exp );
    temp /= f_exp;
    temp = ShiftedIntegral( temp , power );

    for( int i = 0 ; i < power ; i++ ){

      temp[i] -= f[i | power];

    }

    temp *= f_exp;
    
    for( int i = 0 ; i < power ; i++ ){

      f_exp[i|power] -= temp[i];

    }

  }

  f_exp.SetTruncation( N );
  return f_exp;
  
}

template <typename T> inline FormalPowerSeries<T> Log( const FormalPowerSeries<T>& f ) { assert( f[0] == f.c_one() ); return Integral<T>( Differential<T>( f ) /= f ); }

#include "../a_Body.hpp"
// includeìWäJèá:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp
