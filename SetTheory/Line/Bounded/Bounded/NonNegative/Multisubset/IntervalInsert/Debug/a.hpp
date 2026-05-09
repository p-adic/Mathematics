// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../../Multisubset/IntervalInsert/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT = ll>
class IntervalInsertNonNegativeLineMultiSubset :
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<int,INT,const int&,const int&,IntervalAddBIT>
{

public:
  inline IntervalInsertNonNegativeLineMultiSubset( const int& ubound );


protected:
  inline bool InRange( const int& i );
  inline constexpr const int& Normalise( const int& i );
  inline constexpr const int& Denormalise( const int& d );

};
