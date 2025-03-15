// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DisjointSparseTable/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/1053216 (DisjointSparseTable)

// M.One()�ɂ�鏉����O(size log size)
// �z��ɂ�鏉����O(N log N)

// ��Ԑώ擾O(__builtin_clz�̌v�Z��)
template <typename U , typename MONOID>
class AbstractDisjointSparseTable
{
  
private:
  MONOID m_M;
  int m_size;
  // m_prod[v][i]�ɕt�lv�̓_����i�܂ł̗ݐϐρi�E�܂��͍��Ɍ������E��Ԑρj���i�[�B
  // �E�Ɍ������ꍇ�͕t�lv�̓_�����[�Ɏ���ԁA���Ɍ������ꍇ�͉E�[�Ɏ��J��Ԃ������B
  vector<vector<U>> m_prod;

public:
  inline AbstractDisjointSparseTable( MONOID M , const int& size = 0 );
  inline AbstractDisjointSparseTable( MONOID M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalProduct( const int& i_start , const int& i_final );

};
template <typename MONOID , typename...Args> AbstractDisjointSparseTable( MONOID M , const Args&... args ) -> AbstractDisjointSparseTable<inner_t<MONOID>,MONOID>;

template <typename U>
class DisjointSparseTable :
  public AbstractDisjointSparseTable<U,MaxSemilattice<U>>
{

public:
  template <typename...Args> inline DisjointSparseTable( const U& zero_U , const Args&... args );

  inline U IntervalMax( const int& i_start , const int& i_final );

};
// ���@�͗ݐϘa�ŗǂ��̂ŁA�ő�l�ɓ��ꉻ�������̂������B
// �ő�l��Sparse Table�ł��ǂ����A��@���͍ő�l���g�����߁B
