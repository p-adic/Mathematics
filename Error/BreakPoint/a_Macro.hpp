// c:/Users/user/Documents/Programming/Error/BreakPoint/a_Macro.hpp

#pragma once
#include "../Position/a_Macro.hpp"

#ifdef DEBUG

  #define COUNT_BODY( ... ) CountCall( __VA_ARGS__ ) 
  #define FLAG_BODY( ... ) CallFlagContainer( false , __VA_ARGS__  ) 
  #define BREAK( ... ) BreakPoint( POSITION , __VA_ARGS__ ) 
  #define BREAK_IF( CONDITION , ... ) if( CONDITION ){ BREAK( __VA_ARGS__ ); } 
 
#endif

#define COUNT( index , i0 , i1 ) CONNECT( COUNT , index )( i0 , i1 ) 
#define COUNT0( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 ) 
#define COUNT1( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 ) 
#define COUNT2( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 ) 
#define COUNT3( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT4( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT5( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define COUNT6( i0 , i1 ) COUNT_BODY( POSITION , i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 

#define FLAG( index , i0 , i1 ) CONNECT( FLAG , index )( i0 , i1 ) 
#define FLAG0( i0 , i1 ) FLAG_BODY( i0 , i1 ) 
#define FLAG1( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 ) 
#define FLAG2( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 ) 
#define FLAG3( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define FLAG4( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 
#define FLAG5( i0 , i1 ) FLAG_BODY( i0 , i1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) 

// 1�d�̃u���[�N�|�C���g�������g����������BREAK�܂���COUNT(0,-,-)��p����B
// index+1�d�̃u���[�N�|�C���g�������g����������FLAG(0,-,-),�c,FLAG(index,-,-)��COUNT(index+1,-,-)��p����B

// FLAG(0,-,-)��ʂ邽�тɑ�0�J�E���g��1��s���B
// FLAG(index+1,-,-)��ʂ邽�сAFLAG(index,-,-)�̃t���O��true�ł���Α�index+1�J�E���g��1��s���B
// FLAG(index,i0,i1)��i0��ڂ̑�index�J�E���g����i1��̑�index�J�E���g���ƂɃt���O��true�ƂȂ�A����ȊO�̎��̓t���O��false�ƂȂ�B
// COUNT(0,-,-)��ʂ邽�тɑ�0�J�E���g���s���B
// COUNT(index+1,-,-)��ʂ邽�сAFLAG(index,-,-)�̃t���O��true�ł���Α�index+1�J�E���g���s���B
// COUNT(index,i0,i1)��i0��ڂ̑�index�J�E���g����i1��̑�index�J�E���g���Ƃ�BreakPoint()���Ăяo���B
