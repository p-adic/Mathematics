// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Dual/NonCommutative/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../Sqrt/a.hpp"

// �i���Ƃ������I�Ƃ��P�ʓI�Ƃ�����Ȃ��j��_�t���}�O�}(T,m_T:T^2->T,e_T:1->T)�Ɗ�_���P���ϊ��ɑΉ�����T��p�t���W��(U,o_U:T�~U->U)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)

// ��_�X�V�͂Ȃ�
// o_U�ɂ���_�X�V��o_U�ɂ���ԍX�V�ŏ�������iO(N^{1/2})�j
// o_U�ɂ���ԍX�VO(N^{1/2})
template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class NonCommutativeDualSqrtDecomposition
{

private:
  U m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  static const T& g_e;
  
  inline constexpr NonCommutativeDualSqrtDecomposition( const U ( &a )[N] );
  inline constexpr NonCommutativeDualSqrtDecomposition( U ( &&a )[N] );

  inline constexpr U Get( const int& i ) const;

  inline constexpr void IntervalAct( const int& i_start , const int& i_final , const T& n );
  
};

