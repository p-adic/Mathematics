// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFST , typename F>
vector<ret_t<F>> RootingDP( DFST& dfst , F f )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,vector<U>,int> );
  const int& V = dfst.size();
  vector<U> answer( V );
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n , true );
    vector<U> children_value{};

    for( auto& j : dfst.Children( i ) ){

      children_value.push_back( answer[j] );

    }
    
    answer[i] = f( move( children_value ) , i );

  }

  return answer;

}
  
