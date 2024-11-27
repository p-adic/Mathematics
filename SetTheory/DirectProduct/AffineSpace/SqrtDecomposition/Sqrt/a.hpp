// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a.hpp

#pragma once

class SqrtDecompositionCoordinate
{

protected:
  int m_N;
  int m_N_sqrt;
  // m_N / m_N_sqrt �ȏ�ł���ŏ��̐����B
  int m_N_d;
  // m_N �ȏ�ł���ŏ��� m_N_sqrt �̔{���B
  int m_N_m;

public:
  inline SqrtDecompositionCoordinate( const int& N = 0 );
  inline SqrtDecompositionCoordinate( const int& N , const int& N_sqrt );

  // 2�悪N�ȏ�ł���ŏ��̐�������Ԃ��B
  static inline int Sqrt( const int& N ) noexcept;

};
