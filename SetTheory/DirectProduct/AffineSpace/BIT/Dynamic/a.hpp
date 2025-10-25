// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Dynamic/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Group/a.hpp"
#include "../../../../../Utility/Set/Map/a.hpp"

// vectorをMap<int,->に変更し、AccessとReplaceを追加したもの。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのは配列初期化とSetとIntervalSumと単調関係に関する区間での
// Searchのみなので、零初期化AddとInitialSegmentSumとその他のSearchしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// M.Zeroによる初期化O(1)

// 一点取得expected O(log_2 size)
// M.Sum()によるLSB切片和取得expected O(1)（a[j-(j&-j)]+...+a[j-1]）
// M.Sum()による始切片和取得expected O(log_2 size)
// M.Sum()による区間和取得expected O(log_2 size)

// 一点代入expected O(log_2 size)
// M.Sum()による一点加算expected O(log_2 size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.Zero()より小さくない。
// を満たす場合にのみサポート。
// M.Sum()による始切片和がu以上となる要素の添字の最小値の二分探索expected O(log_2 size)
// 左端点を固定した時にM.Sum()による区間和がu以上となる要素の添字の最小値の二分探索expected O(log_2 size)
template <typename U , typename ABELIAN_GROUP , typename INT>
class AbstractDynamicBIT
{
protected:
  ABELIAN_GROUP m_M;
  INT m_size;
  Map<INT,U> m_fenwick;
  INT m_power;
  
public:
  inline AbstractDynamicBIT( ABELIAN_GROUP M , const INT& size );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const INT& i , const U& u );
  void Add( const INT& i , const U& u );

  inline const INT& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const INT& i );
  inline U Get( const INT& i );
  inline const U& LSBSegmentSum( const INT& j ) const;
  U InitialSegmentSum( const INT& i_final );
  inline U IntervalSum( INT i_start , INT i_final );

  // Fは積順序に関して単調な写像f:U \times INT -> {0,1}に相当する型。
  // f( InitialSegmentSum( i ) , i )がtrueとなるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> INT Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline INT Search( const INT& i_start , const F& f );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  inline INT Search( const U& u );
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  inline INT Search( const INT& i_start , const U& u );

private:
  inline void Construct();
  inline U Access( const INT& i , U u ) noexcept;
  inline void Replace( const INT& i , U u ) noexcept;
  
};
template <typename ABELIAN_GROUP , typename INT> AbstractDynamicBIT( ABELIAN_GROUP M , const INT& ) -> AbstractDynamicBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP,INT>;

template <typename U = ll , typename INT = int>
class DynamicBIT :
  public AbstractDynamicBIT<U,AdditiveGroup<U>,INT>
{

public:
  template <typename...Args> inline DynamicBIT( const Args&... args );

};

template <class Traits , typename U , typename ABELIAN_GROUP , typename INT> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractDynamicBIT<U,ABELIAN_GROUP,INT>& bit );
