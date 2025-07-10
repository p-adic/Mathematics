// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Coordinate/a.hpp

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
  inline const int& size() const noexcept;
  inline const int& BucketSize() const noexcept;
  inline const int& BucketCount() const noexcept;

};
