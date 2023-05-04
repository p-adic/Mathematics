// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once


// InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B
// �g�p���Z�F
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )�i������IntervalSum��p���Ȃ��ꍇ�͕s�v�j
template <typename T , int N>
class BIT
{
private:
  T m_fenwick[N + 1];

public:
  inline BIT();
  BIT( const T ( & a )[N] );

  inline void Set( const int& i , const T& n );

  inline BIT<T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
};

