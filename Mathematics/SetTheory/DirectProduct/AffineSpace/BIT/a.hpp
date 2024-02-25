// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/950337�i�돉�����A��_���Z�A��Ԙa�j
// https://yukicoder.me/submissions/950342�i�돉�����A�z�񏉊����A�n�ؕИa�j
// https://yukicoder.me/submissions/955156�i�z�񏉊����A��_���Z�A�ʏ�̓񕪒T���j

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���̂�Set��IntervalSum�ƒP���֌W�Ɋւ����Ԃł�BinarySearch�݂̂Ȃ̂ŁA
// Add��InitialSegmentSum�Ƃ��̑���BinarySearch�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// U.Sum()�ɂ��LSB�ؕИa�擾O(1)�ia[j-(j&-j)]+...+a[j-1]�j
// U.Sum()�ɂ��n�ؕИa�擾O(log_2 size)
// U.Sum()�ɂ���Ԙa�擾O(log_2 size)

// ��_���O(log_2 size)
// U.Sum()�ɂ���_���ZO(log_2 size)
// U.Sum()�ɂ����@O(size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������Q�\���ł���B
// (3) �e������M.One()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// U.Sum()�ɂ��n�ؕИa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// ���[�_���Œ肵������U.Sum()�ɂ���Ԙa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_size;
  vector<U> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a );
  
  template <typename...Args> inline void Reset( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline AbstractBIT<U,ABELIAN_GROUP>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int BinarySearch( const int& i_start , const F& f );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  inline int BinarySearch( const U& u );
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  inline int BinarySearch( const int& i_start , const U& u );

private:
  inline void Initialise();

  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class BIT :
  public AbstractBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline BIT( const Args&... args );

};
template <typename U> BIT( const vector<U>& a ) -> BIT<U>;
