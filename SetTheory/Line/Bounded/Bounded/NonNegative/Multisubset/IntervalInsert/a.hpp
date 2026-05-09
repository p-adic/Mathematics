// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1164110 (IntervalInsert, count, IntervalErase)

#include "../a.hpp"
#include "../../../Multisubset/IntervalInsert/a.hpp"

// 構築O(ubound)
// 一点挿入O(log ubound)
// 区間挿入O(log ubound)
// 一点削除O(log ubound)
// 区間削除O(log ubound)
// 一点帰属判定O(log ubound)
// 区間要素数取得O(log ubound)

// 先頭イテレータ取得O((log ubound)^2)
// 末尾イテレータ取得O((log ubound)^2)
// 上限/下限二分探索O((log ubound)^2)

// 最大値/最小値取得O((log ubound)^2)

// イテレータへの*は要素への値返し。
// イテレータの++や--は要素の重複を無視することに注意。

template <typename INT = ll>
class IntervalInsertNonNegativeLineMultiSubset :
  public AbstractNonNegativeLineSubset<INT,IntervalAddBIT> ,
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<int,INT,const int&,const int&>
{
  
public:
  inline IntervalInsertNonNegativeLineMultiSubset( const int& ubound );

  // 以下のdeleteされていないメソッドはVirtualIntervalInsertBoundedLineMultiSubset内で定義されている。
  // inline void IntervalInsert( const INT1& i_start , const INT1& i_final , const INT2& c = 1 );
  // inline void IntervalErase( const INT1& i_start , const INT1& i_final , const INT2& c = 1 );

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

