// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/IncreasingSubsequence/a_Macro.hpp

#pragma once
#define COUNT_INCREASING_SUBSEQUENCE( INT , PREV , ANSWER , ... )	\
  const int size = a.size();                                            \
  Map<T,int> TheAtsu{};							\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    TheAtsu[a[i]];							\
									\
  }									\
									\
  int length = 0;							\
									\
  for( auto itr = TheAtsu.begin() , end = TheAtsu.end() ; itr != end ; itr++ ){ \
									\
    itr->second = length++;						\
									\
  }									\
									\
  BIT<INT,size_max> count{};						\
  const INT one{ __VA_ARGS__ };						\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    const int& n = TheAtsu[a[i]];					\
    count.Add( n , one + count.IntervalSum( 0 , PREV ) );		\
									\
  }									\
									\
  const INT answer = count.IntervalSum( 0 , length - 1 );		\
  return ANSWER								\


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



