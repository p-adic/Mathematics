// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/LCA/DST/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../EulerTour/a_Body.hpp"
#include "../../../../../../../SetTheory/DirectProduct/AffineSpace/DisjointSparseTable/a_Body.hpp"

#include "../../../../../../../Utility/Vector/a_Body.hpp"

template <typename TREE> inline DSTOnTree<TREE>::DSTOnTree( TREE& T , const int& root ) : DepthFirstSearchOnTree<TREE>( T , root ) , EulerTour<TREE>( T , root ) , m_vertex( id<int>( T.size() ) ) , m_dst( 0 , HeightArray() ) {}

template <typename TREE>
vector<int> DSTOnTree<TREE>::HeightArray()
{

  sort( m_vertex.begin() , m_vertex.end() , [&]( const int& i , const int& j ){ return this->Depth( i ) > this->Depth( j ); } );
  const int& size0 = this->size();
  auto& et = this->Vertex();
  const int size1 = et.size();
  vector<int> index( size0 ) , answer( size1 );

  for( int i = 0 ; i < size0 ; i++ ){

    index[m_vertex[i]] = i;

  }

  for( int i = 0 ; i < size1 ; i++ ){

    answer[i] = index[et[i]];

  }

  return answer;
  
}

template <typename TREE> inline int DSTOnTree<TREE>::LCA( const int& i , const int& j ) { auto [li,ri] = this->Subtree( i ); auto [lj,rj] = this->Subtree( j ); return m_vertex[m_dst.IntervalMax( min( li , lj ) , max( ri , rj ) )]; }
template <typename TREE> inline int DSTOnTree<TREE>::d( const int& i , const int& j ) { return this->Depth( i ) - 2 * this->Depth( LCA( i , j ) ) + this->Depth( j ); }
