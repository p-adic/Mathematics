// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/a.hpp

#pragma once
#include "../Sqrt/a.hpp"

// ���Z��operator+=�łȂ��ꍇ�Ɏg�p

// �����m�C�h(T,m_T:T^2->T,e_T:1->T)�Ɣ񕉐���N���p�����[�^�Ƃ���B
// �P�ʌ��ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ��Ԑώ擾O(N^{1/2})

// ��_�X�VO(1)�i������i_T���g���j
// ��@�ɂ���_�X�VO(1)�i�������g���j
template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class AbstractSqrtDecomposition
{

private:
  T m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  inline constexpr AbstractSqrtDecomposition();
  inline constexpr AbstractSqrtDecomposition( const T ( &a )[N] );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T& Get( const int& i ) const;
  inline constexpr T IntervalSum( const int& i_start , const int& i_final );

  inline constexpr void Set( const int& i , const T& n );
  inline constexpr void Add( const int& i , const T& n );
  
};

