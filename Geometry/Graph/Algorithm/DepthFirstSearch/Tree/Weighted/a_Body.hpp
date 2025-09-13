// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Weighted/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// ファイル容量削減のため極力vectorの成分を参照するだけの変数を用いない。

template <typename TREE , typename U , typename MONOID> inline DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const int& root , const int& digit ) :
  DepthFirstSearchOnTree<TREE>( T , root , digit ) , m_M( move( M ) ) , m_wprev( this->size() , m_M.One() ) , m_wdepth_r() , m_wdepth_l() , m_set_wdepth() , m_wheight_max_r() , m_wheight_max_l() , m_wheight_min_r() , m_wheight_min_l() , m_set_wheight() , m_wheaviness() , m_set_wheaviness() , m_wdoubling( this->m_digit ) , m_set_wdoubling()
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  const int& V = this->size();
  
  for( int i = 0 ; i < V ; i++ ){

    auto&& edge_i = this->m_G.Edge( i );

    for( auto& p : edge_i ){

      const int& j = get<0>( p );

      if( i == this->Parent( j ) ){

	m_wprev[j] = get<1>( p );

      }

    }

  }

}

template <typename TREE , typename U , typename MONOID> inline MONOID& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::Monoid() noexcept { return m_M; }
template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::PrevWeight( const int& i ) const noexcept { return m_prev[i]; }

template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WDepth( const int& i , const bool& right ) { assert( i < this->size() ); if( !m_set_wdepth ){ SetWDepth(); } return ( right ? m_wdepth_r : m_wdepth_l )[i]; }
template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WHeight( const int& i , const bool& maximum , const bool& right ) { assert( i < this->size() ); if( !m_set_wheight ){ SetWHeight(); } return ( maximum ? ( right ? m_wheight_max_r : m_wheight_max_l ) : ( right ? m_wheight_min_r : m_wheight_min_l ) )[i]; }
template <typename TREE , typename U , typename MONOID> inline const U& DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::WHeaviness( const int& i ) { assert( i < this->size() ); if( !m_set_wheaviness ){ SetWHeaviness(); } return m_wheaviness[i]; }

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWDepth()
{

  assert( !m_set_wdepth );
  m_set_wdepth = true;
  const int& V = this->size();
  const U& one = m_M.One();
  m_wdepth_r.resize( V , one );
  m_wdepth_l.resize( V , one );

  for( int n = 1 ; n < V ; n++ ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wdepth_r[i] = m_M.Product( m_wdepth_r[j] , m_wprev[i] );
    m_wdepth_l[i] = m_M.Product( m_wprev[i] , m_wdepth_l[j]  );

  }

  return;

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWHeight()
{

  assert( !m_set_wheight );
  m_set_wheight = true;
  const int& V = this->size();
  const U& one = m_M.One();
  m_wheight_max_r.resize( V , one );
  m_wheight_max_l.resize( V , one );
  m_wheight_min_r.resize( V , one );
  m_wheight_min_l.resize( V , one );
  vector<bool> found( V );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wheight_max_r[j] = max( m_wheight_max_r[j] , m_M.Product( m_wheight_max_r[i] , m_wprev[i] ) );
    m_wheight_max_l[j] = max( m_wheight_max_l[j] , m_M.Product( m_wprev[i] , m_wheight_max_l[i] ) );

    if( found[j] ){

      m_wheight_min_r[j] = min( m_wheight_min_r[j] , m_M.Product( m_wheight_min_r[i] , m_wprev[i] ) );
      m_wheight_min_l[j] = min( m_wheight_min_l[j] , m_M.Product( m_wprev[i] , m_wheight_min_l[i] ) );

    } else {

      m_wheight_min_r[j] = m_M.Product( m_wheight_min_r[i] , m_wprev[i] );
      m_wheight_min_l[j] = m_M.Product( m_wprev[i] , m_wheight_min_l[i] );
      found[j] = true;

    }

  }

  return;

}

template <typename TREE , typename U , typename MONOID>
void DepthFirstSearchOnWeightedTree<TREE,U,MONOID>::SetWHeaviness()
{

  assert( !m_set_wheaviness );
  m_set_wheaviness = true;
  const int& V = this->size();
  m_wheaviness.resize( V , m_M.One() );
  
  for( int n = V - 1 ; n > 0 ; n-- ){

    const int& i = this->m_node_num[n];
    const int& j = this->Parent( i );
    assert( j != -1 );
    m_wheaviness[j] = m_M.Product( m_wheaviness[j] , m_M.Product( m_wheaviness[i] , m_wprev[i] ) );

  }

  return;

}


