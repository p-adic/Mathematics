// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1164108 (insert, ItervalCount)

#include "../a.hpp"
#include "../../Multisubset/a.hpp"

// BoundedLineMultiSubsetの定数倍高速化。

// 構築O(ubound)
// 一点挿入O(log ubound)
// 一点削除O(log ubound)
// 一点帰属判定O(log ubound)
// 区間要素数取得O(log ubound)

// 先頭イテレータ取得O(log ubound)
// 末尾イテレータ取得O(log ubound)
// 上限/下限二分探索O(log ubound)

// 最大値/最小値取得O(log ubound)

// 一点連結成分取得O(log ubound)
// 全連結成分取得O(連結成分数 log ubound)

// イテレータへの*は要素への値返し。
// イテレータの++や--は要素の重複を無視することに注意。

template <typename INT = ll>
class NonNegativeLineMultiSubset :
  public AbstractNonNegativeLineSubset<INT,BIT> ,
  virtual public VirtualBoundedLineMultiSubset<int,INT,const int&,const int&,BIT>
{
  
public:
  inline NonNegativeLineMultiSubset( const int& ubound );

  // 以下のdeleteされていないメソッドはVirtualBoundedLineMultiSubset内で定義されている。
  // inline void insert( const INT1& i , const INT2& c = 1 );
  // inline void erase( const INT1& i , const INT2& c = 1 );
  // inline void EraseAll( const INT1& i );

  // // itrをインクリメントして書き換え、それへの参照を返す。
  // inline iterator& erase( iterator& itr );
  // inline void clear();

  // inline INT2 count( const INT1& i ) noexcept;
  // bool find( const INT1& i ) noexcept;

  // inline INT2 InitialSegmentCount( const INT1& i_final );
  // inline INT2 IntervalCount( const INT1& i_start , const INT1& i_final );

  // VVV重複度が非負の場合のみサポート
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() noexcept;

  // inline iterator MaximumLeq( const INT1& i , const INT2& k = 0 );
  // inline iterator MaximumLt( const INT1& i , const INT2& k = 0 );
  // inline iterator MinimumGeq( const INT1& i , const INT2& k = 0 );
  // inline iterator MinimumGt( const INT1& i , const INT2& k = 0 );

  // inline INT1 Maximum( const INT2& k = 0 );
  // inline INT1 Minimum( const INT2& k = 0 );
  // AAA重複度が非負の場合のみサポート

  // // 構築時に設定した下限と上限を参照する。
  // inline const INT1& lbound() const noexcept;
  // inline const INT1& ubound() const noexcept;

};
