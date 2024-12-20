// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a.hpp

#pragma once

class SqrtDecompositionCoordinate
{

protected:
  int m_N;
  int m_N_sqrt;
  // m_N / m_N_sqrt 以上である最小の整数。
  int m_N_d;
  // m_N 以上である最小の m_N_sqrt の倍数。
  int m_N_m;

public:
  inline SqrtDecompositionCoordinate( const int& N = 0 );
  inline SqrtDecompositionCoordinate( const int& N , const int& N_sqrt );

  // 2乗がN以上である最小の正整数を返す。
  static inline int Sqrt( const int& N ) noexcept;

};
