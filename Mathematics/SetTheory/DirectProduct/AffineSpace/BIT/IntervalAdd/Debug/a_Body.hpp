// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"
#include "../../../../../../../Error/Debug/a_Body.hpp"

template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const int& size , const bool& output_mode ) : AbstractIntervalAddBIT( M , vector<U>( size , M.Zero() ) , output_mode ) {}
template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a , const bool& output_mode ) : Debug( output_mode ) , m_M( move( M ) ) , m_size( a.size() ) , m_a( a )
{

  if( m_output_mode ){
    
    static bool init = true;

    if( init ){

      DERR( "IntervalAddBIT���f�o�b�O���[�h�Ŏ��s���܂��B" );
      DERR( "�ʏ��IntervalAddBIT�Ɣ�ׂ�ƈ�_�擾��const�C�������e�푀���O(N)������" );
      DERR( "���Ƃɂ����ӂ��������B" );
      DERR( "" );
      init = false;

    }

    DERR( "IntervalAddBIT�̏����l�F" );
    DERR( *this );
    DERR( "" );

  }
  
}

template <typename U>  template <typename...Args> inline IntervalAddBIT<U>::IntervalAddBIT( const Args&... args ) : AbstractIntervalAddBIT<U,Module<int,U>>( Module<int,U>() , args... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Initialise( const Args&... args ) { AbstractIntervalAddBIT<U,Z_MODULE> temp{ m_M , args... }; m_size = temp.m_size; m_a = move( temp.m_a ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }

template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Add( const int& i , const U& u ) { assert( 0 <= i && i < size() ); IntervalAdd( i , i , u ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::IntervalAdd( const int& i_start , const int& i_final , const U& u )
{

  if( m_output_mode ){
    
    DERRNS( "IntervalAddBIT�̋��[" , i_start , "," , i_final , "]��" , u , "�����Z���܂��B" );

  }

  for( int i = max( 0 , i_start ) ; i <= min( i_final , m_size - 1 ) ; i++ ){

    m_a[i] = m_M.Sum( move( m_a[i] ) , u );

  }

  if( m_output_mode ){
    
    DERR( "IntervalAddBIT�̍X�V��̐����F" );
    DERR( *this );
    DERR( "" );

  }
  
  return;
  
}


template <typename U , typename Z_MODULE> inline const int& AbstractIntervalAddBIT<U,Z_MODULE>::size() const noexcept { return m_size; }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::Get( const int& i ) const { return operator[]( i ); }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::InitialSegmentSum( const int& i_final ) { return IntervalSum( 0 , i_final ); }

template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::IntervalSum( const int& i_start , const int& i_final )
{

  U answer = m_M.Zero();

  for( int i = max( 0 , i_start ) ; i <= min( i_final , m_size - 1 ) ; i++ ){

    answer = m_M.Sum( move( answer ) , m_a[i] );

  }

  if( m_output_mode ){
    
    DERR( "IntervalAddBIT�̋��[" , i_start , "," , i_final , "] �ɂ����鑍�a�F " , answer );
    DERR( "" );

  }
  
  return answer;

}


template <typename U , typename Z_MODULE> template <typename F , SFINAE_FOR_BIT_BS>
int AbstractIntervalAddBIT<U,Z_MODULE>::Search( const F& f )
{

  int l = -1 , r = size();

  while( l + 1 < r ){

    const int m = ( l + r ) >> 1;
    ( f( InitialSegmentSum( m ) , m ) ? r : l ) = m;

  }

  return r;
  
}

template <typename U , typename Z_MODULE> template <typename F , SFINAE_FOR_BIT_BS> inline int AbstractIntervalAddBIT<U,Z_MODULE>::Search( const int& i_start , const F& f ) { const U u_inv = m_M.Inverse( InitialSegmentSum( i_start - 1 ) ); return max( i_start , Search( [&]( const U& sum , const int& i ){ return i_start <= i && f( m_M.Sum( u_inv , sum ) , i ); } ) ); }

template <typename U , typename Z_MODULE> inline int AbstractIntervalAddBIT<U,Z_MODULE>::Search( const U& u ) { return Search( [&]( const U& sum , const int& ){ return !( sum < u ); } ); }

template <typename U , typename Z_MODULE> inline int AbstractIntervalAddBIT<U,Z_MODULE>::Search( const int& i_start , const U& u ) { return max( i_start , Search( m_M.Sum( InitialSegmentSum( i_start - 1 ) , u ) ) ); }

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractIntervalAddBIT<U,Z_MODULE>& bit )
{

  auto&& size = bit.size();

  #ifndef SAMPLE_CHECK
    os << "[";
  #endif

  for( int i = 0 ; i < size ; i++ ){

    ( i == 0 ? os : os << " " ) << bit[i];

  }

  #ifndef SAMPLE_CHECK
    os << "]";
  #endif

  return os;

}
