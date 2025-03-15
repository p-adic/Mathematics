// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/959653（Abstract、配列による初期化、一点更新、区間積取得）
// https://yukicoder.me/submissions/1053217（配列による初期化、区間最大値取得）

// M.One()による初期化O(size)
// 配列による初期化O(N)

// 一点更新O(log_2 N)

// 一点取得O(1)
// 区間積取得O(log_2 N)
template <typename U , typename MONOID>
class AbstractSegmentTree
{
  
private:
  MONOID m_M;
  int m_size;
  int m_power;
  vector<U> m_a;

public:
  inline AbstractSegmentTree( MONOID M , const int& size = 0 );
  inline AbstractSegmentTree( MONOID M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  void Set( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

};
template <typename MONOID , typename...Args> AbstractSegmentTree( MONOID M , const Args&... args ) -> AbstractSegmentTree<inner_t<MONOID>,MONOID>;

template <typename U>
class SegmentTree :
  public AbstractSegmentTree<U,MaxSemilattice<U>>
{

public:
  template <typename...Args> inline SegmentTree( const U& zero_U , const Args&... args );

  inline U IntervalMax( const int& i_start , const int& i_final );

};
// 加法はBITで良いので、最大値に特殊化したものを扱う。
// IntervalMaxBITより一点更新が速い。
