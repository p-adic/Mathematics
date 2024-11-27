// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/Commutative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/964782�i�돉�����A��_��Z�A��Ԑρj

// ���͈͓͂̔��ŗv��
// (1) M��U�̉����m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ��_��Z�ȊO��MonoidBIT�̉��ʌ݊��ł���̂ň�_��Z���s�v�Ȃ�MonoidBIT���g���Ηǂ��B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})

// ��_���O(N^{1/2})
// M.Product()�ɂ���_��ZO(1)�i�������g���j

// �ȉ����͈͓͂̔��ŗv��
// (2) bool operator<(const U&,const U&)�Ɋւ���M��U�̑S�������m�C�h�\���ł���B
// (3) m_a,m_b�̑S�Ă̐�����M.One()�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M.Product()�Ɋւ����Ԑς̒l�T��O(N^{1/2})
template <typename U , typename COMM_MONOID>
class CommutativeMonoidSqrtDecomposition :
  virtual public MonoidSqrtDecomposition<U,COMM_MONOID>
{
  
public:
  template <typename...Args> inline CommutativeMonoidSqrtDecomposition( COMM_MONOID M , Args&&... args );

  inline void Multiply( const int& i , const U& u );
  
};
template <typename COMM_MONOID , typename...Args> CommutativeMonoidSqrtDecomposition( COMM_MONOID M , Args&&...args ) -> CommutativeMonoidSqrtDecomposition<inner_t<COMM_MONOID>,COMM_MONOID>;
