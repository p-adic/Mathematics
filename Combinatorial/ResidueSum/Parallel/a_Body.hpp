// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/Parallel/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../FloorSum/Parallel/Debug/a_Body.hpp"
#else
  #include "../../FloorSum/Parallel/a_Body.hpp"
#endif
#include "../../../Arithmetic/Iteration/a_Body.hpp"

template <typename INT1 , typename INT2>
vector<ll> NumeratorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den )
{

  const int N = num.size() , M = den.size();
  const INT1 max_num = Max( num );
  ll logM = 1 , weight = 0;

  while( M > 1 << logM ){

    logM++;

  }

  for( auto& a : num ){

    weight += sqrt( a * logM );

  }

  vector<ll> answer( N );

  if( N + M + max_num * logM < M * logM + weight ){
  
    // C[x]‚Éden‚Ì¬•ª‚Å‚ ‚éx‚Ì–ñ”‚Ìd•¡“xž‚Ý‚Ì‘˜a‚ðŠi”[‚·‚éB
    vector<ll> C( max_num + 1 );

    for( auto& b : den ){

      if( b <= max_num ){

        C[b] += b;

      }

    }
  
    for( int x = max_num ; x >= 1 ; x-- ){

      if( C[x] == 0 ){

        continue;
      }
    
      for( int m = x + x ; m <= max_num ; m += x ){

        C[m] += C[x];

      }
    
    }

    ll temp = 0;
    int x = 0;

    for( auto& i : IndexSort( num ).first ){

      while( x < num[i] ){

        temp += M - C[++x];

      }
    
      answer[i] = temp;

    }

  } else {

    vector<ll> coeff( M );

    for( int j = 0 ; j < M ; j++ ){

      coeff[j] = den[j];

    }
    
    auto floor_sum = NumeratorParallelFloorSum( num , den , move( coeff ) );

    for( int i = 0 ; i < N ; i++ ){

      answer[i] = ll( num[i] ) * M - floor_sum[i];

    }

  }

  return answer;

}

template <typename INT1 , typename INT2>
vector<ll> DenominarorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den )
{

  const int N = num.size() , M = den.size();
  vector<ll> answer( M , Sum( 0LL , num ) );
  auto floor_sum = DenominatorParallelFloorSum( num , den );

  for( int j = 0 ; j < M ; j++ ){

    answer[j] -= floor_sum[j] * den[j];

  }

  return answer;

}
