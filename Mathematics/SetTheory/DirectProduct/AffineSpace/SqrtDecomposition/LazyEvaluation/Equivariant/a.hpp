// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/Equivariant/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a.hpp"

//verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/9389155/C++17�i�돉�����A��ԑ���A��Ԑώ擾�j

// TRANS�͎ʑ�trans:U \times S \times N ->U�ɑ�������^�ł���B

// ���͈͓͂̔��ŗv��
// (1) L��R�̊�_�t���}�O�}�\���ł���B
// (2) M0��S�̍�L�W���\���ł����āAL�̊�_��S�̍P���ϊ��ɑΉ�����B
// (3) M1��U�̍�L��p�t�����N���Q�\���ł����āAL�̊�_��M�̍P���ϊ��ɑΉ�����B
// (4) R=int�Ȃ��U��L��p�Ɣ��N���Q�\���������I�ł���B
// (5) ����L���ώʑ�univ:S->U�����݂��āA�C�ӂ�(u,s,n) in U \times S \times N
//     �ɑ΂���trans(u,s,n) = u*univ(s)*n�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ��ԍ�p���s��Ȃ��ꍇ��m_L.Point()�̍�p����Ԑςɗp���邽�߁A
// dummy�ɂ���RegularRSet(MultiplicativeMonoid(1))�Ȃǂ�p����K�v�����邱�Ƃɒ��ӁB

// �z��ɂ�鏉����O(N)

// ��_���O(N^{1/2})�͂Ȃ��B
// ��ԑ��O(N^{1/2})�iM1�̔��N���Q�����g���j
// M0.Act()�ɂ���_��p�͂Ȃ��B
// M0.Act()�ɂ���ԍ�pO(N^{1/2})�iuniv��L���ϐ����g���j

// ��_�擾O(1)
// trans�Ɋւ����Ԑώ擾O(N^{1/2})�iM1�̃��m�C�h�����g���j
template <typename R , typename PT_MAGMA , typename S , typename R_SET , typename U , typename RN_BIMODULE , typename TRANS>
class EquivariantLazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  R_SET m_M0;
  RN_BIMODULE m_M1;
  TRANS m_trans;
  vector<S> m_a;
  vector<U> m_b;
  // ����̒x���]���B�ߋ��̍�p�̒x���]�������p����B
  // ��ԍ�p�͂����ɑ����ɓK�p����B
  vector<S> m_lazy_substitution;
  vector<bool> m_suspended;
  // ��p�̒x���]���B
  vector<R> m_lazy_action;

public:
  // vector���\�z���鎞��
  // vector t( N , EquivariantLazySqrtDecomposition{L,M0,M1,vector<S>()} );
  // �Ƃ���Initialise����΂悢�B
  template <typename...Args> inline EquivariantLazySqrtDecomposition( PT_MAGMA L , R_SET M0 , RN_BIMODULE M1 , TRANS trans , vector<S> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const S& s );
  inline void IntervalSet( const int& i_start , const int& i_final , const S& s );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline S operator[]( const int& i );
  inline S Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalProduct( i_start , i )�𖞂���i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u );

private:
  inline U Univ( const S& s , const int& n );
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const S& s );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const S& s );
  // �ׂ�����Ԃ��w�肵�������������A����i_min��i_ulim�̈ʒu�֌W�Ńo�O�点�₷���̂ł��̂܂܁B
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );

  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );
  
};
template <typename PT_MAGMA , typename S , typename R_SET , typename RN_BIMODULE , typename TRANS , typename...Args> EquivariantLazySqrtDecomposition( PT_MAGMA L , R_SET M0 , RN_BIMODULE M1 , TRANS trans , vector<S> a , const Args&... args ) -> EquivariantLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,S,R_SET,inner_t<RN_BIMODULE>,RN_BIMODULE,TRANS>;
