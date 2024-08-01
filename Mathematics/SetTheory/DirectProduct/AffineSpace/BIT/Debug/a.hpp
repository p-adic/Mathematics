// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Debug/a.hpp

#pragma once

#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Group/a.hpp"

// �f�o�b�O�p��BIT�ɒʏ�̔z���ܒ����o�͋@�\��ǉ��������́B
// HybridBIT�Ɣ�ׂ�ƈ�_�擾�̖߂�l�̌^���قȂ�A
// �ʏ��BIT�Ɣ�ׂ�Ƃƈ�_�擾��const�C�������e�푀���O(N)�����邱�Ƃɒ��ӁB

template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_size;
  vector<U> m_fenwick;
  int m_power;

  vector<U> m_a;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int BinarySearch( const int& i_start , const F& f );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int BinarySearch( const U& u );
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int BinarySearch( const int& i_start , const U& u );

private:
  inline void Construct();
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class BIT :
  public AbstractBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline BIT( const Args&... args );

};
template <typename U> BIT( const vector<U>& a ) -> BIT<U>;

// �f�o�b�O�o�͗p
template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractBIT<U,ABELIAN_GROUP>& bit );
