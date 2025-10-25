// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/SemiDynamic/a.hpp

#pragma once

#include "../../../../../../Algebra/Monoid/Group/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

// vector<vector<>>をvector<Map<int,->>に変更し、AccessとReplaceを追加したもの。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのは配列初期化とSetとRectangleSumのみなので、
// 零初期化とAddとInitialRectangleSumしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// 零初期化O(X)

// 一点取得expected O(log_2 X log_2 Y)
// M.Sum()によるLSB切片矩形和取得expected O(1)（[x-(x&-x),x-1] \times [y-(y&-y),y-1]）
// M.Sum()による始切片矩形和取得expected O(log_2 X log_2 Y)
// M.Sum()による矩形和取得expected O(log_2 X log_2 Y)

// 一点代入expected O(log_2 X log_2 Y)
// M.Sum()による一点加算expected O(log_2 X log_2 Y)

// AbstractBITとAbstractDynamicBITを二重にすれば実装できるが、
// 各操作がexpected O((log_2 X)(Mapのサイズの平均))になることに注意。
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalSemiDynamicBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_X;
  ll m_Y;
  vector<Map<ll,U>> m_fenwick;
  
public:
  inline AbstractTwoDimensionalSemiDynamicBIT( ABELIAN_GROUP M , const int& X , const ll& Y );

  inline void Initialise( const int& X , const ll& Y );
  inline void Set( const int& x , const ll& y , const U& u );
  void Add( const int& x , const ll& y , const U& u );

  inline const int& X() const noexcept;
  inline const ll& Y() const noexcept;
  // const参照でないことに注意。
  inline U Get( const int& x , const ll& y );
  inline const U& LSBRectangleSum( const int& i , const ll& j ) const;
  U InitialRectangleSum( const int& x_final , const ll& y_final );
  inline U RectangleSum( int x_start , int x_final , ll y_start , ll y_final );

private:
  inline U Access( const int& i , const ll& j , U u ) noexcept;
  inline void Replace( const int& i , const ll& j , U u ) noexcept;
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalSemiDynamicBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalSemiDynamicBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalSemiDynamicBIT :
  public AbstractTwoDimensionalSemiDynamicBIT<U,AdditiveGroup<U>>
{

public:
  inline TwoDimensionalSemiDynamicBIT( const int& x = 0 , const ll& Y = 0 );

};

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>& bit );
