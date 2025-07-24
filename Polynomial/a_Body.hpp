// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Body.hpp

#pragma once
#include "a.hpp"

#include "FPS/a_Body.hpp"
// include展開順:
// Poynomial/a.hpp
// FPS/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FPS/a_Body.hpp
// Poynomial/a_Body.hpp

template <typename T> inline Polynomial<T>::Polynomial() : m_f() , m_size( 0 ) {}
template <typename T> inline Polynomial<T>::Polynomial( const Polynomial<T>& f ) : m_f( f.m_f ) , m_size( f.m_size ) {}
template <typename T> inline Polynomial<T>::Polynomial( Polynomial<T>&& f ) : m_f( move( f.m_f ) ) , m_size( f.m_size ) {}
template <typename T> inline Polynomial<T>::Polynomial( vector<T> f ) : m_f( move( f ) ) , m_size( m_f.size() ) {}
template <typename T> inline Polynomial<T>::Polynomial( T t ) : Polynomial() { if( t != c_zero() ){ operator[]( 0 ) = move( t ); } }
template <typename T> inline Polynomial<T>::Polynomial( const int& i , T t ) : Polynomial() { if( t != c_zero() ){ operator[]( i ) = move( t ); } }

template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( T n ) { m_f.clear(); m_size = 0; operator[]( 0 ) = move( n ); return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( Polynomial<T> f ) { m_f = move( f.m_f ); m_size = f.m_size; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( vector<T> f ) { m_f = move( f ); m_size = m_f.size(); return *this; }

template <typename T> inline const T& Polynomial<T>::operator[]( const int& i ) const { return m_size <= i ? c_zero() : m_f[i]; }

template <typename T> inline T& Polynomial<T>::operator[]( const int& i )
{

  if( m_size <= i ){
    
    const T& z = c_zero();

    while( m_size <= i ){

      m_f.push_back( z );
      m_size++;
    
    }

  }

  return m_f[i];

}

template <typename T> T Polynomial<T>::operator()( const T& t ) const
{

  T answer = ( *this )[0];
  T t_power = c_one();

  for( int d = 1 ; d < m_size ; d++ ){

    answer += m_f[d] * ( t_power *= t );

  }
  
  return answer;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=( const Polynomial<T>& f )
{

  if( m_size < f.m_size ){

    for( int i = 0 ; i < m_size ; i++ ){

      m_f[i] += f.m_f[i];

    }

    for( int i = m_size ; i < f.m_size ; i++ ){

      m_f.push_back( f.m_f[i] );

    }

    m_size = f.m_size;

  } else {

    for( int i = 0 ; i < f.m_size ; i++ ){

      m_f[i] += f.m_f[i];

    }

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator-=( const Polynomial<T>& f )
{

  if( m_size < f.m_size ){

    for( int i = 0 ; i < m_size ; i++ ){

      m_f[i] -= f.m_f[i];

    }

    for( int i = m_size ; i < f.m_size ; i++ ){

      m_f.push_back( - f.m_f[i] );

    }

    m_size = f.m_size;

  } else {

    for( int i = 0 ; i < f.m_size ; i++ ){

      m_f[i] -= f.m_f[i];

    }

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator/=( const T& t )
{
  
  if( t == c_one() ){

    return *this;

  }

  const T t_inv{ c_one() / t };
  
  for( int i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= t_inv;

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const T& t )
{

  if( t == c_one() ){

    return *this = zero();

  }
  
  for( int i = 0 ; i < m_size ; i++ ){

    m_f[i] %= t;

  }

  return *this;

}

template <typename T>
bool Polynomial<T>::operator==( const Polynomial<T>& f ) const
{

  const int& size0 = size();
  const int& size1 = f.size();
  const int& size_max = size0 < size1 ? size1 : size0;

  for( int i = 0 ; i < size_max ; i++ ){

    if( operator[]( i ) != f[i] ){

      return false;

    }

  }

  return true;

}

template <typename T>
bool Polynomial<T>::operator==( const T& t ) const
{

  const int& size_max = size();
  const T& zero = Polynomial<T>::c_zero();

  for( int i = 1 ; i < size_max ; i++ ){

    if( m_f[i] != zero ){

      return false;

    }

  }

  return operator[]( 0 ) == t;

}

template <typename T> template<typename P> inline bool Polynomial<T>::operator!=( const P& f ) const { return !( *this == f ); }

DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( + , f += *this );
template <typename T> inline Polynomial<T>& Polynomial<T>::SignInvert() { Reduce(); for( auto& fi : m_f ){ fi = -fi; } return *this; }
template <typename T> inline Polynomial<T> Polynomial<T>::operator-() const { return move( Polynomial<T>( *this ).SignInvert() ); }
DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( - , f.SignInvert() += *this );
DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( * , f *= *this );
template <typename T> inline Polynomial<T> Polynomial<T>::operator/( const T& t ) const { return move( Polynomial<T>( *this ) /= t ); }
template <typename T> inline Polynomial<T> Polynomial<T>::operator/( const Polynomial<T>& f ) const { return move( Polynomial<T>( *this ) /= f ); }
template <typename T> inline Polynomial<T> Polynomial<T>::operator%( const T& t ) const { return move( Polynomial<T>( *this ) %= t ); }
template <typename T> inline Polynomial<T> Polynomial<T>::operator%( const Polynomial<T>& f ) const { return move( Polynomial<T>( *this ) %= f ); }

template <typename T> inline const vector<T>& Polynomial<T>::GetCoefficient() const noexcept { return m_f; }
template <typename T> inline const int& Polynomial<T>::size() const noexcept { return m_size; }
template <typename T> inline void Polynomial<T>::resize( const int& deg_plus ) noexcept { m_f.resize( m_size = deg_plus ); }

template <typename T>
int Polynomial<T>::Valuation() const noexcept
{

  for( int i = 0 ; i < m_size ; i++ ){

    if( m_f[i] != c_zero() ){

      return i;

    }

  }

  return -1;

}

template <typename T> inline void Polynomial<T>::swap( Polynomial<T>& f ) { m_f.swap( f.m_f ); swap( m_size , f.m_size ); }
template <typename T> inline void Polynomial<T>::swap( vector<T>& f ) { m_f.swap( f ); m_size = m_f.size(); }


template <typename T>
void Polynomial<T>::Reduce()
{

  const T& z = c_zero();
  
  while( m_size > 0 && m_f[m_size - 1] == z ){

    m_f.pop_back();
    m_size--;

  }

  return;

}

template <typename T>
void Polynomial<T>::Transpose( const int& N_trunc )
{

  while( N_trunc > m_size ){

    m_f.push_back( c_zero() );
    m_size++;

  }

  const int N_half = min( N_trunc , ( m_size + 1 ) / 2 );
  
  for( int d = 0 ; d < N_half ; d++ ){

    ::swap( m_f[d] , m_f[ m_size - 1 - d ] );

  }

  m_f.resize( N_trunc );
  m_size = N_trunc;
  return;

}

template <typename T> inline const Polynomial<T>& Polynomial<T>::zero() { static const Polynomial<T> z{}; return z; }
template <typename T> inline const Polynomial<T>& Polynomial<T>::one() { static const Polynomial<T> o{ c_one() }; return o; }
template <typename T> inline const Polynomial<T>& Polynomial<T>::x() { static const Polynomial<T> f{ 1 , c_one() }; return f; }
template <typename T> inline const T& Polynomial<T>::c_zero() { static const T z{ 0 }; return z; }
template <typename T> inline const T& Polynomial<T>::c_one() { static const T o{ 1 }; return o; }
template <typename T> inline const T& Polynomial<T>::c_minus_one() { static const T m{ -1 }; return m; }

template <typename T>
Polynomial<T> Differential( const int& n , const Polynomial<T>& f )
{

  const int& size = f.size();

  if( size < n ){

    return Polynomial<T>::zero();

  }

  vector<T> df( size - n );
  T coef = T::Factorial( n );
  int i = n;

  while( i < size ){

    df[i - n] = f[i] * coef;
    i++;
    ( coef *= i ) /= ( i - n );

  }

  return Polynomial<T>( move( df ) );

}

// 以下FormalPowerSeries<T>を使用時は不使用。
template <typename T>
Polynomial<T> Polynomial<T>::NaiveConvolution( Polynomial<T> f0 , const int& valuation0 , const Polynomial<T>& f1 , const int& valuation1 , const int& N_trunc )
{

  const int size0 = f0.size();
  assert( 0 <= valuation0 && valuation0 < size0 );
  const int size1 = f1.size();
  assert( 0 <= valuation1 && valuation1 < size1 );
  const int i_ulim = min( size0 , N_trunc - valuation1 );

  for( int i = i_ulim - 1 ; i >= valuation0 ; i-- ){

    const T f0i = f0[i];
    f0[i] *= f1[0];
    const int j_ulim = min( size1 , N_trunc - i ) , j_min = max( valuation1 , 1 );
    
    for( int j = j_ulim - 1 ; j >= j_min ; j-- ){

      f0[i+j] += f0i * f1[j];

    }

  }

  return move( f0 );

}

template <typename T>
Polynomial<T> Polynomial<T>::NaiveQuotient( Polynomial<T> f0 , const Polynomial<T>& f1 )
{

  const int diff = f0.m_size - f1.m_size;

  if( diff < 0 ){

    return move( f0 );

  }

  const T r = f0[f0.m_size-1] / f1[f1.m_size-1];
  f0.m_f.pop_back();
  f0.m_size--;
  f0.Reduce();

  for( int i = diff ; i < f0.m_size ; i++ ){

    f0[i] -= r * f1[i - diff];

  }

  f0.Reduce();
  f0 = NaiveQuotient( move( f0 ) , f1 );
  f0[diff] = r;
  return move( f0 );

}

template <typename T>
Polynomial<T> Polynomial<T>::NaiveResidue( Polynomial<T> f0 , const Polynomial<T>& f1 )
{

  const int diff = f0.m_size - f1.m_size;

  if( diff < 0 ){

    return move( f0 );

  }

  const T r = f0[f0.m_size-1] / f1[f1.m_size-1];
  f0.m_f.pop_back();
  f0.m_size--;
  f0.Reduce();

  for( int i = diff ; i < f0.m_size ; i++ ){

    f0[i] -= r * f1[i - diff];

  }

  f0.Reduce();
  return NaiveResidue( move( f0 ) , f1 );

}

// 以下FormalPowerSeries<T>を使用時は特殊化で変更。
template <typename T>
Polynomial<T>& Polynomial<T>::operator*=( Polynomial<T> f )
{

  Reduce();
  
  if( m_size == 0 ){

    return *this;

  }

  f.Reduce();

  if( f.m_size == 0 ){

    return *this = move( f );

  }
  
  const int valuation0 = this->Valuation();
  const int valuation1 = f.Valuation();
  const int length0 = m_size - valuation0;
  const int length1 = f.m_size - valuation1;
  const int size = m_size + f.m_size - 1;

  m_f = NaiveConvolution( move( *this ) , valuation0 , f , valuation1 , size );
  m_size = m_f.size();
  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator/=( const Polynomial<T>& f )
{

  assert( f.m_size > 0 && f[f.m_size-1] != c_zero() );
  Reduce();
  
  if( m_size < f.m_size ){

    return *this = zero();

  }

  return *this = NaiveQuotient( move( *this ) , f );

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const Polynomial<T>& f )
{

  assert( f.m_size > 0 && f[f.m_size-1] != c_zero() );
  Reduce();
  return *this = NaiveResidue( move( *this ) , f );

}
