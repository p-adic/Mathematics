// c:/Users/user/Documents/Programming/Contest/ProblemCreation/WriteInSamples/a_Macro.hpp

#pragma once

#define SEARCH_SAMPLE_LIST_DIRECTORY( IFS , OPEN_MODE , MESSAGE )	\
  constexpr const uint star_num = 10;					\
  string star_list[star_num] = { "��" , "����" , "����" , "������" , "������" , "��������" , "��������" , "����������" , "����������" , "������������" }; \
  string star = "�H�H�H/";						\
  bool searching = true;						\
									\
  for( uint i = 0 ; i < star_num ; i++ ){				\
									\
    const string& star_i = star_list[i];				\
    IFS ## _input_list = IFS ## tream( star_i + input_file_list_name , OPEN_MODE ); \
									\
    if ( IFS ## _input_list ) {						\
									\
      star = star_i + "/";						\
      cout << "�T���v�����͈ꗗ�t�@�C���f�B���N�g��: " << star + directory_name + "/�T���v������/" << endl; \
      cout << "������Ő������ł����H[y/n]" << endl;			\
									\
      string reply;							\
									\
      while( searching ){						\
									\
	cin >> reply;							\
									\
	if( reply == "y" ){						\
									\
	  searching = false;						\
	  MESSAGE;							\
									\
	} else if( reply == "n" ){					\
									\
	  cout << "���f���܂��B" << endl;				\
	  return;							\
									\
	} else {							\
									\
	  cout << "[y/n]�œ����Ă��������B" << endl;			\
									\
	}								\
									\
      }									\
									\
      break;								\
									\
    }									\
									\
  }									\
									\
  if( searching ){							\
    cout << "�T���v�����͈ꗗ�t�@�C���f�B���N�g����������܂���ł����B"; \
    cout << "���f���܂��B";						\
    return;								\
  }									\
									\

#define WRITE_IN_MESSAGE_FOR_SEARCH_SAMPLE_LIST_DIRECTORY cout << "���s���܂��B" << endl; ifs_output_list = ifstream( star_i + output_file_list_name , ios::in ); ifs_output_list_copy = ifstream( star_i + output_file_list_name , ios::in ) 

