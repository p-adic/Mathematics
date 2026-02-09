// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/EulerTour/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename TREE>
EulerTour<TREE>::EulerTour( TREE& T , const int& root ) : m_T( T ) , m_length() , m_vertex() , m_vertex_inv( T.size() )
{

  vector<bool> found( T.size() );
  vector<int> dfs = {root};
  int i = 0;

  while( !dfs.empty() ){

    const int t = pop( dfs );
    m_vertex <<= t;

    if( !found[t] ){

      found[t] = true;
    
      for( auto& v : T.Edge( t ) ){

        if( !found[v] ){

          ( dfs <<= t ) <<= v;

        }

      }
    
    }

    m_vertex_inv[t] <<= i++;
    
  }

  m_length = i;
  
}

template <typename TREE> inline const int& EulerTour<TREE>::Length() const noexcept { return m_length; }
template <typename TREE> inline T2<int> EulerTour<TREE>::Subtree( const int& t ) const { return {m_vertex_inv[t][0],m_vertex_inv[t].back()}; }
template <typename TREE> inline const vector<int>& EulerTour<TREE>::Vertex() const noexcept { return m_vertex; }
template <typename TREE> inline const vector<int>& EulerTour<TREE>::Vertex_inv( const int& t ) const { return m_vertex_inv[t]; }

