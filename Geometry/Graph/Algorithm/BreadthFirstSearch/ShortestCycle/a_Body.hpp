// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

template <typename GRAPH>
vector<inner_t<GRAPH>> ShortestCycle( GRAPH& G , const inner_t<GRAPH>& not_found )
{

  using T = inner_t<GRAPH>;
  vector<T> a{};
  int opt = -1;
  const int& size = G.size();
  BreadthFirstSearch bfs{ G , not_found };

  for( int i = 0 ; i < size ; i++ ){

    auto&& r = G.Enumeration( i );
    bfs.Initialise( r );
    vector<int> d( size , -1 );
    d[i] = 0;
    T u;
    
    while( ( u = bfs.Next() ) != not_found ){
      
      auto&& j = G.Enumeration_inv( u );
      auto& p = bfs.prev( u );

      // ê‡•ª‚¯‚ğ‚µ‚È‚¢‚Æu‚ªn“_‚Ì‚É–â‘è‚Æ‚È‚éB
      if( d[j] == -1 ){
        
        d[j] = d[G.Enumeration_inv( p )] + 1;

      }

      int temp = d[j] + 1;

      if( opt != -1 && opt < temp ){

        break;

      }

      if( p == r ||  ){

        continue;

      }

      for( auto& e : G.Edge( u ) ){

        auto&& v = G.Vertex( e );

        if( v == r ){

          opt = temp;
          a = { u };
          T t = u;

          while( ( t = bfs.prev( t ) ) != not_found ){

            a.push_back( t );

          }

          assert( int( a.size() ) == opt );
          break;

        }

      }

    }

  }

  return a;

}
