// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Coordinate/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Arithmetic/Sqrt/a.hpp"

inline SqrtDecompositionCoordinate::SqrtDecompositionCoordinate( const int& N ) : SqrtDecompositionCoordinate( N , RoundUpSqrt( N ) ) {};
inline SqrtDecompositionCoordinate::SqrtDecompositionCoordinate( const int& N , const int& N_sqrt ) : m_N( N ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) {}
inline const int& SqrtDecompositionCoordinate::size() const noexcept { return m_N; }
inline const int& SqrtDecompositionCoordinate::BucketSize() const noexcept { return m_N_sqrt; }
inline const int& SqrtDecompositionCoordinate::BucketCount() const noexcept { return m_N_d; }
