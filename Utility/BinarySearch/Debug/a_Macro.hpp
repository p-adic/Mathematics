// c:/Users/user/Documents/Programming/Mathematics/Utility/BinarySearch/Debug/a_Macro.hpp

#pragma once
#include "../../../../Utility/Stdstream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef BS
// 二分探索用
// EXPRESSIONがANSWERの広義単調関数の時、EXPRESSION >= CONST_TARGETの整数解を格納。
constexpr bool reactive =
#ifdef REACTIVE
  true;
#else
  false;
#endif
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , CONST_TARGET , MONOTONICITY , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER , EXTERNAL ) \
  static_assert( ! is_same<decldecay_t( CONST_TARGET ),uint>::value && ! is_same<decldecay_t( CONST_TARGET ),ull>::value ); \
  DERRNS( "エラー出力 " , __LINE__ , ": 二分探索開始\n" );              \
  ll ANSWER = MINIMUM;							\
  {									\
    ll ANSWER ## _L = MINIMUM , ANSWER ## _R = MAXIMUM , ANSWER_LAST;   \
    ANSWER = UPDATE_ANSWER;						\
    bool INIT_BS = true;                                                \
    ll EXPRESSION_BS_LAST , EXPRESSION_BS;                              \
    const ll CONST_TARGET_BS = ( CONST_TARGET );			\
    ll DIFFERENCE_BS;							\
    while( ANSWER ## _L < ANSWER ## _R ){                               \
      DIFFERENCE_BS = ( EXPRESSION_BS = ( EXPRESSION ) ) - CONST_TARGET_BS; \
      DERR( "二分探索中:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #EXPRESSION , "=" , EXPRESSION_BS , DIFFERENCE_BS > 0 ? ">" : DIFFERENCE_BS < 0 ? "<" : "=" , CONST_TARGET_BS , "=" , #CONST_TARGET ); \
      if( !( INIT_BS || ( ANSWER_LAST < ANSWER ) == ( EXPRESSION_BS_LAST MONOTONICITY EXPRESSION_BS ) ) ){ \
        DERR( "単調でないか、単調増加性と単調減少性を逆にしてしまっています。" ); \
        abort();                                                        \
      }                                                                 \
      if( DIFFERENCE_BS INEQUALITY_FOR_CHECK 0 ){			\
        ANSWER ## _R = UPDATE_U;                                        \
      } else {								\
        ANSWER ## _L = UPDATE_L;                                        \
      }									\
      INIT_BS = false;                                                  \
      ANSWER_LAST = ANSWER;                                             \
      EXPRESSION_BS_LAST = EXPRESSION_BS;                               \
      ANSWER = UPDATE_ANSWER;						\
    }									\
    if( ANSWER ## _L > ANSWER ## _R ){                                  \
      DERR( "二分探索失敗:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , ">" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" , ":" , #ANSWER , ":=" , #EXTERNAL , "=" , EXTERNAL ); \
      DERR( "初期区間が空です。" );                                     \
      ANSWER = EXTERNAL;						\
    } else {								\
      DERR( "二分探索終了:" , string{ #ANSWER } + "_L" , "=" , ANSWER ## _L , "<=" , #ANSWER , "=" , ANSWER , "<=" , ANSWER ## _R , "=" , string{ #ANSWER } + "_R" ); \
      if constexpr( reactive ){                                         \
          DERR( "リアクティブなので二分探索の成功判定を省略します。" ); \
        } else {                                                        \
        DERR( "二分探索が成功したかを確認するために" , #EXPRESSION , "を計算します。" ); \
        EXPRESSION_BS = ( EXPRESSION );                                 \
        DERR( "二分探索結果:" , #EXPRESSION , "=" , EXPRESSION_BS , ( EXPRESSION_BS > CONST_TARGET_BS ? ">" : EXPRESSION_BS < CONST_TARGET_BS ? "<" : "=" ) , CONST_TARGET_BS ); \
        if( EXPRESSION_BS DESIRED_INEQUALITY CONST_TARGET_BS ){         \
          DERR( "二分探索成功:" , #ANSWER , ":=" , ANSWER );		\
        } else {                                                        \
          DERR( "二分探索失敗:" , #ANSWER , ":=" , #EXTERNAL , "=" , EXTERNAL ); \
          DERR( "単調でないか、単調増加性と単調減少性を逆にしてしまったか、探索範囲内に解が存在しません。" ); \
          ANSWER = EXTERNAL;						\
        }                                                               \
      }                                                                 \
    }									\
  }									\

// 単調増加の時にEXPRESSION >= CONST_TARGETの最小解を格納。
#define MIN_GEQ( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , < , >= , ANSWER , ANSWER + 1 , Mid( ANSWER ## _L , ANSWER ## _R ) , ( MAXIMUM ) + 1 )
// 単調増加の時にEXPRESSION <= CONST_TARGETの最大解を格納。
#define MAX_LEQ( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , < , > , ANSWER - 1 , ANSWER , Mid( ANSWER ## _L + 1 , ANSWER ## _R ) , ( MINIMUM ) - 1 )
// 単調減少の時にEXPRESSION >= CONST_TARGETの最大解を格納。
#define MAX_GEQ( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , CONST_TARGET , > , < , ANSWER - 1 , ANSWER , Mid( ANSWER ## _L + 1 , ANSWER ## _R ) , ( MINIMUM ) - 1 )
// 単調減少の時にEXPRESSION <= CONST_TARGETの最小解を格納。
#define MIN_LEQ( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , CONST_TARGET ) BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , CONST_TARGET , > , <= , ANSWER , ANSWER + 1 , Mid( ANSWER ## _L , ANSWER ## _R ) , ( MAXIMUM ) + 1 )
#endif

