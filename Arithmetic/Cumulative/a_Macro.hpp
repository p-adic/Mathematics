// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/a_Macro.hpp

#pragma once

#define DEFIINTION_OF_PROD( RECURSION , UNIT , APPLY )	\
							\
  if( f.empty() ){					\
							\
    f.push_back( UNIT );				\
							\
  }							\
							\
  if( f.size() == 1 ){					\
							\
    return f.front();					\
							\
  }							\
							\
  auto itr = f.begin() , end = f.end();			\
							\
  while( itr != end ){					\
							\
    auto& t = *itr;					\
    itr++;						\
							\
    if( itr != end ){					\
							\
      APPLY;						\
      itr = f.erase( itr );				\
							\
    }							\
							\
  }							\
							\
  return RECURSION;					\
							\


