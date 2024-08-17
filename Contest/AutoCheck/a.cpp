// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "LibrarySearch/a_Body.hpp"
#include "SampleAnalyser/a_Body.hpp"

#include "../../Utility/StdStream/a_Body.hpp"

void AutoCheck( int& exec_mode , const bool& use_getline )
{
  int num = 0;
  int num_temp = 0;
  string reply{};
  vector<string> problems{};
  int problems_size = 0;
  ASK_NUMBER(
	     "��o�p�t�@�C�������s����B" ,
	     "�T���v���̍���Ȃ��t�@�C�����f�o�b�O����B" ,
	     "��o�ς݃t�@�C�����f�o�b�O����B" ,
	     "���C�u�����[��T������B" ,
	     "�T���v������͂���B" ,
	     "�𒼉��Ŏ�������B" ,
	     "�𒼉��ƒ�o�p�t�@�C������͂̏������e�X�g�P�[�X�Ŕ�r����B" ,
	     "�𒼉��ƒ�o�p�t�@�C���������_���e�X�g�Ŕ�r����B" ,
	     "�I������B"
	     );
  exec_mode = num;
  if( num == num_temp++ ){
    CERR( "��o�p�t�@�C�������s���܂��B" );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHintWA );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHint );
  } else if( num == num_temp++ ){
    CALL_AC( LibrarySearch );
  } else if( num == num_temp++ ){
    CALL_AC( SampleAnalyser );
  } else if( num == num_temp++ ){
    CERR( "�𒼉��Ŏ������܂��B" );
  } else if( num == num_temp++ ){
    CERR( "�𒼉��ƒ�o�p�t�@�C������͂̏������e�X�g�P�[�X�Ŕ�r���܂��B" );
  } else if( num == num_temp++ ){
    CERR( "�𒼉��ƒ�o�p�t�@�C���������_���e�X�g�Ŕ�r���܂��B" );
  } else if( num == num_temp++ ){
    CERR( "�I�����܂��B" );
  }
  CERR( "" );
}

AC( DebugHint )
{
  ASK_NUMBER(
	     "WA�̃f�o�b�O" ,
	     "RE�̃f�o�b�O" ,
	     "TLE�̃f�o�b�O" ,
	     "MLE�̃f�o�b�O" ,
	     "CE�̃f�o�b�O"
	     );
  if( num == num_temp++ ){
    CALL_AC( DebugHintWA );
  } else if( num == num_temp++ ){
    CERR( "abort�n:" );
    CERR( "- ������ԈႦ��assert���Ă��܂��񂩁H" );
    CERR( "" );
    CERR( "���[�J���ł�abort�n�i��o����WA�Ȃǁj:" );
    CERR( "- �z��O�Q�Ƃ��Ă��܂��񂩁H" );
    CERR( "  - ���W���k�^�Ɉ��k�O�̓Y������ƈ��k��̓Y��������������Ă��܂��񂩁H" );
    CERR( "  - �O���t����W���k�̑���ő��݂��Ȃ����W-1�̏ꍇ������Y��Ă��܂��񂩁H" );
    CERR( "- �I�[�o�[�t���[���Ă��܂��񂩁H" );
    CERR( "" );
    CERR( "Segmentation Fault�n:" );
    CERR( "- �茳�̊��ł�DEXPR�Őݒ肵���l���������Ȃ邱�Ƃ�Y��Ă��܂��񂩁H" );
    CERR( "- �񕪒T���}�N���ŒT���l�����݂��Ȃ��ꍇ��MAXIMUM+1���Ԃ邱�Ƃ�Y��Ă��܂��񂩁H" );
    CERR( "- �C�e���[�^��͈͊O�܂�--/++���Ă��܂��񂩁H" );
    CERR( "- ���z�p�������֐����R���X�g���N�^���ŌĂяo���Ă��܂��񂩁H" );
    CERR( "- �����|��P�ʂŃf�o�b�O�p�ƒ�o�p��2��ނ̃N���X��`���s����" );
    CERR( "  �������T�C�Y���ς�胁���������Ă��܂��񂩁H" );
    CERR( "" );
    CERR( "arithmetic exception�n:" );
    CERR( "- 0�Ŋ����Ă��܂��񂩁H" );
    CERR( "" );
    CERR( "Heap block/signal SIGTRAP�n:" );
    CERR( "- ���I�z��Ŕz��O�ɑ�����Ă��܂��񂩁H" );
  } else if( num == num_temp++ ){
    CERR( "- �}���`�e�X�g�P�[�X�Ńf�[�^�\���̏���������������Ă��܂��񂩁H" );
    CERR( "  - ���I�z��ւ̒u������" );
    CERR( "  - ���W���k" );
    CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "  ���������܂��傤�B" );
    CERR( "- while���[�v�Ŗ������[�v�͂���܂��񂩁H" );
    CERR( "  - �Y�����̍X�V�Y��͂���܂��񂩁H" );
    CERR( "  - ����������Ă��Ȃ��ϐ��͂���܂��񂩁H�i�茳�ł̂ݒʂ�ꍇ�j" );
    CERR( "- DEXPR�g�p���Ɏ茳�ƃI�����C�����Ŏ��s���Ԃ��ς�邱�Ƃ����O���Ă��܂��񂩁H" );
    CERR( "- �f�o�b�O�p�̏����̏����Y��͂���܂��񂩁H" );
    CERR( "  - cerr���c���Ă��܂��񂩁H" );
    CERR( "  - ��������̃f�o�b�O�p�֐��̌Ăяo���R�X�g�𖳎����Ă��܂��񂩁H" );
    CERR( "- �d�߂���萔�{���l�����Y��Ă܂��񂩁H" );
    CERR( "  - bool�l�̏�����bit���Z�ɂ�����" );
    CERR( "  - �ϐ��̘a��ςɏ��������O���b�h���͓��I�z��" );
    CERR( "  ���������܂��傤�B" );
    CERR( "- �O�v�Z�ł��鏈�����J��Ԃ��Ă܂��񂩁H" );
    CERR( "  - �e(i,j)���Ƃ�S_ij���\�z�������Ɋei���Ƃ�S_i���\�z����S_i��S_j��" );
    CERR( "    S_ij��O(1)�ō\�z���邱�Ƃ��������܂��傤�B" );
    CERR( "- multiset��count���g���Ă��܂��񂩁H" );
    CERR( "- ���A�N�e�B�u����flush�Ɖ��s�����Y��Ă��܂��񂩁H" );
    CERR( "- gcc��variadic array�̃o�O�̉\��������܂��񂩁H" );
    CERR( "- ��ݍ��݂�gcc���g���Ă��܂��񂩁H" );
    CERR( "- �\�z�\���̔�����ł���΁A���Ԃ��v�����đł��؂�܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- �O���t�ŕӂ������߂��Ă��܂��񂩁H" );
    CERR( "- �i���d�j�z��ŃT�C�Y��10^6��啝�ɏ����Ă܂��񂩁H" );
    CERR( "  - �f�[�^�\���͍��W���k���������܂��傤�B" );
    CERR( "  - ���I�v��@�͏������Y��ɒ��ӂ��ēY����swap��mod���������܂��傤�B" );
    CERR( "- �ċA�^��ċA�̑I��������Ă��܂��񂩁H" );
    CERR( "  - �ċA��MLE���Ă��܂����H" );
    CERR( "    - �֐��̈�����Ǐ��ϐ����ċA�Ăяo���̌�ɗp����ꍇ���������������" );
    CERR( "      �ێ���������K�v������̂Ń������g�p�ʂ��c��オ��܂��B" );
    CERR( "    - ���ċA�[�x�ł̌Ăяo���񐔂��ő�ċA�[�x���傫���ꍇ��" );
    CERR( "      �y�������ł���ċA�ɂ��������������ߖ�ł��邩������܂���B" );
    CERR( "    - �Ⴆ�΃�������ɕϐ���ێ����Ȃ��ȒP�ȏ����͍ċA�[�x10^8�ł����v�ł��B" );
    CERR( "  - ��ċA��MLE���Ă��܂����H" );
    CERR( "    - �ϐ��𒀈�\�z����y�ߍċA�ł��ċA�[�x��10^6�ȉ��Ȃ���v�ł��B" );
    CERR( "    - �ő�ċA�[�x��蓯�ċA�[�x�ł̌Ăяo���񐔂��傫���ꍇ��" );
    CERR( "      �d�������ł��ċA���������������ߖ�ł��邩������܂���B" );
    CERR( "    - �Ⴆ�Ζ���10^5�I�[�_�[�̔z����\�z����ċA�ł��ő�ċA�[�x��10���x�Ȃ�" );
    CERR( "      �ċA����������������̕ϐ��̌���10^6�I�[�_�[�ŗ}�����܂��B" );
    CERR( "- ���^�[���D��T���̑I��������Ă��܂��񂩁H" );
    CERR( "  - �o�������傫���ꍇ�A���D��T���ł�MLE���邩������܂���B" );
    CERR( "  - �o������1�̒��_�������ꍇ�A�[���D��T���ł�MLE���邩������܂���B" );
    CERR( "- ���s���v�Z�̃V�t�g���Z�q��64�����ł��邱�Ƃ�Y��Ă��܂��񂩁H" );
    CERR( "  - �Ⴆ��1LL<<-1��-2^{63}�ɂȂ�܂��B" );
    CERR( "  - �Ⴆ��1024>>65��512�ɂȂ�܂��B" );
    CERR( "  - �R���p�C�����v�Z�͂����ł͂Ȃ��悤�ł��B" );
    CERR( "- Python�g�p�^�ɕϐ����̏d���ɂ��^�G���[���N���Ă܂��񂩁H" );
    CERR( "  - range��R��[L,R)��R�̏d���͌�҂�[l,r)��p���ĉ������܂��傤�B" );
    CERR( "  - �f����P�Ə����P�̏d���͌�҂�A��Q��p���ĉ������܂��傤�B" );
    CERR( "- Python�g�p�^�Ɍ������傫���Ȃ�߂��Ă��܂��񂩁H" );
  } else if( num == num_temp++ ){
    CERR( "- ���S�^���g���Ă�������invalid use of incomplete type���o�Ă��鎞��" );
    CERR( "  - �N���X�e���v���[�g�̃e���v���[�g�������ԈႦ�Ă��܂��񂩁H" );
    CERR( "  - �N���X�e���v���[�g�̃e���v���[�g�����𕔕����ꉻ���ă����o�֐���" );
    CERR( "    ��`���悤�Ƃ��Ă��܂��񂩁H" );
    CERR( "    - �������ꉻ�ɑ΂��N���X�����S�ɐ錾�������đ��̃����o����`���邩" );
    CERR( "      ���S���ꉻ��inline�t���Œ�`���܂��傤�B" );
    CERR( "- multiple definition���o�Ă��鎞��" );
    CERR( "  - pragma once�̕t���Y������Ă��܂��񂩁H" );
    CERR( "  - �֐�template�̊��S���ꉻ��inline�̕t���Y������Ă��܂��񂩁H" );
  }
  CERR( "" );
  CERR( "��o�ς݃t�@�C���̃f�o�b�O�͈ȏ�ł��B�I�����܂��B" );
}

AC( DebugHintWA )
{
  CERR( "- int�^���m�̏�@���I�[�o�[�t���[���Ă��܂��񂩁H" );
  CERR( "- operator<<()��int�^�ɓK�p���Ă��܂��񂩁H" );
  CERR( "- ���s���v�Z�̃V�t�g���Z�q��64�����ł��邱�Ƃ�Y��Ă��܂��񂩁H" );
  CERR( "  - �Ⴆ��1LL<<-1��-2^{63}�ɂȂ�܂��B" );
  CERR( "  - �Ⴆ��1024>>65��512�ɂȂ�܂��B" );
  CERR( "  - �R���p�C�����v�Z�͂����ł͂Ȃ��悤�ł��B" );
  CERR( "- �C�x���g�Ǘ���set���g���Ă��܂��񂩁H" );
  CERR( "  - key�ɋ��`�S������p����ꍇ�A" );
  CERR( "    - ����key�̏����𓯎��ɍs���Ȃ��map���������܂��傤�B" );
  CERR( "    - ����key�̏����𓯎��ɍs��Ȃ��Ȃ��multiset���������܂��傤�B" );
  CERR( "  - key�ɋ��`�S�����̐Ϗ�����p����ꍇ�Amap�̓���q���������܂��傤�B" );
  CERR( "- ���I�v��@�ɂ�����index��swap��mod��p���ă������팸���s���ꍇ�A" );
  CERR( "  �e���[�v�̍ŏ���dp�e�[�u���̏����������Y��Ă��܂��񂩁H" );
  CERR( "- �����グ�⑶�ݔ���ɂ����āA�T���ׂ��Ώۂɉۂ���Ă��������Y���" );
  CERR( "  ���܂��񂩁H" );
  CERR( "  - �O�p�`��T������ɐ��������R�𖞂����Ă��Ȃ��R�_��T����" );
  CERR( "    ���܂��񂩁H" );
  CERR( "  - �v�f��K�̕����W����T������ɕ����W���S�̂�T���Ă��܂��񂩁H" );
  CERR( "- �ϐ����̏Փ˂����Ǐ��ϐ��ɂ��铽�����󂯂Ă��܂��񂩁H" );
  CERR( "- l^1������l^���������ԈႦ�Ă��܂��񂩁H" );
  CERR( "- �덷�]�������Y��Ă��܂��񂩁H" );
  CERR( "  - �����^�ւ̃L���X�g���̐؂�̂Ă��K�؂����m�F���܂��傤�B" );
  CERR( "  - �񕪒T�����Ō����l���������͑㐔�������������Č덷�������܂��傤�B" );
  CERR( "- �ԕ��Ȃǂɂ���O�����̃~�X�����Ă��܂��񂩁H" );
  CERR( "  - �P�Ȃ�萔�{��������ړI�Ƃ����O�����͍폜���Ď����Ă݂܂��傤�B" );
  CERR( "  - �����̍�������ړI�Ƃ����O�����͍폜�����������̏ؖ����Ċm�F" );
  CERR( "    ���܂��傤�B" );
  CERR( "- �ʐόv�Z�Ŋi�q�_�̌��ƒ������������Ă��܂��񂩁H" );
  CERR( "  - �̈���Ǘ�����ۂ́u�E���̒P�ʋ�`���h���邩�v�̏����e�i�q�_��" );
  CERR( "    �悹�܂��傤�B" );
  CERR( "  - ���W���k����ۂ́u�h��̈�̒[�_�v���}1�����ɊǗ����܂��傤�B" );
  CERR( "- ���G�ȏ�����main�֐����ɏ����߂��Ă��܂��񂩁H" );
  CERR( "  - ������p����Ӗ��̂���expression�͕ϐ��Œu���܂��傤�B" );
  CERR( "  - �o�O�̌��؂̓�������͊֐������܂��傤�B" );
  CERR( "  - �֐������ꂽ�����́A�����������e�X�g���Ă݂܂��傤�B" );
  CERR( "- inplace�������s���Q�����Z�łQ�����������ꍇ���l�����Y��Ă��܂��񂩁H" );
  CERR( "- TruncatedPolynomial��Polynomial�ɃL���X�g����m_N���m_size���傫��" );
  CERR( "  �Ȃ��Ă��܂��񂩁H" );
  CERR( "- �}���`�e�X�g�P�[�X�Ŕz���static�����Ēl�������z����Ă��܂��񂩁H" );
  CERR( "- cLay�g�p�^��setmod�ȑO��10^9+7���傫���l�������Ă��܂��񂩁H" );
  CERR( "  #define MD 998244353 �Ȃǂ�p���܂��傤�B" );
  CERR( "" );
  CERR( "�����ɐS�����肪�Ȃ��ꍇ�̓����_���e�X�g���������܂��傤�B" );
  CERR( "�����_���e�X�g�ň����|��Ȃ��ꍇ��" );
  CERR( "- �傫�ȓ��͒l�ł̂݋N����o�O" );
  CERR( "  - �^�̎w��~�X" );
  CERR( "  - 64bit�^�̃I�[�o�[�t���[" );
  CERR( "- �������̔j��ɂ���ċN������ˑ��̃o�O" );
  CERR( "  - []��sort�͈͎̔w��~�X" );
  CERR( "  - ��d�z���[i][j]��[j][i]�̏����ԈႢ" );
  CERR( "���^���܂��傤�B" );
}

