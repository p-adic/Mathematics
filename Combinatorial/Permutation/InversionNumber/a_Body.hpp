// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/InversionNumber/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"

template <typename INT>
ll InversionNumber( const vector<INT>& A )
{

  const int size = A.size();
  BIT<int> count{ Max( A ) + 1 };
  ll answer = 0;
  
  for( int i = size - 1 ; i >= 0 ; i-- ){

    answer += count.IntervalSum( 0 , A[i] - 1 );
    count.Add( A[i] , 1 );

  }

  return answer;

}

template <typename INT> inline ll LeastAdjacentSwapCount( const vector<INT>& P ){ return InversionNumber( P ); }


