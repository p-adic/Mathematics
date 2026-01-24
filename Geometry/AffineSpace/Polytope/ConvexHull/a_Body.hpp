// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/ConvexHull/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Area/a_Body.hpp"
#include "../../../../Utility/Vector/a_Body.hpp"

template <typename INT> template <template <typename...> typename PAIR>
ConvexHull<INT>::ConvexHull( const vector<PAIR<INT,INT>>& xy ) : m_size( xy.size() ) , m_ext() , m_ext_inv() , m_non_ext_end() , m_interior()
{

  if( m_size > 0 ){

    auto [x0,y0] = Min( xy );
    ArgumentSortOrder ord{ x0 , y0 };
    auto index_ord = [&]( const int& i0 , const int& i1 ){ return ord( xy[i0] , xy[i1] ); };
    auto index = id<int>( xy.size() );
    sort( index.begin() , index.end() , index_ord );
    int L = 0;

    for( auto& i : index ){

      auto& [x1,y1] = xy[i];

      if( L > 1 ){
        
        auto& [x2,y2] = xy[m_ext[L-1]];
        const ll S = Area<ll>( x2 , y2 , x1 , y1 , x0 , y0 );
        assert( S >= 0 );

        if( S == 0 ){

          m_non_ext_end <<= pop( m_ext );
          L--;

        }
      
      }

      while( L > 1 ){

        auto& [x2,y2] = xy[m_ext[L-1]];
        auto& [x3,y3] = xy[m_ext[L-2]];
        const ll S = Area<ll>( x3 , y3 , x2 , y2 , x1 , y1 );

        if( S > 0 ){

          break;
              
        }
            
        ( S < 0 ? m_interior : m_non_ext_end ) <<= pop( m_ext );
        L--;

      }
      
      m_ext <<= i;
      L++;

    }

    for( int i = 0 ; i < L ; i++ ){
      
      m_ext_inv[m_ext[i]] = i;

    }
    
  }

}

template <typename INT> inline const int& ConvexHull<INT>::TotalSize() const noexcept { return m_size; }
template <typename INT> inline int ConvexHull<INT>::ExtremalPointSize() const noexcept { return m_ext.size(); }
template <typename INT> inline int ConvexHull<INT>::NonExtremalEndPointSize() const noexcept { return m_non_ext_end.size(); }
template <typename INT> inline int ConvexHull<INT>::EndPointSize() const noexcept { return ExtremalPointSize() + NonExtremalEndPointSize(); }
template <typename INT> inline int ConvexHull<INT>::InteriorPointSize() const noexcept { return m_interior.size(); }

template <typename INT> inline const vector<int>& ConvexHull<INT>::ExtremalPointIndex() const noexcept { return m_ext; }
template <typename INT> inline const vector<int>& ConvexHull<INT>::NonExtremalEndPointIndex() const noexcept { return m_non_ext_end; }
template <typename INT> inline const vector<int>& ConvexHull<INT>::InteriorPointIndex() const noexcept { return m_interior; }

template <typename INT> inline int ConvexHull<INT>::Index( const int& i ) const noexcept { auto itr = m_ext_inv.find( i ); return itr == m_ext_inv.end() ? -1 : itr->second; }
template <typename INT> inline int ConvexHull<INT>::Prev( const int& i ) const noexcept { return m_ext[0] == i ? m_ext.back() : m_ext[m_ext_inv.at( i ) - 1]; }
template <typename INT> inline int ConvexHull<INT>::Next( const int& i ) const noexcept { return m_ext.back() == i ? m_ext[0] : m_ext[m_ext_inv.at( i ) + 1]; }
