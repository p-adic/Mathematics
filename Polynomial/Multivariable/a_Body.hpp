// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Multivariable/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SetTheory/DirectProduct/AffineSpace/a_Body.hpp"


template <typename T> inline MultivariablePolynomial<T,0>::MultivariablePolynomial() : m_t() {}
template <typename T> inline MultivariablePolynomial<T,0>::MultivariablePolynomial( const T& t ) : m_t( t ) {}
template <typename T> inline MultivariablePolynomial<T,0>::MultivariablePolynomial( const MultivariablePolynomial<T,0>& t ) : m_t( t.m_t ) {}
template <typename T> inline MultivariablePolynomial<T,0>::MultivariablePolynomial( const typename MultivariablePolynomial<T,0>::index& I ) : m_t( const_one() ) {}
template <typename T> inline MultivariablePolynomial<T,0>::MultivariablePolynomial( const typename MultivariablePolynomial<T,0>::index& I , const T& t ) : m_t( t ) {}
template <typename T , int D> inline MultivariablePolynomial<T,D>::MultivariablePolynomial() : m_f() , m_size( 0 ) , m_no_redundant_zero( true ) {}
template <typename T , int D> inline MultivariablePolynomial<T,D>::MultivariablePolynomial( const T& t ) : MultivariablePolynomial() { if( t != MultivariablePolynomial<T,0>::const_zero() ){ operator[]( 0 ) = t; } }
template <typename T , int D> template <int E> inline MultivariablePolynomial<T,D>::MultivariablePolynomial( const MultivariablePolynomial<T,E>& f ) : MultivariablePolynomial() { if( f != MultivariablePolynomial<T,E>::zero() ){ operator[]( 0 ) = f; }; }
template <typename T , int D> inline MultivariablePolynomial<T,D>::MultivariablePolynomial( const MultivariablePolynomial<T,D>& f ) : m_f( f.m_f ) , m_size( f.m_size ) , m_no_redundant_zero( f.m_no_redundant_zero ) {}
template <typename T , int D> inline MultivariablePolynomial<T,D>::MultivariablePolynomial( const MultivariablePolynomialIndex<D>& I , const T& t ) : MultivariablePolynomial() { if( t != MultivariablePolynomial<T,0>::const_zero() ){ operator()( I ) = t; } }


template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator=( const T& t ) { m_t = t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator=( const MultivariablePolynomial<T,0>& t ) { return operator=( t.m_t ); }
template <typename T , int D> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator=( const T& t ) { m_f.clear(); m_size = 0; operator[]( 0 ) = t; return *this; }
template <typename T , int D> template <int E> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator=( const MultivariablePolynomial<T,E>& f ) { m_f.clear(); m_size = 0; operator[]( 0 ) = f; return *this; }
template <typename T , int D> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator=( const MultivariablePolynomial<T,D>& f ) { m_f = f.m_f; m_size = f.m_size; m_no_redundant_zero = f.m_no_redundant_zero; return *this; }


template <typename T> template <int E> inline const T& MultivariablePolynomial<T,0>::operator()( const MultivariablePolynomialIndex<E>& I ) const { return m_t; }
template <typename T> template <int E> inline T& MultivariablePolynomial<T,0>::operator()( const MultivariablePolynomialIndex<E>& I ) { return m_t; }
template <typename T , int D> template <int E> inline const T& MultivariablePolynomial<T,D>::operator()( const MultivariablePolynomialIndex<E>& I ) const { return operator[]( D <= E ? I[D-1] : 0 )( I ); }
template <typename T , int D> template <int E> inline T& MultivariablePolynomial<T,D>::operator()( const MultivariablePolynomialIndex<E>& I ) { return operator[]( D <= E ? I[D-1] : 0 )( I ); }


template <typename T> inline const T& MultivariablePolynomial<T,0>::operator[]( const int& i ) const { return i == 0 ? m_t : const_zero(); }
template <typename T> inline T& MultivariablePolynomial<T,0>::operator[]( const int& i ) { return m_t; }

template <typename T , int D>
const MultivariablePolynomial<T,D-1>& MultivariablePolynomial<T,D>::operator[]( const int& i ) const
{

  if( m_size <= i ){

    return MultivariablePolynomial<T,D-1>::zero();

  }
  
  return m_f[i];

}

template <typename T , int D> inline MultivariablePolynomial<T,D-1>& MultivariablePolynomial<T,D>::operator[]( const int& i )
{

  m_no_redundant_zero = false;
  const MultivariablePolynomial<T,D-1>& z = MultivariablePolynomial<T,D-1>::zero();

  while( m_size <= i ){

    m_f.push_back( z );
    m_size++;
    
  }

  return m_f[i];

}

template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator+=( const T& t ) { m_t += t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator+=( const MultivariablePolynomial<T,0>& t ) { return operator+=( t.m_t ); }
template <typename T , int D> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator+=( const T& t ) { operator[]( 0 ) += t; return *this; }
template <typename T , int D> template <int E> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator+=( const MultivariablePolynomial<T,E>& f ) { operator[]( 0 ) += f; return *this; }

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator+=( const MultivariablePolynomial<T,D>& f )
{

  for( int i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) += f.m_f[i];

  }

  return *this;

}

template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator-=( const T& t ) { m_t -= t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator-=( const MultivariablePolynomial<T,0>& t ) { return operator-=( t.m_t ); }
template <typename T , int D> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator-=( const T& t ) { operator[]( 0 ) -= t; return *this; }
template <typename T , int D> template <int E> inline MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator-=( const MultivariablePolynomial<T,E>& f ) { operator[]( 0 ) -= f; return *this; }

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator-=( const MultivariablePolynomial<T,D>& f )
{

  for( int i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) -= f.m_f[i];

  }

  return *this;

}

template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator*=( const T& t ) { m_t *= t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator*=( const MultivariablePolynomial<T,0>& t ) { return operator*=( t.m_t ); }

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator*=( const T& t )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 || t == MultivariablePolynomial<T,0>::const_one() ){

    return *this;

  }

  if( t == MultivariablePolynomial<T,0>::const_zero() ){

    return operator=( zero() );

  }
  
  for( int i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= t;

  }

  // T‚ª‘Ì‚Å‚ ‚éê‡‚ÍÈ—ª‰Â”\
  RemoveRedundantZero();
  return *this;

}

template <typename T , int D> template <int E>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator*=( const MultivariablePolynomial<T,E>& f )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 ){

    return *this;

  }

  if( f == MultivariablePolynomial<T,E>::zero() ){

    return operator=( zero() );

  }

  for( int i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= f;

  }

  RemoveRedundantZero();
  return *this;

}

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator*=( const MultivariablePolynomial<T,D>& f )
{
  
  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 ){

    return *this;

  }

  if( f.m_size == 0 ){

    return operator=( zero() );

  }
  
  const int size = m_size + f.m_size - 1;
  MultivariablePolynomial<T,D> product{};  
      
  for( int i = 0 ; i < size ; i++ ){

    MultivariablePolynomial<T,D-1>& product_i = product[i];
    const int j_min = m_size <= i ? i - m_size + 1 : 0;
    const int j_lim = i < f.m_size ? i + 1 : f.m_size;
      
    for( int j = j_min ; j < j_lim ; j++ ){
	
      product_i += m_f[i - j] * f.m_f[j];

    }

  }

  product.RemoveRedundantZero();
  return operator=( product );

}

template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator/=( const T& t ) { m_t /= t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator/=( const MultivariablePolynomial<T,0>& t ) { return operator/=( t.m_t ); }

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator/=( const T& t )
{
  
  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }
  
  for( int i = 0 ; i < m_size ; i++ ){

    operator[]( i ) /= t;

  }

  // T‚ª‘Ì‚Å‚ ‚éê‡‚ÍÈ—ª‰Â”\
  RemoveRedundantZero();
  return *this;

}

template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator%=( const T& t ) { m_t %= t; return *this; }
template <typename T> inline MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::operator%=( const MultivariablePolynomial<T,0>& t ) { return operator%=( t.m_t ); }

template <typename T , int D>
MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::operator%=( const T& t )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  for( int i = 0 ; i < m_size ; i++ ){

    operator[]( i ) %= t;

  }

  RemoveRedundantZero();
  return *this;

}

template <typename T> inline const int& MultivariablePolynomial<T,0>::size() const noexcept { static const int z = 0; return z; }
template <typename T , int D> inline const int& MultivariablePolynomial<T,D>::size() const noexcept { return m_size; }

template <typename T> inline void MultivariablePolynomial<T,0>::RemoveRedundantZero() const noexcept {}

template <typename T , int D>
void MultivariablePolynomial<T,D>::RemoveRedundantZero()
{

  if( m_no_redundant_zero ){
    
    return;

  }
  
  const MultivariablePolynomial<T,D-1>& z = MultivariablePolynomial<T,D-1>::zero();
  
  while( m_size > 0 ? m_f[m_size - 1] == z : false ){

    m_f.pop_back();
    m_size--;

  }

  m_no_redundant_zero = true;
  return;

}

template <typename T> inline void MultivariablePolynomial<T,0>::RecursivelyRemoveRedundantZero() const noexcept {}

template <typename T , int D>
void MultivariablePolynomial<T,D>::RecursivelyRemoveRedundantZero()
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }
  
  for( int i = 0 ; i < m_size ; i++ ){

    m_f[i].RecursivelyRemoveRedundantZero();
    
  }

  return;

}

template <typename T> inline string MultivariablePolynomial<T,0>::Display() const noexcept { return to_string( m_t ); }

template <typename T , int D>
string MultivariablePolynomial<T,D>::Display() const noexcept
{

  string s = "(";

  if( m_size > 0 ){

    s += m_f[0].Display();

    for( int i = 1 ; i < m_size ; i++ ){

      s += "," + m_f[i].Display();

    }

  }

  s += ")";
  return s;

}


template <typename T> inline const MultivariablePolynomial<T,0>& MultivariablePolynomial<T,0>::zero() { static const MultivariablePolynomial<T,0> z{}; return z; }
template <typename T , int D> inline const MultivariablePolynomial<T,D>& MultivariablePolynomial<T,D>::zero() { static const MultivariablePolynomial<T,D> z{}; return z; }

template <typename T> inline const T& MultivariablePolynomial<T,0>::const_zero() { static const T z{ 0 }; return z; }
template <typename T> inline const T& MultivariablePolynomial<T,0>::const_one() { static const T o{ 1 }; return o; }



template <typename T> inline bool operator==( const MultivariablePolynomial<T,0>& f0 , const T& t1 ) { return f0[0] == t1; }
template <typename T> inline bool operator==( const MultivariablePolynomial<T,0>& f0 , const MultivariablePolynomial<T,0>& f1 ) { return f0[0] == f1[0]; }
template <typename T , int D>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const T& t1 )
{

  const int& size = f0.size();
  const MultivariablePolynomial<T,D-1>& zero = MultivariablePolynomial<T,D-1>::zero();

  for( int i = 1 ; i < size ; i++ ){

    if( f0[i] != zero ){

      return false;

    }

  }

  return f0[0] == t1;

}

template <typename T , int D , int E>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,E>& f1 )
{

  const int& size = f0.size();
  const MultivariablePolynomial<T,D-1>& zero = MultivariablePolynomial<T,D-1>::zero();

  for( int i = 1 ; i < size ; i++ ){

    if( f0[i] != zero ){

      return false;

    }

  }

  return f0[0] == f1;

}

template <typename T , int D>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 )
{

  const int& size0 = f0.size();
  const int& size1 = f1.size();
  const int& size = size0 < size1 ? size1 : size0;

  for( int i = 0 ; i < size ; i++ ){

    if( f0[i] != f1[i] ){

      return false;

    }

  }

  return true;

}

template <typename T , int D , typename P> inline bool operator!=( const MultivariablePolynomial<T,D>& f0 , const P& f1 ) { return !( f0 == f1 ); }

template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator+( const MultivariablePolynomial<T,D>& f0 , const P& f1 ) { MultivariablePolynomial<T,D> f = f0; f += f1; return f; }
template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator-( const MultivariablePolynomial<T,D>& f0 , const P& f1 ) { MultivariablePolynomial<T,D> f = f0; f -= f1; return f; }
template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator*( const MultivariablePolynomial<T,D>& f0 , const P& f1 ) { MultivariablePolynomial<T,D> f = f0; f *= f1; return f; }
template <typename T , int D> inline MultivariablePolynomial<T,D> operator/( const MultivariablePolynomial<T,D>& f0 , const T& t1 ) { MultivariablePolynomial<T,D> f = f0; f /= t1; return f; }
template <typename T , int D> inline MultivariablePolynomial<T,D> operator%( const MultivariablePolynomial<T,D>& f0 , const T& t1 ) { MultivariablePolynomial<T,D> f = f0; f %= t1; return f; }
