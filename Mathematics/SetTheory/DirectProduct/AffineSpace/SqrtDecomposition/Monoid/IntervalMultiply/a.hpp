// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalMultiply/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/950345�i��_��Z�A��ԏ�Z�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U��N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})

// ��_���O(N^{1/2})
// M.Product()�ɂ���_��ZO(1)�i�������g���j
// M.Product()�ɂ���ԏ�ZO(N^{1/2})�i�������g���j
template <typename U , typename N_MODULE>
class IntervalMultiplySqrtDecomposition :
  public MonoidSqrtDecomposition<U,N_MODULE>
{

protected:
  vector<U> m_lazy_multiplication;
  
public:
  template <typename...Args> inline IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args );

  template <typename...Args> inline void Reset( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  // �Q�ƕԂ��łȂ����Ƃɒ���
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  inline int Search( const int& i_start , const U& u ) = delete;

};
template <typename N_MODULE , typename...Args> IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args ) -> IntervalMultiplySqrtDecomposition<inner_t<N_MODULE>,N_MODULE>;
