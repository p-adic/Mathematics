// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../../Utility/Set/Map/a.hpp"

// イテレータへの*は要素への値返し。

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR>
class AbstractCompressedSortedSet :
  virtual public VirtualBoundedLineSubset<INT1,INT2,const int&,const INT1&,DATA_STR>
{

protected:
  vector<INT1> m_sorted_coord;
  map<INT1,int> m_sorted_coord_inv;

public:
  inline AbstractCompressedSortedSet( const vector<INT1>& query );

  // 以下のdeleteされていないメソッドはVirtualBoundedLineSubset内で定義されている。
  // inline void insert( const INT1& i );
  // inline void erase( const INT1& i ) noexcept;
  // // itrをインクリメントして書き換え、それへの参照を返す。
  // inline iterator& erase( iterator& itr );
  // inline void clear();

  // inline INT2 count( const INT1& i ) noexcept;
  // bool find( const INT1& i ) noexcept;

  // inline INT2 InitialSegmentCount( const INT1& i_final );
  // inline INT2 IntervalCount( const INT1& i_start , const INT1& i_final );
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() noexcept;

  // inline iterator MaximumLeq( const INT1& i , const INT2& k = 0 );
  // inline iterator MaximumLt( const INT1& i , const INT2& k = 0 );
  // inline iterator MinimumGeq( const INT1& i , const INT2& k = 0 );
  // inline iterator MinimumGt( const INT1& i , const INT2& k = 0 );

  // inline INT1 Maximum( const INT2& k = 0 );
  // inline INT1 Minimum( const INT2& k = 0 );

  // // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  // INT1 RightEndPointOf( const INT1& i , int d = -1 , int comp_minus = -1 , const bool& in = false );
  // // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  // INT1 LeftEndPointOf( const INT1& i , int d = -1 , int comp_minus = -1 , const bool& in = false );

  // // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  // inline pair<INT1,INT1> ConnectedComponentOf( const INT1& i , bool in = false );

  // vector<pair<INT1,INT1>> GetConnectedComponent() noexcept;

  // // 構築時に設定した下限と上限を参照する。
  // inline const INT1& lbound() const noexcept;
  // inline const INT1& ubound() const noexcept;
  // AAA重複度が非負の場合のみサポート

protected:
  inline bool InRange( const INT1& i );
  inline const int& Normalise( const INT1& i );
  inline const INT1& Denormalise( const int& d );

};

#include "a_Alias.hpp"
