// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DisjointSparseTable/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Semilattice/a_Body.hpp"

template <typename U , typename MONOID> inline AbstractDisjointSparseTable<U,MONOID>::AbstractDisjointSparseTable( MONOID M , const int& size ) : AbstractDisjointSparseTable( M , vector<U>( size , M.One() ) ) {}

template <typename U , typename MONOID> inline AbstractDisjointSparseTable<U,MONOID>::AbstractDisjointSparseTable( MONOID M , const vector<U>& a ) : m_M( move( M ) ) , m_size( a.size() ) , m_prod()
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  int digit = 1;
  
  while( m_size >= 1 << digit ){

    ++digit;

  }

  m_prod.resize( digit , vector( m_size , m_M.One() ) );

  for( int v = 0 ; v < digit ; v++ ){

    auto& m_prod_v = m_prod[v];
    int p = 1 << v , p2 = p << 1;

    for( int j = p ; j <= m_size ; j += p2 ){

      const int i_ulim = min( j + p , m_size );

      if( j < m_size ){
        
        m_prod_v[j] = a[j];
      
        for( int i = j + 1 ; i < i_ulim ; i++ ){

          m_prod_v[i] = m_M.Product( m_prod_v[i-1] , a[i] );

        }

      }

      const int i_min = j - p;
      m_prod_v[j-1] = a[j-1];
      
      for( int i = j - 2 ; i >= i_min ; i-- ){

        m_prod_v[i] = m_M.Product( a[i] , m_prod_v[i+1] );

      }

    }

  }

}

template <typename U> template <typename...Args> inline DisjointSparseTable<U>::DisjointSparseTable( const U& zero_U , const Args&... args ) : AbstractDisjointSparseTable<U,MaxSemilattice<U>>( MaxSemilattice<U>( zero_U ) , args... ) {}

template <typename U , typename MONOID> template <typename...Args> inline void AbstractDisjointSparseTable<U,MONOID>::Initialise( const Args&... args ) { *this = AbstractDisjointSparseTable( move( m_M ) , args... ); }

template <typename U , typename MONOID> inline const U& AbstractDisjointSparseTable<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return IntervalProduct( i , i ); }
template <typename U , typename MONOID> inline const U& AbstractDisjointSparseTable<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename MONOID> inline U AbstractDisjointSparseTable<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final ) { assert( 0 <= i_start && i_start <= i_final && i_final < m_size ); const int v = 31 - __builtin_clz( i_start ^ ( i_final + 1 ) ); return i_final < ( ( i_final + 1 ) >> v ) << v ? m_prod[v][i_start] : m_M.Product( m_prod[v][i_start] , m_prod[v][i_final] ); }

template <typename U> inline U DisjointSparseTable<U>::IntervalMax( const int& i_start , const int& i_final ) { return this->IntervalProduct( i_start , i_final ); }
