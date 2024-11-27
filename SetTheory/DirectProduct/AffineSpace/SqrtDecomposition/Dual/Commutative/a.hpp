// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961727�i��_��p�A��ԍ�p�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t�����}�O�}�\���ł���B
// (2) X��U�́uL�̊�_��U�̍P���ϊ��ɑΉ����鍶L��p�\���v�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(N)

// ��_�擾O(1)

// ��_���O(N^{1/2})�i�������󋵎����O(1)�j
// X.Action()�ɂ���_��pO(1)�i�������g���j
// X.Action()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_COMM_MAGMA , typename U , typename R_SET>
class CommutativeDualSqrtDecomposition :
  public DualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_SET>
{

public:
  template <typename...Args> inline CommutativeDualSqrtDecomposition( PT_COMM_MAGMA L , R_SET X , Args&&... args );

  inline void Act( const int& i , const R& r );
  
};
template <typename PT_COMM_MAGMA , typename R_SET , typename...Args> CommutativeDualSqrtDecomposition( PT_COMM_MAGMA M , R_SET X , Args&&... args ) -> CommutativeDualSqrtDecomposition<inner_t<PT_COMM_MAGMA>,PT_COMM_MAGMA,inner_t<R_SET>,R_SET>;

