// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942885�i�돉�����A��_���Z�A��Ԙa�j

// ���Z��operator+=�łȂ��ꍇ�Ɏg�p�B
// M_T�͏�Zm_T:T^2->T�ɑ�������^�B
// I_T�͋t��i_T:T->T�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,e_T:1->T)�����Q�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������i_T���g���̂�Set��IntervalSum�݂̂Ȃ̂ŁA
// Add��InitialSegmentSum�����g��Ȃ��ꍇ��
// i_T���D���ɐݒ肵��(T,m_T,e_T)�����m�C�h�Ƃ��ėǂ��B

// e_T�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// LSB�ؕИa�擾O(1)�ia[j-(j&-j)]+...+a[j-1]�j
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_�X�VO(log_2 size)
// ��_���ZO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const T&,const T&)�Ɋւ���(T,m_T:T^2->T,e_T:1->T)�������Q�ł���B
// (3) �e������e_T��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �n�ؕИa��n�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename T , typename M_T , typename I_T>
class AbstractBIT
{
private:
  M_T m_m_T;
  T m_e_T;
  I_T m_i_T;
  int m_size;
  vector<T> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( M_T m_T , T e_T , I_T i_T , const int& size = 0 );
  inline AbstractBIT( M_T m_T , T e_T , I_T i_T , const vector<T>& a );

  inline AbstractBIT<T,M_T,I_T>& operator=( AbstractBIT<T,M_T,I_T>&& a );
  
  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );
  inline AbstractBIT<T,M_T,I_T>& operator+=( const vector<T>& a );
  void Add( const int& i , const T& n );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline T operator[]( const int& i ) const;
  inline T Get( const int& i ) const;
  inline const T& LSBSegmentSum( const int& j ) const;
  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;

  // InitialSegmentSum( i )��n�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )��n�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
