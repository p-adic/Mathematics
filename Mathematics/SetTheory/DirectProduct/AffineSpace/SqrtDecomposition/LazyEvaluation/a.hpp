// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t���}�O�}�\���ł���B
// (2) M��U�́uL�̊�_��U�̍P���ϊ��ɑΉ�����U�̍�L��p��N���Q�\���v�ł���B
// (3) R!=int�ł���B�iL��p��N���Q�\���̋�ʂ̂��߁j
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ��ԏ�Z��ǉ����Ă��v���ƌv�Z�ʂ̃I�[�_�[�͕ς��Ȃ����A�萔�{�x���Ȃ�B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})�iM�̃��m�C�h�����g���j

// ��_���O(N^{1/2})�iM��N���Q�����g���j
// ��ԑ��O(N^{1/2})�iM��N���Q�����g���j
// M.Act()�ɂ���_��p�͂Ȃ��B
// M.Act()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class LazySqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_M;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  vector<R> m_lazy_action;

public:
  inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a );
  inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const int& N_sqrt );
  
  template <typename...Args> inline void Reset( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

private:
  inline void Initialise();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
};
template <typename PT_MAGMA , typename U , typename R_MODULE , typename...Args> LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const Args&... args ) -> LazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,U,R_MODULE>;
