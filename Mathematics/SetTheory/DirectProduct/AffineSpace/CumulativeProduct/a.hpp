// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/950143�iAbstract�A�z�񏉊����A���ݐϐρj
// https://yukicoder.me/submissions/950139�i�z�񏉊����A��Ԙa�j
// https://atcoder.jp/contests/agc023/submissions/50204861�i�z�񏉊����A��Ԙa�t�������グ�j

// �؏�ŌQ�ɒl�����֐��̗ݐϐς��v�Z����B
template <typename U>
class VirtualCumulativeProduct
{

public:
  // 0 <= i,j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // i����ւ�path��i=v_0->...->v_k=j�̎��ASet�����z��a�ɑ΂���
  // �E����a[v_0]...a[v_k]���v�Z����B
  virtual U PathProduct( const int& i , const int& j ) = 0;

protected:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

template <typename U , typename GROUP>
class PathProductImplementation :
  virtual public VirtualCumulativeProduct<U>
{

protected:
  int m_size;
  GROUP m_M;
  vector<U> m_right;
  vector<U> m_left;

public:
  inline PathProductImplementation( const int& size , GROUP M );
  inline U PathProduct( const int& i , const int& j );

};

// �؂����ɒʏ�̔z��ł���ꍇ�B
// ���͈͓͂̔��ŗv��
// (1) M��U�̌Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.one()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_����ZO(size)
// ��_�E��ZO(size)

// �E��Ԑώ擾O(1)
// ����Ԑώ擾O(1)

// �E��Ԑϋt�������グO(size log size)
// �E��Ԑϋt�������グO(size log size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������Q�\���ł���B
// (3) �e������M.One()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ���[�_���Œ肵�����ɍ���Ԑς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// ���[�_���Œ肵�����ɉE��Ԑς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
template <typename U , typename GROUP>
class AbstractCumulativeProduct :
  public PathProductImplementation<U,GROUP>
{

public:
  inline AbstractCumulativeProduct( GROUP M , const vector<U>& a = vector<U>() );

  inline void Set( const vector<U>& a );
  // a[i]��M.Product(a[i],u)�ɒu���ς���B
  inline void RightMultiply( const int& i , const U& u );
  // a[i]��M.Product(u,a[i])�ɒu���ς���B
  inline void LeftMultiply( const int& i , const U& u );

  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E��Ԑ�a[i]...a[j]��M�Ɋւ��Čv�Z����B
  inline U RightIntervalProduct( const int& i , int j );
  // ����Ԑ�a[j]...a[i]��M�Ɋւ��Čv�Z����B
  inline U LeftIntervalProduct( const int& i , int j );

  // �ȉ���M.Product()�����g�p���Ȃ��̂ŁAM.Product()���Q���Z�ł��������M.One()��M.Inverse()�����֌W�ȉ��Z�ł��悢�B
  // M�Ɋւ���E��Ԑ�a[i]...a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountRightIntervalProductInverseImage( const U& u = One() );
  // M�Ɋւ��鍶��Ԑ�a[j]...a[i]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountLeftIntervalProductInverseImage( const U& u = One() );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( RightIntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const int& i_start , const F& f );
  // f( LeftIntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i��
  // ���݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const int& i_start , const F& f );
  // RightIntervalProduct( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  int RightBinarySearch( const int& i_start , const U& u );
  // LeftIntervalProduct( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  int LeftBinarySearch( const int& i_start , const U& u );
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );
  inline const U& One() const;

};
template <typename GROUP> AbstractCumulativeProduct( GROUP M ) -> AbstractCumulativeProduct<inner_t<GROUP>,GROUP>;

template <typename U>
class CumulativeSum :
  public AbstractCumulativeProduct<U,AdditiveGroup<U>>
{

public:
  inline CumulativeSum( const int& size = 0 );
  inline CumulativeSum( const vector<U>& a );

  // a[i]��M.Sum(u,a[i])�ɒu���ς���B
  inline void Add( const int& i , const U& u );

  // ��Ԙaa[i]+...+a[j]���v�Z����B
  inline U IntervalSum( const int& i , int j );

  // ��Ԙaa[i]+...+a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountIntervalSumInverseImage( const U& u = U() );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�܂���U�B
  // �O�҂̏ꍇ��f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i���A
  // ��҂̏ꍇ��IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F> int BinarySearch( const int& i_start , const F& f );

};
