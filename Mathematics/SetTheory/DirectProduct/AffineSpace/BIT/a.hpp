// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942586

// �z��̊e�v�f��int�^�̔��e�ł����a�������łȂ��ꍇ��T��int�^�ɂ���Ɛ��������삵�Ȃ����Ƃɒ��ӁB
// InitialSegmentSum�ŕ��̓��͂��������߂�uint�ł͂Ȃ�int���e���v���[�g�����ɂ���B

// �g�p���Z�F
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )�i������IntervalSum��p���Ȃ��ꍇ�͕s�v�j
// T operator<( const T& , const T& )�i������BinarySearch��p���Ȃ��ꍇ�͕s�v�j

// T()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// LSB�ؕИa�擾O(1)
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_�X�VO(log_2 size)
// +�ɂ���_�X�VO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)

// �n�ؕИa��n�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename T>
class BIT
{
private:
  int m_size;
  vector<T> m_fenwick;

  // m_size�ȏ�ł���ŏ���2㰁B
  int m_power;

public:
  inline BIT( const int& size = 0 );
  BIT( const vector<T>& a );

  inline BIT<T>& operator=( BIT<T>&& a );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );

  inline BIT<T>& operator+=( const vector<T>& a );
  // 0<=i<m_size�̏ꍇ�͑�i������n�𑫂��A�����łȂ��ꍇ�͉������Ȃ��B
  void Add( const int& i , const T& n );

  // a[j-(j&-j)]+...+a[j-1]��Ԃ��B
  inline const T& LSBSegmentSum( const int& j ) const;
  // a[0]+...+a[i_final]��Ԃ��B
  T InitialSegmentSum( const int& i_final ) const;
  // a[i_start]+...+a[i_final]��Ԃ��B
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=�̒P�ʌ�T()��菬�����Ȃ��v�f�݂̂𐬕��Ɏ��ꍇ�̂݃T�|�[�g�B
  // InitialSegmentSum( i )��n�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��m_size�ȏ�̍ŏ���2㰁~2-1��Ԃ��im_size�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )��n�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��m_size�ȏ�̍ŏ���2㰁~2-1��Ԃ��im_size�ȏ�ł��邱�ƂŔ���\�j�B
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
