// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/Partition/a_Body.hpp

#pragma once
#include "a.hpp"

template <template <typename...> typename PAIR , typename INT>
vector<int> NoncrossingPartition( const int& N , const vector<PAIR<INT,INT>>& chord , const bool& colour_edge )
{

  vector<vector<pair<INT,int>>> left( N );
  vector<vector<pair<INT,int>>> right( N );
  const int M = chord.size();

  for( int j = 0 ; j < M ; j++ ){
    
    auto [l,r] = chord[j];
    assert( 0 <= l && l < N );
    assert( 0 <= r && r != l && r < N );

    if( l < r ){

      left[l].push_back( { -r , j + 1 } );
      right[r].push_back( { -l , j + 1 } );

    } else {

      left[r].push_back( { -l , j + 1 } );
      right[l].push_back( { -r , j + 1 } );

    }
    
  }

  vector<int> colour( N , -1 );
  vector<int> stack = {0};

  for( int i = 0 ; i < N ; i++ ){

    bool paint = colour_edge || ( right[i].empty() && left[i].empty() );

    sort( right[i].begin() , right[i].end() );

    while( !right[i].empty() ){

      assert( !stack.empty() && get<1>( right[i].back() ) == stack.back() );
      right[i].pop_back();
      stack.pop_back();

    }

    sort( left[i].begin() , left[i].end() );

    for( auto& [r,j] : left[i] ){

      stack.push_back( j );

    }

    assert( !stack.empty() );

    if( paint ){

      colour[i] = stack.back();

    }

  }

  return colour;

}
