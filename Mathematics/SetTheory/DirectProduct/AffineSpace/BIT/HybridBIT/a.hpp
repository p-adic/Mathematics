// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/HybridBIT/a.hpp

#pragma once
#include "../../BIT/a.hpp"

//  InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B
template <typename T , int N>
class HybridBIT :
  public BIT<T,N>
{
private:
  T m_a[N];

public:
  inline HybridBIT();
  inline HybridBIT( const T ( & a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline void Set( const int& i , const T& n );

  inline HybridBIT<T,N>& operator+=( const T ( & a )[N] );
  inline void Add( const int& i , const T& n );
  
};

