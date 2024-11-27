// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961746�i��_���Z�A��ԉ��Z�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U��Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// M.Sum()�Ɋւ����Ԙa�擾O(N^{1/2})

// ��_���O(1)�i���Q�\�����g���j
// M.Sum()�ɂ���_���ZO(1)�i�������g���j
// M.Sum()�ɂ���ԉ��ZO(N^{1/2})�iN���Q�\�����g���j
template <typename U , typename Z_MODULE>
class IntervalAddAbstractSqrtDecomposition :
  public AbstractSqrtDecomposition<U,Z_MODULE>
{

protected:
  vector<U> m_lazy_addition;
  
public:
  template <typename...Args> inline IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  // �Q�ƕԂ��łȂ����Ƃɒ���
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalSum( const int& i_start , const int& i_final );

  template <typename F , SFINAE_FOR_SD_S> inline int Search( const int& i_start , const F& f , const bool& reversed = false );
  inline int Search( const int& i_start , const U& u , const bool& reversed = false );

private:
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );

};
template <typename Z_MODULE , typename...Args> IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) -> IntervalAddAbstractSqrtDecomposition<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddSqrtDecomposition :
  public IntervalAddAbstractSqrtDecomposition<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddSqrtDecomposition( Args&&... args );
  
};
template <typename U , typename...Args> IntervalAddSqrtDecomposition( vector<U> a , Args&&...args ) -> IntervalAddSqrtDecomposition<U>;
