// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../../../../../Error/Debug/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>::AbstractBIT( ABELIAN_GROUP M , const int& size , const bool& output_mode ) : Debug( output_mode ) , m_M( move( M ) ) , m_size( size ) , m_fenwick( m_size + 1 , m_M.Zero() ) , m_power( 1 ) , m_a( m_size , m_M.Zero() ) { Construct(); }
template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>::AbstractBIT( ABELIAN_GROUP M , const vector<U>& a , const bool& output_mode ) : Debug( output_mode ) , m_M( move( M ) ) , m_size( a.size() ) , m_fenwick( m_size + 1 , m_M.Zero() ) , m_power( 1 ) , m_a( a )
{

  Construct();

  for( int j = 1 ; j <= m_size ; j++ ){

    U& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i > i_lim ){

      fenwick_j = m_M.Sum( move( fenwick_j ) , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

}

template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Construct()
{

  static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> );
  
  while( m_power < m_size ){

    m_power <<= 1;

  }
  
  static bool init = true;

  if( init ){

    if( m_output_mode ){
      
      DERR( "BIT���f�o�b�O���[�h�Ŏ��s���܂��B" );
      DERR( "HybridBIT�Ɣ�ׂ�ƈ�_�擾�̖߂�l�̌^���قȂ�A" );
      DERR( "�ʏ��BIT�Ɣ�ׂ�ƈ�_�擾��const�C�������e�푀���O(N)������" );
      DERR( "���Ƃɂ����ӂ��������B" );
      DERR( "" );

    }

    init = false;

  }

  if( m_output_mode ){
      
    DERR( "BIT�̏����l�F" );
    DERR( *this );
    DERR( "" );

  }
  
}
  
template <typename U> template <typename...Args> inline BIT<U>::BIT( const Args&... args ) : AbstractBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , args... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractBIT<U,ABELIAN_GROUP>::Initialise( const Args&... args ) { AbstractBIT<U,ABELIAN_GROUP> temp{ m_M , args... }; m_size = temp.m_size; m_fenwick = move( temp.m_fenwick ); m_power = temp.m_power; m_a = move( temp.m_a ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }

template <typename U , typename ABELIAN_GROUP>
void AbstractBIT<U,ABELIAN_GROUP>::Add( const int& i , const U& u )
{
  
  if( m_output_mode ){
      
    DERR( "BIT�̑�" , i , "������" , u , "�����Z���܂��B" );

  }

  int j = i + 1;

  while( j <= m_size ){

    U& fenwick_j = m_fenwick[j];
    fenwick_j = m_M.Sum( move( fenwick_j ) , u );
    j += ( j & -j );

  }

  if( 0 <= i && i < m_size ){

    m_a[i] = m_M.Sum( move( m_a[i] ) , u );

  }
  
  if( m_output_mode ){
      
    DERR( "BIT�̍X�V��̐����F" );
    DERR( *this );
    DERR( "" );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractBIT<U,ABELIAN_GROUP>::size() const noexcept { return m_size; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractBIT<U,ABELIAN_GROUP>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename U , typename ABELIAN_GROUP> 
U AbstractBIT<U,ABELIAN_GROUP>::InitialSegmentSum( const int& i_final )
{

  U sum = m_M.Zero();
  int j = min( i_final + 1 , m_size );

  while( j > 0 ){

    sum = m_M.Sum( move( sum ) , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::IntervalSum( const int& i_start , const int& i_final )
{

  auto answer = m_M.Sum( m_M.Inverse( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) );

  if( m_output_mode ){
      
    DERR( "BIT�̋��[" , i_start , "," , i_final , "] �ɂ����鑍�a�F" , answer );

  }

  return answer;

}


template <typename U , typename ABELIAN_GROUP> template <typename F , SFINAE_FOR_BIT_BS>
int AbstractBIT<U,ABELIAN_GROUP>::Search( const F& f )
{

  int j = 0;
  int power = m_power;
  U sum = m_M.Zero();
  U sum_next = sum;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next <= m_size ){
      
      sum_next = m_M.Sum( move( sum_next ) , m_fenwick[j_next] );

      if( f( sum_next , j_next - 1 ) ){
	
	sum_next = sum;

      } else {

	sum = sum_next;
	j = j_next;
	
      }
      
    }
    
    power >>= 1;

  }

  // f( InitialSegmentSum( i ) , i )��false�ƂȂ�i�����݂���Ȃ��j�͂��̍ő�l��
  // 1�𑫂������̂ƂȂ�A���݂��Ȃ��Ȃ��j=0�ƂȂ�B
  // ������̏ꍇ��f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���Ȃ��
  // j�͂��̂悤�ȍŏ���i�Ɠ������B
  return j;
  
}

template <typename U , typename ABELIAN_GROUP> template <typename F , SFINAE_FOR_BIT_BS> inline int AbstractBIT<U,ABELIAN_GROUP>::Search( const int& i_start , const F& f ) { const U u_inv = m_M.Inverse( InitialSegmentSum( i_start - 1 ) ); return max( i_start , Search( [&]( const U& sum , const int& i ){ return i_start <= i && f( m_M.Sum( u_inv , sum ) , i ); } ) ); }

template <typename U , typename ABELIAN_GROUP> inline int AbstractBIT<U,ABELIAN_GROUP>::Search( const U& u ) { return Search( [&]( const U& sum , const int& ){ return !( sum < u ); } ); }

template <typename U , typename ABELIAN_GROUP> inline int AbstractBIT<U,ABELIAN_GROUP>::Search( const int& i_start , const U& u ) { return max( i_start , Search( m_M.Sum( InitialSegmentSum( i_start - 1 ) , u ) ) ); }


template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractBIT<U,ABELIAN_GROUP>& bit )
{

  auto&& size = bit.size();

  if( exec_mode == solve_mode ){

    os << "[";

  }

  for( int i = 0 ; i < size ; i++ ){

    ( i == 0 ? os : os << "," ) << bit[i];

  }

  if( exec_mode == solve_mode ){

    os << "]";

  }

  return os;

}
