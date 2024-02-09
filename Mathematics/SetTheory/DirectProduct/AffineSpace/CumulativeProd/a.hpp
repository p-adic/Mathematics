// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/946991�i���ݐϐρj
// https://atcoder.jp/contests/agc023/submissions/49678399�i���E��Ԑϋt�������グ�j

// �؏�ŌQ�ɒl�����֐��̗ݐϐς��v�Z����B
template <typename U>
class VirtualCumulativeProd
{

public:
  // 0 <= i,j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // i����ւ�path��i=v_0->...->v_k=j�̎��ASet�����z��a�ɑ΂���
  // �E����a[v_0]...a[v_k]���v�Z����B
  virtual U PathProd( const int& i , const int& j ) = 0;

protected:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

template <typename U , typename GROUP>
class PathProdImplementation :
  virtual public VirtualCumulativeProd<U>
{

protected:
  int m_size;
  GROUP m_M;
  vector<U> m_right;
  vector<U> m_left;

public:
  inline PathProdImplementation( const int& size , GROUP M );
  inline U PathProd( const int& i , const int& j );

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
class AbstractCumulativeProd :
  public PathProdImplementation<U,GROUP>
{

public:
  inline AbstractCumulativeProd(  GROUP M , const vector<U>& a = vector<U>() );

  inline void Set( const vector<U>& a );
  // a[i]��M.Product(a[i],u)�ɒu���ς���B
  inline void RightMultiply( const int& i , const U& u );
  // a[i]��M.Product(u,a[i])�ɒu���ς���B
  inline void LeftMultiply( const int& i , const U& u );


  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // �E��Ԑ�a[i]...a[j]��M�Ɋւ��Čv�Z����B
  inline U RightIntervalProd( const int& i , const int& j );
  // ����Ԑ�a[j]...a[i]��M�Ɋւ��Čv�Z����B
  inline U LeftIntervalProd( const int& i , const int& j );

  // �ȉ���M.Product()�����g�p���Ȃ��̂ŁAM.Product()���Q���Z�ł��������M.One()��M.Inverse()�����֌W�ȉ��Z�ł��悢�B
  // M�Ɋւ���E��Ԑ�a[i]...a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountRightIntervalProdInverseImage( const U& u = One() );
  // M�Ɋւ��鍶��Ԑ�a[j]...a[i]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountLeftIntervalProdInverseImage( const U& u = One() );

  // RightIntervalProd( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int RightBinarySearch( const int& i_start , const U& u );
  // LeftIntervalProd( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int LeftBinarySearch( const int& i_start , const U& u );
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );
  inline const U& One() const;

};
template <typename GROUP> AbstractCumulativeProd( GROUP M ) -> AbstractCumulativeProd<inner_t<GROUP>,GROUP>;

template <typename U>
class CumulativeSum :
  public AbstractCumulativeProd<U,AdditiveGroup<U>>
{

public:
  inline CumulativeSum( const vector<U>& a = vector<U>() );

  // a[i]��M.Sum(u,a[i])�ɒu���ς���B
  inline void Add( const int& i , const U& u );

  // 0 <= i����i-1 <= j < m_size�̏ꍇ�̂݃T�|�[�g�B
  // ��Ԙaa[i]+...+a[j]���v�Z����B
  inline U IntervalSum( const int& i , const int& j );

  // ��Ԙaa[i]+...+a[j]��u�Ɠ��������[i,j]�̌����v�Z����B
  ll CountIntervalSumInverseImage( const U& u = U() );

  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ���\�j�B
  int BinarySearch( const int& i_start , const U& u );

};
