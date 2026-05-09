// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/Debug/a.hpp

#pragma once
#include "../../../Multisubset/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT = ll>
class NonNegativeLineMultiSubset :
  virtual public VirtualBoundedLineMultiSubset<int,INT,const int&,const int&,BIT>
{

public:
  inline NonNegativeLineMultiSubset( const int& ubound , const bool& output_mode = true );

protected:
  inline bool InRange( const int& i );
  inline constexpr const int& Normalise( const int& i );
  inline constexpr const int& Denormalise( const int& d );

};

