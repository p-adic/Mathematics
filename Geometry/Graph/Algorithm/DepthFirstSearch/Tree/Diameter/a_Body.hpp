// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Diameter/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename TREE>
vector<int> Diameter( TREE& T )
{

  auto& V = T.size();
  int i_opt = 0;
  int d_opt = 0;
  vector<int> answer{};

  for( int n = 0 ; n < 2 ; n++ ){

    DepthFirstSearchOnTree dfst{ T , i_opt };

    for( int i = 0 ; i < V ; i++ ){

      if( d_opt <= dfst.Depth( i ) ){

        d_opt = dfst.Depth( i_opt = i );

      }

    }

    if( n == 0 ){

      continue;
      
    }

    while( i_opt != -1 ){

      answer.push_back( i_opt );
      i_opt = dfst.Parent( i_opt );

    }

  }

  return answer;
  
}
