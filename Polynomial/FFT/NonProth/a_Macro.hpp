// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/NonProth/a_Macro.hpp

#pragma once
#include "../../a_Macro.hpp"

// 関数テンプレートの明示的特殊化にinlineをつけないと複数の翻訳単位でincludeできないことに注意。
#define DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( TYPE , MINT , REPRE ) \
  template <> inline Polynomial<TYPE>& Polynomial<TYPE>::operator*=( Polynomial<TYPE> f ) { return *this = NonProthFFTConvolution<TYPE,MINT>( *this , f , REPRE ); } \
  template <> inline FormalPowerSeries<TYPE>& FormalPowerSeries<TYPE>::operator*=( Polynomial<TYPE> f ) { return *this = FormalPowerSeries<TYPE>( m_N , NonProthFFTConvolution<TYPE,MINT>( *this , f , REPRE ) ); } \

#ifdef DEBUG
  #define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MOD , MINT ) \
    DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MINT<MOD> , MINT , []( const MINT<MOD>& n ) { return n.Represent(); } ); \

#else
  #define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MOD , MINT ) \
    DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MINT<MOD> , MINT , []( const MINT<MOD>& n ) -> const INT_TYPE_FOR_MOD& { return n.Represent(); } ); \

#endif

#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( INT ) \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( INT , Mod , []( const INT& n ) -> const INT& { return n; } ); \

