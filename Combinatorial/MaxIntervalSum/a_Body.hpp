// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/MaxIntervalSum/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Arithmetic/Iteration/a_Body.hpp"

template <typename T> inline MaxIntervalSum<T>::MaxIntervalSum( const vector<T>& A ) : m_size( A.size() ) , m_is( m_size + 1 ) , m_fs( m_size + 1 ) , m_mis( m_size ) , m_mfs( m_size )
{

  for( int i = 0 ; i < m_size ; i++ ){

    m_is[i+1] = m_is[i] + A[i];

  }

  m_mis[m_size-1] = m_is[m_size];

  for( int i = m_size - 2 ; i >= 0 ; i-- ){

    m_mis[i] = max( m_mis[i+1] , m_is[i+1] );

  }

  for( int i = m_size - 1 ; i >= 0 ; i-- ){

    m_fs[i] = m_fs[i+1] + A[i];

  }

  m_mfs[0] = m_fs[0];

  for( int i = 1 ; i < m_size ; i++ ){

    m_mfs[i] = max( m_mfs[i-1] , m_fs[i] );

  }

}

template <typename T> inline const int& MaxIntervalSum<T>::size() const noexcept { return m_size; }

template <typename T> inline const T& MaxIntervalSum<T>::InitialSegmentSum( const int& r ) const { assert( 0 <= r && r < m_size ); return m_is[r+1]; }
template <typename T> inline const T& MaxIntervalSum<T>::FinalSegmentSum( const int& l ) const { assert( 0 <= l && l < m_size ); return m_fs[l]; }
template <typename T> inline T MaxIntervalSum<T>::IntervalSum( const int& l , const int& r ) const { assert( 0 <= l && l <= r + 1 && 0 <= r && r < m_size ); return m_is[r+1] - m_is[l]; }

template <typename T> inline const T& MaxIntervalSum<T>::InitialSegmentSumMax( const int& r ) const { assert( 0 <= r && r < m_size ); return m_mis[r]; }
template <typename T> inline const T& MaxIntervalSum<T>::FinalSegmentSumMax( const int& l ) const { assert( 0 <= l && l < m_size ); return m_mfs[l]; }
template <typename T> inline T MaxIntervalSum<T>::PointedIntervalSumMax( const int& i ) const { assert( 0 <= i && i < m_size ); return m_mfs[i] - m_fs[i+1] + m_mis[i] - m_is[i+1] ; }
template <typename T> inline T MaxIntervalSum<T>::IntervalSumMax() const { T answer = m_fs[0]; for( int i = 0 ; i < m_size ; i++ ){ SetMax( answer , PointedIntervalSumMax( i ) ); } return answer; }
