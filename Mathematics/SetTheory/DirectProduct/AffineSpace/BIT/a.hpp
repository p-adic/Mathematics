// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

// InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B
// �g�p���Z�F
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )�i������IntervalSum��p���Ȃ��ꍇ�͕s�v�j
// T operator<( const T& , const T& )�i������BinarySearch��p���Ȃ��ꍇ�͕s�v�j
template <typename T , int N>
class BIT
{
private:
  T m_fenwick[N + 1];

public:
  inline BIT();
  BIT( const T ( & a )[N] );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );

  inline BIT<T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=�̒P�ʌ�T()��菬�����Ȃ��v�f�݂̂𐬕��Ɏ��ꍇ�̂݃T�|�[�g�B
  // InitialSegmentSum( i )��n�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )��t�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
