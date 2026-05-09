// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../Iterator/a.hpp"

#include "../../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"

// デバッグ用にコンストラクタとデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class VirtualIntervalInsertBoundedLineMultiSubset :
  public Debug
{

protected:
  INT1 m_lbound;
  INT1 m_ubound;
  DATA_STR<INT2> m_ds;

  string m_name;
  multiset<INT1> m_S;
  // 負の重複度を管理。
  multiset<INT1> m_S_comp;

public:
  inline VirtualIntervalInsertBoundedLineMultiSubset();
  
  using iterator = IteratorOfBoundedLineSubset<VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>,INT1>;
  
  inline void insert( const INT1& i , const INT2& c = 1 );
  inline void IntervalInsert( const INT1& i_start , const INT1& i_final , const INT2& c = 1 );
  inline void erase( const INT1& i , const INT2& c = 1 );
  inline void IntervalErase( const INT1& i_start , const INT1& i_final , const INT2& c = 1 );
  inline void EraseAll( const INT1& i );

  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );
  inline void clear();

  inline INT2 count( const INT1& i ) noexcept;
  bool find( const INT1& i ) noexcept;

  inline INT2 InitialSegmentCount( const INT1& i_final );
  inline INT2 IntervalCount( const INT1& i_start , const INT1& i_final );
  inline bool empty();

  inline iterator begin();
  inline iterator end();

  inline iterator MaximumLeq( const INT1& i , const INT2& k = 0 );
  inline iterator MaximumLt( const INT1& i , const INT2& k = 0 );
  inline iterator MinimumGeq( const INT1& i , const INT2& k = 0 );
  inline iterator MinimumGt( const INT1& i , const INT2& k = 0 );

  inline INT1 Maximum( const INT2& k = 0 );
  inline INT1 Minimum( const INT2& k = 0 );

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

template <typename INT1 = int , typename INT2 = ll>
class IntervalInsertBoundedLineMultiSubset :
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,INT1,INT1,IntervalAddBIT>
{

public:
  inline IntervalInsertBoundedLineMultiSubset( const INT1& lbound , const INT1& ubound , const bool& output_mode = true );

protected:
  inline bool InRange( const INT1& i );
  inline int Normalise( const INT1& i );
  inline INT1 Denormalise( const int& d );
  
};
