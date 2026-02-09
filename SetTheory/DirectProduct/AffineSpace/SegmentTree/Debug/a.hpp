// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/Debug/a.hpp

#pragma once
#include "../../../../../Algebra/Monoid/Semilattice/a.hpp"

#include "../../../../../../Error/Debug/a.hpp"

// デバッグ用に通常の配列を折衷し出力機能を追加したもの。
// 通常のSegmentTreeと比べると各種更新操作にO(N)かかることに注意。

template <typename U , typename MONOID>
class AbstractSegmentTree :
  public Debug
{
  
private:
  MONOID m_M;
  int m_size;
  int m_power;
  vector<U> m_a;

public:
  inline AbstractSegmentTree( MONOID M , const int& size = 0 , const bool& output_mode = true );
  inline AbstractSegmentTree( MONOID M , const vector<U>& a , const bool& output_mode = true );

  template <typename...Args> inline void Initialise( const Args&... args );
  void Set( const int& i , const U& u );

  inline const int& size() const noexcept;
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

template <class Traits , typename U , typename MONOID> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractSegmentTree<U,MONOID>& st );
