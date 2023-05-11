// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/LazyEvaluation/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../Sqrt/a.hpp"

// �i�����I�Ƃ��P�ʓI�Ƃ����Ƃ�����Ȃ��j��_�t���}�O�}(T,m_T:T^2->T,e_T:1->T)��
// �i���Ƃ͌���Ȃ��j���m�C�h(U,m_U:U^2->U,e_U:1->U)��
// ��_���P���ϊ��ɑΉ�����T��p(o_U:T�~U->U)�Ɣ񕉐���N���p�����[�^�Ƃ���B

// e_U�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ��Ԑώ擾O(min(i_final-i_start+1,N^{1/2}))�iU�̃��m�C�h�����g���j

// ��_�X�VO(N^{1/2})�i��ԍX�V�ƃI�[�_�[�͓��������萔�{�ǂ��j
// �P�̑���l�ɂ���ԍX�VO(N^{1/2})

// o_U�ɂ���_�X�V�͂Ȃ��B
// o_U�ɂ���ԍX�VO(N^{1/2})
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class LazySqrtDecomposition
{

private:
  static constexpr const int N_d = ( N + N_sqrt - 1 ) / N_sqrt;
  static constexpr const int N_m = N_d * N_sqrt;
  U m_a[N_m];
  U m_b[N_d];
  U m_lazy_substitution[N_d];
  bool m_suspended[N_d];
  T m_lazy_action[N_d];

public:
  static const T& g_e_T;
  static const U& g_e_U;
  
  inline constexpr LazySqrtDecomposition();
  inline constexpr LazySqrtDecomposition( const U ( &a )[N] );

  inline constexpr U Get( const int& i ) const;
  inline constexpr U IntervalProd( const int& i_start , const int& i_final ) const;

  inline constexpr void Set( const int& i , const U& u );
  inline constexpr void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline constexpr void IntervalAct( const int& i_start , const int& i_final , const T& t );

  static inline constexpr U Power( const U& u , int exponent );

private:
  inline constexpr U IntervalProd_Body( const int& i_min , const int& i_ulim ) const;

  inline constexpr void SetProd( const int& i );
  inline constexpr void SolveSuspension( const int& d , const U& �� );
  inline constexpr void IntervalSet_Body( const int& i_min , const int& i_ulim , const TU& t );
  inline constexpr void IntervalAct_Body( const int& i_min , const int& i_ulim , const T& t );
  
};

