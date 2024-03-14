// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/950346�i��ԍ�p�A��_�擾�j
// https://yukicoder.me/submissions/950347�i��ԍ�p�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t���}�O�}�\���ł���B
// (2) X��U�́uL�̊�_��U�̍P���ϊ��ɑΉ�����U�̍�L��p�\���v�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M�ɉ������ۂ��ꍇ�͈�_��p��O(1)��CommutativeDualSqrtDecomposition���g�p�B

// �z��ɂ�鏉����O(N)

// ��_�擾O(1)

// ��_���O(N^{1/2})�i�������󋵎����O(1)�j
// X.Action()�ɂ���_��p�͂Ȃ��i��_�������ԍ�p���g���j
// X.Action()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class DualSqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_X;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<R> m_b;

public:
  inline DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a );
  inline DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Act( const int& i , const R& r );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  // �Q�ƕԂ��łȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i );
  inline U Get( const int& i );

protected:
  // ��p�̒x���]������������B
  inline void Update( const int& d );
  
};
template <typename PT_MAGMA , typename U , typename R_MODULE , typename...Args> DualSqrtDecomposition( PT_MAGMA M , R_MODULE X , vector<U> a , Args&&... args ) -> DualSqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,U,R_MODULE>;

