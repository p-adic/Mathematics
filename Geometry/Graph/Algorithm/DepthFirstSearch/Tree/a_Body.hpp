// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// ファイル容量削減のため極力vectorの成分を参照するだけの変数を用いない。
// 実行時間に優位差はなし。

template <typename TREE> inline DepthFirstSearchOnTree<TREE>::DepthFirstSearchOnTree( TREE& T , const int& root ) : DepthFirstSearch<int,TREE>( T , -1 , root ) , PointedSet<int>( root ) ,  m_node_num() , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height_max() , m_height_min() , m_set_height() , m_heaviness() , m_set_heaviness() { static_assert( is_same_v<TREE,Graph<decldecay_t( declval<TREE>().edge() )>> ); assert( int( ( m_node_num = this->GetNodeEnumeration() ).size() ) == this->size() ); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Root() const { return this->Point(); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Parent( const int& i ) { return this->prev( i ); }
template <typename TREE> inline const vector<int>& DepthFirstSearchOnTree<TREE>::Children( const int& i ) { if( !m_set_children ){ SetChildren(); } return m_children[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Depth( const int& i ) { if( !m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Height( const int& i , const bool& maximum ) { if( !m_set_height ){ SetHeight(); } return ( maximum ? m_height_max : m_height_min )[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Heaviness( const int& i ) { if( !m_set_heaviness ){ SetHeaviness(); } return m_heaviness[i]; }
template <typename TREE> inline int DepthFirstSearchOnTree<TREE>::Degree( const int& i ) { return Children( i ).size() + ( i == Root() ? 0 : 1 ); }
template <typename TREE> inline bool DepthFirstSearchOnTree<TREE>::IsLeaf( const int& i , const int& root ) { assert( -1 <= root && root < this->size() ); return Degree( i ) == 1 && i != ( root == -1 ? Root() : root ); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::NodeNumber( const int& i , const bool& reversed ) const { const int& V = this->size(); assert( i < V ); return m_node_num[reversed ? V - 1 - i : i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }
template <typename TREE> template <typename Ord> inline void DepthFirstSearchOnTree<TREE>::ReorderChildren( Ord& ord ) { const int& V = this->size(); for( int i = 0 ; i < V ; i++ ){ sort( m_children[i].begin() , m_children[i].end() , [&]( const int& j , const int& k ) { return ord( i , j , k ); } ); const int L = m_children[i].size(); for( int j = 0 ; j < L ; j++ ){ m_children_num[m_children[i][j]] = j; } } }

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetChildren()
{

  assert( !m_set_children );
  m_set_children = true;
  const int& V = this->size();
  m_children.resize( V );
  m_children_num.resize( V );
  
  for( int i = 0 ; i < V ; i++ ){

    const int& j = Parent( i );

    if( j == -1 ){

      m_children_num[i] = -1;

    } else {
      
      m_children_num[i] = m_children[j].size();
      m_children[j].push_back( i );

    }

  }

  return;
  
}

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetDepth()
{

  assert( !m_set_depth );
  m_set_depth = true;
  const int& V = this->size();
  m_depth.resize( V );
  
  for( int n = 1 ; n < V ; n++ ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_depth[i] += m_depth[j] + 1;

  }

  return;

}

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetHeight()
{

  assert( !m_set_height );
  m_set_height = true;
  const int& V = this->size();
  m_height_max.resize( V );
  m_height_min.resize( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_height_max[j] = max( m_height_max[j] , m_height_max[i] + 1 );
    m_height_min[j] = m_height_min[j] == 0 ? m_height_min[i] + 1 : min( m_height_min[j] , m_height_min[i] + 1 );

  }

  return;

}

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetHeaviness()
{

  assert( !m_set_heaviness );
  m_set_heaviness = true;
  const int& V = this->size();
  m_heaviness.resize( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = m_node_num[n];
    const int& j = Parent( i );
    assert( j != -1 );
    m_heaviness[j] += m_heaviness[i] + 1;

  }

  return;

}

