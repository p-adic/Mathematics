// c:/Users/user/Documents/Programming/Contest/ProblemCreation/ExecuteSolution/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void ExecuteSolution( const string& directory_name )
{
  cout << directory_name << "�̑z�����������s���܂����H" << endl;
  CIN_ASSERT( how_many_times , 1 , 100 );
  cout << how_many_times << "����s���܂��B" << endl;

  if( how_many_times > 1 ){

    cout << "�O���t�Ȃǂ��g���ۂ�main�֐��̊O�ŏ���������ϐ�������ꍇ�A" << endl;
    cout << "���̎��s�@�\�ł͕ϐ��̒l���c�����܂܎��s���J��Ԃ���邱�Ƃ�" << endl;
    cout << "���ӂ��Ă��������B" << endl;

  }

  REPEAT( how_many_times ){

    ExecuteSolution_Body();

  }

  return;

}

