// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// ファイル容量削減のため極力vectorの成分を参照するだけの変数を用いない。
// 実行時間に優位差はなし。

template <typename TREE> inline DepthFirstSearchOnTree<TREE>::DepthFirstSearchOnTree( TREE& T , const int& root , const int& digit ) : DepthFirstSearch<int,TREE>( T , -1 , root ) , PointedSet<int>( root ) ,  m_node_num() , m_children() , m_set_children() , m_depth() , m_set_depth() , m_height_max() , m_height_min() , m_set_height() , m_heaviness() , m_set_heaviness() , m_digit( digit ) , m_doubling( m_digit ) , m_set_doubling() { static_assert( is_same_v<TREE,Graph<decldecay_t( declval<TREE>().edge() )>> ); assert( int( ( m_node_num = this->GetNodeEnumeration() ).size() ) == this->size() ); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Root() const { return this->Point(); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Parent( const int& i ) { return this->prev( i ); }
template <typename TREE> inline const vector<int>& DepthFirstSearchOnTree<TREE>::Children( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Depth( const int& i ) { if( !m_set_depth ){ SetDepth(); } return m_depth[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Height( const int& i , const bool& maximum ) { if( !m_set_height ){ SetHeight(); } return ( maximum ? m_height_max : m_height_min )[i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::Heaviness( const int& i ) { if( !m_set_heaviness ){ SetHeaviness(); } return m_heaviness[i]; }
template <typename TREE> inline int DepthFirstSearchOnTree<TREE>::Degree( const int& i ) { return Children( i ).size() + ( i == Root() ? 0 : 1 ); }
template <typename TREE> inline bool DepthFirstSearchOnTree<TREE>::IsLeaf( const int& i , const int& root ) { assert( -1 <= root && root < this->size() ); return Degree( i ) == 1 && i != ( root == -1 ? Root() : root ); }

template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::NodeNumber( const int& i , const bool& reversed ) const { const int& V = this->size(); assert( i < V ); return m_node_num[reversed ? V - 1 - i : i]; }
template <typename TREE> inline const int& DepthFirstSearchOnTree<TREE>::ChildrenNumber( const int& i ) { if( ! m_set_children ){ SetChildren(); } return m_children_num[i]; }
template <typename TREE> template <typename Ord> inline void DepthFirstSearchOnTree<TREE>::ReorderChildren( Ord& ord ) { const int& V = this->size(); for( int i = 0 ; i < V ; i++ ){ sort( m_children[i].begin() , m_children[i].end() , [&]( const int& j , const int& k ) { return ord( i , j , k ); } ); const int L = m_children[i].size(); for( int j = 0 ; j < L ; j++ ){ m_children_num[m_children[i][j]] = j; } } }

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::Ancestor( int i , int n )
{

  if( !m_set_doubling ){

    SetDoubling();

  }

  assert( ( n >> m_digit ) == 0 );
    
  int d = 0;
  
  while( n != 0 ){

    assert( ( n & 1 ) == 1 ? ( i = m_doubling[d][i] ) != -1 : true );
    d++;
    n >>= 1;

  }

  return i;

}

template <typename TREE> inline int DepthFirstSearchOnTree<TREE>::LCA( int i , int j ) { int i_prev; int j_prev; return LCA( i , j , i_prev , j_prev ); }

template <typename TREE>
int DepthFirstSearchOnTree<TREE>::LCA( int i , int j , int& i_prev , int& j_prev )
{

  i_prev = j_prev = -1;
  const int diff = Depth( i ) - Depth( j );
  assert( diff > 0 ? ( i = Parent( i_prev = Ancestor( i , diff - 1 ) ) ) != -1 : diff < 0 ? ( j = Parent( j_prev = Ancestor( j , - diff - 1 ) ) ) != -1 : true );

  if( i != j ){
  
    if( !m_set_doubling ){

      SetDoubling();

    }
  
    int d = m_digit;

    while( --d >= 0 ){

      assert( m_doubling[d][i] != m_doubling[d][j] ? ( i = m_doubling[d][i] ) != -1 && ( j = m_doubling[d][j] ) != -1 : true );

    }

    assert( ( i = Parent( i_prev = i ) ) == ( j = Parent( j_prev = j ) ) );

  }
  
  return i;

}

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

template <typename TREE>
void DepthFirstSearchOnTree<TREE>::SetDoubling()
{

  assert( !m_set_doubling );
  m_set_doubling = true;
  const int& V = this->size();
  
  {
    
    m_doubling[0].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      m_doubling[0].push_back( Parent( i ) );

    }

  }
  
  for( int d = 1 ; d < m_digit ; d++ ){

    m_doubling[d].reserve( V );

    for( int i = 0 ; i < V ; i++ ){

      m_doubling[d].push_back( m_doubling[d-1][i] == -1 ? -1 : m_doubling[d-1][m_doubling[d-1][i]] );

    }

  }

  return;

}

template <typename TREE> template <typename F>
ret_t<F> DepthFirstSearchOnTree<TREE>::RootingDP( F& f )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,vector<U>,int> );

  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  vector<vector<U>> children_value( V );
  U temp;
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const int& j = Parent( i );
    temp = f( children_value[i] , i );

    if( j != -1 ){

      children_value[j].push_back( temp );

    }

  }

  return temp;

}
  
template <typename TREE> template <typename MONOID , typename F , typename G>
vector<inner_t<MONOID>> DepthFirstSearchOnTree<TREE>::RerootingDP( MONOID M , F& f , G& g )
{

  using U = inner_t<MONOID>;
  static_assert( is_invocable_r_v<U,F,U,int> && is_invocable_r_v<U,G,U,bool,int,int> );
  
  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = this->size();
  const U& e = M.Unit();

  // children_value[i][m]にiのm番目の子ノードjまでの計算値のfでの像を格納。
  vector<vector<U>> children_value( V );
  // l_sum[i][m]にchildren_value[i][0],...,children_value[i][m-1]の
  // gでの像のMに関する積を格納。
  vector<vector<U>> l_sum( V );
  // r_sum[i][m]にchildren_value[i][m+1],...,children_value[i][size_i-1]の
  // gでの像のMに関する積を格納。
  vector<vector<U>> r_sum( V );
  
  for( int i = 0 ; i < V ; i++ ){

    children_value[i].resize( m_children[i].size() );

  }
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n , true );
    const vector<U>& children_value_i = children_value[i];
    const int size_i = children_value_i.size();

    U temp = e;
    l_sum[i].reserve( size_i + 1 );
    l_sum[i].push_back( temp );
    
    for( int m = 0 ; m < size_i ; m++ ){

      l_sum[i].push_back( temp = M.Product( temp , g( children_value_i[m] , true , i , m_children[i][m] ) ) );

    }
    
    const int& j = Parent( i );

    if( j != -1 ){
      
      children_value[j][m_children_num[i]] = f( temp , i );

    }

    temp = e;
    r_sum[i].resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      r_sum[i][size_i - m] = temp;
      temp = M.Product( g( children_value_i[size_i - m] , true , i , m_children[i][size_i - m] ) , temp );

    }

  }

  // l_sum[i][m]にchildren_value[i][0],...,children_value[i][m-1]の
  // gでの像のMに関する積を格納していたが、さらにこれに親ノードの寄与も追加する。
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = NodeNumber( n );
    const int& j = Parent( i );
    const int& k = ChildrenNumber( i );
    const int size_i = r_sum[i].size();
    // children_value[j][0],...,children_value[j][k-1]のgでの像と
    // rest_j（既に計算済み）と
    // children_value[j][k+1],...,children_value[j][size_i-1]のgでの像と
    // のMに関する積のfでの像のgでの像。
    const U rest_i = g( f( M.Product( l_sum[j][k] , r_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // l_sum[i][m]にrest_i（ある意味m_children[i][-1]）と
      // children_value[i][0],...,children_value[i][m-1]の
      // gでの像のMに関する積を格納。
      l_sum[i][m] = M.Product( rest_i , l_sum[i][m] );

    }

  }

  vector<U> answer( V );

  for( int i = 0 ; i < V ; i++ ){

    // l_sum[i].back()は親の寄与（ある意味children_value[i][-1]）と
    // children_value[i][0],...,children_value[i][size_i-1]の
    // gでの像のMに関する積。
    answer[i] = f( l_sum[i].back() , i );

  }

  return answer;

}

template <typename TREE> inline tuple<int,int,int> DepthFirstSearchOnTree<TREE>::Diameter()
{

  auto& V = this->size();
  int i_opt[2] = {-1,-1};
  int d_opt = size;

  for( int i = 0 ; i < V ; i++ ){

    auto& d = Depth( i );

    if( d_opt > d ){

      d_opt = d;
      i_opt[0] = i;

    }

  }

  DepthFirstSearchOnTree<TREE> dfs{ this->m_G , i_opt };
  d_opt = size;
  
  for( int i = 0 ; i < V ; i++ ){

    auto& d = dfs.Depth( i );

    if( d_opt > d ){

      d_opt = d;
      i_opt[1] = i;

    }

  }
  
  return {i_opt[0],i_opt[1],d_opt};
  
}
