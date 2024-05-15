// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/a.hpp

#pragma once
#include "../Sqrt/a.hpp"

//verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/9207257/C++17�i�돉�����A��ԑ���A��Ԑώ擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t������p�\���i�Ⴆ�Ί�_�t���}�O�}�̐��������Q�\���j�ł���B
// (2) M��U�̍�L��p��N���Q�\���ł����Ĉȉ��𖞂����F
//     (2-1) L�̊�_��M�̍P���ϊ��ɑΉ�����B
//     (2-2) L�̍���p��M�̍�L��p�������I�ł���B�i�Ⴆ�΃}�O�}��p�ł���j
// (3) R=int�Ȃ��U��L��p��N���Q�\���������I�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ��p���g��Ȃ��ꍇ�͂��v���̊ɂ�IntervalSetSqrtDecomposition���g�p�\�B
// ��ԏ�Z��ǉ����Ă��v���ƌv�Z�ʂ̃I�[�_�[�͕ς��Ȃ����A�萔�{�x���Ȃ�B

// ��ԍ�p���s��Ȃ��ꍇ��m_L.Point()�̍�p����Ԑςɗp���邽�߁A
// dummy�ɂ���RegularRSet(MultiplicativeMonoid(1))�Ȃǂ�p����K�v�����邱�Ƃɒ��ӁB

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_���O(N^{1/2})�iM��N���Q�����g���j
// ��ԑ��O(N^{1/2})�iM��N���Q�����g���j
// M.Act()�ɂ���_��p�͂Ȃ��B
// M.Act()�ɂ���ԍ�pO(N^{1/2})

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})�iM�̃��m�C�h�����g���j
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class LazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  vector<R> m_lazy_action;

public:
  // vector���\�z���鎞��
  // vector t( N , LazySqrtDecomposition{L,M} );
  // �Ƃ���Initialise����΂悢�B
  template <typename...Args> inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

private:
  inline void Construct();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
};
template <typename PT_MAGMA , typename R_MODULE , typename...Args> LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const Args&... args ) -> LazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<R_MODULE>,R_MODULE>;
