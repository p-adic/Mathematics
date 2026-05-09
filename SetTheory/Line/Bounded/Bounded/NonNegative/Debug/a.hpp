// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Debug/a.hpp

#pragma once
#include "../../Debug/a.hpp"

// デバッグ用にデバッグ出力とsetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset :
  virtual public VirtualBoundedLineSubset<int,INT,const int&,const int&,DATA_STR>
{

public:
  inline AbstractNonNegativeLineSubset( const int& ubound , const bool& output_mode = true );

private:
  inline bool InRange( const int& i );
  inline constexpr const int& Normalise( const int& i );
  inline constexpr const int& Denormalise( const int& d );

};

#include "../a_Alias.hpp"
