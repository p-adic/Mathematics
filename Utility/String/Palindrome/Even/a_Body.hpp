// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Palindrome/Even/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Arithmetic/Iteration/a_Body.hpp"

template <typename STR>
vector<int> Manacher( const STR& S )
{

  const int N = S.size();
  vector<int> answer( N );
  int i = 0 , l = 0 , r = 0;

  while( i < N ){

    while( 0 <= l - 1 && r + 1 < N && S[l-1] == S[r+1] ){

       l--;
       r++;

    }

    answer[i] = r - i;
    int l0 = i , r0 = i;

    while( 0 <= l0 - 1 && l < l0 - 1 - answer[l0-1] ){

      l0--;
      r0++;
      answer[r0] = answer[l0];

    }

    i = r0 + 1;
    SetMax( r , i );
    l = i - ( r - i );

  }

  return answer;

}

