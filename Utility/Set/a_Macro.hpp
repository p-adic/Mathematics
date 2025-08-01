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
  template <typename T> inline T pop_max( SET& S );                     \
  template <typename T> inline T pop_min( SET& S );                     \
  template <typename T> inline SET& operator<<=( SET& S , T t ); \
  template <typename T , typename U> inline SET& operator<<=( SET& S , U&& u ); \
  template <typename T> inline SET& operator>>=( SET& S , const T& t ); \
  template <typename T , typename U> inline SET& operator>>=( SET& S , const U& u ); \
  template <typename T> inline const T& Get( const SET& S , int i ) \

#define DEFINITION_OF_POP_FOR_SET( SET )                                \
  template <typename T> inline T pop_max( SET& S ) { assert( !S.empty() ); auto itr = --S.end(); T answer = *itr; S.erase( itr ); return answer; } \
  template <typename T> inline T pop_min( SET& S ) { assert( !S.empty() ); auto itr = S.begin(); T answer = *itr; S.erase( itr ); return answer; } \
  template <typename T> inline SET& operator<<=( SET& S , T t ) { S.insert( move( t ) ); return S; } \
  template <typename T , typename U> inline SET& operator<<=( SET& S , U&& u ) { S.insert( T{ forward<U>( u ) } ); return S; } \
  template <typename T> inline SET& operator>>=( SET& S , const T& t ) { S.erase( t ); return S; } \
  template <typename T , typename U> inline SET& operator>>=( SET& S , const U& u ) { return S >>= T{ u }; } \
  template <typename T> inline const T& Get( const SET& S , int i ) { auto begin = S.begin() , end = S.end(); auto& itr = i < 0 ? ( ++i , --end ) : begin; while( i > 0 && itr != end ){ --i; ++itr; } while( i < 0 && itr != begin ){ ++i; --itr; } assert( i == 0 ); return *itr; } \

#define DECLARATION_OF_UNION_FOR_SET( SET )                             \
  template <typename T> inline SET& operator|=( SET& S0 , SET S1 ); \
  template <typename T> inline SET operator|( SET S0 , SET S1 ); \

#define DEFINITION_OF_UNION_FOR_SET( SET )                              \
  template <typename T> inline SET& operator|=( SET& S0 , SET S1 ) { S0.merge( move( S1 ) ); return S0; } \
  template <typename T> inline SET operator|( SET S0 , SET S1 ) { return move( S0.size() < S1.size() ? S1 |= move( S0 ) : S0 |= move( S1 ) ); } \


