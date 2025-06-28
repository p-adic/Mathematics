// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/Dual/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDualBIT( ABELIAN_GROUP M , const int& X , const int& Y ) : m_M( move( M ) ) , m_fenwick( m_M , X , Y ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDualBIT( ABELIAN_GROUP M , vector<vector<U>> a ) : m_M( move( M ) ) , m_fenwick( m_M )
{
  
  const int m_X = a.size();
  const int m_Y = m_X == 0 ? 0 : a[0].size();

  for( int x = m_X ; x >= 0 ; x-- ){

    if( x > 0 ){
      
      for( int y = m_Y ; y >= 0 ; y-- ){

        a[x][y] = m_M.Sum( move( a[x][y] ) , m_M.Inverse( a[x-1][y] ) );

      }

    }
  
    for( int y = m_Y ; y > 0 ; y-- ){

      a[x][y] = m_M.Sum( move( a[x][y] ) , m_M.Inverse( a[x][y-1] ) );

    }

  }

  m_fenwick.Initialise( move( a ) );

}


template <typename U> template <typename...Args> inline TwoDimensionalDualBIT<U>::TwoDimensionalDualBIT( Args&&... args ) : AbstractTwoDimensionalDualBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<Args>( args )... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::Initialise( Args&&... args ) { AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP> temp{ m_M , forward<Args>( args )... }; m_fenwick = move( temp.m_fenwick ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::Set( const int& x , const int& y , const U& u ) { Add( x , y , m_M.Sum( m_M.Inverse( Get( x , y ) ) , u ) ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::Add( const int& x , const int& y , const U& u ) { IntervalAdd( x , x , y , y ); }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u )
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

  if( x_final + 1 < X && y_final + 1 < m_Y ){

    m_fenwick.Add( x_final + 1 , y_final + 1 , u );

  }
  
  if( x_final + 1 < m_X ){

    m_fenwick.Add( x_final + 1 , y_start , u_inv );

  }
  
  if( y_final + 1 < m_Y ){

    m_fenwick.Add( x_start , y_final + 1 , u_inv );

  }
  
  m_fenwick.Add( x_start , y_start , u );
  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::X() const noexcept { return m_fenwick.X(); }
template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::Y() const noexcept { return m_fenwick.Y(); }

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>::Get( const int& x , const int& y ) { assert( 0 <= x && x < X() && 0 <= y && y < Y() ); return m_fenwick.InitialRectangleSum( x , y ); }

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( int x = 0 ; x < X ; x++ ){ for( int y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
