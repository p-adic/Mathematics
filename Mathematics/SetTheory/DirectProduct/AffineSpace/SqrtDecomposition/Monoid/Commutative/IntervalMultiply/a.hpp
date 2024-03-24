// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/Commutative/IntervalMultiply/a.hpp

#pragma once
#include "../../../a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/964789�i��_��Z�A��ԏ�Z�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U��N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �R���X�g���N�^�ȊO�̑����̎����������m�C�h���������ƈقȂ邽�ߌp�����Ȃ��B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})

// ��_���O(N^{1/2})
// M.Product()�ɂ���_��ZO(1)�i�������g���j
// M.Product()�ɂ���ԏ�ZO(N^{1/2})�iN���Q�\�����g���j
template <typename U , typename N_MODULE>
class IntervalMultiplySqrtDecomposition
{

protected:
  N_MODULE m_M;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_multiplication;
  
public:
  // MonoidSqrtDecomposition�̃R���X�g���N�^��m_lazy_multiplication�̗돉����
  inline IntervalMultiplySqrtDecomposition( N_MODULE M , const int& N = 0 );
  inline IntervalMultiplySqrtDecomposition( N_MODULE M , const int& N , const int& N_sqrt );
  inline IntervalMultiplySqrtDecomposition( N_MODULE M , vector<U> a );
  inline IntervalMultiplySqrtDecomposition( N_MODULE M , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Multiply( const int& i , const U& u );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  // �Q�ƕԂ��łȂ����Ƃɒ���
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

private:
  // MonoidSqrtDecomposition��IntervalProdct
  inline U IntervalProduct_Body( const int& i_start , const int& i_final );

};
template <typename N_MODULE , typename...Args> IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args ) -> IntervalMultiplySqrtDecomposition<inner_t<N_MODULE>,N_MODULE>;
