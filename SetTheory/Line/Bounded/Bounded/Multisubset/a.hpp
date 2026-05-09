// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1164096 (insert, IntervalCount)

#include "../a.hpp"

// 構築O(ubound - lbound)
// 一点挿入O(log(ubound - lbound))
// 一点削除O(log(ubound - lbound))
// 一点帰属判定O(log(ubound - lbound))
// 区間要素数取得O(log(ubound - lbound))

// 先頭イテレータ取得O(log(ubound - lbound))
// 末尾イテレータ取得O(log(ubound - lbound))
// 上限/下限二分探索O(log(ubound - lbound))

// 最大値/最小値取得O(log(ubound - lbound))

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class VirtualBoundedLineMultiSubset :
  virtual public VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>
{
  
public:
  inline void insert( const INT1& i , const INT2& c = 1 );
  inline void erase( const INT1& i , const INT2& c = 1 );
  inline void EraseAll( const INT1& i );

  // 以下のdeleteされていないメソッドはVirtualBoundedLineSubset内で定義されている。
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
  
  INT1 RightEndPointOf( const INT1& i , const bool& in = false ) = delete;
  INT1 LeftEndPointOf( const INT1& i , const bool& in = false ) = delete;
  inline pair<INT1,INT1> ConnectedComponentOf( const INT1& i , bool in = false ) = delete;
  vector<pair<INT1,INT1>> GetConnectedComponent() noexcept = delete;

};

template <typename INT1 = int , typename INT2 = ll>
class BoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT1,INT2,BIT> ,
  virtual public VirtualBoundedLineMultiSubset<INT1,INT2,INT1,INT1,BIT>
{
  
public:
  inline BoundedLineMultiSubset( const INT1& lbound , const INT1& ubound );

};
