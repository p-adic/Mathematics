// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void CompareAnswer( const string& sample_path , const string& problem_order , const string& sample_num )
{

  ifstream prepared_answer{ sample_path + problem_order + "/output/sample" + sample_num + ".txt" };
  ifstream submitted_answer{ sample_path + problem_order + "/output/exec" + sample_num + ".txt" };
  int count = 0;
  const string formatted_sample_num = to_string( stoi( sample_num ) );
  bool correct = true;
  
  while( !prepared_answer.eof() && !submitted_answer.eof() ){

    count++;
    string line0 , line1;
    getline( prepared_answer , line0 );
    getline( submitted_answer , line1 );

    if( line0 != line1 ){

      correct = false;
      CERR( "�T���v��" + formatted_sample_num + "�ɑ΂���o�͂�" + to_string( count ) + "�s�ڂ�" );
      CERR( line0 );
      CERR( "�ƂȂ�z��ł����A" );
      CERR( line1 );
      CERR( "�ƂȂ�܂����B" );
      CERR( "" );

    }

  }

  if( !prepared_answer.eof() ){

    CERR( "�T���v��" + formatted_sample_num + "�ɑ΂���o�͂�" + to_string( count - 1 ) + "�s��葽���z��ŁA�s�����Ă��܂��B" );

  } else if( !submitted_answer.eof() ){

    CERR( "�T���v��" + formatted_sample_num + "�ɑ΂���o�͂�" + to_string( count - 1 ) + "�s�̑z��ŁA�]�v�ȏo�͂����Ă��܂��B" );

  } else if( correct ){

    CERR( "�T���v��" + formatted_sample_num + "�͐����ł��B" );

  }

  CERR( "" );
  return;

}
