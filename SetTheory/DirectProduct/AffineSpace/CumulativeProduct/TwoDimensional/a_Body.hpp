// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/TCumulativeProduct/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename ABELIAN_GROUP , typename U> template <typename T>
AbstractTwoDimensionalCumulativeSum<ABELIAN_GROUP,U>::AbstractTwoDimensionalCumulativeSum( ABELIAN_GROUP M , const vector<vector<T>>& a ) :
  m_M( move( M ) ) , m_size_X( a.size() ) , m_size_Y() , m_a( m_size_X + 1 )
{

  static_assert( ! is_same<U,int>::value );
  const U& zero = M.Zero();

  if( ! a.empty() ){

    m_size_Y = a[0].size();

  }

  m_a[0] = vector<U>( m_size_Y + 1 , zero );

  for( int x = 0 ; x < m_size_X ; x++ ){

    const vector<T>& a_x = a[x];
    const vector<U>& m_a_x_minus = m_a[x];
    vector<U>& m_a_x = m_a[x+1];
    m_a_x = vector<U>( m_size_Y + 1 , zero );
    U temp = zero;

    for( int y = 0 ; y < m_size_Y ; y++ ){

      m_a_x[y+1] = m_M.Sum( m_a_x_minus[y+1] , temp = m_M.Sum( move( temp ) , a_x[y] ) );

    }

  }

}

template <typename U> template <typename T> inline TwoDimensionalCumulativeSum<U>::TwoDimensionalCumulativeSum( const vector<vector<T>>& a ) : AbstractTwoDimensionalCumulativeSum<AdditiveGroup<U>>( AdditiveGroup<U>() , a ) {}

template <typename ABELIAN_GROUP , typename U> template <typename...Args> inline void AbstractTwoDimensionalCumulativeSum<ABELIAN_GROUP,U>::Initialise( const Args&... args ) { *this = AbstractTwoDimensionalCumulativeSum<ABELIAN_GROUP,U>( move( m_M ) , args... ); }

template <typename ABELIAN_GROUP , typename U> inline const U& AbstractTwoDimensionalCumulativeSum<ABELIAN_GROUP,U>::InitialRectangleSum( const int& i_x , const int& i_y ) const { assert( -1 <= i_x && i_x < m_size_X && -1 <= i_y && i_y < m_size_Y ); return m_a[i_x+1][i_y+1]; }

template <typename ABELIAN_GROUP , typename U> inline U AbstractTwoDimensionalCumulativeSum<ABELIAN_GROUP,U>::RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y ) { assert( 0 <= i_start_x && i_start_x - 1 <= i_final_x && i_final_x < m_size_X && 0 <= i_start_y && i_start_y - 1 <= i_final_y && i_final_y < m_size_Y ); return m_M.Sum( m_M.Sum( m_a[i_start_x][i_start_y] , m_M.Inverse( m_M.Sum( m_a[i_final_x+1][i_start_y] , m_a[i_start_x][i_final_y+1] ) ) ) , m_a[i_final_x+1][i_final_y+1] ); }
