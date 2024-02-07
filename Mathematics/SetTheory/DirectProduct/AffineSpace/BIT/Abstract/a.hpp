// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947861�i��_���Z�A��Ԙa�j

// ���Z��operator+=�Ȃǂŗ^�����Ă���ꍇ�͓��ꉻ�ł͂Ȃ�
// ../a.hpp
// ���g�����ƂŃt�@�C���e�ʂ��팸����B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���̂�Set��IntervalSum�݂̂Ȃ̂ŁA
// Add��InitialSegmentSum�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// LSB�ؕИa�擾O(1)�ia[j-(j&-j)]+...+a[j-1]�j
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_�X�VO(log_2 size)
// ��_���ZO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������Q�\���ł���B
// (3) �e������M.One()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �n�ؕИa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// ���[�_���Œ肵�����ɋ�Ԙa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
private:
  int m_size;
  ABELIAN_GROUP m_M;
  vector<U> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a = vector<U>() );
  
  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );
  inline AbstractBIT<U,ABELIAN_GROUP>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const U& u );
  // IntervalSum( i_start , i )��n�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  inline int BinarySearch( const int& i_start , const U& u );
  
};
template <typename ABELIAN_GROUP> AbstractBIT( ABELIAN_GROUP M ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;
