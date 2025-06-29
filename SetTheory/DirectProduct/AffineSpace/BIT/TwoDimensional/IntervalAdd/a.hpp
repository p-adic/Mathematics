// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"

// 入力の範囲内で要件
// (1) MがUのZ加群構造である。
// を満たす場合にのみサポート。

// 零初期化O(X \times Y)
// 配列による初期化O(X \times Y)

// 矩形和取得O(log_2 X log_2 Y)

// 一点代入O(log_2 X log_2 Y)
// M.Sum()による矩形加算O(log_2 X log_2 Y)
template <typename U , typename Z_MODULE>
class AbstractTwoDimensionalIntervalAddBIT
{

private:
  Z_MODULE m_M;
  // 階差数列（a_i - a_{i-1}）を取る操作をD
  // 次数を1ずらした負の階差数列の微分（-(i-1)(a_i - a_{i-1})）を取る操作をFと置く。
  // x方向にD、y方向にDしたものを２次元BITで管理（矩形和が一点取得に対応）
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit00;
  // x方向にD、y方向にFしたものを２次元BITで管理（矩形和がy方向の累積和-一点取得の定数倍に対応）
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit01;
  // x方向にF、y方向にDしたものを２次元BITで管理（矩形和がx方向の累積和-一点取得の定数倍に対応）
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit10;
  // x方向にF、y方向にFしたものを２次元BITで管理（矩形和が矩形和-x方向の累積和-y方向の累積和+一点取得の定数倍に対応）
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit11;
  
public:
  inline AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , vector<vector<U>> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& x , const int& y , const U& u );
  inline void Add( const int& x , const int& y , const U& u );
  void IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u );

  inline const int& X() const noexcept;
  inline const int& Y() const noexcept;
  // const参照でないことに注意。
  inline U Get( const int& x , const int& y );
  inline U InitialRectangleSum( const int& x , const int& y );
  inline U RectangleSum( int x_start , int x_final , int y_start , int y_final );
  
};
template <typename Z_MODULE , typename...Args> AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , const Args&... args ) -> AbstractTwoDimensionalIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class TwoDimensionalIntervalAddBIT :
  public AbstractTwoDimensionalIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline TwoDimensionalIntervalAddBIT( Args&&... args );

};
template <typename U> TwoDimensionalIntervalAddBIT( vector<vector<U>> a ) -> TwoDimensionalIntervalAddBIT<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>& bit );
