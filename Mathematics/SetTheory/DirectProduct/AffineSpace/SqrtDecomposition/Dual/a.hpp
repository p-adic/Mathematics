// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/961729�i��ԍ�p�A��_�擾�j
// https://yukicoder.me/submissions/961738�i�񌋍��I�}�O�}�A��ԍ�p�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t������p�\���i�Ⴆ�Ί�_�t���}�O�}�̐��������Q�\���j�ł���B
// (2) X��U�̍�L��p�\���ł����Ĉȉ��𖞂����F
//     (2-1) L�̊�_��X�̍P���ϊ��ɑΉ�����B
//     (2-2) L�̍���p��X�̍���p�������I�ł���B�i�Ⴆ�΃}�O�}��p�ł���j
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// L�ɉ��}�O�}�����ۂ��ꍇ�͈�_��p��O(1)��CommutativeDualSqrtDecomposition���g�p�B

// �z��ɂ�鏉����O(N)

// ��_�擾O(1)

// ��_���O(N^{1/2})�i�������󋵎����O(1)�j
// X.Action()�ɂ���_��p�͂Ȃ��i��_�������ԍ�p���g���j
// X.Action()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_SET>
class DualSqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_SET m_X;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<R> m_b;

public:
  inline DualSqrtDecomposition( PT_MAGMA L , R_SET X , vector<U> a = {} );
  inline DualSqrtDecomposition( PT_MAGMA L , R_SET X , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  // Arg��L.Action�̑�1�����Ƃ��ėL���Ȍ^�B
  template <typename Arg> inline void IntervalAct( const int& i_start , const int& i_final , const Arg& r );

  // �Q�ƕԂ��łȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i );
  inline U Get( const int& i );

protected:
  // ��p�̒x���]������������B
  inline void Update( const int& d );
  
};
template <typename PT_MAGMA , typename R_SET , typename...Args> DualSqrtDecomposition( PT_MAGMA M , R_SET X , Args&&... args ) -> DualSqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<R_SET>,R_SET>;

