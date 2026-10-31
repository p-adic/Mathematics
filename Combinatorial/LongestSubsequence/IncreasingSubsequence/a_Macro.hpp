// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LongestSubsequence/IncreasingSubsequence/a_Macro.hpp

#pragma once
#define MAXIMISE_INCREASING_SUBSEQUENCE( INDEX )                        \
  const int size = a.size();                                            \
  vector<pair<T,int>> a_copy( size );                                   \
                                                                        \
  for( int i = 0 ; i < size ; i++ ){                                    \
                                                                        \
    a_copy[i] = { a[i] , INDEX };                                           \
                                                                        \
  }                                                                     \
                                                                        \
  sort( a_copy.begin() , a_copy.end() );                                \
  IntervalMaxBIT length( 0 , size );                                    \
  vector<int> answer( size );                                           \
                                                                        \
  for( auto& [ai,i] : a_copy ){                                         \
                                                                        \
    length.SetMax( INDEX , answer[INDEX] = length.IntervalMax( 0 , INDEX ) + 1 );   \
                                                                        \
  }                                                                     \
                                                                        \
  return answer                                                         \



