// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Multisubset/a.hpp"

// 構築O(size log size)
// 一点挿入O(log size)
// 一点削除O(log size)
// 一点帰属判定O(log size)
// 区間要素数取得O(log size)

// 先頭イテレータ取得O(log size)
// 末尾イテレータ取得O(log size)
// 上限/下限二分探索O(log size)

// 最大値/最小値取得O(log size)

// イテレータは要素の重複を無視することに注意。
template <typename INT>
class CompressedSortedMultiSet :
  public CompressedSortedSet<INT> ,
  public AbstractBoundedLineMultiSubset<INT,const int&,const INT&,BIT>
{
  
public:
  inline CompressedSortedMultiSet( const vector<INT>& query );

};
