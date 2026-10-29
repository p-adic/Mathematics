// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/a_Macro.hpp

#pragma once

// 関数テンプレートの明示的特殊化にinlineをつけないと複数の翻訳単位でincludeできないことに注意。
#define PARTIAL_SPECIALISATION_FOR_FFT_BODY( MOD , LENGTH , PR , IPR , TYPE ) \
  static_assert( ( TYPE::Derepresent( PR ) *= TYPE::Derepresent( IPR ) ) == TYPE::Derepresent( 1 ) ); \
  template <> inline constexpr const uint LimitOfPowerForFFT<TYPE> = LENGTH - 1; \
  template <> inline const TYPE ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<TYPE>] { static constexpr Power3Power_constexpr<TYPE,LimitOfPowerForFFT<TYPE>> PRT{ PR }; static_assert( PRT.m_val[0] == TYPE::Derepresent( 1 ) ); return PRT.Get(); } \
  template <> inline const TYPE ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<TYPE>] { static constexpr Power3Power_constexpr<TYPE,LimitOfPowerForFFT<TYPE>> IPRT{ IPR }; static_assert( IPRT.m_val[0] == TYPE::Derepresent( 1 ) && ( TYPE::Derepresent( PR ) *= TYPE::Derepresent( IPR ) ) == TYPE::Derepresent( 1 ) ); return IPRT.Get(); } \
  template <> inline Polynomial<TYPE>& Polynomial<TYPE>::operator*=( Polynomial<TYPE> f ) { const int size = m_size + f.m_size - 1; return *this = FFTConvolution( move( *this ) , move( f ) , size ); } \
  template <> inline Polynomial<TYPE>& Polynomial<TYPE>::operator/=( Polynomial<TYPE> f ) { return *this = FFTQuotient( *this , move( f ) ); } \
  template <> inline Polynomial<TYPE>& Polynomial<TYPE>::operator%=( Polynomial<TYPE> f ) { return *this = FFTResidue( *this , move( f ) ); } \

#define PARTIAL_SPECIALISATION_FOR_FFT( MOD , LENGTH , PR , IPR , MINT ) \
  PARTIAL_SPECIALISATION_FOR_FFT_BODY( MOD , LENGTH , PR , IPR , MINT<MOD> ) \

