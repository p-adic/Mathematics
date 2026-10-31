// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LongestSubsequence/ZigZagSubsequence/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename T>
T2<int> LongestZigZagSubsequence( const vector<T>& A )
{

  const int N = A.size();
  // up[i] = ’·‚³i+1‚Ì‘Œ¸‘...Œ^‚Ì––”ö‚ÌÅ‘å’l‚ğ—^‚¦‚é“Yš‚ÌÅ¬’l
  // down[i] = ’·‚³i+1‚ÌŒ¸‘Œ¸...Œ^‚Ì––”ö‚ÌÅ¬’l‚ğ—^‚¦‚é“Yš‚ÌÅ¬’l
  vector<int> up( N , -1 ) , down( N , -1 );

  if( N > 0 ){

    up[0] = down[0] = 0;
    
    for( int i = 0 ; i < N ; i++ ){

      for( int j = 0 ; j <= i ; j++ ){

        if( up[j] == -1 ? j > 0 && down[j-1] != -1 && A[down[j-1]] < A[i] : A[up[j]] < A[i] ){

          up[j] = i;

        }

        if( down[j] == -1 ? j > 0 && up[j-1] != -1 && A[up[j-1]] > A[i] : A[down[j]] > A[i] ){

          down[j] = i;

        }
    
      }

    }

  }

  int a0 = 0 , a1 = 0;

  for( int i = 0 ; i < N ; i++ ){

    if( up[i] != -1 ){

      a0 = i + 1;

    }

    if( down[i] != -1 ){

      a1 = i + 1;

    }

  }

  return {a0,a1};

}


