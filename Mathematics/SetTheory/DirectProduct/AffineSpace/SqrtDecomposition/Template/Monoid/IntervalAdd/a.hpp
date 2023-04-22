// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Monoid/IntervalAdd/a.hpp

#pragma once
#include "../../../Sqrt/a.hpp"

// �����m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// m_T�Ɋւ����Ԙa�擾O(i_start - i_final)�i�������g���j

// ��_�X�V�͂Ȃ�
// m_T�ɂ���_�X�VO(1)�i�������g���j
// m_T�ɂ���ԍX�VO(N^{1/2})�i�������g���j

// ��Ԙa�擾��O(N^{1/2})�ɂ��邱�Ƃ��\����
// ��Ԙa�擾���قƂ�ǈ�_�擾�ł����p���Ȃ��ꍇ��
// ���̂܂܂̕���m_T�ɂ���ԍX�V���萔�{�����B
template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class IntervalAddSqrtDecomposition
{

private:
  T m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  inline constexpr IntervalAddSqrtDecomposition();
  inline constexpr IntervalAddSqrtDecomposition( const T ( &a )[N] );

  inline constexpr T IntervalSum( const int& i_start , const int& i_final ) const;

  inline constexpr void Add( const int& i , const T& n );
  inline constexpr void IntervalAdd( const int& i_start , const int& i_final , const T& n );
  
};

