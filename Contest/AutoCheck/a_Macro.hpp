// c:/Users/user/Documents/Programming/Contest/AutoCheck/a_Macro.hpp

#pragma once

#define ASK_NUMBER( ... )						\
  while( true ){                                                        \
    CERR( "" );								\
    CERR( "���Ԃ�I�����܂����H" );					\
    problems = { __VA_ARGS__ };						\
    problems_size = problems.size();					\
    for( int i = 0 ; i < problems_size ; i++ ){				\
      CERR( i , ": " , problems[i] );					\
    }									\
    if( use_getline ){							\
      getline( cin , reply );						\
      num = stoi( reply );						\
    } else {								\
      cin >> num;                                                       \
    }									\
    CERR( "" );								\
    if( num < 0 || num >= problems_size ){				\
      CERR( "�ԓ���" , problems_size - 1 , "�ȉ��̔񕉐����ɂ��Ă��������B" ); \
    } else {                                                            \
      break;                                                            \
    }                                                                   \
  }                                                                     \
  num_temp = 0;                                                         \
  
#define ASK_YES_NO( QUESTION )                          \
  while( true ){                                        \
    CERR( "" );                                         \
    CERR( QUESTION , "[y/n]" );                         \
    if( use_getline ){                                  \
      getline( cin , reply );                           \
    } else {                                            \
      cin >> reply;                                     \
    }                                                   \
    CERR( "" );                                         \
    if( reply != "y" && reply != "n" ){                 \
      CERR( "y/n�̂����ꂩ�œ����Ă��������B" );	\
    } else {                                            \
      break;                                            \
    }                                                   \
  }                                                     \

#define AC( BRANCH ) void BRANCH ## AutoCheck( int& num , int& num_temp , string& reply , vector<string>& problems , int& problems_size , const bool& use_getline )
#define CALL_AC( BRANCH ) BRANCH ## AutoCheck( num , num_temp , reply , problems , problems_size , use_getline )

