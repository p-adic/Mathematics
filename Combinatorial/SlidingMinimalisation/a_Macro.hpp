// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SlidingMinimalisation/a_Macro.hpp

#pragma once

#define DECLARATION_OF_SLIDING_MINIMALISATION( MIN )                    \
  template <typename FUNC0 , typename FUNC1 , typename T> void Sliding ## MIN ## imalisation( FUNC0 f , FUNC1 g , vector<T>& answer , const int& interval_size ) \

#define DEFINITION_OF_SLIDING_MINIMALISATION( MIN , OPR )               \
  template <typename FUNC0 , typename FUNC1 , typename T>               \
  void Sliding ## MIN ## imalisation( FUNC0 f , FUNC1 g , vector<T>& answer , const int& interval_size ){ SlidingMinimalisationBody( move( f ) , move( g ) , answer , interval_size , [&]( const T& t0 , const T& t1 ){ return t0 OPR t1; } ); } \


