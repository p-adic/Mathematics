// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalSet/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a_Body.hpp"

// verify:
// https://yukicoder.me/submissions/964805�i�z�񏉊����A��_����A��Ԑρj
// https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I�i�돉�����A��ԑ���A��Ԑώ擾�j
// https://yukicoder.me/submissions/964836�i�z�񏉊����A��ԑ���A��Ԑώ擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U�̔��N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �R���X�g���N�^�ȊO�̑����̎��������m�C�h���������ƈقȂ邽�ߌp�����Ȃ��B

// M.One()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Product()�Ɋւ����Ԑώ擾O(N^{1/2})

// ��_���O(N^{1/2})�i��ԑ�����g���j
// ��ԑ��O(N^{1/2})�i���N���Q�\�����g���j
template <typename U , typename NON_COMM_N_MODULE>
class IntervalSetSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  NON_COMM_N_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  
public:
  // MonoidSqrtDecomposition�̃R���X�g���N�^��m_lazy_substitution,m_suspended�̗돉����
  template <typename...Args> inline IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );

  // �Q�ƕԂ��łȂ����Ƃɒ���
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( i_start , i ) , i )��true�ƂȂ�i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f , const bool& reversed = false );
  // u <= IntervalProduct( i_start , i )�𖞂���i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u , const bool& reversed = false );

private:
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );
  
};
template <typename NON_COMM_N_MODULE , typename...Args> IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , Args&&... args ) -> IntervalSetSqrtDecomposition<inner_t<NON_COMM_N_MODULE>,NON_COMM_N_MODULE>;
