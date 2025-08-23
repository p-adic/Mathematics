// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/WeightSum/Namori/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../../Polynomial/a_Body.hpp"

template <typename INT0 , typename INT1 , typename INT2>
INT2 NamoriWeightSum( const vector<Tuple<INT0,INT1,INT2>>& u )
{

  const int size = u.size();
  INT2 answer{} , sum0{} , sum1{};
  Polynomial<INT2> f{};
  Polynomial<INT2> g{};

  for( int i = 0 ; i < size ; i++ ){

    auto& [ui0,ui1,ui2] = u[i];
    sum0 += f[i] = g[size - 1 - i] = ui0;
    sum1 += ui1;
    answer += ui2 - ui0 * ui1;

  }

  answer += ( sum0 *= sum1 );
  f *= g;

  for( int d = 1 ; d <= size - d ; d++ ){

    answer += d * ( d == size - d ? ( f[size-1-d] + f[size*2-1-d] ) / 2 : f[size-1-d] + f[size*2-1-d] );

  }

  return answer;

}
