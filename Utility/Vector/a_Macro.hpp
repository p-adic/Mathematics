// c:/Users/user/Documents/Programming/Utility/Vector/a_Macro.hpp

#pragma once

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#define DECLARATION_OF_SCALAR_ACTION_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ); \

#define DEFINITION_OF_SCALAR_ACTION_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ) { for( auto& s : a ){ a OPR ## = t; } return a; } \

#define DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ); \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ); \

#define DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ) { assert( a0.size() <= a1.size() ); auto itr0 = a0.begin() , end0 = a0.end(); auto itr1 = a1.begin(); while( itr0 != end0 ){ *( itr0++ ) OPR ## = *( itr1++ ); } return a0; } \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ) { return move( a OPR ## = u ); } \

#define DECLARATION_OF_INCREMENT_FOR_VECTOR( V , INCR )		\
  template <typename T> inline V<T>& operator INCR( V<T>& a );	\

#define DEFINITION_OF_INCREMENT_FOR_VECTOR( V , INCR )			\
  template <typename T> inline V<T>& operator INCR( V<T>& a ) { for( auto& i : a ){ INCR i; } return a; } \

#define DECLARATION_OF_ARITHMETICS_FOR_VECTOR( V )			\
  template <typename T> inline V<T>& operator+=( V<T>& a , const T& t ); \
  DECLARATION_OF_SCALAR_ACTION_FOR_VECTOR( V , * );			\
  DECLARATION_OF_SCALAR_ACTION_FOR_VECTOR( V , / );			\
  DECLARATION_OF_SCALAR_ACTION_FOR_VECTOR( V , % );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , + );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , - );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , * );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , / );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , % );			\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , ++ );			\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , -- );			\
  template <typename T> inline V<T> operator*( const T& scalar , V<T> v ) \

#define DEFINITION_OF_ARITHMETICS_FOR_VECTOR( V )			\
  template <typename T> inline V<T>& operator+=( V<T>& a , const T& t ) { a.push_back( t ); return a; } \
  DEFINITION_OF_SCALAR_ACTION_FOR_VECTOR( V , * );                      \
  DEFINITION_OF_SCALAR_ACTION_FOR_VECTOR( V , / );                      \
  DEFINITION_OF_SCALAR_ACTION_FOR_VECTOR( V , % );                      \
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , + );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , - );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , * );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , / );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , % );				\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , ++ );				\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , -- );				\
  template <typename T> inline V<T> operator*( const T& scalar , V<T> v ) { for( auto& t : v ){ t *= scalar; } return move( v ); } \


