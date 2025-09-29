// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a_Macro.hpp

#pragma once
// static_assertだとTruncatedPolynomial<DMod>へのスカラー倍などで
// 余計なオーバーロード候補が生じてしまい不適。
#define SFINAE_FOR_DMOD enable_if_t<is_constructible_v<uint,decay_t<T>>>*

#define DECLARATION_OF_COMPARISON_FOR_DMOD( OPR )		\
  inline bool operator OPR( const DMods<NUM>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_DMOD( OPR , EX )		\
  inline DMods<NUM> operator OPR( DMods<NUM> n ) const EX;	\

#define DEFINITION_OF_COMPARISON_FOR_DMOD( OPR )			\
  template <int NUM> inline bool DMods<NUM>::operator OPR( const DMods<NUM>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_DMOD( OPR , EX , LEFT , OPR2 ) \
  template <int NUM> inline DMods<NUM> DMods<NUM>::operator OPR( DMods<NUM> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <int NUM , typename T , SFINAE_FOR_DMOD = nullptr> inline DMods<NUM> operator OPR( T n0 , const DMods<NUM>& n1 ) EX { return move( DMods<NUM>( move( n0 ) ) OPR ## = n1 ); } \


