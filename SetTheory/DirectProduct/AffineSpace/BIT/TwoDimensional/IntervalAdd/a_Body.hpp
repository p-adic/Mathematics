// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename U , typename Z_MODULE> inline AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , const int& X , const int& Y ) : m_M( move( M ) ) , m_bit00( m_M , X , Y ) , m_bit01( m_M , X , Y ) , m_bit10( m_M , X , Y ) , m_bit11( m_M , X , Y ) {}
template <typename U , typename Z_MODULE> inline AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , vector<vector<U>> a ) : m_M( move( M ) ) , m_bit00( m_M ) , m_bit01( m_M ) , m_bit10( m_M ) , m_bit11( m_M )
{

  const int m_X = a.size();
  const int m_Y = m_X == 0 ? 0 : a[0].size();
  auto da = a;

  for( int x = m_X - 1 ; x >= 0 ; x-- ){

    if( x > 0 ){
      
      for( int y = 0 ; y < m_Y ; y++ ){

        a[x][y] = m_M.Sum( move( a[x][y] ) , m_M.Inverse( a[x-1][y] ) );

      }

      da[x] = a[x];

    }

    for( int y = m_Y - 1 ; y > 0 ; y-- ){

      a[x][y] = m_M.Sum( move( a[x][y] ) , m_M.Inverse( a[x][y-1] ) );

    }

  }

  m_bit00.Initialise( a );

  for( int x = 0 ; x < m_X ; x++ ){
  
    for( int y = 1 ; y < m_Y ; y++ ){

      a[x][y] = m_M.ScalarProduct( 1 - y , move( a[x][y] ) );

    }

  }

  m_bit01.Initialise( a );

  for( int x = 0 ; x < m_X ; x++ ){

    if( x > 0 ){
  
      for( int y = 0 ; y < m_Y ; y++ ){

        da[x][y] = m_M.ScalarProduct( 1 - x , move( da[x][y] ) );

      }

    }

    for( int y = m_Y - 1 ; y > 0 ; y-- ){

      da[x][y] = m_M.Sum( move( da[x][y] ) , m_M.Inverse( da[x][y-1] ) );

    }

  }

  m_bit10.Initialise( da );

  for( int x = 0 ; x < m_X ; x++ ){
  
    for( int y = 1 ; y < m_Y ; y++ ){

      da[x][y] = m_M.ScalarProduct( 1 - y , move( da[x][y] ) );

    }

  }

  m_bit11.Initialise( da );

}

template <typename U> template <typename...Args> inline TwoDimensionalIntervalAddBIT<U>::TwoDimensionalIntervalAddBIT( Args&&... args ) : AbstractTwoDimensionalIntervalAddBIT<U,Module<int,U>>( Module<int,U>() , forward<Args>( args )... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::Initialise( Args&&... args ) { AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE> temp{ m_M , forward<Args>( args )... }; m_bit00 = move( temp.m_bit00 ); m_bit01 = move( temp.m_bit01 ); m_bit10 = move( temp.m_bit10 ); m_bit11 = move( temp.m_bit11 ); }
template <typename U , typename Z_MODULE> inline void AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::Set( const int& x , const int& y , const U& u ) { Add( x , y , m_M.Sum( m_M.Inverse( Get( x , y ) ) , u ) ); }
template <typename U , typename Z_MODULE> inline void AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::Add( const int& x , const int& y , const U& u ) { IntervalAdd( x , x , y , y ); }

template <typename U , typename Z_MODULE> inline void AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u )
{

  auto& m_X = X();
  auto& m_Y = Y();
  x_start = max( 0 , x_start );
  x_final = min( m_X - 1 , x_final );
  y_start = max( 0 , y_start );
  y_final = min( m_Y - 1 , y_final );

  if( x_start > x_final || y_start > y_final ){

    return;

  }

  const U u_inv = m_M.Inverse( u );

  if( x_final + 1 < m_X && y_final + 1 < m_Y ){

    m_bit00.Add( x_final + 1 , y_final + 1 , u );
    m_bit01.Add( x_final + 1 , y_final + 1 , m_M.ScalarProduct( y_final , u_inv ) );
    m_bit10.Add( x_final + 1 , y_final + 1 , m_M.ScalarProduct( x_final , u_inv ) );
    m_bit11.Add( x_final + 1 , y_final + 1 , m_M.ScalarProduct( x_final * y_final , u ) );

  }
  
  if( x_final + 1 < m_X ){

    m_bit00.Add( x_final + 1 , y_start , u_inv );
    m_bit01.Add( x_final + 1 , y_start , m_M.ScalarProduct( y_start - 1 , u ) );
    m_bit10.Add( x_final + 1 , y_start , m_M.ScalarProduct( x_final , u ) );
    m_bit11.Add( x_final + 1 , y_start , m_M.ScalarProduct( x_final * ( y_start - 1 ) , u_inv ) );

  }
  
  if( y_final + 1 < m_Y ){

    m_bit00.Add( x_start , y_final + 1 , u_inv );
    m_bit01.Add( x_start , y_final + 1 , m_M.ScalarProduct( y_final , u ) );
    m_bit10.Add( x_start , y_final + 1 , m_M.ScalarProduct( x_start - 1 , u ) );
    m_bit11.Add( x_start , y_final + 1 , m_M.ScalarProduct( ( x_start - 1 ) * y_final , u_inv ) );

  }
  
  m_bit00.Add( x_start , y_start , u );
  m_bit01.Add( x_start , y_start , m_M.ScalarProduct( y_start - 1 , u_inv ) );
  m_bit10.Add( x_start , y_start , m_M.ScalarProduct( x_start - 1 , u_inv ) );
  m_bit11.Add( x_start , y_start , m_M.ScalarProduct( ( x_start - 1 ) * ( y_start - 1 ) , u ) );
  return;
  
}

template <typename U , typename Z_MODULE> inline const int& AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::X() const noexcept { return m_bit00.X(); }
template <typename U , typename Z_MODULE> inline const int& AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::Y() const noexcept { return m_bit00.Y(); }

template <typename U , typename Z_MODULE> inline U AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::Get( const int& x , const int& y ) { assert( 0 <= x && x < X() && 0 <= y && y < Y() ); return m_bit00.InitialRectangleSum( x , y ); }
template <typename U , typename Z_MODULE> inline U AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::InitialRectangleSum( const int& x , const int& y ) { return m_M.Sum( m_M.Sum( m_bit11.InitialRectangleSum( x , y ) , m_M.ScalarProduct( x * y , m_bit00.InitialRectangleSum( x , y ) ) ) , m_M.Sum( m_M.ScalarProduct( x , m_bit01.InitialRectangleSum( x , y ) ) , m_M.ScalarProduct( y , m_bit10.InitialRectangleSum( x , y ) ) ) ); }
template <typename U , typename Z_MODULE> inline U AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>::RectangleSum( int x_start , int x_final , int y_start , int y_final ) { x_start = max( 0 , x_start ); x_final = min( X() - 1 , x_final ); y_start = max( 0 , y_start ); y_final = min( Y() - 1 , y_final ); return x_start <= x_final && y_start <= y_final ? m_M.Sum( m_M.Sum( InitialRectangleSum( x_start - 1 , y_start - 1 ) , m_M.Inverse( InitialRectangleSum( x_final , y_start - 1 ) ) ) , m_M.Sum( m_M.Inverse( InitialRectangleSum( x_start - 1 , y_final ) ) , InitialRectangleSum( x_final , y_final ) ) ) : m_M.Zero(); }

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( int x = 0 ; x < X ; x++ ){ for( int y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
