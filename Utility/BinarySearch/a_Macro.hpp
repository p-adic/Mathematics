// c:/Users/user/Documents/Programming/Utility/BinarySearch/a_Macro.hpp

#pragma once
#include "../Stdstream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef BS
/* �񕪒T���p */
/* EXPRESSION��ANSWER�̍L�`�P���֐��̎��AEXPRESSION >= CONST_TARGET�̐��������i�[�B*/
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CONST_TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<decldecay_t( CONST_TARGET ),uint>::value && ! is_same<decldecay_t( CONST_TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  {									\
    ll ANSWER ## _L = MINIMUM;                                          \
    ll ANSWER ## _R = MAXIMUM;                                          \
    ANSWER = UPDATE_ANSWER;						\
    ll EXPRESSION_BS;							\
    const ll CONST_TARGET_BS = ( CONST_TARGET );			\
    ll DIFFERENCE_BS;							\
    while( ANSWER ## _L < ANSWER ## _R ){                               \
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
	ANSWER ## _R = UPDATE_U;                                        \
      } else {								\
	ANSWER ## _L = UPDATE_L;                                        \
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( ANSWER ## _L > ANSWER ## _R || !( ( EXPRESSION ) DESIRED_INEQUALITY CONST_TARGET_BS ) ){ \
      ANSWER = MAXIMUM + 1;						\
    }									\
  }									\

/* �P�������̎���EXPRESSION >= CONST_TARGET�̍ŏ������i�[�B*/
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , >= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )
/* �P�������̎���EXPRESSION <= CONST_TARGET�̍ő�����i�[�B*/
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* �P�������̎���EXPRESSION >= CONST_TARGET�̍ő�����i�[�B*/
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , ANSWER - 1 , ANSWER , ( ANSWER ## _L + 1 + ANSWER ## _R ) / 2 )
/* �P�������̎���EXPRESSION <= CONST_TARGET�̍ŏ������i�[�B*/
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , <= , ANSWER , ANSWER + 1 , ( ANSWER ## _L + ANSWER ## _R ) / 2 )
#endif

