// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Coordinate/a.hpp

#pragma once

class SqrtDecompositionCoordinate
{

protected:
  int m_N;
  int m_N_sqrt;
  // m_N / m_N_sqrt à»è„Ç≈Ç†ÇÈç≈è¨ÇÃêÆêîÅB
  int m_N_d;
  // m_N à»è„Ç≈Ç†ÇÈç≈è¨ÇÃ m_N_sqrt ÇÃî{êîÅB
  int m_N_m;

public:
  inline SqrtDecompositionCoordinate( const int& N = 0 );
  inline SqrtDecompositionCoordinate( const int& N , const int& N_sqrt );
  inline const int& size() const noexcept;
  inline const int& BucketSize() const noexcept;
  inline const int& BucketCount() const noexcept;

};
