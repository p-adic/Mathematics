// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const int& X , const int& Y ) : m_M( move( M ) ) , m_X( X ) , m_Y( Y ) , m_fenwick( m_X + 1 , vector( m_Y + 1 , m_M.Zero() ) ) { static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> ); }
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const vector<vector<U>>& a ) : m_M( move( M ) ) , m_X( a.size() ) , m_Y( m_X == 0 ? 0 : a[0].size() ) , m_fenwick( m_X + 1 , vector( m_Y + 1 , m_M.Zero() ) )
{

  static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> );
  vector temp( m_X , vector<U>( m_Y + 1 , m_M.Zero() ) );

  for( int i = 1 ; i <= m_X ; i++ ){

    const int x = i - 1;
    assert( int( a[x].size() ) == m_Y );

    for( int j = 1 ; j <= m_Y ; j++ ){

      int y = j - 1;
      const int y_lim = j - ( j & -j );
      m_fenwick[i][j] = a[x][y];

      while( y > y_lim ){
      
        m_fenwick[i][j] = m_M.Sum( move( m_fenwick[i][j] ) , m_fenwick[i][y] );
        y -= ( y & -y );
        
      }

    }

  }

  for( int i = 1 ; i <= m_X ; i++ ){

    int x = i - 1;
    const int x_lim = i - ( i & -i );

    while( x > x_lim ){

      for( int j = 1 ; j <= m_Y ; j++ ){

        m_fenwick[i][j] = m_M.Sum( move( m_fenwick[i][j] ) , m_fenwick[x][j] );

      }

      x -= ( x & -x );
      
    }

  }

}

template <typename U> template <typename...Args> inline TwoDimensionalBIT<U>::TwoDimensionalBIT( const Args&... args ) : AbstractTwoDimensionalBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , args... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Initialise( const Args&... args ) { AbstractTwoDimensionalBIT<U,ABELIAN_GROUP> temp{ m_M , args... }; m_X = temp.m_X; m_Y = temp.m_Y; m_fenwick = move( temp.m_fenwick ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Set( const int& x , const int& y , const U& u ) { Add( x , y , m_M.Sum( m_M.Inverse( Get( x , y ) ) , u ) ); }

template <typename U , typename ABELIAN_GROUP>
void AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Add( const int& x , const int& y , const U& u )
{
  
  int i = x + 1;

  while( i <= m_X ){

    auto& fenwick_i = m_fenwick[i];
    int j = y + 1;

    while( j <= m_Y ){

      U& fenwick_ij = fenwick_i[j];
      fenwick_ij = m_M.Sum( move( fenwick_ij ) , u );
      j += ( j & -j );

    }

    i += ( i & -i );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::X() const noexcept { return m_X; }
template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Y() const noexcept { return m_Y; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Get( const int& x , const int& y ) { assert( 0 <= x && x < m_X && 0 <= y && y < m_Y ); return RectangleSum( x , x , y , y ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::LSBRectangleSum( const int& i , const int& j ) const { assert( 0 < i && i <= m_X && 0 < j && j <= m_Y ); return m_fenwick[i][j]; }

template <typename U , typename ABELIAN_GROUP> 
U AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::InitialRectangleSum( const int& x_final , const int& y_final )
{

  U sum = m_M.Zero();
  int i = min( x_final + 1 , m_X );

  while( i > 0 ){

    auto& fenwick_i = m_fenwick[i];
    int j = min( y_final + 1 , m_Y );

    while( j > 0 ){

      sum = m_M.Sum( move( sum ) , fenwick_i[j] );
      j -= ( j & -j );
    
    }

    i -= ( i & -i );
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::RectangleSum( int x_start , int x_final , int y_start , int y_final ) { x_start = max( 0 , x_start ); x_final = min( m_X - 1 , x_final ); y_start = max( 0 , y_start ); y_final = min( m_Y - 1 , y_final ); return x_start <= x_final && y_start <= y_final ? m_M.Sum( m_M.Sum( InitialRectangleSum( x_start - 1 , y_start - 1 ) , m_M.Inverse( InitialRectangleSum( x_final , y_start - 1 ) ) ) , m_M.Sum( m_M.Inverse( InitialRectangleSum( x_start - 1 , y_final ) ) , InitialRectangleSum( x_final , y_final ) ) ) : m_M.Zero(); }

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( int x = 0 ; x < X ; x++ ){ for( int y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
