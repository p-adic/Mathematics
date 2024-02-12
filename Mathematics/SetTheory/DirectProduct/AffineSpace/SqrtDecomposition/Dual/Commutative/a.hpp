// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/950348�i��_��p�A��ԍ�p�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t�����}�O�}�\���ł���B
// (2) X��U�́uL�̊�_��U�̍P���ϊ��ɑΉ�����U�̍�L��p�\���v�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(N)

// ��_�擾O(1)

// ��_���O(N^{1/2})�i�������󋵎����O(1)�j
// X.Action()�ɂ���_��pO(1)�i�������g���j
// X.Action()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_COMM_MAGMA , typename U , typename R_MODULE>
class CommutativeDualSqrtDecomposition :
  public DualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_MODULE>
{

public:
  template <typename...Args> inline CommutativeDualSqrtDecomposition( PT_COMM_MAGMA L , R_MODULE X , vector<U> a , Args&&... args );

  inline void Act( const int& i , const R& r );
  
};
template <typename PT_COMM_MAGMA , typename U , typename R_MODULE , typename...Args> CommutativeDualSqrtDecomposition( PT_COMM_MAGMA M , R_MODULE X , vector<U> a , Args&&... args ) -> CommutativeDualSqrtDecomposition<inner_t<PT_COMM_MAGMA>,PT_COMM_MAGMA,U,R_MODULE>;

