// ���p
#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Random/a_Body.hpp"

int main()
{
  const string directory_name = "��薼�������ɓ����";
  COUT( "�ǂ��I�����܂����H" );
  COUT( "0:" , directory_name , "�̑z��������s����B" );
  COUT( "1:" , directory_name , "�̃T���v���𐶐�����B" );
  COUT( "2:" , directory_name , "�̃T���v�����i�[����t�@�C�����쐬����B" );
  COUT( "3:" , directory_name , "�̃T���v���̃t�H�[�}�b�g��ύX����B" );
  CIN_ASSERT( branch , 0 , 3 );
  int branch_temp = 0;
  if( branch == branch_temp++ ){
    ExecuteSolution( directory_name );
  } else if( branch == branch_temp++ ){
    GenerateSamples( directory_name );
  } else if( branch == branch_temp++ ){
    WriteInSamples( directory_name );
  } else if( branch == branch_temp++ ){
    RearrangeSamples( directory_name );
  }
  QUIT;
}

int MAIN()
{
  // �z����������ɓ����B
}

void GenerateSamples_Body( ofstream& ofs_input_list )
{
  // �W�F�l���[�^�R�[�h�������ɓ����B
}

void WriteInSamples_Body( VLArray<string>& file_prefix , VLArray<int>& file_num )
{
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" };
  VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" , "Tester_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" , "evil_" };
  // VLArray<string> prefix{ "Sampuru_" };
  VLArray<int> num{ 10 , 5 , 5 , 8 };
  file_prefix = prefix;
  file_num = num;
  return;
}

// �o�͈ꗗ�t�@�C��������ꍇ�A������폜���Ȃ��Ɛ������t�@�C���������݂��ł��Ȃ����Ƃɒ��ӁB
void RearrangeSamples_Body( ifstream& ifs_input_list , ofstream& ofs_input_list )
{
  REPEAT( 28 ){
    // �t�H�[�}�b�g�ύX�R�[�h�������ɓ����B
    OFS( "" );
  }
  IFS( string , check_redundant );
  assert( check_redundant == "" );
  assert( ! ifs_input_list );
  cout << "�������݂��������܂����B" << endl;
  return;
}
