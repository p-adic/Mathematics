// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/Odd/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../Debug/a_Body.hpp"
#else
  #include "../../a_Body.hpp"
#endif

#include "../../../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename GRAPH>
vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found , const inner_t<GRAPH>& t_start )
{

  using T = inner_t<GRAPH>;
  const int& size = G.size();
  auto Enum = [&]( const int& i ){ return Pair<T,int>{ G.Enumeration( i < size ? i : i - size ) , i >= size }; };
  auto EnumInv = [&]( const Pair<T,bool>& t ){ return G.Enumeration_inv( t[O] ) + ( t[I] ? size : 0 ); };

  auto edge = [&]( const Pair<T,int>& t ){

    vector<Pair<T,int>> answer{};

    for( auto& u : G.Edge( t[O] ) ){

      answer.push_back( { G.Vertex( u ) , !t[I] } );

    }

    return answer;

  };
  
  EnumerationGraph G2{ size * 2 , Enum , EnumInv , edge };
  BreadthFirstSearch bfs{ G2 , Pair<T,int>{ not_found , true } , Pair<T,int>{ t_start , false } };
  vector<int> d = bfs.GetDistance();
  vector<T> a{};
  Pair<T,int> t{ t_start , true };

  while( ( t = bfs.prev( t ) )[O] != not_found ){

    a.push_back( t[O] );

  }

  auto&& i = G.Enumeration_inv( t_start );
  assert( d[i+size] == -1 || int( a.size() ) == d[i+size] );
  return a;

}

template <typename GRAPH>
vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found )
{

  using T = inner_t<GRAPH>;
  const int& size = G.size();
  vector<T> a{};

  for( int i = 0 ; i < size ; i++ ){

    auto temp = ShortestOddCycle( G , not_found , G.Enumeration( i ) );

    if( !temp.empty() && ( a.empty() || a.size() > temp.size() ) ){

      a = move( temp );

    }

  }

  return a;

}


