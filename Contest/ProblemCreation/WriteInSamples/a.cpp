// c:/Users/user/Documents/Programming/Contest/ProblemCreation/WriteInSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Utility/FileStream/a_Body.hpp"
#include "../../../Utility/Time/a_Body.hpp"

void WriteInSamples( const string& directory_name , VLArray<string>& file_names )
{

  ifstream ifs_output_list;
  ifstream ifs_output_list_copy;
  ifstream ifs_input_list;
  const string output_file_list_name = "/" + directory_name + "/�T���v���o��/�ꗗ.txt";
  const string input_file_list_name = "/" + directory_name + "/�T���v������/�ꗗ.txt";
  SEARCH_SAMPLE_LIST_DIRECTORY( ifs , ios::in , WRITE_IN_MESSAGE_FOR_SEARCH_SAMPLE_LIST_DIRECTORY );
  
  if ( ! ifs_output_list ) {

    cout << "�T���v���o�͈ꗗ�t�@�C���f�B���N�g��: " << star + directory_name + "/�T���v���o��/" << endl;
    cout << "�T���v���o�͈ꗗ�t�@�C�����J���܂���ł����B" << endl;
    return;

  }

  StartWatch( "�ꗗ�t�@�C���ǂݍ���" );
  VLArray<string> input_samples{};
  VLArray<string> output_samples{};
  string s_current;
  string s_sum = "";
  getline( ifs_output_list_copy , s_current );
  const bool with_output = ! ifs_output_list_copy.eof();

  if( with_output ){

    cout << "�o�̓t�@�C������łȂ��̂œ��̓t�@�C���Əo�̓t�@�C�������̏������݂����܂��B" << endl;
    bool searching_input = true;

    while( ! ifs_output_list.eof() ){
    
      if( searching_input ){

	getline( ifs_input_list , s_current );

	if( s_current == "" ){

	  if( s_sum != "" ){

	    PushBackSample( input_samples , s_sum );

	  }

	  searching_input = false;

	} else {

	  AddCurrentSample( s_sum , s_current );
	  getline( ifs_output_list , s_current );

	}

      } else {

	getline( ifs_output_list , s_current );

	if( s_current == "" ){

	  if( s_sum != "" ){

	    PushBackSample( output_samples , s_sum );
	    searching_input = true;

	  }

	} else {

	  AddCurrentSample( s_sum , s_current );

	}

      }

    }

    if( s_current != "" ){

      if( s_sum != "" ){

	PushBackSample( output_samples , s_sum );

      }

    }

  } else {

    cout << "�o�̓t�@�C������Ȃ̂œ��̓t�@�C���݂̂̏������݂����܂��B" << endl;

    while( ! ifs_input_list.eof() ){
    
      getline( ifs_input_list , s_current );

      if( s_current == "" ){

	if( s_sum != "" ){

	  PushBackSample( input_samples , s_sum );

	}

      } else {

	AddCurrentSample( s_sum , s_current );

      }

    }

    if( s_current != "" ){

      if( s_sum != "" ){

	PushBackSample( input_samples , s_sum );

      }

    }
    
  }

  StopWatch();
  cout << "�ǂݍ��݂��������܂����B" << endl;

  const uint& input_sample_size = input_samples.size();
  const uint& output_sample_size = output_samples.size();
  const uint& file_name_size = file_names.size();

  if( with_output ){

    if( input_sample_size < output_sample_size ){

      cout << "���̓T���v�������s�����Ă��܂��B�o�̓T���v���t�@�C���̖����ɗ]�v�ȋ�s���Ȃ����Ƃ�A�o�̓t�@�C���̍폜���Y�ꂪ�Ȃ������m�F���Ă��������B" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "output_sample_size: " << output_sample_size << endl;
      cout << "�ǂ̃t�@�C���������Ă��邩�̏��𓾂邽�߂ɂ��̃G���[�𖳎����đ��s���܂��B" << endl;

    } else if(  input_sample_size > output_sample_size ){

      cout << "�o�̓T���v�������s�����Ă��܂��B�o�̓T���v���t�@�C���̖����ɕK�v�ȋ�s������Ă��邱�Ƃ�A�o�̓t�@�C���̍폜���Y�ꂪ�Ȃ������m�F���Ă��������B" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "output_sample_size: " << output_sample_size << endl;
      cout << "�ǂ̃t�@�C���������Ă��邩�̏��𓾂邽�߂ɂ��̃G���[�𖳎����đ��s���܂��B" << endl;

    }

  }

  if( input_sample_size < file_name_size ){

    cout << "���̓T���v�������s�����Ă��܂��B�t�@�C�������ԈႦ�Ă��Ȃ����Ƃ�A�o�̓t�@�C���̍폜���Y�ꂪ�Ȃ������m�F���Ă��������B" << endl;
    cout << "input_sample_size: " << input_sample_size << endl;
    cout << "file_name_size: " << file_name_size << endl;
    cout << "�ǂ̃t�@�C���������Ă��邩�̏��𓾂邽�߂ɂ��̃G���[�𖳎����đ��s���܂��B" << endl;

  } else if(  input_sample_size > file_name_size ){

    cout << "�t�@�C�������s�����Ă��܂��B�t�@�C�������ԈႦ�Ă��Ȃ����Ƃ�A�o�̓t�@�C���̍폜���Y�ꂪ�Ȃ������m�F���Ă��������B" << endl;
    cout << "input_sample_size: " << input_sample_size << endl;
    cout << "file_name_size: " << file_name_size << endl;
    cout << "�ǂ̃t�@�C���������Ă��邩�̏��𓾂邽�߂ɂ��̃G���[�𖳎����đ��s���܂��B" << endl;

    for( uint i = file_name_size ; i < input_sample_size ; i++ ){

      file_names.push_back( "zzz_" + to_string( i + 100 ).substr( 1 ) );

    }

  }
  
  auto itr_file = file_names.begin();
  
  string input_file_name;
  string output_file_name;
  const string file_name_list_file_name = star + directory_name + "/�T���v���o��/�t�@�C����.txt";
  DeleteContents( file_name_list_file_name );
  
  auto itr_input_sample = input_samples.begin();
  auto itr_output_sample = output_samples.begin();

  StartWatch( "�ꗗ�t�@�C�������o��" );

  for( uint i = 0 ; i < input_sample_size ; i++ ){

    if( *itr_file == "" ){

      cout << "�󔒂̃t�@�C�����𖳎����܂����B�o�͈ꗗ�Ɏ��ۂ̃t�@�C������葽���̃T���v�����܂܂�Ă��Ȃ����Ƃ��m�F���Ă��������B" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "file_name_size: " << file_name_size << endl;
      return;

    }

    input_file_name = star + directory_name + "/�T���v������/" + *itr_file + ".txt";
    DeleteContents( input_file_name );
    WriteIn( input_file_name , *itr_input_sample );
    itr_input_sample++;

    if( with_output ){

      output_file_name = star + directory_name + "/�T���v���o��/" + *itr_file + ".txt";
      DeleteContents( output_file_name );
      WriteIn( output_file_name , *itr_output_sample );
      itr_output_sample++;

    }

    WriteIn( file_name_list_file_name , "\"" + *itr_file + "\" ," );
    itr_file++;

  }

  StopWatch();
  cout << "�������݂��������܂����B" << endl;
  return;

}

void WriteInSamples( const string& directory_name )
{

  cout << "�X�̃T���v�����i�[����t�@�C�����쐬���܂��B" << endl;
  VLArray<string> file_prefix;;
  VLArray<int> file_num;
  WriteInSamples_Body( file_prefix , file_num );
  const int prefix_size = file_prefix.size();
  const int num_size = file_num.size();
 
  if( prefix_size != num_size ){

    cout << "�t�@�C���ړ����̐��������Ă��܂���B" << endl;
    cout << "file_prefix.size(): " << prefix_size << endl;
    cout << "file_num.size(): " << num_size << endl;
    cout << "�t�@�C���ړ����̃R�����g�A�E�g���Ԉ���Ă���\�������邽�߁A�������݂��I�����܂��B" << endl;
    return;
    
  }
  
  VLArray<string> file_names{};

  for( int i = 0 ; i < prefix_size ; i++ ){

    const string& prefix = file_prefix[i];
    const int& num = file_num[i];

    for( int j = 0 ; j < num ; j++ ){

      file_names.push_back( prefix + to_string( j + 100 ).substr( 1 ) );

    }

    cout << prefix << "00 �` " << to_string( num - 1 + 100 ).substr( 1 ) << "\n";

  }

  string reply = "";

  while( reply != "y" && reply != "n" ){

    cout << "��L�̃t�@�C���\���Ő������ł����H[y/n]" << endl;

    cin >> reply;

    if( reply != "y" && reply != "n" ){

      cout << "�񓚂�[y/n]�̂����ꂩ�ł��肢���܂��B" << endl;

    }

  }

  if( reply == "y" ){

    WriteInSamples( directory_name , file_names );

  } else {

    cout << "���f���܂��B" << endl;

  }

  return;

}
