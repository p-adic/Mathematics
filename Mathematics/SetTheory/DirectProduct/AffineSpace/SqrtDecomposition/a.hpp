// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a.hpp

#pragma once
#include "a_macro.hpp"

#include "Sqrt/a.hpp"

// verify:
// https://yukicoder.me/submissions/981574�i�돉�����A��_���Z�A��Ԙa�j

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()�͈�_����ɂ̂ݎg�p����̂ň�_��������Ȃ��Ȃ��M.Inverse()��
// �K���ɒ�`����Ηǂ����A������̓��m�C�h�����������g���΂悢�B
// �܂���_���Z�ȊO��HybridBIT�̉��ʌ݊��ł���̂ň�_���Z���s�v�Ȃ�HybridBIT���g���Ηǂ��B

// M.Zero()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_���O(1)�i�����Ƌt�����g���j
// M.Sum()�ɂ���_���ZO(1)�i�������g���j

// ��_�擾O(1)
// M.Sum()�Ɋւ����Ԙa�擾O(N^{1/2})

// �ȉ����͈͓͂̔��ŗv��
// (2) bool operator<(const U&,const U&)�Ɋւ���M��U�̑S���������m�C�h�\���ł���B
// (3) m_a,m_b�̑S�Ă̐�����M.Zero()�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M.Sum()�Ɋւ����Ԙa�̒l�T��O(N^{1/2})
template <typename U , typename ABELIAN_GROUP>
class AbstractSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

private:
  ABELIAN_GROUP m_M;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  template <typename...Args> inline AbstractSqrtDecomposition( ABELIAN_GROUP M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline AbstractSqrtDecomposition( ABELIAN_GROUP M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalSum( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalSum( i_start , i )�𖞂���i_start�ȏ�̍ŏ���i��T���B
  // ���݂��Ȃ��ꍇ��-1��Ԃ��B
  inline int Search( const int& i_start , const U& u );
  
private:
  void Construct();
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractSqrtDecomposition( ABELIAN_GROUP M , Args&&...args ) -> AbstractSqrtDecomposition<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class SqrtDecomposition :
  public AbstractSqrtDecomposition<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline SqrtDecomposition( Args&&... args );
  
};
template <typename U , typename...Args> SqrtDecomposition( vector<U> a , Args&&...args ) -> SqrtDecomposition<U>;
