// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void Solve();

void SampleCheck( const string& sample_path , const string& input_path , const string& output_path , const string& problem_order , const int& test_case_num_bound , ifstream& ifs , ofstream& ofs )
{

  ifstream sample_count{ sample_path + problem_order + "/count.txt" };
  int sample_repetition_num; sample_count >> sample_repetition_num;

  for( int sample_num = 1 ; sample_num <= sample_repetition_num ; sample_num++ ){

    string sample_num_str; sample_count >> sample_num_str;
    assert( sample_num == stoi( sample_num_str ) );
    CERRNS( "�T���v��" , sample_num , "�����s���܂��B\n" );
    CERR( "" );
    ifs = ifstream{ input_path + sample_num_str + ".txt" };
    ofs = ofstream{ output_path + sample_num_str + ".txt" , ios::trunc };
    int test_case_num = 1;

    if( test_case_num_bound > 1 ){

      ifs >> test_case_num;
      assert( 1 <= test_case_num && test_case_num <= test_case_num_bound );
        
    }

    for( int t = 0 ; t < test_case_num ; t++ ){

      Solve();

    }

    CompareAnswer( sample_path , problem_order , sample_num_str );
    CERRNS( "�T���v��" , sample_num , "�̎��s���I�����܂����B\n" );
    CERR( "" );
    
  }

}

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
      CERR( "�T���v��" , formatted_sample_num , "�ɑ΂���o�͂�" , count , "�s�ڂ�" );
      CERR( line0 );

      if( line1 == "" ){

        CERR( "�ƂȂ�z��ł����A�����o�͂���܂���ł����B" );

      } else {
        
        CERR( "�ƂȂ�z��ł����A" );
        CERR( line1 );
        CERR( "�ƂȂ�܂����B" );

      }

      CERR( "" );

    }

  }

  if( !prepared_answer.eof() ){

    CERR( "�T���v��" , formatted_sample_num , "�ɑ΂���o�͂�" , count - 1 , "�s��葽���z��ŁA�s�����Ă��܂��B" );

  } else if( !submitted_answer.eof() ){

    CERR( "�T���v��" , formatted_sample_num , "�ɑ΂���o�͂�" , count - 1 , "�s�̑z��ŁA�]�v�ȏo�͂����Ă��܂��B" );

  } else if( correct ){

    CERR( "�T���v��" , formatted_sample_num , "�͐����ł��B" );

  }

  CERR( "" );
  return;

}
