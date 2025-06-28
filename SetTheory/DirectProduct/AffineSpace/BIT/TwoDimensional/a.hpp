// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/a.hpp

#pragma once

#include "../../../../../Algebra/Monoid/Group/a.hpp"

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのは配列初期化とSetとRectangleSumのみなので、
// 零初期化とAddとInitialRectangleSumしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// M.Zero()による初期化O(X \times Y)
// 配列による初期化O(X \times Y)

// 一点取得O(log_2 X log_2 Y)
// M.Sum()によるLSB切片矩形和取得O(1)（[x-(x&-x),x-1] \times [y-(y&-y),y-1]）
// M.Sum()による始切片矩形和取得O(log_2 X log_2 Y)
// M.Sum()による矩形和取得O(log_2 X log_2 Y)

// 一点代入O(log_2 X log_2 Y)
// M.Sum()による一点加算O(log_2 X log_2 Y)

// AbstractBITを二重にすれば実装できるが、
// 演算の定義のために余計なfriend指定が必要なので直接実装する。
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_X;
  int m_Y;
  vector<vector<U>> m_fenwick;
  
public:
  inline AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const vector<vector<U>>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& x , const int& y , const U& u );
  void Add( const int& x , const int& y , const U& u );

  inline const int& X() const noexcept;
  inline const int& Y() const noexcept;
  // const参照でないことに注意。
  inline U Get( const int& x , const int& y );
  inline const U& LSBRectangleSum( const int& i , const int& j ) const;
  U InitialRectangleSum( const int& x_final , const int& y_final );
  inline U RectangleSum( int x_start , int x_final , int y_start , int y_final );

};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalBIT :
  public AbstractTwoDimensionalBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalBIT( const Args&... args );

};
template <typename U> TwoDimensionalBIT( const vector<vector<U>>& a ) -> TwoDimensionalBIT<U>;

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>& bit );
