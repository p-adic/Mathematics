// c:/Users/user/Documents/Programming/Utility/Set/a_Macro.hpp

#pragma once

#define DECLARATION_OF_HASH( ... )				\
  struct hash<__VA_ARGS__>					\
  {								\
								\
    inline size_t operator()( const __VA_ARGS__& n ) const;	\
								\
  };								\


#define DECRALATION_OF_POP_FOR_SET( SET )                               \
  template <typename T> inline T pop_max( SET& S );                    \
  template <typename T> inline T pop_min( SET& S );                   \
  template <typename T> inline SET& operator+=( SET& S , T t );         \
  template <typename T> inline SET& operator-=( SET& S , const T& t )   \

#define DEFINITION_OF_POP_FOR_SET( SET )                                \
  template <typename T> inline T pop_max( SET& S ) { assert( !S.empty() ); auto itr = --S.end(); const T answer = move( *itr ); S.erase( itr ); return answer; } \
  template <typename T> inline T pop_min( SET& S ) { assert( !S.empty() ); auto itr = S.begin(); const T answer = move( *itr ); S.erase( itr ); return answer; } \
  template <typename T> inline SET& operator+=( SET& S , T t ) { S.insert( move( t ) ); return S; } \
  template <typename T> inline SET& operator-=( SET& S , const T& t ) { S.erase( t ); return S; } \


