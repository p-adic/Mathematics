// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Fast/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"

// verify:
// https://yukicoder.me/submissions/970730�iAbstractFastZetaTransform, InitialSegmentSum�j

template <typename U , typename Z_ALG> class AbstractFastZetaTransform;

class SubsetEdge
{

  template <typename U , typename Z_ALG> friend class AbstractFastZetaTransform;
  
private:
  const int* m_p_size_minus;

public:
  inline vector<int> operator()( const int& t ) const;

};

class SupsetEdge
{

  template <typename U , typename Z_ALG> friend class AbstractFastZetaTransform;
  
private:
  const int* m_p_size_minus;

public:
  inline vector<int> operator()( const int& t ) const;

};

// ���͈͓͂̔��ŗv��
// (1) R��U�̔�P�ʓIZ�㐔�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �������S�̉��Z���_�擾��e�_�擾���s��Ȃ��Ȃ��R�̓_�~�[��Z��p������P�ʓI�ł��ǂ��B

// R.Zero()�ɂ�鏉����O(2^digit)
// �[�[�^�ϊ��O�̔z��ɂ�鏉����O(digit 2^digit)
// �[�[�^�ϊ���̔z��ɂ�鏉����O(1)

// ��_���ZO(2^digit)
// �S�̉��ZO(2^digit)
// ���@O(2^digit)
// �S�̏�ZO(2^digit)
// ��ݍ��ݏ�@O(2^digit)

// ��_�擾O(2^digit)
// �e�_�擾O(digit 2^digit)
// �n�ؕИa�擾O(1)

// �t���a�擾O(�n�ؕ�(-��,f_inv_max(r_max)]�̃T�C�Y)
// �n�ؕЋt���a�擾O(1)
template <typename U , typename Z_ALG>
class AbstractFastZetaTransform :
  public VirtualZetaTransform<int,Graph<SubsetEdge>,Graph<SupsetEdge>,U,Z_ALG>
{

private:
  int m_digit;
  int m_size_minus;
  
public:
  inline AbstractFastZetaTransform( Z_ALG R , const int& digit = 0 );
  inline AbstractFastZetaTransform( Z_ALG R , vector<U> a , const bool& transformed = false );

  // �������r�E�X�ϊ��ɂ�镜��
  vector<U> TotalGet();

private:
  inline AbstractFastZetaTransform( Z_ALG R , const int& size , vector<U>& a , const bool& transformed );
  inline int Moevius( const int& t0 , const int& t1 );

};
template <typename Z_ALG , typename...Args> AbstractFastZetaTransform( Z_ALG R , Args&&... args ) -> AbstractFastZetaTransform<inner_t<Z_ALG>,Z_ALG>;

template <typename U>
class FastZetaTransform :
  public AbstractFastZetaTransform<U,Algebra<int,U>>
{

public:
  template <typename...Args> inline FastZetaTransform( const U& one , Args&&... args );

};
