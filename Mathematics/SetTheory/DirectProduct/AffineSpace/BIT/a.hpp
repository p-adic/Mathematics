// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947999�i�돉�����A��_���Z�A��Ԙa�j

// �g�p���Z�F
// U& U::operator=( const U& )
// U& U::operator+=( const U& )
// U operator-( const U& , const U& )�i������IntervalSum��p���Ȃ��ꍇ�͕s�v�j
// U operator<( const U& , const U& )�i������BinarySearch��p���Ȃ��ꍇ�͕s�v�j

// U()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�X�VO(log_2 size)
// +�ɂ���_�X�VO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)

// ��_�擾O(log_2 size)
// LSB�ؕИa�擾O(1)
x// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// �n�ؕИa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// ���[�_���Œ肵�����ɋ�Ԙa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename U>
class BIT
{
private:
  int m_size;
  vector<U> m_fenwick;

  // m_size�ȏ�ł���ŏ���2㰁B
  int m_power;

public:
  inline BIT( const int& size = 0 );
  BIT( const vector<U>& a );

  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );
  inline void Initialise( const int& size = 0 );

  inline BIT<U>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  // a[j-(j&-j)]+...+a[j-1]��Ԃ��B
  inline const U& LSBSegmentSum( const int& j ) const;
  // a[0]+...+a[i_final]��Ԃ��B
  U InitialSegmentSum( const int& i_final ) const;
  // a[i_start]+...+a[i_final]��Ԃ��B
  inline U IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=�̒P�ʌ�U()��菬�����Ȃ��v�f�݂̂𐬕��Ɏ��ꍇ�̂݃T�|�[�g�B
  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��size�ȏ�̍ŏ���2㰁~2-1��Ԃ��isize�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const U& u ) const;
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��size�ȏ�̍ŏ���2㰁~2-1��Ԃ��isize�ȏ�ł��邱�ƂŔ���\�j�B
  inline int BinarySearch( const int& i_start , const U& u ) const;
  
};
