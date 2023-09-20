// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// ���Z��operator+=�łȂ��ꍇ�Ɏg�p
// ���Q(T,m_T:T^2->T,e_T:1->T,i_T:T->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// ������i_T���g���̂�Set��IntervalSum�݂̂Ȃ̂ŁA
// Add��InitialSegmentSum�����g��Ȃ��ꍇ��
// i_T���D���ɐݒ肵��(T,m_T,e_T)�����m�C�h�Ƃ��ėǂ��B
template <TEMPLATE_ARGUMENTS_FOR_BIT>
class AbstractBIT
{
private:
  T m_fenwick[N + 1];
  
public:
  static const T& g_e;

  inline AbstractBIT();
  inline AbstractBIT( const T ( &a )[N] );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const T ( &a )[N] );
  inline void Initialise();

  inline AbstractBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;

  // �����Q�\��operator<( const T& , const T& )����`����Ă��鎞�̂݃T�|�[�g�B
  // g_e��菬�����Ȃ��v�f�݂̂𐬕��Ɏ��ꍇ�̂݃T�|�[�g�B
  // InitialSegmentSum( i )��n�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )��n�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
