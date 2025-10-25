// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/Dynamic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::AbstractTwoDimensionalDynamicBIT( ABELIAN_GROUP M , const ll& X , const ll& Y ) : m_M( move( M ) ) , m_X( X ) , m_Y( Y ) , m_fenwick() { static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> ); }

template <typename U> inline TwoDimensionalDynamicBIT<U>::TwoDimensionalDynamicBIT( const ll& X , const ll& Y ) : AbstractTwoDimensionalDynamicBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , X , Y ) {}

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Access( const ll& i , const ll& j , U u ) noexcept { if( m_fenwick.count( i ) > 0 ){ auto& fenwick_i = m_fenwick.at( i ); if( fenwick_i.count( j ) > 0 ){ u = m_M.Sum( move( u ) , fenwick_i.at( j ) ); } } return move( u ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Replace( const ll& i , const ll& j , U u ) noexcept { if( u == m_M.Zero() ){ if( m_fenwick.count( i ) > 0 ){ auto& fenwick_i = m_fenwick.at( i ); fenwick_i.erase( j ); if( fenwick_i.empty() ){ m_fenwick.erase( i ); } }; } else { m_fenwick[i][j] = move( u ); } }

template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Initialise( const ll& X , const ll& Y ) { m_fenwick.clear(); m_X = X; m_Y = Y; }
template <typename U , typename ABELIAN_GROUP> inline void AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Set( const ll& x , const ll& y , const U& u ) { Add( x , y , m_M.Sum( m_M.Inverse( Get( x , y ) ) , u ) ); }

template <typename U , typename ABELIAN_GROUP>
void AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Add( const ll& x , const ll& y , const U& u )
{
  
  ll i = x + 1;

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

template <typename U , typename ABELIAN_GROUP> inline const ll& AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::X() const noexcept { return m_X; }
template <typename U , typename ABELIAN_GROUP> inline const ll& AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Y() const noexcept { return m_Y; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::Get( const ll& x , const ll& y ) { assert( 0 <= x && x < m_X && 0 <= y && y < m_Y ); return RectangleSum( x , x , y , y ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::LSBRectangleSum( const ll& i , const ll& j ) const { assert( 0 < i && i <= m_X && 0 < j && j <= m_Y ); return Access( i , j , m_M.Zero() ); }

template <typename U , typename ABELIAN_GROUP> 
U AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::InitialRectangleSum( const ll& x_final , const ll& y_final )
{

  U sum = m_M.Zero();
  ll i = min( x_final + 1 , m_X );

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

template <typename U , typename ABELIAN_GROUP> inline U AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>::RectangleSum( ll x_start , ll x_final , ll y_start , ll y_final ) { x_start = max( 0LL , x_start ); x_final = min( m_X - 1 , x_final ); y_start = max( 0LL , y_start ); y_final = min( m_Y - 1 , y_final ); return x_start <= x_final && y_start <= y_final ? m_M.Sum( m_M.Sum( InitialRectangleSum( x_start - 1 , y_start - 1 ) , m_M.Inverse( InitialRectangleSum( x_final , y_start - 1 ) ) ) , m_M.Sum( m_M.Inverse( InitialRectangleSum( x_start - 1 , y_final ) ) , InitialRectangleSum( x_final , y_final ) ) ) : m_M.Zero(); }

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>& bit ) { auto&& X = bit.X(); auto&& Y = bit.Y(); for( ll x = 0 ; x < X ; x++ ){ for( ll y = 0 ; y < Y ; y++ ){ ( y == 0 ? x == 0 ? os : os << "\n" : os << " " ) << bit.Get( x , y ); } } return os; }
