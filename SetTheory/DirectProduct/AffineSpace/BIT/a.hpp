// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/961771（零初期化、一点加算、区間和）
// https://yukicoder.me/submissions/961772（零初期化、配列初期化、始切片和）
// https://yukicoder.me/submissions/961774（配列初期化、一点加算、二分探索）

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのは配列初期化とSetとIntervalSumと単調関係に関する区間での
// Searchのみなので、零初期化AddとInitialSegmentSumとその他のSearchしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// M.Zeroによる初期化O(size)
// 配列による初期化O(size)

// 一点取得O(log_2 size)
// M.Sum()によるLSB切片和取得O(1)（a[j-(j&-j)]+...+a[j-1]）
// M.Sum()による始切片和取得O(log_2 size)
// M.Sum()による区間和取得O(log_2 size)

// 一点代入O(log_2 size)
// M.Sum()による一点加算O(log_2 size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.Zero()より小さくない。
// を満たす場合にのみサポート。
// M.Sum()による始切片和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時にM.Sum()による区間和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_size;
  vector<U> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( InitialSegmentSum( i ) , i )がtrueとなるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int Search( const int& i_start , const F& f );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  inline int Search( const U& u );
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  inline int Search( const int& i_start , const U& u );

private:
  inline void Construct();
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class BIT :
  public AbstractBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline BIT( const Args&... args );

};
template <typename U> BIT( const vector<U>& a ) -> BIT<U>;

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractBIT<U,ABELIAN_GROUP>& bit );
