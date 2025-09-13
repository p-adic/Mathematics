// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/NearestNeighbour/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFST>
vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<bool>& subset )
{

  const int& V = dfst.size();
  vector<int> answer( V , -1 );

  for( int n = 0 ; n < size ; n++ ){

    auto&& i = dfst.NodeNumber( n );
    answer[i] = subset[i] ? i : n == 0 ? -1 : answer[dfst.Parent( i )];
    
  }

  return answer;
  
}

template <typename DFST> inline vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<int>& subset ) { const int& V = dfst.size(); vector<bool> image( V ); for( auto& i : subset ){ image[i] = true; } return NearestNeighbourOnRotedTree( dfst , image ); }
