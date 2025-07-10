// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <typename U , typename MONOID> template <typename...Args> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , const int& N , const Args&... args ) : SqrtDecompositionCoordinate( N , args... ) , m_M( move( M ) ) , m_a( m_N_m , m_M.Zero() ) , m_b( m_N_d , m_M.Zero() ) , m_updated( m_N_d , false ) { static_assert( is_same_v<U,inner_t<MONOID>> ); }
template <typename U , typename MONOID> template <typename...Args> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , vector<U> a , const Args&... args ) : SqrtDecompositionCoordinate( a.size() , args... ) , m_M( move( M ) ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() ) , m_updated( m_N_d , false ) { static_assert( is_same_v<U,inner_t<MONOID>> ); m_a.resize( m_N_m , m_M.One() ); }

template <typename U , typename MONOID> template <typename...Args> inline void MonoidSqrtDecomposition<U,MONOID>::Initialise( Args&&... args ) { MonoidSqrtDecomposition<U,MONOID> temp{ m_M , forward<Args>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); m_updated = move( temp.m_updated ); }

template <typename U , typename MONOID> inline void MonoidSqrtDecomposition<U,MONOID>::Set( const int& i , const U& u ) { const int d = i / m_N_sqrt; m_a[i] = u; m_updated[d] = true; }

template <typename U , typename MONOID> inline const U& MonoidSqrtDecomposition<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_N ); return m_a[i]; }
template <typename U , typename MONOID> inline const U& MonoidSqrtDecomposition<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }
template <typename U , typename MONOID> inline const U& MonoidSqrtDecomposition<U,MONOID>::BucketProduct( const int& d ) { if( m_updated[d] ){ ComputeProduct( d ); } return m_b[d]; }

template <typename U , typename MONOID> inline U MonoidSqrtDecomposition<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  U answer = m_M.One();
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Product( move( answer ) , BucketProduct( d ) );

  }

  for( int i = i_1 ; i < i_ulim ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }

  return answer;
  
}

template <typename U , typename MONOID> template <typename F , SFINAE_FOR_SD_S> inline int MonoidSqrtDecomposition<U,MONOID>::Search( const int& i_start , const F& f , const bool& reversed ) { return reversed ? SearchReverse_Body( i_start , f , m_M.Zero() ) : Search_Body( i_start , f , m_M.Zero() ); }
template <typename U , typename MONOID> inline int MonoidSqrtDecomposition<U,MONOID>::Search( const int& i_start , const U& u , const bool& reversed ) { return Search( i_start , [&]( const U& product , const int& ){ return !( product < u ); } , reversed ); }

template <typename U , typename MONOID> template <typename F> int MonoidSqrtDecomposition<U,MONOID>::Search_Body( const int& i_start , const F& f , U product_temp )
{

  const int i_min = max( i_start , 0 );
  const int d_0 = i_min / m_N_sqrt + 1;
  const int i_0 = min( d_0 * m_N_sqrt , m_N );
  
  for( int i = i_min ; i < i_0 ; i++ ){

    product_temp = m_M.Product( move( product_temp ) , m_a[i] );

    if( f( product_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_0 ; d < m_N_d ; d++ ){

    U product_next = m_M.Product( product_temp , BucketProduct( d ) );

    if( f( product_next , min( ( d + 1 ) * m_N_sqrt , m_N ) - 1 ) ){

      return Search_Body( d * m_N_sqrt , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}

template <typename U , typename MONOID> template <typename F> int MonoidSqrtDecomposition<U,MONOID>::SearchReverse_Body( const int& i_final , const F& f , U product_temp )
{

  const int i_max = min( i_final , m_N - 1 );
  const int d_1 = i_max / m_N_sqrt;
  const int i_1 = max( d_1 * m_N_sqrt , 0 );
  
  for( int i = i_max ; i >= i_1 ; i-- ){

    product_temp = m_M.Product( m_a[i] , product_temp );

    if( f( product_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_1 - 1 ; d >= 0 ; d-- ){

    U product_next = m_M.Product( BucketProduct( d ) , product_temp );

    if( f( product_next , d * m_N_sqrt ) ){
      
      return Search_Body( ( d + 1 ) * m_N_sqrt - 1 , f , move( product_temp ) );

    }

    product_temp = move( product_next );
    
  }

  return -1;

}

template <typename U , typename MONOID> void MonoidSqrtDecomposition<U,MONOID>::ComputeProduct( const int& d )
{
  
  int i_min = d * m_N_sqrt;
  int i_ulim = i_min + m_N_sqrt;
  U& m_bd = m_b[d] = m_M.One();
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    m_bd = m_M.Product( move( m_bd ) , m_a[i] );

  }

  m_updated[d] = false;
  return;

}
