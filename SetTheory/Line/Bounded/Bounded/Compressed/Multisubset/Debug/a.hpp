// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a.hpp

#pragma once
#include "../../../Multisubset/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT1 , typename INT2>
class CompressedSortedMultiSet :
  virtual public VirtualBoundedLineMultiSubset<INT1,INT2,const int&,const INT1&,BIT>
{

protected:
  vector<INT1> m_sorted_coord;
  map<INT1,int> m_sorted_coord_inv;

public:
  inline CompressedSortedMultiSet( const vector<INT1>& query , const bool& output_mode = true );

protected:
  inline bool InRange( const INT& i );
  inline const int& Normalise( const INT& i );
  inline const INT& Denormalise( const int& d );

};

