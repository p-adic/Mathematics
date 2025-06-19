// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/CompleteBipartiteMatching/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../../../../SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"
#else
  #include "../../../../../SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp"
#endif

template <typename RET , typename INT>
RET ShortestCompleteBipartiteMatching( const vector<INT>& S , const vector<INT>& T )
{

  const int N = S.size() , M = T.size();

  if( N > M ){

    return -1;
    
  }

  if( N == 0 ){

    return 0;

  }

  vector<pair<INT,bool>> V{};

  for( auto& s : S ){

    V.push_back( {s,false} );

  }

  for( auto& t : T ){

    V.push_back( {t,true} );

  }

  sort( V.begin() , V.end() );
  const int L = N + M;
  const INT c_min = V[0].first;
  const RET infty = RET{ V.back().first - c_min } * L * 2;
  vector<RET> init( L + 1 , infty );
  int zero = M;
  init[zero] = 0;
  IntervalAddBIT bit( init );

  for( auto& [c,target] : V ){

    c -= c_min;
    assert( c >= 0 );
    const RET diff = c;
    
    if( target ){

      RET temp0 = bit[zero];
      bit.IntervalAdd( 0 , zero - 1 , diff );
      bit.IntervalAdd( zero , L , -diff );
      zero--;
      RET temp1 = bit[zero];

      if( temp0 < temp1 ){

        bit.Add( zero , temp0 - temp1 );

      }

    } else {

      bit.IntervalAdd( 0 , zero , -diff );
      bit.IntervalAdd( zero + 1 , L , diff );
      zero++;

    }

  }

  return bit[zero];

}
