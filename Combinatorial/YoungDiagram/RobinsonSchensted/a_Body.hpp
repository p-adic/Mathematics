// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/YoungDiagram/RobinsonSchensted/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Tuple/Wrap/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"

template <typename INT>
Pair<vector<vector<INT>>,vector<vector<int>>> RobinsonSchenstedKnuth( const vector<INT>& v , int K )
{

  const int N = v.size();
  vector<vector<INT>> a0 = {{}};
  vector<vector<int>> a1 = {{}};

  if( K == -1 ){

    K = N;

  }

  for( int i = 0 ; i < N ; i++ ){

    const int L = a0.size();
    INT t = v[i];

    for( int j = 0 ; j < L ; j++ ){

      auto end = a0[j].end() , itr = lower_bound( a0[j].begin() , end , t );

      if( itr == end ){

        a0[j] <<= t;
        a1[j] <<= i;

        if( j == L - 1 && L < K ){

          a0 <<= {};
          a1 <<= {};

        }
        
        break;

      } else {

        swap( *itr , t );

      }

    }

  }

  if( a0.back().empty() ){

    pop( a0 );
    pop( a1 );

  }
  
  return { move( a0 ) , move( a1 ) };

}
