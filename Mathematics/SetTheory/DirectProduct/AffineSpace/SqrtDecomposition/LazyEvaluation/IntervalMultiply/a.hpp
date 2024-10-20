// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a.hpp"

// verify:
// https://judge.yosupo.jp/submission/209796�i�z�񏉊����A��ԍ�p�A��ԏ�Z�A��Ԑώ擾�j
// https://yukicoder.me/submissions/959027�i�z�񏉊����A��ԑ���A��ԏ�Z�A��Ԑώ擾�j

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t���}�O�}�\���ł���B
// (2) M��U�̍�L��p�t����N���Q�\���ł����āAL�̊�_��M�̍P���ϊ��ɑΉ�����B
// (3) R=int�Ȃ��U�̍�L��p�Ɖ�N���Q�\���������I�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ��ԍ�p���s��Ȃ��ꍇ��m_L.Point()�̍�p����Ԑςɗp���邽�߁A
// dummy�ɂ���RegularRSet(MultiplicativeMonoid(1))�Ȃǂ�p����K�v�����邱�Ƃɒ��ӁB

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})�iM�̃��m�C�h�����g���j

// ��_���O(N^{1/2})�iM�̔��N���Q�����g���B�����x���]������Ă��Ȃ�����O(1)�j
// ��ԑ��O(N^{1/2})�iM�̔��N���Q�����g���j
// M.Product()�ɂ���_��Z�͂Ȃ��B
// M.Product()�ɂ���ԏ�ZO(N^{1/2})�iM�̉������g���j
// M.Act()�ɂ���_��p�͂Ȃ��B
// M.Act()�ɂ���ԍ�pO(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE>
class IntervalMultiplyLazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  RN_BIMODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  // ����̒x���]���B���̒x���]�������p����B
  // �Ō�ɓK�p����悤�ɊǗ����邽�߁A��ԍ�p���ԏ�@�͂����ɑ����ɓK�p����B
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  // ��p�̒x���]���B
  vector<R> m_lazy_action;
  // ��Z�̒x���]���B
  // (��Z(��p(����)))�̏��ɓK�p����悤�ɊǗ����邽�߁A��ԍ�p�͂����ɑ����ɓK�p����B
  vector<U> m_lazy_multiplication;

public:
  // vector���\�z���鎞��
  // vector t( N , IntervalMultiplyLazySqrtDecomposition{L,M} );
  // �Ƃ���Initialise����΂悢�B
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , vector<U> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalProduct( i_start , i )�𖞂���i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u );

private:
  inline void Construct();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  // ��p�Ə�Z�̒x���]�������̏��ɉ�������B
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline void IntervalMultiply_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );

};
template <typename PT_MAGMA , typename RN_BIMODULE , typename...Args> IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const Args&... args ) -> IntervalMultiplyLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<RN_BIMODULE>,RN_BIMODULE>;
