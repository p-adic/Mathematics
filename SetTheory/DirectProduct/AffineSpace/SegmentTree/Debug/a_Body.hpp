// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Semilattice/a_Body.hpp"

#include "../../../../../../Error/Debug/a_Body.hpp"

template <typename U , typename MONOID> inline AbstractSegmentTree<U,MONOID>::AbstractSegmentTree( MONOID M , const int& size , const bool& output_mode ) : AbstractSegmentTree( M , vector<U>( size , M.One() ) , output_mode ) {}

template <typename U , typename MONOID> inline AbstractSegmentTree<U,MONOID>::AbstractSegmentTree( MONOID M , const vector<U>& a , const bool& output_mode ) : Debug( output_mode ) , m_M( move( M ) ) , m_size( a.size() ) , m_power( 1 ) , m_a()
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  
  while( m_size > m_power ){

    m_power <<= 1;

  }

  m_a.resize( m_power << 1 , m_M.One() );
  
  for( int i = 0 ; i < m_size ; i++ ){

    m_a[m_power | i] = a[i];

  }

  for( int j = m_power - 1 ; j >= 1 ; j-- ){

    int j2 = j << 1;
    m_a[j] = m_M.Product( m_a[j2] , m_a[j2 | 1] );

  }

  static bool init = true;

  if( init ){

    if( m_output_mode ){
      
      DERR( "SegmentTreeをデバッグモードで実行します。" );
      DERR( "通常のSegmentTreeと比べると各種操作にO(N)かかることにご注意ください。" );
      DERR( "" );

    }

    init = false;

  }

  if( m_output_mode ){
      
    DERR( "SegmentTreeの初期値：" );
    DERR( *this );
    DERR( "" );

  }
  
}

template <typename U> template <typename...Args> inline SegmentTree<U>::SegmentTree( const U& zero_U , const Args&... args ) : AbstractSegmentTree<U,MaxSemilattice<U>>( MaxSemilattice<U>( zero_U ) , args... ) {}

template <typename U , typename MONOID> template <typename...Args> inline void AbstractSegmentTree<U,MONOID>::Initialise( const Args&... args ) { *this = AbstractSegmentTree( move( m_M ) , args... ); }

template <typename U , typename MONOID>
void AbstractSegmentTree<U,MONOID>::Set( const int& i , const U& u )
{

  assert( 0 <= i && i < m_size );
  int j = m_power | i;
  m_a[j] = u;
  
  while( ( j >>= 1 ) >= 1 ){
    
    int j2 = j << 1;
    m_a[j] = m_M.Product( m_a[j2] , m_a[j2 | 1] );

  }

  if( m_output_mode ){
      
    DERR( "SegmentTreeの第" , i , "成分に" , u , "を代入します。" );
    DERR( "SegmentTreeの更新後の成分：" );
    DERR( *this );
    DERR( "" );

  }

  return;

}

template <typename U , typename MONOID> inline const int& AbstractSegmentTree<U,MONOID>::size() const noexcept { return m_size; }
template <typename U , typename MONOID> inline const U& AbstractSegmentTree<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[m_power | i]; }
template <typename U , typename MONOID> inline const U& AbstractSegmentTree<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename MONOID>
U AbstractSegmentTree<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final ) 
{

  U answer0 = m_M.One();
  int j_min = max( 0 , i_start );
  int j_ulim = min( i_final , m_size - 1 );

  if( j_min > j_ulim ){

    return answer0;
    
  }
  
  j_min |= m_power;
  ++( j_ulim |= m_power );
  U answer1 = answer0;

  while( j_min < j_ulim ){

    ( j_min & 1 ) == 1 ? answer0 = m_M.Product( move( answer0 ) , m_a[j_min++] ) : answer0;
    ( j_ulim & 1 ) == 1 ? answer1 = m_M.Product( m_a[--j_ulim] , answer1 ) : answer1;
    j_min >>= 1;
    j_ulim >>= 1;

  }

  auto answer = m_M.Product( move( answer0 ), answer1 );
  
  if( m_output_mode ){
      
    DERR( "SegmentTreeの区間[" , i_start , "," , i_final , "] における総和：" , answer );

  }

  return answer;

}

template <typename U> inline U SegmentTree<U>::IntervalMax( const int& i_start , const int& i_final ) { return this->IntervalProduct( i_start , i_final ); }

template <class Traits , typename U , typename MONOID> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractSegmentTree<U,MONOID>& st )
{

  auto&& size = st.size();

  if( exec_mode == solve_mode ){

    os << "[";

  }

  for( int i = 0 ; i < size ; i++ ){

    ( i == 0 ? os : os << "," ) << st[i];

  }

  if( exec_mode == solve_mode ){

    os << "]";

  }

  return os;

}
