// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Iterator/a_Body.hpp"
#include "../../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::VirtualIntervalInsertBoundedLineMultiSubset() : Debug() , m_lbound() , m_ubound() , m_ds( 0 , false ) , m_name() , m_S() , m_S_comp() {}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::insert( const INT1& i , const INT2& c )
{

  assert( InRange( i ) && c >= 0 );
  m_ds.Add( Normalise( i ) , c );
  auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

  for( INT2 repetition = 0 ; repetition < c ; repetition++ ){

    if( itr != end && *itr == i ){

      itr = m_S_comp.erase( itr );

    } else {

      m_S.insert( i );

    }

  }

  if( m_output_mode ){
  
    DERR( m_name , "に" , i , "を" , c , "個挿入しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::IntervalInsert( const INT1& i_start , const INT1& i_final , const INT2& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , c );

  for( INT1 i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

    for( INT2 repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S_comp.erase( itr );

      } else {

        m_S.insert( i );

      }

    }

  }
  
  DERR( m_name , " に閉区間 [" , i_start , "," , i_final , "] の和集合を " , c , " 個取りました。" );
  Display();
  DERR( "" );
  return;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::erase( const INT1& i , const INT2& c )
{

  assert( c >= 0 );

  if( InRange( i ) ){
    
    m_ds.Add( Normalise( i ) , -c );
    auto itr = m_S.find( i ) , end = m_S.end();

    for( INT2 repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を" , c , "個削除挿入しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator& VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::erase( typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator& itr )
{

  const INT1 i = *itr;
  assert( m_S.count( i ) > 0 && m_S_comp.empty() );
  auto& itr_ref = itr.erase_from( *this );

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を" , 1 , "個削除しました。" );
    m_S.erase( i );
    Display();
    DERR( "" );

  }
  
  return itr_ref;

}


template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::EraseAll( const INT1& i )
{

  if( InRange( i ) ){
    
    m_ds.Set( Normalise( i ) , 0 );
    auto itr = m_S.find( i ) , end = m_S.end();

    while( itr != end && *itr == i ){

      itr = m_S.erase( itr );

    }

    auto itr_comp = m_S_comp.find( i ) , end_comp = m_S_comp.end();

    while( itr_comp != end_comp && *itr_comp == i ){

      itr_comp = m_S_comp.erase( itr_comp );

    }

  }

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を全て削除しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::IntervalErase( const INT1& i_start , const INT1& i_final , const INT2& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , -c );

  for( INT1 i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S.find( i ) , end = m_S.end();

    for( INT2 repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  if( m_output_mode ){

    DERR( m_name , " から閉区間 [" , i_start , "," , i_final , "] の差集合を " , c , " 回取りました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::clear()
{
  
  m_ds.Initialise( m_ds.size() );
  m_S.clear();
  m_S_comp.clear();

  if( m_output_mode ){

    DERR( m_name , "から全ての要素を削除しました。" );
    Display();
    DERR( "" );

  }

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::count( const INT1& i ) noexcept { return InRange( i ) ? m_ds[Normalise( i )] : 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::find( const INT1& i ) noexcept { return count( i ) > 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::InitialSegmentCount( const INT1& i_final ) { return i_final < m_lbound ? 0 : m_ds.InitialSegmentSum( Normalise( i_final ) ); }
  
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT2 VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::IntervalCount( const INT1& i_start , const INT1& i_final )
{

  auto&& l = Normalise( i_start );
  const INT2 answer = m_ds.IntervalSum( ( l < 0 || Denormalise( l ) < i_start ) ? l + 1 : l , Normalise( i_final ) );

  if( m_output_mode ){

    DERR( m_name , "の区間[" , i_start , "," , i_final , "]内の重複を込めた要素数は" , answer , "です。" );
    DERR( "\n" );

  }
  
  return answer;

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::empty() { assert( m_S_comp.empty() ); return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::begin() { return MinimumGeq( m_lbound ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::end() { assert( m_S_comp.empty() ); return typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator( *this , m_ubound + 1 ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MaximumLeq( const INT1& i , const INT2& k )
{

  assert( m_S_comp.empty() );
  const INT2 num = InitialSegmentCount( i ) - k;

  if( num >= 0 ){

    const int d = m_ds.Search( [&]( const INT2& sum , const int& j ){ return num <= sum; } );

    if( d < m_ds.size() ){

      auto&& l = Denormalise( d );

      if( find( l ) ){

        return typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , l };

      }

    }

  }

  return end(); 
  
}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MaximumLt( const INT1& i , const INT2& k )
{

  const int d = Normalise( i );

  if( d == 0 ){

    return end();

  }

  return MaximumLeq( Denormalise( d - 1 ) , k );

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MinimumGeq( const INT1& i , const INT2& k )
{

  const INT2 c = count( i );
  return c > k ? typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , i } : MinimumGt( i , k - c );

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::MinimumGt( const INT1& i , const INT2& k )
{

  assert( m_S_comp.empty() );
  const INT2 num = InitialSegmentCount( i ) + k;
  const int d = m_ds.Search( [&]( const INT2& sum , const int& j ){ return num < sum; } );

  if( d < m_ds.size() ){

    auto&& r = Denormalise( d );

    if( find( r ) ){

      return typename VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::iterator{ *this , r };

    }

  }

  return end(); 

}

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT1 VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::Maximum( const INT2& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline INT1 VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::Minimum( const INT2& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline const INT1& VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::lbound() const noexcept { return m_lbound; }
template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline const INT1& VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::ubound() const noexcept { return m_ubound; }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::Display() noexcept
{

  DERR( "重複を込めた要素数:" , int( m_S.size() ) - int( m_S_comp.size() ) );
  DERR( "集合:" , m_S , "-" , m_S_comp );
  return;

}


template <typename INT1 , typename INT2> inline IntervalInsertBoundedLineMultiSubset<INT1,INT2>::IntervalInsertBoundedLineMultiSubset( const INT1& lbound , const INT1& ubound , const bool& output_mode ) : VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,INT1,INT1,IntervalAddBIT>()
{

  assert( lbound <= ubound + 1 );
  this->m_output_mode = output_mode;
  this->m_lbound = lbound;
  this->m_ubound = ubound;
  static int count = 0;
  this->m_name = "IntervalInsertBoundedLineMultiSubset" + to_string( count++ );
  this->m_ds.Initialise( int( this->m_ubound - this->m_lbound + 1 ) , false );

  if( this->m_output_mode ){
    
    DERR( this->m_name , "をデバッグモードで実行します。" );

    static bool init = true;

    if( init ){

      init = true;
      DERR( "各処理の計算量がO(size)増えることに注意してください。" );

    }
    
    this->Display();
    DERR( "" );

  }
  
}

template <typename INT1 , typename INT2> inline bool IntervalInsertBoundedLineMultiSubset<INT1,INT2>::InRange( const INT1& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT1 , typename INT2> inline int IntervalInsertBoundedLineMultiSubset<INT1,INT2>::Normalise( const INT1& i ) { return i - this->m_lbound; }
template <typename INT1 , typename INT2> inline INT1 IntervalInsertBoundedLineMultiSubset<INT1,INT2>::Denormalise( const int& d ) { return d + this->m_lbound; }
