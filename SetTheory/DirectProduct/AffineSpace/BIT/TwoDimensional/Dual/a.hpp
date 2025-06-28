// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/Dual/a.hpp

#pragma once
#include "../a.hpp"

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。

// 零初期化O(X \times Y)
// 配列による初期化O(X \times Y)

// 一点取得O(log_2 X log_2 Y)

// 一点代入O(log_2 X log_2 Y)
// M.Sum()による矩形加算O(log_2 X log_2 Y)
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalDualBIT :
  public AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>
{

public:
  inline AbstractTwoDimensionalDualBIT( ABELIAN_GROUP M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalDualBIT( ABELIAN_GROUP M , vector<vector<U>> a );

  inline AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>& operator=( AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>&& bit );
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& x , const int& y , const U& u );
  inline void Add( const int& x , const int& y , const U& u );
  void IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u );

  // const参照でないことに注意。
  inline U Get( const int& x , const int& y );

private:
  inline AbstractTwoDimensionalDualBIT( ABELIAN_GROUP& M , const vector<vector<U>>& a , const bool& dummy );
  static vector<vector<U>> Differentiate( ABELIAN_GROUP& M , vector<vector<U>> a );
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalDualBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalDualBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalDualBIT :
  public AbstractTwoDimensionalDualBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalDualBIT( Args&&... args );

};
template <typename U> TwoDimensionalDualBIT( vector<vector<U>> a ) -> TwoDimensionalDualBIT<U>;

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDualBIT<U,ABELIAN_GROUP>& bit );
