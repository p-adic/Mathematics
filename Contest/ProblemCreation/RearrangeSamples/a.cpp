// c:/Users/user/Documents/Programming/Contest/ProblemCreation/RearrangeSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../WriteInSamples/a_Body.hpp"

void RearrangeSamples( const string& directory_name )
{

  ifstream ifs_input_list;
  const string input_file_list_name = "/" + directory_name + "/�T���v������/�ꗗ.txt";
  cout << "�T���v���ύX�R�[�h�ŃT���v���̌`����ύX���܂��B" << endl;
  SEARCH_SAMPLE_LIST_DIRECTORY( ifs , ios::app , cout << "a.txt�ɏ㏑���������݂����܂��B" << endl );
  ofstream ofs_input_list( "a.txt" , ios::trunc );
  RearrangeSamples_Body( ifs_input_list , ofs_input_list );
  return;

}
