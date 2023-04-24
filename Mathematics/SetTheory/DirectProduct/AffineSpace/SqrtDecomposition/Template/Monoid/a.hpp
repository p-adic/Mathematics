// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Monoid/a.hpp

#pragma once
#include "../../Sqrt/a.hpp"

// �����m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// m_T�Ɋւ����Ԙa�擾O(N^{1/2})

// ��_�X�VO(N^{1/2})
// m_T�ɂ���_�X�VO(1)�i�������g���j
template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class MonoidSqrtDecomposition
{

private:
  T m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  static const T& g_e;
  
  inline constexpr MonoidSqrtDecomposition();
  inline constexpr MonoidSqrtDecomposition( const T ( &a )[N] );
  inline constexpr MonoidSqrtDecomposition( T ( &&a )[N] );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T& Get( const int& i ) const;
  inline constexpr T IntervalSum( const int& i_start , const int& i_final );

  inline constexpr void Set( const int& i , const T& n );
  inline constexpr void Add( const int& i , const T& n );
  
};

