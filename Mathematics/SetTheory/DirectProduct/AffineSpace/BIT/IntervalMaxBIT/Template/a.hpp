// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/BIT/IntervalMaxBIT/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// ��㰓����m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ��Ԙa�擾O(log_2 N)

// ��_�X�VO((log_2 N)^2)
// ��_���ZO(log_2 N)
// ��ԉ��ZO(i_final-i_start+log_2 N)
template <TEMPLETE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
class IdempotentMonoidBIT
{
private:
  T m_a[N];
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];

public:
  static const T& g_e;

  inline IdempotentMonoidBIT();
  inline IdempotentMonoidBIT( const T ( &a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalAdd( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );
  void SetAdd( const int& i , const T& n );
  void IntervalSetAdd( const int& i_start , const int& i_final , const T& n ); 

};
