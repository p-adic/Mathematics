// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"
#include "../../../Arithmetic/Divisor/Constexpr/a.hpp"
#include "../../../Arithmetic/Divisor/Moevius/Constexpr/a.hpp"

// verify:
// https://yukicoder.me/submissions/970736�iMultipleZetaTransform, Add, InitialSegmentSum, InverseImageSum�j

// MU��MoeviusFunction����ꉻ�����^�B
// LD��LeastDivisor����ꉻ�����^�B

template <typename MU>
class DivisorMoeviusFunction
{

private:
  const MU* m_p_mu;
  
public:
  // O( size )
  inline constexpr DivisorMoeviusFunction( const MU& mu );

  // �ÓT�I�ȂP�ϐ����r�E�X�֐�mu��mu(t1/t0)�ɂ��Q�ϐ����B
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename MU>
class MultipleMoeviusFunction
{

private:
  const MU* m_p_mu;

public:
  // O( size )
  inline constexpr MultipleMoeviusFunction( const MU& mu );

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
template <typename LD , typename MU , typename U , typename Z_ALG>
class AbstractDivisorZetaTransform :
  public AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<MU>>
{

private:
  MU m_mu;

public:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size = 0 );
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
template <int val_limit , typename Z_ALG , typename...Args> AbstractDivisorZetaTransform( const LeastDivisor<int,val_limit>& , Z_ALG , Args&&... ) -> AbstractDivisorZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,inner_t<Z_ALG>,Z_ALG>;

template <int val_limit , typename U>
class DivisorZetaTransform :
  public AbstractDivisorZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>
{

public:
  template <typename...Args> inline DivisorZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args );

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
template <typename LD , typename MU , typename U , typename Z_ALG>
class AbstractMultipleZetaTransform :
  public AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<MU>>
{

private:
  MU m_mu;

public:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size = 0 );
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
template <int val_limit , typename Z_ALG , typename...Args> AbstractMultipleZetaTransform( const LeastDivisor<int,val_limit>& , Z_ALG , Args&&... ) -> AbstractMultipleZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,inner_t<Z_ALG>,Z_ALG>;

template <int val_limit , typename U>
class MultipleZetaTransform :
  public AbstractMultipleZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>
{

public:
  template <typename...Args> inline MultipleZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args );

};
