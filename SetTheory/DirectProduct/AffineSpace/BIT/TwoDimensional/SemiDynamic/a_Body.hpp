// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/SemiDynamic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalSemiDynamicBIT( ABELIAN_GROUP M , const int& X , const ll& Y ) : m_M( move( M ) ) , m_X( X ) , m_Y( Y ) , m_fenwick( m_X + 1 ) { static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> ); }

template <typename U> inline TwoDimensionalSemiDynamicBIT<U>::TwoDimensionalSemiDynamicBIT( const int& X , const ll& Y ) : AbstractTwoDimensionalSemiDynamicBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , X , Y ) {}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Access( const int& i , const ll& j , U u ) noexcept { if( m_fenwick[i].count( j ) > 0 ){ u = m_M.Sum( move( u ) , m_fenwick[i][j] ); } return move( u ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Replace( const int& i , const ll& j , U u ) noexcept { if( u == m_M.Zero() ){ m_fenwick[i].erase( j ); } else { m_fenwick[i][j] = move( u ); } }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Initialise( const int& X , const ll& Y ) { m_X = X; m_Y = Y; m_fenwick = vector<Map<ll,U>>( m_X + 1 ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Set( const int& x , const ll& y , const U& u ) { Add( x , y , m_M.Sum( m_M.Inverse( Get( x , y ) ) , u ) ); }

template <typename U , typename ABELIAN_GROUP>
void AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Add( const int& x , const ll& y , const U& u )
{
  
  int i = x + 1;

  while( i <= m_X ){

    ll j = y + 1;

    while( j <= m_Y ){

      Replace( i , j , Access( i , j , u ) );
      j += ( j & -j );

    }

    i += ( i & -i );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::X() const noexcept { return m_X; }
template <typename U , typename ABELIAN_GROUP> inline const ll& AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Y() const noexcept { return m_Y; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::Get( const int& x , const ll& y ) { assert( 0 <= x && x < m_X && 0 <= y && y < m_Y ); return RectangleSum( x , x , y , y ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::LSBRectangleSum( const int& i , const ll& j ) const { assert( 0 < i && i <= m_X && 0 < j && j <= m_Y ); return Access( i , j , m_M.Zero() ); }

template <typename U , typename ABELIAN_GROUP> 
U AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::InitialRectangleSum( const int& x_final , const ll& y_final )
{

  U sum = m_M.Zero();
  int i = min( x_final + 1 , m_X );

  while( i > 0 ){

    ll j = min( y_final + 1 , m_Y );

    while( j > 0 ){

      sum = Access( i , j , move( sum ) );
      j -= ( j & -j );
    
    }

    i -= ( i & -i );
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>::RectangleSum( int x_start , int x_final , ll y_start , ll y_final ) { x_start = max( 0 , x_start ); x_final = min( m_X - 1 , x_final ); y_start = max( 0LL , y_start ); y_final = min( m_Y - 1 , y_final ); return x_start <= x_final && y_start <= y_final ? m_M.Sum( m_M.Sum( InitialRectangleSum( x_start - 1 , y_start - 1 ) , m_M.Inverse( InitialRectangleSum( x_final , y_start - 1 ) ) ) , m_M.Sum( m_M.Inverse( InitialRectangleSum( x_start - 1 , y_final ) ) , InitialRectangleSum( x_final , y_final ) ) ) : m_M.Zero(); }

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( int x = 0 ; x < X ; x++ ){ for( ll y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
