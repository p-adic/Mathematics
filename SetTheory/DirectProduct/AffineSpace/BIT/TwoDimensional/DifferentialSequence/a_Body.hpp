// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/DifferentialSequence/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP M , const int& X , const int& Y ) : AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>( move( M ) , X , Y ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP M , vector<vector<U>> a ) : AbstractTwoDimensionalDifferenceSequenceBIT( M , Differentiate( M , move( a ) ) , true ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP& M , const vector<vector<U>>& a , const bool& dummy ) : AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>( move( M ) , a ) {}

template <typename U , typename ABELIAN_GROUP>
vector<vector<U>> AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::Differentiate( ABELIAN_GROUP& M , vector<vector<U>> a )
{

  const int X = a.size();
  assert( X >= 0 );
  const int Y = a[0].size();
  assert( Y >= 0 );

  for( int x = X - 1 ; x >= 0 ; x-- ){

    if( x > 0 ){
      
      for( int y = Y - 1 ; y >= 0 ; y-- ){

        a[x][y] = M.Sum( move( a[x][y] ) , M.Inverse( a[x-1][y] ) );

      }

    }
  
    for( int y = Y - 1 ; y > 0 ; y-- ){

      a[x][y] = M.Sum( move( a[x][y] ) , M.Inverse( a[x][y-1] ) );

    }

  }

  return move( a );

}


template <typename U> template <typename...Args> inline TwoDimensionalDifferenceSequenceBIT<U>::TwoDimensionalDifferenceSequenceBIT( Args&&... args ) : AbstractTwoDimensionalDifferenceSequenceBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<Args>( args )... ) {}

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>& AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::operator=( AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>&& bit ) { AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>& ref = *this; ref = bit; return *this; }
template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::Initialise( Args&&... args ) { return *this = AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>{ move( this->m_M ) , forward<Args>( args )... }; }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::Set( const int& x , const int& y , const U& u ) { Add( x , y , this->m_M.Sum( this->m_M.Inverse( Get( x , y ) ) , u ) ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::Add( const int& x , const int& y , const U& u ) { IntervalAdd( x , x , y , y ); }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u )
{

  x_start = max( 0 , x_start );
  x_final = min( this->m_X - 1 , x_final );
  y_start = max( 0 , y_start );
  y_final = min( this->m_Y - 1 , y_final );

  if( x_start > x_final || y_start > y_final ){

    return;

  }

  const U u_inv = this->m_M.Inverse( u );

  if( x_final + 1 < this->m_X && y_final + 1 < this->m_Y ){

    AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Add( x_final + 1 , y_final + 1 , u );

  }
  
  if( x_final + 1 < this->m_X ){

    AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Add( x_final + 1 , y_start , u_inv );

  }
  
  if( y_final + 1 < this->m_Y ){

    AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Add( x_start , y_final + 1 , u_inv );

  }
  
  AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>::Add( x_start , y_start , u );
  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>::Get( const int& x , const int& y ) { assert( 0 <= x && x < this->m_X && 0 <= y && y < Ym_Y ); return this->InitialRectangleSum( x , y ); }

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( int x = 0 ; x < X ; x++ ){ for( int y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
