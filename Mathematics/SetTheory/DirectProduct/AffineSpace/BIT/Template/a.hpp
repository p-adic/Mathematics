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
  AbstractBIT( const T ( & a )[N] );

  inline void Set( const int& i , const T& n );

  inline AbstractBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
};
