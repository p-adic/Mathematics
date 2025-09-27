// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/Parallel/a_Macro.hpp

#pragma once

#define PARALLEL_FLOOR_SUM_PREP                 \
  vector<INT2> cc{};                            \
  Map<INT2,int> cc_inv{};                       \
                                                \
  for( auto& m : den ){                         \
                                                \
    assert( m > 0 );                            \
    cc_inv[m];                                  \
                                                \
    if( cc_inv.size() > cc.size() ){            \
                                                \
      cc.push_back( m );                        \
                                                \
    }                                           \
                                                \
  }                                             \
                                                \
  Sort( cc );                                   \
  const int N = num.size() , M = den.size() , L = cc.size();     \
                                                \
  for( int j = 0 ; j < L ; j++ ){               \
                                                \
    cc_inv[cc[j]] = j;                          \
                                                \
  }                                             \
                                                \
  int logL = 1;                                 \
                                                \
  while( L > 1 << logL ){                       \
                                                \
    logL++;                                     \
                                                \
  }                                             \

#define PARALLEL_FLOOR_SUM_BODY( ANS , ANS_INT )                        \
  for( int i = 0 ; i < N ; i++ ){                                       \
                                                                        \
    auto& n = num[i];                                                     \
    assert( n >= 0 );                                                   \
    const int B = max( int( sqrt( n / logL ) ) , 1 ) , B_div = n / B;   \
    MAX_LEQ( j0 , 0 , L - 1 , cc[j0] , B_div );                         \
                                                                        \
    for( int j = 0 ; j <= j0 ; j++ ){                                   \
                                                                        \
      ANS;                                                 \
                                                                        \
    }                                                                   \
                                                                        \
    ll v_div = B_div;                                                   \
                                                                        \
    for( int v = B - 1 ; v >= 1 ; v-- ){                                \
                                                                        \
      v_div = n / v;                                                    \
      MAX_LEQ( j , j0 , L - 1 , j >= 0 ? cc[j] : -1 , v_div );          \
      ANS_INT;                                                         \
      j0 = j;                                                           \
                                                                        \
    }                                                                   \
                                                                        \
  }                                                                     \


