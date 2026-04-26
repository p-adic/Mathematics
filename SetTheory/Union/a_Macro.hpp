// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Union/a_Macro.hpp

#pragma once

#define ENUM_SUB( UPDATE )                              \
  const int K = S_inv[i].size() , p = 1 << K;           \
                                                        \
  for( int s = 1 ; s < p ; s++ ){                       \
                                                        \
    vector<int> t{};                                    \
                                                        \
    for( int k = 0 ; k < K ; k++ ){             \
                                                \
      if( ( s >> k ) & 1 ){                     \
                                                \
        t <<= S_inv[i][k];                      \
                                                \
      }                                         \
                                                \
    }                                           \
                                                \
    UPDATE;                                     \
                                                \
  }                                             \

