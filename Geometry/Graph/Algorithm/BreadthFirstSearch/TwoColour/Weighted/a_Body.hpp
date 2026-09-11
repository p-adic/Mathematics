// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/TwoColour/Weighted/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../../../Utility/Tuple/Wrap/a_Body.hpp"
#include "../../../../../../Utility/Vector/a_Body.hpp"

template <typename GRAPH , typename T>
vector<T2<vector<T>>> WeightedTwoColour( GRAPH& G , const T& not_found )
{
  
  using U = Pair<T,bool>;
  auto&& N = G.size();
  auto Enum = [&]( const int& i ){ return U{ G.Enumeration( i>>1 ) , ( i & 1 ) == 1 }; };
  auto Enum_inv = [&]( const U& v ){ return ( G.Enumeration_inv( v[O] ) << 1 ) | ( v[I] ? 1 : 0 ); };
  
  auto edge = [&]( const U& v ){

    auto& [t,k] = v;
    vector<U> a{};

    for( auto& [u,b] : G.Edge( t ) ){
      a <<= {u,k^!b};
    }

    return a;

  };
  
  EnumerationGraph graph{ N * 2 , Enum , Enum_inv , edge };
  BreadthFirstSearch bfs{ graph , U{not_found,true} };
  auto [colour,colour_inv,colour_ulim] = bfs.GetConnectedComponent();
  vector<bool> found( colour_ulim );
  vector<T2<vector<T>>> answer{};
  
  for( int i = 0 ; i < N ; i++ ){

    auto&& t = G.Enumeration( i );
    auto& c0 = colour[Enum_inv({t,false})] , c1 = colour[Enum_inv({t,true})];

    if( c0 == c1 ){

      return {};

    }

    if( found[c0] ){

      continue;

    }

    found[c0] = found[c1] = true;
    answer <<= {{},{}};

    for( auto& [u,b] : colour_inv[c0] ){

      if( b ){

        answer.back()[O] <<= u;

      } else {

        answer.back()[I] <<= u;

      }

    }

  }

  return answer;  
  
}
