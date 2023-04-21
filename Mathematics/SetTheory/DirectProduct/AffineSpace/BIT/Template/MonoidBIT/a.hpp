// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/BIT/Template/MonoidBIT/a.hpp

#pragma once
#include "a_Macro.hpp"

// �i���Ƃ͌���Ȃ��j���m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ��Ԑώ擾O(log_2 N)

// ��_�X�VO((log_2 N)^2)
// ���̂����̋�Ԑώ擾�ƈ�_�X�V��
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// �̎�@����ʂ̃��m�C�h�Ɋg�����邱�ƂŎ���
template <TEMPLETE_ARGUMENTS_FOR_MONOID_BIT>
class MonoidBIT
{
private:
  T m_a[N];
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];

public:
  static const T& g_e;

  inline MonoidBIT();
  inline MonoidBIT( const T ( &a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalProduct( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );

};
