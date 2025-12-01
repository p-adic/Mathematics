// c:/Users/user/Documents/Programming/Mathematics/SetTheory/MaximalElement/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename X , typename Y> inline int MaximalElementSet<X,Y>::size() const noexcept { return m_S.size(); }
template <typename X , typename Y> inline bool MaximalElementSet<X,Y>::empty() const noexcept { return m_S.empty(); }

template <typename X , typename Y> void MaximalElementSet<X,Y>::push( const X& x , const Y& y )
{

  if( m_S.empty() ){

    m_S.push_back( {x,y} );

  } else {

    auto& [xr,yr] = m_S.back();

    if( x < xr ) {

      auto& [xl,yl] = m_S.front();
      assert( !( xl < x ) );

      if( yl < y ){

        if( x < xl ){

          m_S.push_front( {x,y} );

        } else {

          assert( x == xl );
          yl = y;
        
        }

      }

    } else {

      if( y < yr ){

        if( xr < x ){

          m_S.push_back( {x,y} );

        } else {

          assert( x == xr );

        }

      } else {

        m_S.pop_back();
        push( x , y );

      }
    
    }

  }

  return;

}

template <typename X , typename Y> inline const pair<X,Y>& MaximalElementSet<X,Y>::LeftMaximal() const { assert( !empty() ); return m_S.front(); }
template <typename X , typename Y> inline const pair<X,Y>& MaximalElementSet<X,Y>::RightMaximal() const { assert( !empty() ); return m_S.back(); }

template <typename X , typename Y> inline pair<X,Y> MaximalElementSet<X,Y>::pop_left() { assert( !empty() ); pair<X,Y> answer = move( m_S.front() ); m_S.pop_front(); return answer; }
template <typename X , typename Y> inline pair<X,Y> MaximalElementSet<X,Y>::pop_right() { assert( !empty() ); pair<X,Y> answer = move( m_S.back() ); m_S.pop_back(); return answer; }
template <typename X , typename Y> inline void MaximalElementSet<X,Y>::clear() { m_S.clear(); }

template <typename X , typename Y> inline typename deque<pair<X,Y>>::const_iterator MaximalElementSet<X,Y>::begin() const noexcept { return m_S.begin(); }
template <typename X , typename Y> inline typename deque<pair<X,Y>>::const_iterator MaximalElementSet<X,Y>::end() const noexcept { return m_S.end(); }

template <class Traits , typename X , typename Y> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MaximalElementSet<X,Y>& mes ) { auto begin = mes.begin() , end = mes.end() , itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *( itr++ ); } return os; }
