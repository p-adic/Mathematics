// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Iterator/a_Body.hpp"

template <typename INT>
void LineSubset<INT>::insert( const INT& i ) noexcept
{

  auto itr0 = m_l.lower_bound( i - 1 ) , end = m_l.end();

  // 全ての要素より大きくかつ左に隣接していない場合
  if( itr0 == end ){

    m_l[i] = i;
    m_size++;
    return;

  }

  auto& [r0,l0] = *itr0;

  // 属している場合
  if( l0 <= i && i <= r0 ){

    return;

  }

  m_size++;

  // 右のみに隣接している場合
  if( i + 1 == l0 ){

    l0--;
    return;

  }

  // 何らかの要素より小さくかつ左右どちらにも隣接していない場合
  if( i + 1 < l0 ){

    m_l[i] = i;
    return;

  }
  
  auto itr1 = m_l.lower_bound( i + 1 );

  // 全ての要素より大きくかつ左に隣接している場合
  if( itr1 == end ){

    assert( r0 == i - 1 );
    m_l[i] = l0;

  // 何らかの要素より小さくかつ左に隣接している場合
  } else {
    
    auto& [r1,l1] = *itr1;

    // 何らかの要素より小さくかつ左のみに隣接している場合
    if( i + 1 < l1 ){

      m_l[i] = l0;

    // 何らかの要素より小さくかつ左右両方に隣接している場合
    } else {
    
      l1 = l0;

    }

  }

  // 重複する区間の削除
  m_l.erase( itr0 );
  return;

}

template <typename INT> void LineSubset<INT>::IntervalInsert( const INT& i_start , const INT& i_final ) noexcept
{

  // 挿入区間が空の場合
  if( i_start > i_final ){

    return;

  }

  auto itr_i = m_l.lower_bound( i_final ) , end_i = m_l.end();

  // 挿入区間が交わりを持たない場合
  if( itr_i == end_i || i_final + 1 < itr_i->second ){

    m_size += i_final - i_start + 1;
    m_l[i_final] = i_start;
    itr_i = m_l.lower_bound( i_final );

  // 挿入区間が含まれる場合
  } else if( itr_i->second <= i_start ){

    return;

  // 挿入区間が含まれず交わりを持つ場合
  } else {

    m_size += itr_i->second - i_start;
    itr_i->second = i_start;

  }

  INT& l = itr_i->second;
  auto begin_i = m_l.begin();

  while( itr_i != begin_i && l - 1 <= ( --itr_i )->first ){

    // 重複の寄与を削除
    m_size -= itr_i->first - l + 1;
    l = min( l , itr_i->second );

    // 重複区間が左端である場合
    if( itr_i == begin_i ){

      m_l.erase( itr_i );
      break;

    // 重複区間が左端でない場合
    } else {

      --( itr_i = m_l.erase( itr_i ) );

    }

  }

  return;

}

template <typename INT>
void LineSubset<INT>::erase( const INT& i ) noexcept
{

  auto itr = m_l.lower_bound( i );

  // 全ての要素より大きい場合
  if( itr == m_l.end() ){

    return;

  }

  auto& [r,l] = *itr;

  // 何らかの要素より小さくかつ属していない場合
  if( i < l ){

    return;

  }

  m_size--;

  // 属しておりかつ区間の左端でない場合
  if( l < i ){

    m_l[i-1] = l;

  }

  // 属しておりかつ区間の右端である場合
  if( i == r ){

    m_l.erase( itr );

  // 属しておりかつ区間の右端でない場合
  } else {

    l = i + 1;

  }
  
  return;

}

template <typename INT> inline IteratorOfLineSubset<INT>& LineSubset<INT>::erase( IteratorOfLineSubset<INT>& itr ) { m_size--; return itr.erase_from( m_l ); }


template <typename INT> void LineSubset<INT>::IntervalErase( const INT& i_start , const INT& i_final ) noexcept
{

  // 削除区間が空の場合
  if( i_start > i_final ){

    return;

  }

  // 削除区間の左端のみ削除
  erase( i_start );
  auto itr_i = m_l.upper_bound( i_start ) , end_i = m_l.end();

  // 削除区間がまだ交わりを持つ場合
  while( itr_i != end_i && itr_i->second <= i_final ){

    // 削除区間がまだ交わりを持ち区間を含まない場合
    if( i_final < itr_i->first ){

      m_size -= i_final - itr_i->second + 1;
      itr_i->second = i_final + 1;
      break;

    // 削除区間がまだ交わりを持ち区間を含む場合
    } else {

      m_size -= itr_i->first - itr_i->second + 1;
      itr_i = m_l.erase( itr_i );

    }

  }

  return;

}

template <typename INT> inline int LineSubset<INT>::count( const INT& i ) const noexcept { return find( i ) ? 1 : 0; }

template <typename INT>
bool LineSubset<INT>::find( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return false;

  }

  return itr->second <= i;

}

template <typename INT> inline const INT& LineSubset<INT>::size() const noexcept { return m_size; }
template <typename INT> inline bool LineSubset<INT>::empty() const noexcept { return m_size == 0; }
template <typename INT> inline void LineSubset<INT>::clear() noexcept { m_l.clear(); m_size = 0; }

template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::begin() noexcept { return IteratorOfLineSubset<INT>{ m_l , m_l.begin() , m_l.empty() ? 0 : m_l.begin()->second }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::end() noexcept { return IteratorOfLineSubset<INT>{ m_l , m_l.end() , 0 }; }

template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MaximumLeq( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); if( itr != m_l.end() && itr->second <= i ){ return IteratorOfLineSubset<INT>( m_l , itr , i ); } if( itr == m_l.begin() ){ return end(); } --itr; return IteratorOfLineSubset<INT>{ m_l , itr , itr->first }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MaximumLt( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); if( itr != m_l.end() && itr->second < i ){ return IteratorOfLineSubset<INT>( m_l , itr , i - 1 ); } if( itr == m_l.begin() ){ return end(); } --itr; return IteratorOfLineSubset<INT>{ m_l , itr , itr->first }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MinimumGeq( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); return itr == m_l.end() ? end() : IteratorOfLineSubset<INT>( m_l , itr , max( i , itr->second ) ); }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MinimumGt( const INT& i ) const noexcept { auto itr = m_l.upper_bound( i ); return itr == m_l.end() ? end() : IteratorOfLineSubset<INT>( m_l , itr , max( i + 1 , itr->second ) ); }

template <typename INT> inline INT LineSubset<INT>::Maximum() const { assert( !m_l.empty() ); return ( --m_l.end() )->first; }
template <typename INT> inline INT LineSubset<INT>::Minimum() const { assert( !m_l.empty() ); return m_l.begin()->second; }

template <typename INT>
pair<INT,INT> LineSubset<INT>::IntervalOf( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return {i+1,i-1};

  }

  return itr->second <= i ? pair<INT,INT>{itr->second,itr->first} : pair<INT,INT>{i+1,i-1};

}

template <typename INT> inline const map<INT,INT>& LineSubset<INT>::GetInterval() const noexcept { return m_l; }
