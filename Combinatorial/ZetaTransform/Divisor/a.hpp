// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"

// verify:
// https://yukicoder.me/submissions/1014293 (DivisorZetaTransform)
// https://yukicoder.me/submissions/1016342 (MultipleZetaTransform, Add, InitialSegmentSum, InverseImageSum)

// LD��LeastDivisor����ꉻ�����^�B
template <typename LD>
class DivisorMoeviusFunction
{

private:
  vector<int> m_val;
  
public:
  // O( n_max )
  inline DivisorMoeviusFunction( const LD& ld , const int& n_max );

  // �ÓT�I�ȂP�ϐ����r�E�X�֐�mu��mu(t1/t0)�ɂ��Q�ϐ����B
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename LD>
class MultipleMoeviusFunction
{

private:
  vector<int> m_val;

public:
  // O( n_max )
  inline MultipleMoeviusFunction( const LD& ld , const int& n_max );

  // �ÓT�I�ȂP�ϐ����r�E�X�֐�mu��mu(t0/t1)�ɂ��Q�ϐ����B
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename LD>
class DivisorEdge
{

private:
  const LD* m_p_ld;

public:
  inline DivisorEdge( const LD& ld );
  inline vector<int> operator()( const int& t );

};

class MultipleEdge
{

private:
  int m_size;

public:
  inline MultipleEdge( const int& size );
  inline vector<int> operator()( const int& t );

};


// �񐔂��킽�鑍�a���Ǘ�����B

// ���͈͓͂̔��ŗv��
// (1) R�͔�P�ʓIZ�㐔�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B��_�擾�Ƌt���a�擾�ɂ̂�mu���g���B
// �������S�̉��Z���_�擾���s��Ȃ��Ȃ��R�̓_�~�[��Z��p������P�ʓI�ł��ǂ��B

// R.Zero()�ɂ�鏉����O(size log log size)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(size log size)
// �[�[�^�ϊ���̔z��ɂ�鏉����O(size log log size)

// ��_���ZO(size/t)
// �S�̉��ZO(size)
// �e�_���@O(size)
// �S�̏�ZO(size)
// ��ݍ��ݏ�@O(size)

// ��_�擾O(d(t)) = O(log t/log log t)
// �n�ؕИa�擾O(1)

// �t���a�擾O(d(f_inv_max(r_max)))
// �n�ؕЋt���a�擾O(1)
template <typename LD , typename U , typename Z_ALG>
class AbstractDivisorZetaTransform :
  public AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<LD>>
{

public:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed = false );

  // a,b��a��b�̖񐔂ł���萔 in [1,size)�Ƃ��āA
  // f_inv_max=id
  // range=a�̔{���ł���b�̖񐔑S�̂̏W����Ԃ��萔�֐�
  // �ƒ�߂�ƁA
  // �t���aInverseImageSum(f_inv_max,range,b)��
  // lcm(a,t)��b�̔{���ł���size�����̊e������t���킽��m_val[t]�̑��a�B

private:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed );

};
template <typename LD , typename Z_ALG , typename...Args> AbstractDivisorZetaTransform( const LD& , Z_ALG , Args&&... ) -> AbstractDivisorZetaTransform<LD,inner_t<Z_ALG>,Z_ALG>;

template <typename LD , typename U>
class DivisorZetaTransform :
  public AbstractDivisorZetaTransform<LD,U,Algebra<int,U>>
{

public:
  inline DivisorZetaTransform( const LD& ld , const U& one , const int& size );
  inline DivisorZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed = false );

};


// �{�����킽�鑍�a���Ǘ�����B

// ���͈͓͂̔��ŗv��
// (1) R�͔�P�ʓIZ�㐔�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B��_�擾�Ƌt���a�擾�ɂ̂�mu���g���B
// �������S�̉��Z���_�擾���s��Ȃ��Ȃ��R�̓_�~�[��Z��p������P�ʓI�ł��ǂ��B

// R.Zero()�ɂ�鏉����O(size log log size)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(size log size)
// �[�[�^�ϊ���̔z��ɂ�鏉����O(size log log size)

// ��_���ZO(d(t)) = O(log t/log log t)
// �S�̉��ZO(size)
// �e�_���@O(size)
// �S�̏�ZO(size)
// ��ݍ��ݏ�@O(size)

// ��_�擾O(size/t)
// �n�ؕИa�擾O(1)

// �t���a�擾O(size/t)
// �n�ؕЋt���a�擾O(1)
template <typename LD , typename U , typename Z_ALG>
class AbstractMultipleZetaTransform :
  public AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<LD>>
{

public:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed = false );

  // a��萔in [1,size)�Ƃ���
  // f_inv_max=id
  // range=a�̖񐔑S�̂̏W����Ԃ��萔�֐�
  // �ƒ�߂�ƁA
  // �t���aInverseImageSum(f_inv_max,range,b)��
  // a�ƌ݂��ɑf��size�����̊e������t���킽��m_val[t]�̑��a�B

private:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed );

};
template <typename LD , typename Z_ALG , typename...Args> AbstractMultipleZetaTransform( const LD& , Z_ALG , Args&&... ) -> AbstractMultipleZetaTransform<LD,inner_t<Z_ALG>,Z_ALG>;

template <typename LD , typename U>
class MultipleZetaTransform :
  public AbstractMultipleZetaTransform<LD,U,Algebra<int,U>>
{

public:
  inline MultipleZetaTransform( const LD& ld , const U& one , const int& size );
  inline MultipleZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed = false );

};
