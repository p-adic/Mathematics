// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// https://yukicoder.me/submissions/1101956�i��_���Z�A��ԉ��Z�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U��Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// m_M.Zero()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_���O(log_2 size)
// m_M.Sum()�ɂ���_���ZO(log_2 size)
// m_M.Sum()�ɂ���ԉ��ZO(log_2 size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������Q�\���ł���B
// (3) �e������M.Zero()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// U.Sum()�ɂ��n�ؕИa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O((log_2 size)^2)
// ���[�_���Œ肵������U.Sum()�ɂ���Ԙa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O((log_2 size)^2)
template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
  
protected:
  Z_MODULE m_M;
  // ������1���炵�����̊K������̔����i-(i-1)(a_i - a_{i-1})�j��BIT�ŊǗ�
  AbstractBIT<U,Z_MODULE> m_bit_0;
  // �K������ia_i - a_{i-1}�j��BIT�ŊǗ�
  AbstractBIT<U,Z_MODULE> m_bit_1;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const int& size = 0 );
  AbstractIntervalAddBIT( Z_MODULE M , vector<U> a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int Search( const int& i_start , const F& f );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int Search( const U& u );
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int Search( const int& i_start , const U& u );

};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddBIT :
  public AbstractIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddBIT( const Args&... args );
  
};
template <typename U> IntervalAddBIT( const vector<U>& a ) -> IntervalAddBIT<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractIntervalAddBIT<U,Z_MODULE>& bit );
