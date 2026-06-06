// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"

#include "../../../../Error/Debug/a.hpp"

// デバッグ用にデバッグ出力とsetそのものを追加したもの。
// 各計算量にO(m_size)が加わることに注意。

template <typename INT>
class LineSubset :
  public Debug
{

private:
  // 区間[l,r]ごとにm_l[r] = lとして直線の部分集合を管理する。
  map<INT,INT> m_l;
  INT m_size;

  set<INT> m_set;
  int m_num;

public:
  inline LineSubset( const bool& output_mode = true );
  
  using iterator = IteratorOfLineSubset<INT>;
  
  void insert( const INT& i ) noexcept;
  void IntervalInsert( const INT& i_start , const INT& i_final ) noexcept;
  void erase( const INT& i ) noexcept;
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );
  void IntervalErase( const INT& i_start , const INT& i_final ) noexcept;

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  // （区間数でなく）要素数を返す。
  inline const INT& size() const noexcept;
  inline bool empty() const noexcept;
  inline void clear() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i ) const noexcept;
  inline iterator MaximumLt( const INT& i ) const noexcept;
  inline iterator MinimumGeq( const INT& i ) const noexcept;
  inline iterator MinimumGt( const INT& i ) const noexcept;

  inline INT Maximum() const;
  inline INT Minimum() const;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  pair<INT,INT> IntervalOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetInterval() const noexcept;

  inline void Display() const noexcept;
  
};
