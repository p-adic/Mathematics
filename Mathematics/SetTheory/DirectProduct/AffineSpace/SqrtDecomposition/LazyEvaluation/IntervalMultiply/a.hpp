// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/a.hpp

#pragma once
// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/8901822/C++17�i�돉�����A��ԑ���A��Ԑώ擾�j
// https://judge.yosupo.jp/submission/190200�i�z�񏉊����A��ԍ�p�A��ԏ�Z�A��Ԑώ擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t���}�O�}�\���ł���B
// (2) M��U�́uL�̊�_��U�̍P���ϊ��ɑΉ�����U�̍�L��p��N���Q�\���v�ł���B
// (3) R=int�Ȃ��L��p��N���Q�\���������I�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ��ԍ�p���s��Ȃ��ꍇ��m_L.Point()�̍�p����Ԑςɗp���邽�߁A
// dummy�ɂ���MultiplicativeMonoid(1)�Ȃǂ�p����K�v�����邱�Ƃɒ��ӁB

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})�iM�̃��m�C�h�����g���j

// ��_���O(N^{1/2})�iM��N���Q�����g���j
// ��ԑ��O(N^{1/2})�iM��N���Q�����g���j
// M.Product()�ɂ���_��Z�͂Ȃ��B
// M.Product()�ɂ���ԏ�ZO(N^{1/2})�iM�̉������g���j
// M.Act()�ɂ���_��p�͂Ȃ��B
// M.Act()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class IntervalMultiplyLazySqrtDecomposition
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
  vector<U> m_lazy_multiplication;

public:
  // vector���\�z���鎞��
  // vector t( N , IntervalMultiplyLazySqrtDecomposition{L,M} );
  // �Ƃ���Initialise����΂悢�B
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N = 0 );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N , const int& N_sqrt );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const int& N_sqrt );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

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
  inline void IntervalMultiply_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
};
template <typename PT_MAGMA , typename R_MODULE , typename...Args> IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const Args&... args ) -> IntervalMultiplyLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<R_MODULE>,R_MODULE>;
