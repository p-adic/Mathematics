// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/HeavyLightDecomposition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename TREE> inline HeavyLightDecomposition<TREE>::HeavyLightDecomposition( TREE& T , const int& root , const int& digit ) : DepthFirstSearchOnTree<TREE>( T , root , digit ) , m_HL() , m_HL_inv() , m_path() , m_subtree()
{

  // HL�����̍\�z�B�ł��d���ӂ������Ɋi�[���Ă������ƂŊe�����؂��P�̋�Ԃɕϊ�����B
  const int& V = this->size();
  m_HL.resize( V , this->NodeNumber( 0 ) );
  m_HL_inv.resize( V );

  for( int n = 0 ; n < V ; n++ ){

    const int& i = this->NodeNumber( n );
    auto& children_i = this->Children( i );

    if( !children_i.empty() ){

      int j_opt = -1;
      int heaviness_opt = -1;

      for( auto& j : this->Children( i ) ){

	const int& heaviness_j = this->Heaviness( j );

	if( heaviness_opt < heaviness_j ){

	  j_opt = j;
	  heaviness_opt = heaviness_j;

	}

      }

      int temp = m_HL_inv[i] + 1;
      temp += this->Heaviness( m_HL[m_HL_inv[j_opt] = temp] = j_opt ) + 1;

      for( auto& j : this->Children( i ) ){

	if( j != j_opt ){

	  temp += this->Heaviness( m_HL[m_HL_inv[j] = temp] = j ) + 1;

	}

      }

    }

  }

  // root����e�m�[�h�ւ̃p�X�̂Ȃ�m_HL��̕��[l,r]���̌v�Z�B
  // �e�m�[�h�ő��̔Z�x��O(log V)�ɂȂ�B
  m_path.resize( V , {{root,root}} );

  for( int n = 1 ; n < V ; n++ ){

    const int& i = this->NodeNumber( n );
    const int& parent_i = this->Parent( i );
    auto& m_path_i = m_path[i] = m_path[parent_i];
    auto& [l,r] = m_path_i.back();
    const int& HL_inv_parent_i = m_HL_inv[parent_i];

    if( r == HL_inv_parent_i ){

      r = m_HL_inv[i];

    } else {

      r = HL_inv_parent_i;
      const int& HL_inv_i = m_HL_inv[i];
      m_path_i.push_back( {HL_inv_i,HL_inv_i} );

    }

  }

  // �e�m�[�h�����Ƃ��镔���؂̂Ȃ�m_HL��̕��[l,r]�̌v�Z�B
  m_subtree.resize( V );

  for( int n = V - 1 ; n >= 0 ; n-- ){

    const int& i = this->NodeNumber( n );
    auto& [l,r] = m_subtree[i];
    l = r = m_HL_inv[i];

    for( auto& j : this->Children( i ) ){

      r = max( r , m_subtree[j].second );

    }

  }

}

template <typename TREE> inline const int& HeavyLightDecomposition<TREE>::RearragedNodeNumber( const int& n ) const { assert( 0 <= n && n < this->size() ); return m_HL[n]; }
template <typename TREE> inline const int& HeavyLightDecomposition<TREE>::RearragedNodeNumber_inv( const int& i ) const { assert( 0 <= i && i < this->size() ); return m_HL_inv[i]; }
template <typename TREE> inline const vector<pair<int,int>>& HeavyLightDecomposition<TREE>::PathFromRoot( const int& i ) const { assert( 0 <= i && i < this->size() ); return m_path[i]; }
template <typename TREE> inline const pair<int,int> HeavyLightDecomposition<TREE>::Subtree( const int& i ) const { assert( 0 <= i && i < this->size() ); return m_subtree[i]; }
