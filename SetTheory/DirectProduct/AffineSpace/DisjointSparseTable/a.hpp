// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DisjointSparseTable/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/1053216 (DisjointSparseTable)

// M.One()による初期化O(size log size)
// 配列による初期化O(N log N)

// 区間積取得O(__builtin_clzの計算量)
template <typename U , typename MONOID>
class AbstractDisjointSparseTable
{
  
private:
  MONOID m_M;
  int m_size;
  // m_prod[v][i]に付値vの点からiまでの累積積（右または左に向かう右区間積）を格納。
  // 右に向かう場合は付値vの点を左端に持つ閉区間、左に向かう場合は右端に持つ開区間を扱う。
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
// 加法は累積和で良いので、最大値に特殊化したものを扱う。
// 最大値はSparse Tableでも良いが、乗法よりは最大値を使うため。
