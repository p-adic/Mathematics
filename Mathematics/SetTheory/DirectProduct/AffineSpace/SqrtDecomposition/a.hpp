// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a.hpp

#pragma once
#include "Sqrt/a.hpp"

// InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B
// �g�p���Z�F
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T& T::operator-=( const T& ) // ������Set�ɂ̂ݎg�p
template <typename T , int N , int N_sqrt = SqrtCalculation<N>{}.m_val >
class SqrtDecomposition
{

private:
  T m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  inline constexpr SqrtDecomposition();
  inline constexpr SqrtDecomposition( const T ( &a )[N] );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T& Get( const int& i ) const;
  inline constexpr T IntervalSum( const int& i_start , const int& i_final );

  inline constexpr void Set( const int& i , const T& n );
  inline constexpr void Add( const int& i , const T& n );
  
};

