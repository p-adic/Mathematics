// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1164091 (insert,erase,ConnectedComponentOf)

// 非負に制限したBoundedLineSubsetの定数倍高速化版。

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

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset :
  virtual public VirtualBoundedLineSubset<int,INT,const int&,const int&,DATA_STR>
{

public:
  inline AbstractNonNegativeLineSubset( const int& ubound );

  // 以下のdeleteされていないメソッドはVirtualBoundedLineSubset内で定義されている。
  // inline void insert( const INT& i );
  // inline void erase( const INT& i ) noexcept;
  // // itrをインクリメントして書き換え、それへの参照を返す。
  // inline iterator& erase( iterator& itr );
  // inline void clear();

  // inline INT count( const INT& i ) noexcept;
  // bool find( const INT& i ) noexcept;

  // inline INT InitialSegmentCount( const INT& i_final );
  // inline INT IntervalCount( const INT& i_start , const INT& i_final );

  // VVV重複度が非負の場合のみサポート
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() noexcept;

  // inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  // inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  // inline INT Maximum( const INT& k = 0 );
  // inline INT Minimum( const INT& k = 0 );

  // // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  // INT RightEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );
  // // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  // INT LeftEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );

  // // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  // inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false );

  // vector<pair<INT,INT>> GetConnectedComponent() noexcept;
  // AAA重複度が非負の場合のみサポート

  // // 構築時に設定した下限と上限を参照する。
  // inline const INT& lbound() const noexcept;
  // inline const INT& ubound() const noexcept;

protected:
  inline bool InRange( const int& i );
  inline constexpr const int& Normalise( const int& i );
  inline constexpr const int& Denormalise( const int& d );

};

#include "a_Alias.hpp"
