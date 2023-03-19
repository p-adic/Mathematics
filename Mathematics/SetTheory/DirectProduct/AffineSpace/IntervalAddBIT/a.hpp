// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalAddBIT/a.hpp

#pragma once
#include "../BIT/a.hpp"

// �g�p���Z�F
// T& T::operator=( const T& )�iBIT���̂��̂Ɏg�p�j
// T& T::operator+=( const T& )
// T& operator+( const T& , const T& )
// T operator-( const T& )
// T operator-( const T& , const T& )
template <typename T , int N>
class IntervalAddBIT
{
private:
  // ��֐��̔����̕��̊K������i(i-1)a_{i-1} - ia_i�j�̊Ǘ�
  BIT<T,N> m_bit_0;
  // �K������ia_i - a_{i-1}�j�̊Ǘ�
  BIT<T,N> m_bit_1;

public:
  inline IntervalAddBIT();
  inline IntervalAddBIT( const T ( & a )[N] );

  inline void Set( const int& i , const T& n );

  inline IntervalAddBIT<T,N>& operator+=( const T ( & a )[N] );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  inline T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );
  
};
