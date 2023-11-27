// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Arithmetic/Power/Constexpr/Inverse/a.hpp"

// verify: https://yukicoder.me/submissions/932066

// �i���Ƃ͌���Ȃ��j���m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ��Ԑώ擾O(log_2 N)

// ��_�X�VO(log_2 N)
template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE>
class SegmentTree
{
private:
  static constexpr const int g_power = PowerInverse_constexpr<N>{}.m_val;
  static constexpr const int g_power2 = g_power << 1;
  T m_a[g_power2];

public:
  static const T& g_e;

  inline SegmentTree();
  inline SegmentTree( const T ( &a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalProduct( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );

};
