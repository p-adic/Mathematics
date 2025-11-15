// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/ConvexHull/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Area/a_Body.hpp"

template <typename INT , template <typename...> typename PAIR> template <template <typename...> typename VEC> inline ConvexHull<INT,PAIR>::ConvexHull( const VEC<PAIR<INT,INT>>& xy ) : ConvexHull()  { for( auto& p : xy ){ insert( p ); } }

template <typename INT , template <typename...> typename PAIR> inline void ConvexHull<INT,PAIR>::insert( const Pair<INT,INT>& xy ) { insert( get<0>( xy ) , get<1>( xy ) ); }

template <typename INT , template <typename...> typename PAIR>
void ConvexHull<INT,PAIR>::insert( const INT& x , const INT& y )
{

  vector<tuple<int,INT,INT,int>> update = {{0,x,y,m_size++}};
  auto end = m_ext_cyc.end();
  using iterator = typename set<tuple<int,INT,INT,int>>::iterator;

  auto eval = [&]( const iterator& itr ){

    auto [t,x,y,i] = *itr;
    
    if( t == 1 ){

      x *= -1;
      y *= -1;

    }

    return tuple{t,x,y,i};

  };

  auto decr = [&]( iterator& itr ) -> iterator& {

    return --( itr == m_ext_cyc.begin() ? itr = end : itr );
    
  };

  auto incr = [&]( iterator& itr ) -> iterator& {

    return ++itr == end ? itr = m_ext_cyc.begin() : itr;
    
  };

  auto valid = [&]( iterator& itr ){

    if( m_ext_cyc.size() < 3 ){

      return true;

    }
    
    auto prev = itr , next = itr;
    auto [t1,x1,y1,i1] = eval( decr( prev ) );
    auto [t2,x2,y2,i2] = eval( itr );
    auto [t3,x3,y3,i3] = eval( incr( next ) );
    auto S = Area( x1 , y1 , x2 , y2 , x3 , y3 );

    if( S > 0 || ( t2 == 0 && ( t3 == 1 || tuple{x3,i3,i3} < tuple{x2,y2,i2} || tuple{x2,y2,i2} < tuple{x1,y1,i1} ) ) ){

      return true;

    }

    if( S < 0 ){

      if( t2 == 0 ){

        update.push_back( {1,-x2,-y2,i2} );

      } else {

        m_interior.push_back( i2 );

      }

    } else {

      m_non_ext_end.push_back( i2 );      

    }

    m_ext.erase( i2 );
    itr = m_ext_cyc.erase( itr );

    if( itr == end ){

      itr = m_ext_cyc.begin();

    }
    
    return false;

  };

  while( !update.empty() ){
    
    auto p = update.back();
    update.pop_back();
    m_ext_cyc.insert( p );
    m_ext.insert( get<3>( p ) );
    auto itr = m_ext_cyc.lower_bound( p );

    if( valid( itr ) ){

      auto temp = itr;

      while( !valid( decr( temp ) ) ){}

      temp = itr;

      while( !valid( incr( temp ) ) ){}

    }

  }

  return;

}

template <typename INT , template <typename...> typename PAIR> inline const int& ConvexHull<INT,PAIR>::TotalSize() const noexcept { return m_size; }
template <typename INT , template <typename...> typename PAIR> inline int ConvexHull<INT,PAIR>::ExtremalPointSize() const noexcept { return m_ext.size(); }
template <typename INT , template <typename...> typename PAIR> inline int ConvexHull<INT,PAIR>::NonExtremalEndPointSize() const noexcept { return m_non_ext_end.size(); }
template <typename INT , template <typename...> typename PAIR> inline int ConvexHull<INT,PAIR>::EndPointSize() const noexcept { return ExtremalPointSize() + NonExtremalEndPointSize(); }
template <typename INT , template <typename...> typename PAIR> inline int ConvexHull<INT,PAIR>::InteriorPointSize() const noexcept { return m_interior.size(); }

template <typename INT , template <typename...> typename PAIR> inline const set<int>& ConvexHull<INT,PAIR>::ExtremalPoints() const noexcept { return m_ext; }
template <typename INT , template <typename...> typename PAIR> inline const vector<int>& ConvexHull<INT,PAIR>::NonExtremalEndPoints() const noexcept { return m_non_ext_end; }
template <typename INT , template <typename...> typename PAIR> inline const vector<int>& ConvexHull<INT,PAIR>::InteriorPoints() const noexcept { return m_interior; }

