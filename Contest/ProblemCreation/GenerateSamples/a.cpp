// c:/Users/user/Documents/Programming/Contest/ProblemCreation/GenerateSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../WriteInSamples/a_Body.hpp"
#include "../../../Utility/Random/a_Body.hpp"

void GenerateSamples( const string& directory_name )
{

  ofstream ofs_input_list;
  const string input_file_list_name = "/" + directory_name + "/�T���v������/�ꗗ.txt";
  cout << "LL_TYPE��" << WhatIsLL_TYPE << "�Ƃ��Ē�`����Ă��܂��B" << endl;
  cout << "�W�F�l���[�^�R�[�h�ŃT���v���𐶐����܂��B"  << endl;
  SEARCH_SAMPLE_LIST_DIRECTORY( ofs , ios::app , cout << "�W�F�l���[�^�R�[�h�ŃT���v���𐶐�����񐔂���͂��Ă��������B" << endl );
  CEXPR( int , bound_T , 100 );
  CIN_ASSERT( T , 1 , bound_T );
  GetRand( 0 , 1 );
  
  REPEAT( T ){

    GenerateSamples_Body( ofs_input_list );

  }
  
  return;
  
}
