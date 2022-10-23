// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

//  InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B
template <typename T , int N>
class BIT
{
private:
  T m_fenwick[N + 1];

public:
  inline BIT();
  inline BIT( const T ( & a )[N] );

  inline BIT<T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );
  
};

