// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/LowLink/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Arithmetic/Iteration/a_Body.hpp"

template <typename GRAPH> template <typename Arg> inline LowLink<GRAPH>::LowLink( GRAPH& G , Arg starts ) : DepthFirstSearch<int,GRAPH>( G , -1 , move( starts ) ) , m_csize() , m_ord( G.size() , -1 ) , m_ord_inv( this->GetNodeEnumeration() ) , m_link( G.size() , -1 ) , m_child_link( G.size() , -1 )
{

  m_csize = m_ord_inv.size();

  for( int i = 0 ; i < m_csize ; i++ ){

    m_ord[m_ord_inv[i]] = m_link[m_ord_inv[i]] = i;

  }

  for( int i = m_csize - 1 ; i >= 0 ; i-- ){

    const int& t = m_ord_inv[i];
    const int& p = this->prev( t );    
    
    for( auto& u : G.Edge( t ) ){

      if( p == u ){

        continue;

      }

      SetMin( m_link[t] , m_ord[u] );

      if( this->prev( u ) == t ){

        SetMax( m_child_link[t] , m_link[u] );

      }

    }

    if( p != -1 ){

      SetMin( m_link[p] , m_link[t] );

    }

  }

}

template <typename GRAPH> inline const int& LowLink<GRAPH>::csize() const noexcept { return m_csize; }
template <typename GRAPH> inline const int& LowLink<GRAPH>::Ord( const int& t ) const { return m_ord[t]; }
template <typename GRAPH> inline const int& LowLink<GRAPH>::Ord_inv( const int& i ) const { return m_ord_inv[i]; }
template <typename GRAPH> inline const int& LowLink<GRAPH>::Link( const int& t ) const { return m_link[t]; }

template <typename GRAPH> inline bool LowLink<GRAPH>::IsBridge( int t , int u ) { if( m_ord[t] > m_ord[u] ){ swap( t , u ); } return t == this->prev( u ) && m_ord[t] < m_link[u]; }
template <typename GRAPH> inline bool LowLink<GRAPH>::IsJoint( const int& t ) { return m_ord[t] != -1 && ( this->prev( t ) == -1 ? this->m_G.Edge( t ).size() > 1 : m_ord[t] <= m_child_link[t] ); }
