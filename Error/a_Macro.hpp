// c:/Users/user/Documents/Programming/Error/a_Macro.hpp

#pragma once
#include "Position/a_Macro.hpp"
#include "../Utility/GlobalVariable/a_Macro.hpp"

#define g_OCCURRENCE_OF_ERR ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_ERR , false ) ) 
#define g_ALLIANCE_OF_OVERLAPPING ( *GLOBAL_VARIABLE( bool , ALLIANCE_OF_OVERLAPPING , false ) ) 
#define g_CHECK_OVERLAPPING ( *GLOBAL_VARIABLE( bool , CHECK_OVERLAPPING , false ) ) 
#define g_MEMORISE_FILE ( *GLOBAL_VARIABLE( string , MEMORISE_FILE , "NaN" ) ) 
#define g_MEMORISE_LINE ( *GLOBAL_VARIABLE( int , MEMORISE_LINE , 0 ) ) 
#define g_MEMORISE_FUNC ( *GLOBAL_VARIABLE( string , MEMORISE_FUNC , "NaN" ) ) 

#define CHECK_ERR CheckError( FILE , LINE , FUNC )

// �����[�X���Ƀu���b�N�����������̂ŁA��O�r�o���̂��̂��R�[�h�̃o�O�ł���ӏ��ɂ̂ݗp����B
// �R���}�̉e���Ń}�N�����W�J�ł��Ȃ��u���b�N�͔g����{ }�ň͂ށB
#ifdef DEBUG

  #define TRY_CATCH( TRY_BLOCK , ERROR_TYPE , CATCH_BLOCK )	\
								\
    try{							\
								\
      TRY_BLOCK	;						\
								\
    }								\
    catch( ERROR_TYPE ){					\
								\
      CATCH_BLOCK ;						\
								\
    }								\
  
#else

  #define TRY_CATCH( TRY_BLOCK , ERROR_TYPE , CATCH_BLOCK ) TRY_BLOCK ; 

#endif


#include "Warning/a_Macro.hpp"
