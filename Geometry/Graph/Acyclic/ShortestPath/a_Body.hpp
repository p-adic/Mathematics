// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/ShortestPath/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename TOPOLOGICAL_SORTED_ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename U>
vector<pair<U,int>> TopologicalSortedShortestPath( TOPOLOGICAL_SORTED_ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const int& start )
{

  static_assert( is_same_v<inner_t<TOPOLOGICAL_SORTED_ACYCLIC_GRAPH>,int> && is_same_v<inner_t<MONOID>,U> && is_invocable_r_v<U,WEIGHT,int,int> );
  auto&& size = G.size();
  const U& one = M.One();
  vector<pair<U,int>> answer( size , {one,-1} );

  for( int i = start ; i < size ; i++ ){

    for( auto& u : G.Edge( i ) ){

      auto&& j = G.Vertex( u );
      auto& [w,prev] = answer[j];
      U temp = M.Product( get<0>( answer[i] ) , weight( i , j ) );

      if( prev == -1 || temp < w ){

        answer[j] = { move( temp ) , i };

      }

    }

  }

  return answer;


}

template <typename ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename T , typename U>
vector<pair<U,T>> AcyclicGraphShortestPath( ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const T& start , const T& external_point )
{

  static_assert( is_same_v<inner_t<ACYCLIC_GRAPH>,T> && is_invocable_r_v<U,WEIGHT,T,T> );
  auto [ts,ts_inv,ts_e] = TopologicalSortedGraph( G );
  auto&& size = G.size();
  vector<pair<U,T>> answer( size , { M.One() , -1 } );
  auto ts_answer = TopologicalSortedShortestPath( Graph{ size , move( ts_e ) } , move( M ) , [&]( const int& i , const int& j ) { return weight( ts[i] , ts[j] ); } , ts_inv[start] );

  for( int i = 0 ; i < size ; i++ ){

    auto& [w,prev] = ts_answer[ts_inv[i]];
    answer[i] = { move( w ) , prev == -1 ? external_point : ts[prev] };

  }

  return answer;

}
