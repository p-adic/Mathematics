// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DigitConcatenation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Vector/a_Body.hpp"

template <typename T> inline DigitConcatenationString<T>::DigitConcatenationString( ll n , const ll& base ) : DigitConcatenationString( DigitExpansion( move( n ) , base ) , 0LL , base ) {}

template <typename T> template <template <typename...> typename VEC , typename U> inline DigitConcatenationString<T>::DigitConcatenationString( VEC<U> a , const U& zero , T base ) : m_base( move( base ) ) , m_length() , m_sub( 1 ) , m_power( 1 ) , m_power_lsum() , m_power_sum( 1 ) , m_val() , m_lsum() , m_rsum() , m_csum() , m_sum()
{

  if( !a.empty() ){

    m_length = 1;
    m_sub = 2;
    m_power = m_power_lsum = m_base;
    m_power_sum = m_base + 1;
    m_val = m_lsum = m_rsum = m_csum = m_sum = pop( a ) - zero;
    *this = DigitConcatenationString<T>( move( a ) , zero , m_base ) * *this;

  }
  
}

template <typename T>
DigitConcatenationString<T>& DigitConcatenationString<T>::operator*=( const DigitConcatenationString<T>& n )
{

  assert( m_base == n.m_base );
  // 先に*=で処理すると*this *= *thisを行う際に問題が生じる。
  m_sum = m_sum * m_power_sum + m_sub * n.m_sum;
  m_csum += n.m_csum + m_rsum * n.m_power_lsum + m_length * n.m_lsum;
  // 先に*=で処理すると*this *= *thisを行う際に問題が生じる。
  m_rsum = m_rsum * n.m_power + m_length * n.m_val + n.m_rsum;
  m_lsum += m_val * n.m_power_lsum + n.m_lsum;
  // 先に*=で処理すると*this *= *thisを行う際に問題が生じる。
  m_val = m_val * n.m_power + n.m_val;
  m_power_sum *= n.m_power_sum;
  m_power_lsum += m_power * n.m_power_lsum;
  m_power *= n.m_power;
  m_sub *= n.m_sub;
  m_length += n.m_length;
  return *this;

}

template <typename T> DigitConcatenationString<T> DigitConcatenationString<T>::operator*( const DigitConcatenationString<T>& n ) const { return move( DigitConcatenationString<T>{ *this } *= n ); }

template <typename T> inline const T& DigitConcatenationString<T>::val() const noexcept { return m_val; }
template <typename T> inline const T& DigitConcatenationString<T>::lsum() const noexcept { return m_lsum; }
template <typename T> inline const T& DigitConcatenationString<T>::rsum() const noexcept { return m_rsum; }
template <typename T> inline const T& DigitConcatenationString<T>::csum() const noexcept { return m_csum; }
template <typename T> inline const T& DigitConcatenationString<T>::sum() const noexcept { return m_sum; }

template <typename T>
vector<T> DigitConcatenationString<T>::DigitExpansion( ll n , const ll& base )
{

  vector<T> a{};

  if( n == 0 ){

    a = {0};

  } else {

    assert( n > 0 );
    
    while( n > 0 ){

      a <<= n % base;
      n /= base;

    }

    Reverse( a );

  }
  
  return a;

}
