// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Dynamic/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../../../../Algebra/Monoid/Group/a_Body.hpp"
#include "../../../../../Utility/Set/Map/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP , typename INT> inline AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::AbstractDynamicBIT( ABELIAN_GROUP M , const INT& size ) : m_M( move( M ) ) , m_size( size ) , m_fenwick() , m_power( 1 ) { Construct(); }

template <typename U , typename ABELIAN_GROUP , typename INT> inline void AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Construct()
{

  static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> );
  
  while( m_power < m_size ){

    m_power <<= 1;

  }
  
}
  
template <typename U , typename INT> template <typename...Args> inline DynamicBIT<U,INT>::DynamicBIT( const Args&... args ) : AbstractDynamicBIT<U,AdditiveGroup<U>,INT>( AdditiveGroup<U>() , args... ) {}

template <typename U , typename ABELIAN_GROUP , typename INT> inline U AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Access( const INT& i , U u ) noexcept { return m_fenwick.count( i ) == 0 ? move( u ) : m_M.Sum( move( u ) , m_fenwick.at( i ) ); }
template <typename U , typename ABELIAN_GROUP , typename INT> inline void AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Replace( const INT& i , U u ) noexcept { if( u == m_M.Zero() ){ m_fenwick.erase( i ); } else { m_fenwick[i] = move( u ); } }

template <typename U , typename ABELIAN_GROUP , typename INT> template <typename...Args> inline void AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Initialise( const Args&... args ) { AbstractDynamicBIT<U,ABELIAN_GROUP,INT> temp{ m_M , args... }; m_size = temp.m_size; m_fenwick = move( temp.m_fenwick ); m_power = temp.m_power; }
template <typename U , typename ABELIAN_GROUP , typename INT> inline void AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Set( const INT& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }

template <typename U , typename ABELIAN_GROUP , typename INT>
void AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Add( const INT& i , const U& u )
{

  if( i < 0 ){

    return;

  }
  
  INT j = i + 1;

  while( j <= m_size ){

    Replace( j , Access( j , u ) );
    j += ( j & -j );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP , typename INT> inline const INT& AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::size() const noexcept { return m_size; }
template <typename U , typename ABELIAN_GROUP , typename INT> inline U AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::operator[]( const INT& i ) { assert( 0 <= i && i < m_size ); return IntervalSum( i , i ); }
template <typename U , typename ABELIAN_GROUP , typename INT> inline U AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Get( const INT& i ) { return operator[]( i ); }

 template <typename U , typename ABELIAN_GROUP , typename INT> inline const U& AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::LSBSegmentSum( const INT& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick.count( j ) == 0 ? m_M.Zero() : m_fenwick[j]; }

template <typename U , typename ABELIAN_GROUP , typename INT> 
U AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::InitialSegmentSum( const INT& i_final )
{

  U sum = m_M.Zero();
  INT j = min( i_final + 1 , m_size );

  while( j > 0 ){

    sum = Access( j , move( sum ) );
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP , typename INT> inline U AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::IntervalSum( INT i_start , INT i_final ) { i_start = max( 0 , i_start ); i_final = min( size() , i_final ); return i_start <= i_final ? m_M.Sum( m_M.Inverse( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ) : m_M.Zero(); }


template <typename U , typename ABELIAN_GROUP , typename INT> template <typename F , SFINAE_FOR_BIT_BS>
INT AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Search( const F& f )
{

  INT j = 0;
  INT power = m_power;
  U sum = m_M.Zero();
  U sum_next = sum;
  
  while( power > 0 ){

    INT j_next = j | power;

    if( j_next <= m_size ){
      
      sum_next = Access( j_next , move( sum_next ) );

      if( f( sum_next , j_next - 1 ) ){
	
	sum_next = sum;

      } else {

	sum = sum_next;
	j = j_next;
	
      }
      
    }
    
    power >>= 1;

  }

  // f( InitialSegmentSum( i ) , i )がfalseとなるiが存在するならばjはその最大値に
  // 1を足したものとなり、存在しないならばj=0となる。
  // いずれの場合もf( InitialSegmentSum( i ) , i )がtrueとなるiが存在するならば
  // jはそのような最小のiと等しい。
  return j;
  
}

template <typename U , typename ABELIAN_GROUP , typename INT> template <typename F , SFINAE_FOR_BIT_BS> inline INT AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Search( const INT& i_start , const F& f ) { const U u_inv = m_M.Inverse( InitialSegmentSum( i_start - 1 ) ); return max( i_start , Search( [&]( const U& sum , const INT& i ){ return i_start <= i && f( m_M.Sum( u_inv , sum ) , i ); } ) ); }

template <typename U , typename ABELIAN_GROUP , typename INT> inline INT AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Search( const U& u ) { return Search( [&]( const U& sum , const INT& ){ return !( sum < u ); } ); }

template <typename U , typename ABELIAN_GROUP , typename INT> inline INT AbstractDynamicBIT<U,ABELIAN_GROUP,INT>::Search( const INT& i_start , const U& u ) { return max( i_start , Search( m_M.Sum( InitialSegmentSum( i_start - 1 ) , u ) ) ); }

template <class Traits , typename U , typename ABELIAN_GROUP , typename INT> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractDynamicBIT<U,ABELIAN_GROUP,INT>& bit ) { auto&& size = bit.size(); for( INT i = 0 ; i < size ; i++ ){ ( i == 0 ? os : os << " " ) << bit[i]; } return os; }
