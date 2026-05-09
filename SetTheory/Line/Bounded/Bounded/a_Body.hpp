// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Iterator/a_Body.hpp"
#include "../../DirectProduct/AffineSpace/BIT/a_Body.hpp"

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::insert( const INT1& i ) { assert( InRange( i ) ); m_ds.Set( Normalise( i ) , 1 ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::erase( const INT1& i ) noexcept { if( InRange( i ) ){ m_ds.Set( Normalise( i ) , 0 ); } }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator& VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::erase( typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator& itr ) { return itr.erase_from( *this ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::clear() { m_ds.Initialise( m_ds.size() ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::count( const INT1& i ) noexcept { return InRange( i ) ? m_ds[Normalise( i )] : 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline bool VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::find( const INT1& i ) noexcept { return count( i ) > 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::InitialSegmentCount( const INT1& i_final ) { return i_final < m_lbound ? 0 : m_ds.InitialSegmentSum( Normalise( i_final ) ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::IntervalCount( const INT1& i_start , const INT1& i_final ) { auto&& l = Normalise( i_start ); return m_ds.IntervalSum( ( l < 0 || Denormalise( l ) < i_start ) ? l + 1 : l , Normalise( i_final ) ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline bool VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::empty() noexcept { return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::begin() noexcept { return MinimumGeq( m_lbound ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::end() noexcept { return typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator( *this , m_ubound + 1 ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MaximumLeq( const INT1& i , const INT2& k ) { const INT2 num = InitialSegmentCount( i ) - k; if( num >= 0 ){ const int d = m_ds.Search( [&]( const INT2& sum , const int& j ){ return num <= sum; } ); if( d < m_ds.size() ){ auto&& l = Denormalise( d ); if( find( l ) ){ return typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , l }; } } } return end(); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MaximumLt( const INT1& i , const INT2& k ) { const int d = Normalise( i ); if( d == 0 ){ return end(); } return MaximumLeq( Denormalise( d - 1 ) , k ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MinimumGeq( const INT1& i , const INT2& k ) { const int c = count( i ); return c > k ? typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , i } : MinimumGt( i , k - c ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MinimumGt( const INT1& i , const INT2& k ) { const INT2 num = InitialSegmentCount( i ) + k; const int d = m_ds.Search( [&]( const INT2& sum , const int& j ){ return num < sum; } ); if( d < m_ds.size() ){ auto&& r = Denormalise( d ); if( find( r ) ){ return typename VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , r }; } } return end(); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT1 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::Maximum( const INT2& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT1 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::Minimum( const INT2& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
INT1 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::RightEndPointOf( const INT1& i , int d , int comp_minus , const bool& in )
{

  if( !in && !find( i ) ){

    return i - 1;

  }

  if( d == -1 ){

    d = Normalise( i );
    comp_minus = d - InitialSegmentCount( i );

  }

  // inÇ™trueÇ»ÇÃÇ≈DenormaliseÇÃà¯êîÇ™ê≥Ç≈Ç†ÇÈÇ±Ç∆Ç…íçà”ÅB
  return Denormalise( m_ds.Search( [&]( const INT2& sum , const int& j ){ return d <= j && sum + comp_minus < j; } ) - 1 );

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
INT1 VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::LeftEndPointOf( const INT1& i , int d , int comp_minus , const bool& in )
{

  if( !in && !find( i ) ){

    return i + 1;

  }

  if( d == -1 ){

    d = Normalise( i );
    comp_minus = d - InitialSegmentCount( i );

  }

  // inÇ™trueÇ»ÇÃÇ≈DenormaliseÇÃà¯êîÇ™m_ds.size()ñ¢ñûÇ≈Ç†ÇÈÇ±Ç∆Ç…íçà”ÅB
  return Denormalise( m_ds.Search( [&]( const INT2& sum , const int& j ){ return d <= j || ( find( j ) && sum + comp_minus == j ); } ) );

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline pair<INT1,INT1> VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::ConnectedComponentOf( const INT1& i , bool in ) { if( !in ){ in = find( i ); } const int d = Normalise( i ) , comp_minus = d - InitialSegmentCount( i ); return { LeftEndPointOf( i , d , comp_minus , in ) , RightEndPointOf( i , d , comp_minus , in ) }; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
vector<pair<INT1,INT1>> VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::GetConnectedComponent() noexcept
{

  vector<pair<INT1,INT1>> answer{};
  INT1 r;
  
  for( auto itr = begin() ; *itr <= m_ubound ; itr = MinimumGt( r ) ){

    answer.push_back( { *itr , r = RightEndPointOf( *itr ) } );

  }

  return answer;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline const INT1& VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::lbound() const noexcept { return m_lbound; }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline const INT1& VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::ubound() const noexcept { return m_ubound; }


template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline AbstractBoundedLineSubset<INT1,INT2,DATA_STR>::AbstractBoundedLineSubset( const INT1& lbound , const INT1& ubound ) { assert( lbound <= ubound + 1 ); this->m_lbound = lbound; this->m_ubound = ubound; this->m_ds.Initialise( int( this->m_ubound - this->m_lbound + 1 ) ); }

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineSubset<INT1,INT2,DATA_STR>::InRange( const INT1& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT1,INT2,DATA_STR>::Normalise( const INT1& i ) { return i - this->m_lbound; }
template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline INT1 AbstractBoundedLineSubset<INT1,INT2,DATA_STR>::Denormalise( const int& d ) { return d + this->m_lbound; }
