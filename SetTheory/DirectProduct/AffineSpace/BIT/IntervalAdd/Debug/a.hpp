// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp

#pragma once
#include "../../a_macro.hpp"

#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"
#include "../../../../../../../Error/Debug/a.hpp"

// �f�o�b�O�p��IntervalAddBIT���𒼂Ȕz��ɕύX���Əo�͋@�\��ǉ��������́B
// �ʏ��IntervalAddBIT�Ɣ�ׂ�Ƃƈ�_�擾��const�C�������e�푀���O(N)�����邱�Ƃɒ��ӁB

template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT :
  public Debug
{
  
protected:
  Z_MODULE m_M;
  int m_size;
  vector<U> m_a;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const int& size = 0 , const bool& output_mode = true );
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a , const bool& output_mode = true );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int Search( const int& i_start , const F& f );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int Search( const U& u );
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int Search( const int& i_start , const U& u );

};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddBIT :
  public AbstractIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddBIT( const Args&... args );
  
};
template <typename U> IntervalAddBIT( const vector<U>& a ) -> IntervalAddBIT<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractIntervalAddBIT<U,Z_MODULE>& bit );
