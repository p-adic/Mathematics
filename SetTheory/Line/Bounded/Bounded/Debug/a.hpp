// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// デバッグ用にコンストラクタとデバッグ出力とsetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。


template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class VirtualBoundedLineSubset :
  public Debug
{

protected:
  INT1 m_lbound;
  INT1 m_ubound;
  DATA_STR<INT2> m_ds;

  string m_name;
  set<INT1> m_S;

public:
  inline VirtualBoundedLineSubset();
  
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>,INT1>;
  
  inline void insert( const INT1& i );
  inline void erase( const INT1& i ) noexcept;
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );
  inline void clear();

  inline INT2 count( const INT1& i ) noexcept;
  bool find( const INT1& i ) noexcept;

  inline INT2 InitialSegmentCount( const INT1& i_final );
  inline INT2 IntervalCount( const INT1& i_start , const INT1& i_final );
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT1& i , const INT2& k = 0 );
  inline iterator MaximumLt( const INT1& i , const INT2& k = 0 );
  inline iterator MinimumGeq( const INT1& i , const INT2& k = 0 );
  inline iterator MinimumGt( const INT1& i , const INT2& k = 0 );

  inline INT1 Maximum( const INT2& k = 0 );
  inline INT1 Minimum( const INT2& k = 0 );

  // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  INT1 RightEndPointOf( const INT1& i , int d = -1 , int comp_minus = -1 , const bool& in = false );
  // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  INT1 LeftEndPointOf( const INT1& i , int d = -1 , int comp_minus = -1 , const bool& in = false );

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  inline pair<INT1,INT1> ConnectedComponentOf( const INT1& i , bool in = false );

  vector<pair<INT1,INT1>> GetConnectedComponent() noexcept;

  // 構築時に設定した下限と上限を参照する。
  inline const INT1& lbound() const noexcept;
  inline const INT1& ubound() const noexcept;

  void Display() noexcept;

protected:
  virtual bool InRange( const INT1& i ) = 0;
  // RET_NORはintまたはconst int&
  virtual RET_NOR Normalise( const INT1& i ) = 0;
  // RET_NORはINT1またはconst INT1&
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset :
  virtual public VirtualBoundedLineSubset<INT1,INT2,int,INT1,DATA_STR>
{

public:
  inline AbstractBoundedLineSubset( const INT1& lbound , const INT1& ubound , const bool& output_mode = true );

protected:
  inline bool InRange( const INT1& i );
  inline int Normalise( const INT1& i );
  inline INT1 Denormalise( const int& d );

};

#include "../a_Alias.hpp"
