// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

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
	     "�𒼉��Ŏ�������B" ,
	     "�𒼉��ƒ�o�p�t�@�C������͂̏������e�X�g�P�[�X�Ŕ�r����B" ,
	     "�𒼉��ƒ�o�p�t�@�C���������_���e�X�g�Ŕ�r����B"
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
    CERR( "�𒼉��Ŏ������܂��B" );
  } else if( num == num_temp++ ){
    CERR( "�𒼉��ƒ�o�p�t�@�C������͂̏������e�X�g�P�[�X�Ŕ�r���܂��B" );
  } else if( num == num_temp++ ){
    CERR( "�𒼉��ƒ�o�p�t�@�C���������_���e�X�g�Ŕ�r���܂��B" );
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
    CERR( "- ������ԈႦ��assert���Ă��܂��񂩁H" );
    CERR( "- �茳�̊��ł�DEXPR�Őݒ肵���l���������Ȃ邱�Ƃ�Y��Ă��܂��񂩁H" );
    CERR( "- �z��O�Q�Ƃ��Ă��܂��񂩁H" );
    CERR( "  - ���W���k�^�Ɉ��k�O�̓Y������ƈ��k��̓Y��������������Ă��܂��񂩁H" );
    CERR( "  - �O���t����W���k�̑���ő��݂��Ȃ����W-1�̏ꍇ������Y��Ă��܂��񂩁H" );
    CERR( "- �񕪒T���}�N���ŒT���l�����݂��Ȃ��ꍇ��MAXIMUM+1���Ԃ邱�Ƃ�Y��Ă��܂��񂩁H" );
    CERR( "- �C�e���[�^��͈͊O�܂�--/++���Ă��܂��񂩁H" );
    CERR( "- multiset��count���g���Ă��܂��񂩁H" );
    CERR( "- 0�Ŋ����Ă��܂��񂩁H" );
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
    CERR( "      ���S�ȓ��ꉻ�����܂��傤�B" );
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

AC( LibrarySearch )
{
  ASK_NUMBER(
	     "�������̌v�Z���" ,
	     "�ő�^�ŏ������" ,
	     "�����グ���" ,
	     "������" ,
	     "�N�G���������" ,
	     "�^�U������" ,
	     "�\�z���" ,
	     "������"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( Maximisation );
  } else if( num == num_temp++ ){
    CALL_AC( Counting );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( Query );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  } else if( num == num_temp++ ){
    CALL_AC( Deduction );
  }
  ASK_YES_NO( "�}���`�e�X�g�P�[�X�ł����H" );
  if( reply == "y" ){
    CERR( "�e�X�g�P�[�X���ׂ��O�v�Z���\���ۂ���D��I�ɍl�@���܂��傤�B" );
    CERR( "" );
    CERR( "�e�X�g�P�[�X�S�̂ł�N�̑��a�ɒ��ڏ�����^�����Ă�����ł́A" );
    CERR( "���C�u�����[�̎g�p���͔z��̏��������e�e�X�g�P�[�X�ɕK�v�ƂȂ�ꍇ��" );
    CERR( "TLE�ƂȂ�\���������ł��B" );
    CERR( "- ���I�z��ւ̒u������" );
    CERR( "- ���W���k" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
  }
  CERR( "���C�u�����[�T���͈ȏ�ł��B�I�����܂��B" );
}

AC( ExplicitExpression )
{
  ASK_NUMBER(
	     "�P�ϐ��֐��^����̌v�Z���" ,
	     "�z���p�����֐��̑��a�̌v�Z���" ,
	     "�����̊֐��̌v�Z���" ,
	     "�؏�̊֐��̑��a�̌v�Z���" ,
	     "�؈ȊO�̃O���t��̊֐��̌v�Z���" ,
	     "�����̌v�Z���" ,
	     "�m���^���Ғl�̌v�Z���" ,
	     "����񐔂̌v�Z���" ,
	     "augmentation���ݍ��݂̌v�Z���" ,
	     "�ʐς̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnary );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnPermutation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnNonTreeGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOrder );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionConvolution );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArea );
  }
}

AC( ExplicitExpressionUnary )
{
  ASK_NUMBER(
	     "���`�Q�����̌v�Z���" ,
	     "�P�ϐ��֐��̔��������̌v�Z���" ,
	     "bit�֐��Ƒ��̊֐��̍����̌v�Z���" ,
	     "���̑��̂P�ϐ��֐��̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryIteration );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionBitwiseFunction );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryOther );
  }
}

AC( ExplicitExpressionUnaryLinearRecursion )
{
  CERR( "L���Ԑ��`�Q����" );
  CERR( "a_n = sum(i,0,L){c_i a_{n-L+i}} (n>=L)" );
  CERR( "��N��a_N��@B�ŋ��߂܂��B" );
  CERR( "" );
  CERR( "�K�XZ/B Z�̌^" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\ConstexprModulo" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\QuotientRing" );
  CERR( "��p����" );
  CERR( "- O(LN)���Ԃɍ��������Ȃ�Β���L+1�������������铮�I�v��@" );
  CERR( "- O(L^2 log N)���Ԃɍ��������Ȃ�΍s��ݏ�" );
  CERR( "  \\Mathematics\\LinearAlgebra" );
  CERR( "- B=998244353������L�����Q�����𖞂�������O(N log N)���Ԃɍ��������Ȃ��" );
  CERR( "  1/(1-sum(i,0,L){c_i x^i})��N���W���̍����t�[���G�ϊ��ɂ��v�Z" );
  CERR( "  \\Mathematics\\Polynomial\\Truncate" );
  CERR( "- �W����(c_i)_i������P������O(PN log N)���Ԃɍ��������Ȃ��P�̋�ԉ��ZBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalAddo" );
  CERR( "- �W����(c_i)_i���P����D�K�������萔���O((N+L)D)���Ԃɍ��������Ȃ��" );
  CERR( "  �u�W�����d�K��^d(c_i)_i������(a_i)_{i=n-L+d+1}^{n}�̓���dp[n][d]�v" );
  CERR( "  ���Ǘ����铮�I�v��@" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionUnaryIteration )
{
  CERR( "��`��̗v�f��N�A�e�X�g�P�[�X��T�A�����񐔂̏��K�Ƃ��܂��B" );
  CERR( "- O((N + T)log_2 K)���ʂ肻���Ȃ�΃_�u�����O" );
  CERR( "  \\Mathematics\\Function\\Iteration\\Doubling" );
  CERR( "- O(TN)���ʂ肻���Ȃ�΃��[�v���o" );
  CERR( "  \\Mathematics\\Function\\Iteration\\LoopDetection" );
  CERR( "- O(N)����ʂ�Ȃ������Ȃ�Ί֐��̋K���������t���邽�߂̎���" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionBitwiseFunction )
{
  CERR( "(M,*)�������m�C�h�Ƃ��܂��B�ʑ�f:N^n->(M,*)��bit�����^�Ƃ�" );
  CERR( "- (a&b)==0�𖞂����C�ӂ�a,b�ɑ΂�f(a|b)=f(a)*f(b)" );
  CERR( "�𖞂����Ƃ������ƂƂ��܂��B" );
  CERR( "" );
  CERR( "�Ⴆ��" );
  CERR( "- �P���ʑ�:N->(N,+)" );
  CERR( "- �P���ʑ�:N->(N,|)" );
  CERR( "- �P���ʑ�:N->(N,^)" );
  CERR( "- �Œ�̌��Ƃ�2��bit���Z:N->(N,+)" );
  CERR( "- ��i�@�\�L:N->(N^{oplus N},+)" );
  CERR( "- ��i�@�̌��a:N->(N,+)" );
  CERR( "- ��i�@�\�L�Ɖ��@�I�����^�̍���:N->(Z,+)" );
  CERR( "- ��i�@�\�L�Ə�@�I�����^�̍���:N->(Z,*)" );
  CERR( "- �Q��bit�֐�f,g:N->(M,*)�̊e�_��fg:N->(M,*)" );
  CERR( "- �Q��bit�֐�f,g:N->(M,*)�̒��ς̐�f*g:N^2->(M,*)" );
  CERR( "- (M,*)���Q�ł���ꍇ��bit�֐�f:N->(M,*)�Ƌt���̍���" );
  CERR( "�Ȃǂ�bit�����^�ł��B" );
  ASK_NUMBER(
	     "(Z,+)�ւ�bit�����^" ,
	     "(Z,*)�ւ�bit�����^�̐��`�a"
	     );
  if( num == num_temp++ ){
    CERR( "�m�[�h��n�̍��t���؏�̊֐�t�ƈ���2��bit���Zotimes�ɑ΂��A" );
    CERR( "��������otimes:N^n->N��bit�����^f:N->(Z,+)�̍�����" );
    CERR( "t���������l��f(t)�Ɨ��L���܂��B" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "" );
    CALL_AC( ExplicitExpressionBitFunctionOnTree );
  } else if( num == num_temp++ ){
    CERR( "N^n�̕����W��S��bit�����^f:N^n->(Z,*)�ɑ΂��A" );
    CERR( "S�̗v�fa���킽��f(a)�̑��a�́Aa�̊e������bit�ɕ�������" );
    CERR( "f(a)��ςŕ\�����A���̓r���܂ł̐ς̑��a���Ǘ�����" );
    CERR( "��DP���������܂��傤�B" );
  }
}

AC( ExplicitExpressionUnaryOther )
{
  CERR( "�܂��͏��������͂̏ꍇ���𒼂Ɍv�Z���AOEIS�Ō������܂��傤�B" );
  CERR( "https://oeis.org/?language=japanese" );
  CERR( "" );
  CERR( "���ɏo�͂̒�`�Ɠ����Ȏ����l�@���܂��傤�B" );
  CERR( "- �P���Ȃ�΁A�p���K��" );
  CERR( "- ��`��p�i�@���g���Ă���΁A�e��T���A���S���Y��" );
  CERR( "- ���͂��f���ɋ߂��ꍇ�ɋK����������΁Ap�i�t�l�Ap�i�@�A" );
  CERR( "  �I�C���[�֐��A�񐔂̌��Ȃ�" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "�����đO�v�Z�����݂܂��傤�B���Ƃ��Ă�" );
  CERR( "- �K��^�t���^�ꍇ�̐�" );
  CERR( "- �f����" );
  CERR( "- �P�܂��͕����̐����̖񐔗�" );
  CERR( "- �I�C���[�֐��̒l�̗�" );
  CERR( "- �T�u�S�[���ƂȂ�֌W���𖞂������̗�" );
  CERR( "������܂��B���ɑQ�����ɂ��O�v�Z���\�ȏꍇ�A�@�܂��͎�����" );
  CERR( "�o�P�b�g�������ă\�[�X�R�[�h�ɖ��ߍ��ލ��������������܂��傤�B" );
}

AC( ExplicitExpressionArraySum )
{
  ASK_NUMBER(
	     "�P�̔z��̐����ƈʒu���󂯎��֐��̑��a�̌v�Z���" ,
	     "�P�̔z��̕�������󂯎��֐��̑��a�̌v�Z���" ,
	     "�z����󂯎��֐��̔z����킽�鑍�a�̌v�Z���"
	     );
  if( num == num_temp++ ){
    CERR( "- �a�̏�������" );
    CERR( "- �����l�ɂȂ鍀�̓Z�ߏグ" );
    CERR( "- 2�ϐ��֐�f�Ɛ���(a_i)_i���^�����Asum_i f(a_i,i)�����߂�ꍇ�A" );
    CERR( "  f(x,i)=sum_k b_{i,k} g_k(x)�ƕ\���ł����" );
    CERR( "  (b_{i,k})_i��(g_k(a_i))_i�̓��ς̑��a�ɋA���A" );
    CERR( "  ���ς͕Е��̓Y�����𔽓]�����邱�Ƃŏ�ݍ��݂ɋA��" );
    CERR( "  - �z��ւ̑��삪�V�t�g�ł���ꍇ�͌J��Ԃ����ς����߂邱�ƂɂȂ�̂ŁA" );
    CERR( "    �K���Ȗ@�ł̍����t�[���G�ϊ�" );
    CERR( "    \\Mathematics\\Polynoial\\Truncate" );
    CERR( "- 2�ϐ��֐�f�Ɛ���(a_i)_i���^�����Asum_{i,j} f(a_i,a_j)�����߂�ꍇ�A" );
    CERR( "  f(x,y)=sum_k g_k(x) h_k(y)�ƕ\���ł����" );
    CERR( "  (g_k(a_i))_i�̗ݐϘa��(h_k(a_j))_j�̐ς̑��a�ɋA��" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    ASK_NUMBER(
	       "�A��������ւ̕����Ɋւ���֐��̑��a�̌v�Z���" ,
	       "�A���Ƃ͌���Ȃ�������ւ̕����Ɋւ���֐��̑��a�̌v�Z���"
	       );
    if( num == num_temp++ ){
      CERR( "�z��̓Y���W���͑S�����W���Ȃ̂ŁA�؂̕����̖��Ɉ�ʉ�����܂��B" );
      CALL_AC( ExplicitExpressionFunctionOnTree );
      CERR( "" );
      CERR( "�X��f��������̒����Ɋւ���ċA�I�ȍ\�������ꍇ�A�S�Ă̘A���������" );
      CERR( "�΂�f�̒l��O�v�Z���邱�Ƃ��������܂��傤�B" );
    } else if( num == num_temp++ ){
      CERR( "�z��̕��ъ����ɂ���ē������ς��Ȃ��̂ŁA�K�؂Ƀ\�[�g���Ă���" );
      CERR( "�v�Z���邱�Ƃ��������܂��傤�B" );
    }
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
  }
  CERR( "" );
  CERR( "N���傫���ꍇ�Ə������ꍇ�ŉ�@��ς���l�@��Y��Ȃ��悤�ɂ��܂��傤�B" );
}

AC( ExplicitExpressionArrayCombinatorial )
{
  CERR( "����N�̔z��̗L���W��S�ƁAS���`��Ɏ��֐�f���^�����Ă���Ƃ��āA" );
  CERR( "sum_{A in S} f(A)�����߂܂��B" );
  CERR( "- �C�ӂ�A in S�ɑ΂�" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  �𖞂����֐�g�����݂���Ȃ�΁A" );
  CERR( "  sum_{A in S} f(A) = sum_{A in S} sum_{i=0}^{N-1} g(A,i)" );
  CERR( "                    = sum_{i=0}^{N-1} sum_{A in S} g(A,i)" );
  CERR( "  �ɂ��g(-,i)�̋t���̐����グ���ɋA��" );
  CERR( "- �C�ӂ�A in S�ɑ΂�" );
  CERR( "  f(A) = #{i in [0,N)|P(A,i)} " );
  CERR( "  �𖞂����֌WP�����݂���Ȃ�΁AP�̓����֐���g�ƒu���ΔC�ӂ�A in S�ɑ΂�" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  �����藧�̂ŏ�̏ꍇ�ɋA��" );
  CERR( "- �C�ӂ�A in S�ɑ΂�" );
  CERR( "  f(A) = prod_{i=0}^{N-1} g(A,i)" );
  CERR( "  �𖞂����֐�g�����݂���Ȃ�΁A�ς̘a�T�^�Ȃǂ̑g�ݍ��킹�_�I����" );
  CERR( "  https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "  https://ladywingclover.hatenablog.com/entry/2022/11/24/084524" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionFunctionOnPermutation )
{
  ASK_NUMBER(
	     "�P�̏���Ɋւ���l�̌v�Z���" ,
	     "������󂯎��֐��̑��a�̌v�Z���"
	     );
  if( num == num_temp++ ){
    CERR( "- �������̂��̂̌v�Z����" );
    CERR( "  - O(N log_2 N)��O(N^2)���Ԃɍ��������Ȃ�]�|���̌v�Z" );
    CERR( "  - O(N log_2 N)���Ԃɍ���Ȃ������Ȃ�݊��\���iO(N)�j" );
    CERR( "- �����Ɖ����̐ς̘a�͍s�񎮂ɋA�������A" );
    CERR( "  - �s�񎮂��̂��̂Ȃ�s��{�ό`�iO(N^3)�j" );
    CERR( "  - �]���q�W�J�̓r���̒l���K�v�Ȃ烁�����ċA�iO(N 2^N)�j" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "�]�|����" );
    CERR( "- O(N^2)���ʂ肻���Ȃ�΋𒼂ȓ�d���[�v" );
    CERR( "- O(N log_2 N)���ʂ肻���Ȃ�Ή��QBIT" );
    CERR( "  \\Mathematics\\Combinatorial\\Permutation" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
    CERR( "�Ōv�Z���܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
    CERR( "" );
    CERR( "�����𖞂�������S�̂��킽��]�|���̑��a�^���Ғl�́A" );
    CERR( "�ei<j���Ƃɂ����œ]�|�������鏇��̌����v�Z���A���̑��a�^���Ғl��" );
    CERR( "���܂��傤�B�������ǂ���΁A�]�|�������鏇��̌��͓]�|��������Ƃ�" );
    CERR( "����Ȃ�����̌��̔����ƂȂ�܂��B" );
  }
}

AC( ExplicitExpressionFunctionOnTree )
{
  ASK_NUMBER(
	     "�؂��󂯎��֐��̌v�Z���" ,
	     "�؏�̊֐��̑��a�̌v�Z���" ,
	     "�\���؂̌v�Z���"
	     );
  if( num == num_temp++ ){
    CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "- �e�m�[�h�i�܂��͂��̋ߖT�j�̊�^�ɕ����ł��鎞�̓m�[�h���Ƃ̌v�Z" );
    CERR( "- �����؂Ɋւ���ǂ��J�ڊ֌W������΁i�S���ʁj��DP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree" );
    CERR( "���������܂��傤�B" );
    ASK_YES_NO( "f��bit���Z�̑��������ł�����ł����H" );
    if( reply == "y" ){
      CALL_AC( ExplicitExpressionBitFunctionOnTree );
    }
  } else if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CERR( "�\����͂͌���̍ċA���ɉ����čċA�֐��Ŏ������܂��傤�B" );
    CERR( "�Ⴆ�Ύ�S�������珇�ɓǂ݁A" );
    CERR( "Expression(S,�ǂ�ł���ʒui,���ԍ�v,�\����T)��" );
    CERR( "�uS[i]�����Z�q�܂��͎n�[�Ƃ��鎮e�ɔԍ�v��U��A" );
    CERR( " T��e�̕������̎��ԍ��֗L���ӂ𒣂�Ai��v�𑝂₷�v" );
    CERR( "�Ƃ������������̍ċA���ɏ]���Ă������̊֐��ɕ�����" );
    CERR( "�ċA����Ɨǂ��ł��B" );
    CERR( "https://qiita.com/kazuki_tamaribuchi/items/77a4b4e6214646a079ed" );
    CERR( "" );
    CERR( "�\���؂ɉ������v�Z�́A���Z���P�ȊO�̈������Œ肵���P�ϐ��֐��Ƃ݂Ȃ�" );
    CERR( "�����Ƃ��ď������A����������compress+rake��g�ݍ��킹��O(N(log N)^3)��" );
    CERR( "�������邱�Ƃ��������܂��傤�B" );
    CERR( "https://en.wikipedia.org/wiki/Tree_contraction#Expression_Evaluation" );
    CERR( "https://yukicoder.me/submissions/940108" );
  }
}

AC( ExplicitExpressionBitFunctionOnTree )
{
  CERR( "�uT�̊e�m�[�hv�����Ƃ��镔���؂ł�j���ڂ�bit���s�̌�dp[v][s][j]�v" );
  CERR( "���Ǘ�����v,s,j�Ɋւ��铮�I�v��@���������܂��傤�B" );
  CERR( "" );
  CERR( "�����T��{0,1,...,N-1}�ɒʏ�̏����̋t��������ꂽ���̂ł���ꍇ��" );
  CERR( "�u��i�����Ő؂���������ł�j���ڂ�bit��s�i=0,1�j�ł����dp[i][s][j]�v" );
  CERR( "���Ǘ����邱�Ƃɑ��Ȃ�܂���B" );
}

AC( FunctionOnTree )
{
  CERR( "��T�̕���P�ɑ΂��AP�̊e����p��n��f(p)�̑��a��F(P)�ƒu���܂��B" );
  CERR( "T�ɍ����Œ肵�A�[���D��T����T�̒��_�Ƀ��x���Â������܂��B" );
  CERR( "" );
  CERR( "P�̊e����p�ɑ΂�p�̊e���_�̃��x���̍ŏ��l��D(p)�ƒu���A" );
  CERR( "D�ɂ��ď�����P����ׂ܂��B" );
  CERR( "" );
  CERR( "P�̖�������p���폜��������P'�����̖؂���p���폜�����؂̕����ł���" );
  CERR( "F(P)=F(P')+f(p)�ƕ\���邱�Ƃɒ��ӂ��܂��傤�B" );
}

AC( ExplicitExpressionFunctionOnNonTreeGraph )
{
  CERR( "- �����W����̊֐��̌v�Z����" );
  CERR( "  - O(N 2^N)���Ԃɍ��������Ȃ獂���[�[�^�ϊ��^���r�E�X�ϊ�" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - O(N^2)���Ԃɍ��������ŗv�f���ɂ݈̂ˑ�����Ȃ�}�[���[�ϊ�" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  CERR( "- ���̑��̏����W����̊֐��̌v�Z���̓[�[�^�ϊ��^���r�E�X�ϊ�" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- �ӂɏd�݂��t����ꂽ�O���t��̂Q�_�����Ԍo�H�i�������͒��_�̏d���̂Ȃ��o�H�jP" );
  CERR( "  �S�̂��킽����P�ɉ������ӂ̏d�݂̑���f(P)���l��f(P)�̉������v�Z�������" );
  CERR( "  - �d�݂��u�P�ʌ����ŏ����ł��铙�����S�������m�C�hM�̒��ρv�ɒl������" );
  CERR( "    O(M(V+E)log V)���Ԃɍ��������Ȃ�Ίe���ϐ����ɑ΂���_�C�N�X�g���@" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Dijkstra" );
  CERR( "  - �d�݂��u�P�ʌ����ŏ����ł���meet�������m�C�h�v�ɒl������" );
  CERR( "    O(V^3)���Ԃɍ��������Ȃ�΃��[�V�����t���C�h�@" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionOrder )
{
  ASK_NUMBER(
	     "�^����ꂽ�����W���Ɋւ�����" ,
	     "�����W�����X�V������"
	     );
  if( num == num_temp++ ){
    CERR( "���d�W��S�����炩�̏����Ń\�[�g�����z��a�Ɋւ�������l���܂��B" );
    ASK_NUMBER(
	       "�^����ꂽ�v�fs�ɑ΂�s=a[i]�𖞂���i�����߂���" ,
	       "�^����ꂽi�ɑ΂���a[i]�����߂���" ,
	       "�^����ꂽi�ɑ΂���a[0],...,a[i]��S�ċ��߂���"
	       );
    if( num == num_temp++ ){
      ASK_YES_NO( "�ei���Ƃ�a[i]�������ɋ��߂�����ł����H" );
      if( reply == "y" ){
	CERR( "i�Ɋւ���񕪒T�����������܂��傤�B" );
      } else {
	CERR( "s������S�̍��̐����グ���������܂��傤�B" );
	ASK_YES_NO( "S���Œ蒷�ϐ��֐��̑��ŗ^�����܂����H" );
	if( reply == "y" ){
	  CERR( "�Œ蒷�ϐ��֐��̋t���̐����グ���́A" );
	  CALL_AC( CountingExplicitExpression );
	}
      }
    } else if( num == num_temp++ ){
      CERR( "S�̊e�v�fs���Ƃ�s������S�̍��𐔂��グ��s�Ɋւ���񕪒T�����������܂��傤�B" );
      ASK_YES_NO( "S���Œ蒷�ϐ��֐��̑��ŗ^�����܂����H" );
      if( reply == "y" ){
	CERR( "�Œ蒷�ϐ��֐��̋t���̐����グ���́A" );
	CALL_AC( CountingExplicitExpression );
      }
    } else if( num == num_temp++ ){
      CERR( "- �ei���Ƃ�a[i]�������ɋ��߂���Ȃ�΁Aa[i]�ȉ���S�̗v�f�̑S�񋓂��������܂��傤�B" );
      CERR( "- S�����d�W��M�̘a�W���ł���Ȃ�΁A�e���d�W�����\�[�g����M��priority_queue�ŃC�x���g�\�[�g" );
      CERR( "���������܂��傤�B" );
    }
    CERR( "" );
    CERR( "���Ɏ�����������s�����̍��̐����グ������ۂ́A" );
    CERR( "�us��d�����ڂŏ��߂ăY����l�����̍��̑���count[d][l]�v" );
    CERR( "��d��l���킽�鑍�a�����߂܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  }
}

AC( ExplicitExpressionProbability )
{
  CERR( "- �m���v�Z��" );
  CERR( "  - �]���ۂ������i�����[�[�^�ϊ��^���r�E�X�ϊ��j" );;
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - ���l�Ɋm���炵�����ۂ̓���" );
  CERR( "  - �x�C�Y�̒藝" );
  CERR( "- ���Ғl�v�Z��" );
  CERR( "  - ��L���@�ł̊m���v�Z" );
  CERR( "  - �Ώۂ�Ɨ��Șa�ŕ\���Đ��`��" );
  CERR( "  - ����^�J�ډ񐔂Ȃ���Ғl�Ԃ̊֌W�������ߍs��ݏ��{�X�^���X�@" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Polynomial\\BostanMori" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionCountingOperation )
{
  CERR( "�I���̗]�n�̂Ȃ�����񐔂����߂�ۂ́A" );
  CERR( "- �������C�x���g�Ƃ݂Ȃ����n��ɕ��ׁA�u��Ăɏ����ł����ԁv�������ɕ������A" );
  CERR( "  ���ꂼ��̋�Ԃł̏������܂Ƃ߂Čv�Z" );
  CERR( "- �����̏�Ԃ����炩�̕s�ϗʂŕ��ނ��A�����s�ϗʊԂ̑J�ڂƂ݂Ȃ����Ƃ�" );
  CERR( "  ���I�v��@��ړ��R�X�g�ŏ������ɋA��" );
  CERR( "- ���삪���炩�̏W���̗v�f�ɍ��X�P�񂵂��K�p���Ȃ��Ȃ�΁A�K�p����v�f�S�̂̂Ȃ�" );
  CERR( "  �����W���̑S�T��┼���S��" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionConvolution )
{
  ASK_NUMBER(
	     "�������Ɋւ���v�Z" ,
	     "cup/cap�Ɋւ���v�Z"
	     "gcd/lcm�Ɋւ���v�Z"
	     "���̑���join������̌v�Z"
	     );
  if( num == num_temp++ ){
    CERR( "- �����̑傫�ȑ������Ə����ȑ������̐ς͋𒼏�Z" );
    CERR( "  Mathematics\\Polynomial\\a.hpp" );
    CERR( "- �ʏ�̐ς͍����t�[���G�ϊ��ƒ�����]�藝" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- �p��̐ς͍����t�[���G�ϊ���exp��log" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- f mod g�̋t���v�Z��" );
    CERR( "  - deg(g)���������Ȃ�Ίg�����[�N���b�h�̌ݏ��@" );
    CERR( "    Mathematics\\Polynomial\\Mod" );
    CERR( "  - deg(f)���������Ȃ��1����(g mod f)^{-1}�̑�\����g%f�̐ς�������" );
    CERR( "    ������f�̔{����f�Ŋ�������" );
    CERR( "- f/g�̌W���v�Z�̓{�X�^���X�@" );
    CERR( "  Mathematics\\Polynomial\\BostanMori" );
  } else if( num == num_temp++ ){
    CERR( "- �����W���̊e�����W����n��augmentation�͍����[�[�^�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- �֐��l���v�f���Ɉˑ�����ꍇ�̏�ݍ��݂͍����[�[�^�ϊ��^�������r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- �֐��l���v�f���Ɉˑ����Ȃ��ꍇ�̏�ݍ��݂̓}�[���[�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  } else if( num == num_temp++ ){
    CERR( "- N�̊e�񐔂�n��augmentation�͖񐔗񋓂ő��a�v�Z" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
    CERR( "- [1,N]��̊֐��̏�ݍ��݂͖񐔃[�[�^�ϊ��^�񐔃��r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\Divisor" );
    CERR( "- N�̖񐔏�̊֐��̏�ݍ��݂�N��f��������������Ŗ񐔃[�[�^�ϊ���" );
    CERR( "  N/����ł̒l�݂̂����ό`�Ōv�Z���e�_��Z������" );
    CERR( "  ����̑f�����̌����g�������r�E�X�֐��ō������r�E�X�ϊ��̌v�Z" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
  } else if( num == num_temp++ ){
    CERR( "- �v�fs�̏I�ؕЂł�augmentation�͗אڑ㐔��̃[�[�^�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- join�Ɋւ����ݍ��݂͗אڑ㐔��̃[�[�^�ϊ��^���r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
  }
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "������̏�Z�͕�������" );
  CERR( "Mathematics\\Arithmetic\\a.hpp" );

}

AC( ExplicitExpressionArea )
{
  CERR( "- �O�p�`�̖ʐς͊O��" );
  CERR( "  Mathematics\\Geometry\\AffineSpace" );
  CERR( "- �i�q�_�𒸓_�Ɏ����p�`�̖ʐς̓s�b�N�̒藝" );
  CERR( "  https://en.wikipedia.org/wiki/Pick%27s_theorem" );
  CERR( "- �֐��̃O���t�ň͂܂ꂽ�̈�̖ʐς͐ϕ�" );
  CERR( "  - ���n�֐��ɂ��v�Z" );
  CERR( "  - �敪���ϖ@" );
  CERR( "  - �����e�J�����@" );
  CERR( "���������܂��傤�B" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "�ړ��R�X�g�̍ŏ������" ,
	     "�ړ����̍ő剻���" ,
	     "�z���̊֐��Ɋւ���ő�^�ŏ������" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̍Œ������" ,
	     "�᎟���A�t�B����ԏ�̊֐��̍ő�^�ŏ������" ,
	     "�W���̕����W���̗v�f���̍ő剻���" ,
	     "�O���t�̕ӏW���Ɋւ���ő�^�ŏ������" ,
	     "�؏�̊֐��Ɋւ���ő�^�ŏ������" ,
	     "������̃}�b�`���O�Ɋւ���ő�^�Œ������" ,
	     "�ő�񕔃}�b�`���O���" ,
	     "�m���^���Ғl�̍ő剻���" ,
	     "����R�X�g�̍ŏ������" ,
	     "����񐔂̍ő剻���" ,
	     "�`��T�C�Y�^���̍ő�^�ŏ������" ,
	     "�ő�l�^���a�̍ŏ������" ,
	     "�ŏ��l�^���a�̍ő剻���"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistance );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationGraphCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationBipartiteMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationOperationCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationDrawingImage );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMinimum );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationMaximum );
  }
}

AC( MinimisationMovingCost )
{
  ASK_NUMBER(
	     "�P�n�_���I�_�R�X�g�ŏ����i���H�j���" ,
	     "���n�_�P�I�_�R�X�g�ŏ����i�����j���" ,
	     "���n�_���I�_�R�X�g�ő�l�ŏ����i�J�핢�j���" ,
	     "���n�_���I�_�R�X�g���a�ŏ����i�ŏ���p���j���" ,
	     "�P�n�_���o�R�_�R�X�g�ŏ����i�X�^���v�����[�j���"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "- �ŒZ�o�H�̎n�_�̓��肪�s�v�Ȃ�΁A�n�_���P�ǉ����Č��̎n�_�փR�X�g0��" );
    CERR( "  �L���ӂ�ǉ�" )
    CERR( "- �ŒZ�o�H�̎n�_�̓��肪�K�v�Ȃ�΁A�ӂ𔽓]" );
    CERR( "�ɂ��P�n�_���I�_�ŏ��R�X�g�ړ��i���H�j���ɋA������܂��B" )
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingOpenCovering );
  } else if( num == num_temp++ ){
    CERR( "�e�I�_tj���S�[���Ƃ��ėǂ��l���̏����Nj�ƒu����" );
    CERR( "- �e�ӂ̗e�ʂ����ɐݒ�" );
    CERR( "- �e�n�_si�֗e��1�R�X�g0�̕ӂ������_S��ǉ�" );
    CERR( "- �e�I�_tj����e��Nj�R�X�g0�̕ӂ������_T��ǉ�" );
    CERR( "�Ƃ��邱�Ƃœ�����L�����O���t�ɑ΂�Primal-Dual�@��K�p���܂��傤�B" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Dijkstra\\Potentialised\\MinimumCostFlow" );
  } else if( num == num_temp++ ){
    CERR( "- HeldKarp�@" );
    CERR( "- �ړ����@�𕪗ނ���p�����[�^�̑S�T��" );
    CERR( "���������܂��傤�B" );
  }
  CERR( "" );
  CERR( "�_�̍��W�ƍŏ������ׂ��R�X�g�ȊO�̐��lx�ɕω�������ꍇ�A�ŏ��R�X�g�ړ���" );
  CERR( "������x�̓����͈͂��i���ē_�̍��W��x�̑g�𒸓_�Ƃ���O���t���l���܂��傤�B" );
  CERR( "" );
  CERR( "�d�݂��ӂł͂Ȃ����_�ɂ��Ă���ꍇ" );
  CERR( "- 㰓����m�C�h�Ȃ�Γ��ɒ��_�͒ǉ�����" );
  CERR( "- 㰓��łȂ������m�C�h�Ȃ�Ώd�݂��P�ʌ��ł���n�_�ƏI�_��ǉ�����" );
  CERR( "�e�ӂ̏d�݂𗼒[�̏d�݂ɉ��Z��K�p�������̂Œ�`���܂��傤�B" );
  CERR( "" );
  CERR( "�ӏW��E���傫�߂���ꍇ�A�o�H��ۓ�������@�ł����ăR�X�g���傫���Ȃ�Ȃ�" );
  CERR( "���̂���肵�A�ۓ��\�łȂ��o�H�݂̂ɍi�邱�Ƃ�E�����炵�܂��傤�B" );
  CERR( "" );
}

AC( MinimisationSolvingMaze )
{
  ASK_YES_NO( "E��10^8�I�[�_�[�ŗ}�����܂����H" );
  if( reply == "y" ){
    CERR( "- �R�X�g��1�݂̂�O(V+E)���ʂ肻���Ȃ�Ε��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g��1�݂̂łȂ�{0,1}�l��O(V+E)���ʂ肻���Ȃ��01���D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g��{0,1}�l�łȂ����񕉂Ȃ��" );
    CERR( "  - O(min(V^2,(V+E)log_2 E))���Ԃɍ��������Ȃ�΃_�C�N�X�g���@" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "  - G���O���t�̔�֏�O���t�Ȃ��" );
    CERR( "    - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E?i))���Ԃɍ��������Ȃ��" );
    CERR( "      ���������_�C�N�X�g���@�܂��͂��̃f�[�^�\��������" );
    CERR( "      \\Mathematics\\Geometry\\Graph\\Acyclic\\Double" );
    CERR( "    - �Ԃɍ���Ȃ������Ȃ�Ε��������𓮓I�v��@�ŏ��������f�[�^�\��������" );
    CERR( "  - �R�X�g���a�����C�Ƃ�O((V+E)C)���Ԃɍ��������Ȃ��" );
    CERR( "    �R�X�g���a����ԂɊ܂߂��O���t��ł̕��D��T��" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g���񕉂łȂ��Ȃ��" );
    CERR( "  - O(VE)���Ԃɍ��������Ȃ�΃x���}���t�H�[�h�@" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\BellmanFord" );
    CERR( "  - �ӂ̍폜���s���J��Ԃ������ꍇO(VE+Q(V+E)log_2 E)���Ԃɍ��������Ȃ��" );
    CERR( "    �|�e���V�����t���_�C�N�X�g���@" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Dijkstra\\Potentialised" );
    CERR( "���������܂��傤�B" );
  } else {
    CERR( "�z��̏�����������LightsOut���̂悤��E�����ɑ傫���Ȃ�΁A" );
    CERR( "�e������f�[�^�\���ɖ|�󂷂邱�ƂŃV���v���ȍŏ������ɋA�������܂��傤�B" );
    CERR( "- ��ԉ��Z�Ȃ�΁A�K������̂Q�_���Z�ɖ|��" );
    CERR( "- �����؂̔������]�Ȃ�΁A�؏�̊K������̂P�_�X�V�ɖ|��" );
    CERR( "- �����O���t�Ɣ�֏�L���O���t�̍����Ȃ�΁A�L���O���t�̗L���ӂɉ�����" );
    CERR( "  ���I�v��@�̃f�[�^�\��������" );
    CERR( "���̏�ŁA�����" );
    CERR( "- �I�𕔕��i�ǂ��𑀍삷�邩�A�Ȃǁj" );
    CERR( "- ����I�J�ځi�I�𕔕������߂���ŏ��R�X�g���������邽�߂�" );
    CERR( "  �����I�Ɍ��܂镔���j" );
    CERR( "�ɕ����čl�����Ȃ����������A�I�𕔕��̑S�T���┼���S�񋓂Ȃǂ�" );
    CERR( "�������܂��傤�B�Ⴆ�Ίe�������X�P�񂵂����삵�Ȃ��̂��œK�ł���΁A" );
    CERR( "�ǂ̐����𑀍삷�邩�ɑΉ����镔���W���̒T�����ƂȂ�܂��B" );
    CERR( "" );
    CERR( "����O��ŕs�ςȒl�i���a�┒���̌���mod2�Ȃǁj������΁A" );
    CERR( "��������炩�̗뉻���ɖ|��ł��邩������܂���B" );
    CERR( "�Ȃ�ׂ��R�X�g���ȒP�œ����Ȓl�ɖ|�󂵁A���̖|��ɑ����đ�����X�ɖ|�󂵁A" );
    CERR( "���V���v���ȁi�Ⴆ���×~�@���K�p�\�ȁj�뉻���ւ̋A�������݂܂��傤�B" );
  }
}

AC( MinimisationSolvingOpenCovering )
{
  ASK_YES_NO( "�n�_�i�핢���S�j����܂��Ă��邩�A�܂���E���������ł����H" );
  if( reply == "y" ){
    CERR( "- �R�X�g���Ȃ�O(V+E)���ʂ肻���Ȃ�΁A���_���D��T����" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̕��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g��0��1��O(V+E)���ʂ肻���Ȃ�΁A���_01���D��T��" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł�01���D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "- max���Z���l���Ă���O(E(log_2 E + ��(V)))���ʂ肻���Ȃ�΁A" );
    CERR( "  �d�݂ŕӂ��\�[�g���đf�W���f�[�^�\��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
    CERR( "- O((V+E)log_2 E)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̃_�C�N�X�g���@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "- O(V^3)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���[�V�����t���C�h�@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
    CERR( "���������܂��傤�B" );
  } else {
    CALL_AC( MinimisationSolvingOpenCoveringUnknownCentres );
  }
}

AC( MinimisationSolvingOpenCoveringUnknownCentres )
{
  CERR( "�핢���aL��񕪒T�����܂��傤�B�Ⴆ�Ύn�_�i�핢���S�܂��͔핢�[�_�j��" );
  CERR( "�����i������Ŏn�_���P�Œ肵�Ă��̎n�_���狗��L�ȓ��̓_���폜���A" );
  CERR( "�c��̓_�Q�ɑ΂��čċA�I�ɖ����������Ƃ��������܂��傤�B" );
}

AC( MaximisationMovingDistance )
{
  ASK_NUMBER(
	     "�P�n�_���I�_�����Œ����i�ŉ��_�T���j���" ,
	     "���n�_���I�_�����Œ����i�Œ������T���j���" ,
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "�H�������Ȃ��L���O���t�ł����H" );
    if( reply == "y" ){
      CERR( "�g�|���W�J���\�[�g�ɂ�铮�I�v��@" );
      CERR( "\\Mathematics\\Geometry\\Graph\\TopologicalSort" );
    } else {
      CERR( "�n�_��S�T�􂷂邱�ƂŁA�P�n�_���I�_�R�X�g�ő剻���ɋA������܂��B" );
      CALL_AC( MaximisationMovingDistanceSingleStart );
    }
  }
  CERR( "���������܂��傤�B" );
}

AC( MaximisationMovingDistanceSingleStart )
{
  CERR( "- �R�X�g���񐳂�O((V+E)log_2 E)���Ԃɍ��������Ȃ��-1�{���ă_�C�N�X�g���@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
  CERR( "- �R�X�g�����ɂȂ肦��O(VE)���Ԃɍ��������Ȃ��1�{���ăx���}���t�H�[�h�@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BellmanFord" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "��蕶�܂��͓��͂ŗ^������P�̔z��Ɋւ�����" ,
	     "�����𖞂����C�ӂ̔z��Ɋւ�����"
	     );
  if( num == num_temp++ ){
    ASK_NUMBER(
	       "�������󂯎��֐��̕����ő�l�^�����a�̍ő剻���" ,
	       "�������󂯎��֐��̕����a�ƕ╔���a�̍��̍ŏ������" ,
	       "0/1�{�ȊO�̔z��̕ύX�Ɣz����󂯎��֐��̍����̍ő剻���"
	       );
    if( num == num_temp++ ){
      CALL_AC( MaximisationSubArraySum );
    } else if( num == num_temp++ ){
      CERR( "�����a�Ƒ��a�̔����̍��̍ŏ������s���܂��傤�B" )
      CERR( "����͏����������l���邱�Ƃŏ���t�������a�̍ő剻���ƂȂ�܂��B" )
      CALL_AC( MaximisationSubArraySum );
    } else if( num == num_temp++ ){
      CALL_AC( MaximisationArrayFunction );
    }
  } else if( num == num_temp++ ){
    CERR( "- ��蓾��l�����Ȃ��֐��������Ɋւ��čċA�I�\�������ꍇ�́A" );
    CERR( "  �u����i�̎��ɉ\�Ȓl�S�̂܂��͈ꕔ�̏W��dp[i]�v" );
    CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
    CERR( "- �uv�ȏ�̒l����蓾�邩�ۂ��v������\�ł��鎞��" );
    CERR( "  v�Ɋւ���񕪒T��" );
    CERR( "- �uv�ȏ�̒l����蓾�邩�ۂ��v������\�ł��鎞��" );
    CERR( "  v�Ɋւ���񕪒T��" );
    CERR( "���������܂��傤�B" );
  }
}

AC( MaximisationSubArraySum )
{
  CERR( "�ő�l�^���a�����l�����l�ƌĂԂ��Ƃɂ��܂��B" );
  CERR( "�z��̍���N�A��i�����̉��lA_i�A���l�̍ő�l�^���a�̏��V�Ƃ��܂��B" );
  CERR( "{0,...,N-1}�̕����W��I�ł����āA" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- ���̑��̏���" );
  CERR( "�𖞂������̂����݂���v <= V�̍ő剻���l���܂��B" );
  ASK_NUMBER(
	     "I�ɃR�X�g���񂪂���d�������I���������ꍇ" ,
	     "I�ɃR�X�g���񂪂���d�������I���������Ȃ��ꍇ" ,
	     "I���Œ蒷�̋�Ԃł���ꍇ" ,
	     "I�ɒǉ��̐��񂪂Ȃ��ꍇ"
	     );
  if( num == num_temp++ ){
    CERR( "�e�I���̃R�X�g��������݂���ꍇ�A���̏���ȉ��̍��������l���܂��傤�B" );
    CERR( "�R�X�g�̎�����K<=2�An���ڂ̃R�X�g��C_n�Ƃ��A" );
    CERR( "m�I��ڂł�C_n[k_m]<=D_m�𖞂�����n��I�ׂ�Ƃ��܂��B" );
    CERR( "" );
    CERR( "��{C_n,n}�ƑI��{k_m,D_m}�����ꂼ�ꎫ���������Ń\�[�g���A" );
    CERR( "�ȉ��̎菇�őI���������Ɍ��肵�Ă����܂��傤�B" );
    CERR( "- K=1�̏ꍇ�A�e�I���ł͉\�ȑI���̒��ōő�̂��̂��̗p���܂��傤�B" );
    CERR( "- K=2�̏ꍇ�A�e�I���ł͉\�ȑI����{��2����,���ԍ�}��set�ŊǗ�����" );
    CERR( "  ���̒��ōő�̂��̂��̗p���܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�e�I���̃R�X�g��������݂���ꍇ�A���̏���ȉ��̍��������l���܂��傤�B" );
    CERR( "�R�X�g�̍ő�l�^���a���C<���Ƃ��܂��BC�̎����͎��R�ł��B" );
    CERR( "- C���\���������Ȃ�΁A�R�X�g�̑傫���I���񐔂̑S�T���񕪒T��" );
    CERR( "- O(NC)���ʂ肻���Ȃ��" );
    CERR( "  �ui�Ԗڂ̍��܂Ŏg���ăR�X�g�̍ő�l�^���a��c�ȉ��̎��̉��l�̍ő�ldp[i][c]�v" );
    CERR( "  ���Ǘ�����c�Ɋւ��铮�I�v��@" );
    CERR( "- O(C^2)���ʂ肻���Ȃ��" );
    CERR( "  �u�R�X�gc�̍��̉��l�̍ő�lv[c]�v" );
    CERR( "  ��O�v�Z��" );
    CERR( "  �u�R�X�g�̍ő�l�^���a��c�ȉ��̎��̉��l�̍ő�ldp[c]�v" );
    CERR( "  ���Ǘ�����c�Ɋւ��铮�I�v��@" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "��Ԃ��X���C�h���Ă����A���[�̍X�V�l��p���čő�l���Ǘ����܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)���ʂ肻���Ȃ�΋𒼂ɑS�T��" );
    CERR( "- O(N 2^{N/2})���ʂ肻���Ȃ�Δ����S��" );
    CERR( "- O(NV)���ʂ肻���Ȃ��[v-V,v+V]�ł̎����\����" );
    CERR( "  �J�ڂ��铮�I�v��@" );
    CERR( "  https://stackoverflow.com/a/18949218" );
    CERR( "- O((N+V)log_2 V)���ʂ肻����V��10^5�I�[�_�[��" );
    CERR( "  �v���X�f��P��@�Ƃ���Ȃ�Ζ@P�ł̍����t�[���G�ϊ��ɂ��" );
    CERR( "  exp(log�̑��a)�v�Z" );
    CERR( "  \\Mathematics\\Polynomial\\Truncate" );
    CERR( "���������܂��傤�B" );
  }
}

AC( MaximisationArrayFunction )
{
  CERR( "�z����󂯎��֐�F���^�����Ă���Ƃ��܂��B�^����ꂽ�z��A��" );
  CERR( "���炩�̏��������ē�����z��B�ɑ΂���F(B)�̍ő剻���́A" );
  CERR( "�ő剻���ׂ����̃T�u�S�[��f�ɕ\��鍀x�̂������ߑł��₷�����̂�T���܂��傤�B" );
  CERR( "- �z��̒�����i�őł��؂�������x�̌�␔��X(i)" );
  CERR( "- �z��̒�����i�őł��؂���x�����ߑł������̔z��̒���i+1�ł�x�̌�␔��dX(i)" );
  CERR( "�ƒu���܂��B" );
  CERR( "- O(sum_i X(i) dX(i))���ʂ肻����f��x����O(1)�Ōv�Z�ł���Ȃ�΁A" );
  CERR( "  i��x�Ɋւ��铮�I�v��@" );
  CERR( "- O(N log_2 X(N))���ʂ肻����" );
  CERR( "  - f��x����O(N)�Ōv�Z�ł�x�Ɋւ��ĒP���Ȃ�΁Ax�̓񕪒T��" );
  CERR( "  - f��x����O(N/x)�Ōv�Z�ł���Ȃ�΁Ax�̑S�T��" );
  CERR( "- O(N log_2 N)���ʂ肻����x����ёւ����f��x����O(log_2 N)�Ōv�Z�ł���Ȃ�΁A" );
  CERR( "  �D��x���L���[�Ȃǂł�x�̊Ǘ�" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationArrayLength )
{
  CERR( "�S�������a�Ȕ��������Ō����I�Ȏ������Ⴂ�܂��B" );
  CERR( "- �S�����Ȃ�΁A�����𖞂���������̒����̍ő�l���C���f�b�N�X�Ɏ���" );
  CERR( "  �z���p���āA�����̕�����̖����ł��鍀���L�^���邱��" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- �a�Ȕ������Ȃ�΁A�����𖞂���������̖������C���f�b�N�X�Ɏ���" );
  CERR( "  �A�z�z���p���āA����畔����̒����̍ő�l���L�^���邱��" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "�ʊ֐��̍ŏ��^�ő剻���" ,
	     "�����֐��̍ŏ��^�ő剻���" ,
	     "�����̍ŏ��^�ő剻���" ,
	     "�핢���a�̍ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "�O���T�����������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�j���[�g���@���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�}���n�b�^�������il^1�j�͈ꎟ�ϊ���l^���ɋA����������ŁA" );
    CERR( "- �P���Ȏ��ɋA���ł���ꍇ�A�񕪒T��" );
    CERR( "- �ő剻���̏ꍇ�A��Βl���O�������p�^�[���̑S�T��" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�}���n�b�^�������il^1�j�͈ꎟ�ϊ���l^���ɋA����������ŁA" );
    CALL_AC( MinimisationSolvingOpenCoveringUnknownCentres );
  }
  CERR( "" );
  CERR( "�����̃p�����[�^�����肷�ׂ��ꍇ�́A�T�u�S�[���̎��̒l�����ߑł��܂��傤�B" );
}

AC( MaximisationSubsetSize )
{
  CERR( "�^����ꂽ�W���̃T�C�Y��N�ƒu���܂��B" );
  CERR( "- O(2^N)���Ԃɍ��������Ȃ�΁Abit�S�T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- O(N2^N)���Ԃɍ��������Ȃ�΁A�����W���̕�ܑ΂�bit�S�T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- �ɑ卽�̌v�Z�Ȃ�΁A�㑱�֐����`���A�ɑ匳����㑱�֐��̋t���̃O���t�̐[���v�Z" );
  CERR( "- �ɑ唽���̌v�Z�Ȃ�΁A" );
  CERR( "  - Dilworth�̒藝�̏ؖ��Ɋ�\�z" );
  CERR( "    https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
  CERR( "  - �㑱�֐����`���A�㑱�Ɋւ���񕪒T��" );
  CERR( "- ���S��\�n�̌v�Z�Ȃ�΁A���D��T����UnionFind�ɂ��A�������v�Z" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "- ���J��Ԃ̋ɑ�r���I�W���Ȃ�΁A��ԃX�P�W���[�����O" );
  CERR( "���������܂��傤�B" );
}

AC( MinimisationGraphCost )
{

  CERR( "���l�̍ő剻���͉��l��-1�{�����R�X�g���l���邱�Ƃ�" );
  CERR( "�R�X�g�̍ŏ������ɋA������܂��B" );
  ASK_NUMBER(
	     "�S��X�̃R�X�g�ŏ������" ,
	     "�p�X�̃R�X�g�ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "�N���X�J���@" );
    CERR( "\\Mathematics\\Geometry\\Graph\\UnionFindForest\\Kruscal" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "����͍ŒZ�o�H��肻�̂��̂ł��B" );
    AC( MinimisationMovingCost );
  }
}

AC( MaximisationFunctionOnTree )
{
  ASK_NUMBER(
	     "�؏�̊֐��̓���̕����W����ł̍ő�^�ŏ��l�v�Z���" ,
	     "�؂̕������Ƃɒ�܂�l�̍ő�^�ŏ������"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "�u��i���_�܂łŐ؂�������F(P)�����̍ő�ldp[i]�v" );
    CERR( "���Ǘ�����i�Ɋւ��铮�I�v��@�iO(N^2�~f�̌v�Z��)�j" );
    CERR( "���������܂��傤�B" );
  }
}

AC( MaximisationStringMatching )
{
  CERR( "��{�I�ɂ͒��J�Ƀ��[�v���񂵂ĉ����܂��傤�B" );
  CERR( "- ��r�Ώۂ����Ȃ��ꍇ�A�O�܂��͌�납�珇�ɒT���i�×~�@�^���I�v��@�j" );
  CERR( "- ���C���h�J�[�h���܂ޏꍇ�A" );
  CERR( "  - �O�܂��͌�납�珇�ɏꍇ����������O(N)�ŏ����ł��邩" );
  CERR( "  - �\�ȑ�����@���i�荞���O(N)��ނɗ����邩" );
  CERR( "- ��r�񐔂������ꍇ�A���[�����O�n�b�V��" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- �����񕶂̍Œ���������ꍇ�A�ڎ��@�ɂ��O�v�Z" );
  CERR( "  \\Utility\\String\\Palindrome" );
  CERR( "- �}�b�`���O���镔��������̍Œ���������ꍇ�AZ�A���S���Y��" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- �}�b�`���O���镶�����̍ő剻������ꍇ�A�����̎�ޕ���{0,1}�l�z���" );
  CERR( "  �����ē��ς̍ő剻�i�Y�����𔽓]�����ēK���Ȗ@�ł̏�ݍ��݁j" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationBipartiteMatching )
{
  CERR( "�z�b�v�N���t�g�J�[�v�@��ő嗬" );
  CERR( "\\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationProbability )
{
  CERR( "����^�헪��I��Ŋm���^���Ғl���ő剻����ꍇ�A" );
  CERR( "�푀��Ώۂ�\�ȑ���^�헪�̃f�[�^�Ȃǂ���ԂƂ��Ē莮�����A" );
  CERR( "�us���o�R����ꍇ�̊m���^���Ғl�̍ő�ldp[s]�v" );
  CERR( "���Ǘ�����s�Ɋւ��铮�I�v��@���������܂��傤�B" );
}

AC( MinimisationOperationCost )
{
  CERR( "����R�X�g�̍ŏ����́A����ɂ���ԑJ�ڂ��O���t��̈ړ��Ƃ݂Ȃ����Ƃ�" );
  CERR( "�ŒZ�o�H���ɋA�������邱�Ƃ��\�ł��B" );
  CALL_AC( MinimisationMovingCost );
}

AC( MaximisationCountingOperation )
{
  CERR( "����ɂ���Č��鐔�lx�����t���邱�Ƃő���񐔂̏�E�����߂܂��傤�B" );
  CERR( "��E��B��������@�̒T���ɂ�" );
  CERR( "- ����ɂ����x������l���ŏ��ɂȂ�悤�ȑ���̔���" );
  CERR( "- �قƂ�Ǔ�������̔���" );
  CERR( "- ���삪���炩�̏W���̗v�f�ɍ��X�P�񂵂��K�p���Ȃ��Ȃ�΁A�K�p����v�f�S�̂̂Ȃ�" );
  CERR( "  �����W���̑S�T��┼���S��" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationDrawingImage )
{
  CERR( "�`����̍ő�^�ŏ����͕`��T�C�Y�̍ŏ��^�ő剻�ɋA�������܂��傤�B" );
  CERR( "�`��T�C�Y�̍ő�^�ŏ������̓T�C�Y�����ߑł����񕪒T����e�_�ł̃T�C�Y�̍ő剻" );
  CERR( "�Ȃǂ��s������ŕ`��\��������ɋA�������܂��傤�B" );
  CALL_AC( DecisionDrawability );
}

AC( MaximisationMinimum )
{
  CERR( "�S�Ă�-1�{���邱�Ƃōő�l�^���a�̍ŏ������ɋA�������܂��B" );
  CALL_AC( MinimisationMaximum );
}

AC( MinimisationMaximum )
{
  ASK_NUMBER(
	     "�O���t�̕ӏW��E��̊֐��̕����ő�l�^�����a�̍ŏ������" ,
	     "��ʂ̏W����̊֐��̕����ő�l�^�����a�̍ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "max�^+�����Z�Ƃ���ŒZ�o�H���ɋA�������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "�����ő�l�^�����a���Œ肵�ĕ����W���̑��݂𔻒肷��" );
    CERR( "�񕪒T�����������܂��傤�B" );
  }
}

AC( Counting )
{
  ASK_NUMBER(
	     "�Œ蒷�ϐ��֐��̋t���̐����グ���" ,
	     "�����𖞂����z��^������̐����グ���" ,
	     "�����𖞂����O���t�̐����グ���" ,
	     "�^����ꂽ�z��̕�����̐����グ���" ,
	     "�^����ꂽ������̕���������̐����グ���" ,
	     "�^����ꂽ�؂̕����̐����グ���" ,
	     "�^����ꂽ�W���̕����W���̐����グ���" ,
	     "�헪�^������@�̐����グ���" ,
	     "�o�H�̐����グ���" ,
	     "�^�C�����O�^�h�蕪���̐����グ���" ,
	     "�����O�}�`�̐����グ���" ,
	     "�J�^�������̌v�Z���" ,
	     "����񐔂̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubset );
  } else if( num == num_temp++ ){
    CALL_AC( CountingStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPath );
  } else if( num == num_temp++ ){
    CALL_AC( CountingTiling );
  } else if( num == num_temp++ ){
    CALL_AC( CountingYoundDiagram );
  } else if( num == num_temp++ ){
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- �ϐ��̑Ώ̐�������Α召�֌W�𐧌������S�T��" );
  CERR( "- ���炩�̖񐔂ƂȂ�ȂǓ����͈͂������ϐ�������΂��������ߑł����S�T��" );
  CERR( "- �������W���ւ̎ʑ��̋t���Ȃ�΃[�[�^�ϊ��^���r�E�X�ϊ�" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- gcd(n,x)=1����1<=x<=n�𖞂���x�̐����グ�̓I�C���[�֐�" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod\\Function\\Euler" );
  CERR( "- f(g(x),g(y))=c�̌`��" );
  CERR( "  - �܂��eb in im(g)�ɑ΂�f(a,b) = c�𖞂���a in im(g)�S�̂�O�v�Z����B" );
  CERR( "  - ����|dom(g)| = N�Amax im(g) = M�Ƃ��āA�ey in im(g)�ɑ΂���" );
  CERR( "    �t���̔Z�x|g^{-1}(y)|���Ǘ�����g_inv[y]��" );
  CERR( "    - O(N)���Ԃɍ��������Ȃ��unordered_map::g_inv[g[x]]++" );
  CERR( "    - O(M+N)���Ԃɍ��������Ȃ�Δz��::g_inv[g[x]]++" );
  CERR( "    - x,y�ɐ���h(x)<h(y)������ꍇ��h(x)�̏��c�ɂ��ă��[�v����" );
  CERR( "      g_inv[g(x)]++���Ă����A����ƕ��s����y��c<h(y)�͈̔͂őS�T��" );
  CERR( "    �ɂ��Ǘ�����B" );
  CERR( "  - �Ō�Ɋey���Ƃ�f(a,g(y)) = c�𖞂����ea in im(g)�ɑ΂�a = g(x)�𖞂���" );
  CERR( "    x��g_inv[a]�Ő����グ��B" );
  CERR( "- f(g(x),g(y))<=c�̌`��f��g���P���������鎞��" );
  CERR( "  - �܂��eb in im(g)�ɑ΂�f(a,b) <= c�𖞂���a�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - ���ɂ������ē�����ea�ɑ΂�g(x)<=a�𖞂���x�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - �Ō�Ɋey���Ƃ�b = g(y)�ɑ΂���O�v�Z���ʂ̑��a�����߂�B" );
  CERR( "- �������̘a�̓��R�r�̓񕽕��藝" );
  CERR( "  https://ja.wikipedia.org/wiki/���R�r�̓񕽕��藝" );
  CERR( "���������܂��傤�B" );
}

AC( CountingArray )
{
  ASK_NUMBER(
	     "�z����󂯎��֐��̒l���Œ肳�ꂽ�z��̐����グ���" ,
	     "�אڐ����Ԋ֌W���𖞂����z��̐����グ���" ,
	     "���̑��̊֌W���𖞂����z��̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "- �z��̎�ނ����Ȃ��ꍇ�́A�S�Ă̔z��ɑ΂���֐��̒l�̑O�v�Z" );
    CERR( "- ��蓾��l�����Ȃ��֐��������Ɋւ��čċA�I�\�������ꍇ�́A" );
    CERR( "  �u����i�̎��ɒlv�ł���z��̑���dp[i][v]�v" );
    CERR( "  ���Ǘ�����i,v�Ɋւ��铮�I�v��@" );
    CERR( "- �z�񂪗L�E�Ŋ֐������W���x�N�g��B�����ꍇ�́A" );
    CERR( "  �u����i�̎��ɒlv�ł���z��̑���dp[i][v]�v" );
    CERR( "  ���Q����dp[i+1][v] = sum_j dp[i][v-j*B_{i+1}]��" );
    CERR( "  ���������Ƃ���dp[i][p+xv]��x�Ɋւ��鑽�����֐��ƂȂ�̂�" );
    CERR( "  ���s�ړ��ƗݐϘa�ɂ��v�Z" );
    CERR( "  \\Mathematics\\Polynomial\\ParallelTranslation" );
    CERR( "  \\Mathematics\\Polynomial\\CumulativeSum" );
    CERR( "- �֐�����Ԙa�Ȃǃf�[�^�\���Ōv�Z�ł���ꍇ�́A" );
    CERR( "  �f�[�^�\���ɖ|�󂵂���ł̐����グ" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- �������ł̒P�����̏ꍇ�A" );
    CERR( "  - �S�����Ȃ�΁A���̕������@�Ȃǂւ̖|��" );
    CERR( "  - �a�Ȕ������Ȃ�΁A�O���t�̑O�v�Z" );
    CERR( "- ���̑��̏����̏ꍇ�͓��I�v��@�ŁA" );
    CERR( "  - �֎~�����̎��͗]���ۂ������X�V" );
    CERR( "  - ���������̎��͕�����ɂ��X�V" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "�z��ւ̊i�[�����֌W����܂����H" );
    if( reply == "y" ){
      CERR( "���������\�����O���t�̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
      CALL_AC( CountingGraph );
    } else {
      CERR( "�i���d�j�W����\�[�g���ꂽ�z��̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
      CALL_AC( CountingSubset );
    }
  }
}

AC( CountingGraph )
{
  CERR( "- �؂̓P�[���[�̌����₻�̈���" );
  CERR( "  https://oeis.org/A000272" );
  CERR( "- �Ȃ���O���t�̓T�C�N���Ƃ���ȊO�ւ̕���" );
  CERR( "���������܂��傤�B" );
}

AC( CountingSubArray )
{
  ASK_NUMBER(
	     "�z��̐������󂯎��֐��̕����a���Œ肵��������̐����グ���" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̐����グ���" ,
	     "�z��̂��̑��̊֌W���𖞂���������̐����グ���" ,
	     "�z��̕����񂩂�擾�ʒu���𗎂Ƃ����z��̐����グ���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGeneralRelationSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArrayImageArray );
  }
}

AC( CountingSumFixedSubArray )
{
  CERR( "�a�����l�����l�ƌĂԂ��Ƃɂ��܂��B" );
  CERR( "�z��̍���N�A��i�����̉��lA_i�A���l�̑��av�Av�̏��V�Ƃ��܂��B" );
  CERR( "{0,...,N-1}�̕����W��I�ł����āA" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- ���̑��̏���" );
  CERR( "�𖞂������̂̐����グ���l���܂��B" );
  ASK_NUMBER(
	     "I�ɃR�X�g���񂪂���ꍇ" ,
	     "I���A��������Ɍ�����ꍇ" ,
	     "I�ɒǉ��̐��񂪂Ȃ��ꍇ"
	     );
  if( num == num_temp++ ){
    CERR( "O(2^N)���ʂ肻���Ȃ�Ή��l�ƃR�X�g�������Ƃ���𒼂ȂQ�ϐ���������Z" );
    CERR( "  \\Mathematics\\Polynomial\\Multivariable" );
  } else if( num == num_temp++ ){
    CERR( "- O(N^2)���ʂ肻���Ȃ�ΗݐϘa�ō��̎擾" );
    CERR( "- O(N log_2 N)���ʂ肻����v=0�ɌŒ�Ȃ�ΗݐϘa��CountUnitProdRange" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProd" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)���ʂ肻���Ȃ�΋𒼂ȂP�ϐ���������Z" );
    CERR( "- O(2^{N/2}N)���ʂ肻����v���P�̒l�ɌŒ�Ȃ�Δ�������������Z������" );
    CERR( "  �Ō�ɂ����̐ς�v���W���݂̂̌v�Z" );
    CERR( "- O((N+V)log_2 V)���ʂ肻����V��10^5�I�[�_�[��" );
    CERR( "  �v���X�f��P��@�Ƃ���Ȃ�Ζ@P�ł̍����t�[���G�ϊ��ɂ��" );
    CERR( "  exp(log�̑��a)�v�Z" );
    CERR( "  \\Mathematics\\Polynomial\\Truncate" );
  }
  CERR( "���������܂��傤�B" );
}

AC( CountingRestrctedSubArray )
{
  ASK_NUMBER(
	     "�A��������̐����グ���" ,
	     "�A���Ƃ͌���Ȃ�������̐����グ���" ,
	     "��������i������̕��ъ����j�̐����グ���"
	     );
  CERR( "����N�̔z��A�ƁAL+n<=N+1�𖞂�������n,L��" );
  CERR( "- ����i�Ɋւ������Q(i)" );
  CERR( "- �e0<=l<L�ɑ΂���n-tuple(b_0,...,b_{n-1})�Ɋւ������R_l(b_0,...,b_{n-1})" );
  CERR( "���^�����Ă���Ƃ��A�z��B�̏���P(B)��" );
  CERR( "�uB�̒���|B|��Q(|B|)����|B|<L+n�𖞂����A���C�ӂ�0<=l<=|B|-n�ɑ΂�" );
  CERR( "�@R_l(B_l,...,B_{l+n-1})�����藧�B�v" );
  CERR( "�̘_���ςƂ��Ē�߂܂��B" );
  CERR( "" );
  CERR( "�Ⴆ�ΎR�^�̕�����̐����グ���ł�N>=3����(n,L)=(2,2)��" );
  CERR( "- Q(i)=�ui=3�v" );
  CERR( "- R_0(b_0,b_1)=�ub_0<b_1�v" );
  CERR( "- R_1(b_0,b_1)=�ub_0>b_1�v" );
  CERR( "�ƕ\����܂��B" );
  CERR( "" );
  if( num == num_temp++ ){
    CALL_AC( CountingRestrctedContinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedDiscontinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubPermutation );
  }
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "����R_l(B)������gcd��max�Ȃǂ�㰓����Z�Ɋւ��铙���ŗ^������ꍇ�́A" );
  CERR( "�s�����̕��������₷���̂Ń[�[�^�ϊ��^���r�E�X�ϊ�" );
  CERR( "\\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "���������܂��傤�B" );
}

AC( CountingRestrctedContinuousSubArray )
{
  CERR( "P(B)�𖞂���A�̘A��������B�̐����グ�́A" );
  CERR( "- R_l������l�Ɉˑ����Ȃ��Ȃ�Ύڎ��@O(N)" );
  CERR( "- R_l������l�Ɉˑ�����ꍇ�A" );
  CERR( "  - O(N^2)���ʂ肻���Ȃ獶�[���Œ肵���𒼒T��" );
  CERR( "  - O(N^2)���ʂ�Ȃ������Ȃ�R_l�����̓ǂݑւ�" );
  CERR( "���������܂��傤�B" );
}

AC( CountingRestrctedDiscontinuousSubArray )
{
  CERR( "P(B)�𖞂���A�̘A���Ƃ͌���Ȃ�������B�̐����グ�́A" );
  CERR( "- n-1<=i<=max{j<=N|Q(j)}�𖞂����ei" );
  CERR( "- (0,1,...,N-1)�̒���n-1�̊e������s" );
  CERR( "�ɑ΂���" );
  CERR( "�u����i�ŁA�C�ӂ�0<=l<=i-n�ɑ΂�R_l(B)�𖞂����A" );
  CERR( "�@����n-1����s�ɑΉ�����A�̕�����B�̌�dp[i][s]�v" );
  CERR( "���Ǘ�����i,s�Ɋւ��铮�I�v��@" );
  CERR( "\\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "\\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "���������܂��傤�B" );
}

AC( CountingRestrctedSubPermutation )
{
  CERR( "P(B)�𖞂���A�̕�������B�̐����グ�́A" );
  CERR( "- n-1<=|S|<=max{j<=N|Q(j)}�𖞂���(0,1,...,N-1)�̕����W��S" );
  CERR( "- S�̒���n-1�̊e��������s" );
  CERR( "�ɑ΂���" );
  CERR( "�u�C�ӂ�0<=l<=|S|-n�ɑ΂�R_l(B)�𖞂����A����n-1����s�ɑΉ����A�v" );
  CERR( "�@�S�̂�S�ɑΉ�����A�̕�������B�̌�dp[S][s]�v" );
  CERR( "���Ǘ�����S,s�Ɋւ��铮�I�v��@���������܂��傤�B" );
  CERR( "" );
  CERR( "s�̖ԗ���[0,N)^{n-1}�̑S�T��ł�S���̏���T���ƒ萔�{�����ς��Ȃ��̂�" );
  CERR( "�����̑�����D�悵�܂��傤�B" );
  CERR( "" );
  CERR( "N���������ꍇ�͊T�Z�l" );
  CERR( "7! �� 5�~10^3" );
  CERR( "8! �� 4�~10^4" );
  CERR( "9! �� 4�~10^5" );
  CERR( "10! �� 4�~10^6" );
  CERR( "11! �� 4�~10^7" );
  CERR( "12! �� 5�~10^8" );
  CERR( "���Q�l�ɏ���̑S��" );
  CERR( "\\Mathematics\\Combinatorial\\Permutation" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "�K�X�����O�}�`�Ƃ̊֌W���������܂��傤�B" );
  CALL_AC( CountingYoundDiagram );
}

AC( CountingGeneralRelationSubArray )
{
  ASK_NUMBER( "�z��ւ̊i�[�����֌W����܂����H" );
  if( reply == "y" ){
    CERR( "���������\�����O���t�̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
    CALL_AC( CountingGraph );
  } else {
    CERR( "�i���d�j�W����\�[�g���ꂽ�z��̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
    CALL_AC( CountingSubset );
  }
}

AC( CountingSubArrayImageArray )
{
  CERR( "���͂ŗ^������z���A�ƒu���܂��B" );
  CERR( "�z��Ƃ��ē�����A�̕�����̂��������������ŏ��̂��̂𐔂��グ��" );
  CERR( "������DP���������܂��傤�B��̓I�ɂ�" );
  CERR( "�u��������i�����R���Ŏ������ŏ���A�̕�����̌�dp[i]�v" );
  CERR( "�us=A[j]�𖞂���j<i�̍ő�llast[i][s]�v" );
  CERR( "�̂Q���Ǘ�����i�Ɋւ��铮�I�v��@���������܂��傤�B" );
}

AC( CountingSubString )
{
  ASK_NUMBER(
	     "���������񂩂�擾�ʒu���𗎂Ƃ���������S�̂̐����グ���" ,
	     "�������v�Ɋւ��鐫���𖞂�������������̐����グ���" ,
	     "�����z�u�Ɋւ��鐫���𖞂�������������̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "������𕶎��̔z��Ƃ݂Ȃ����ƂŁA�z��̖��ɋA�������邱�Ƃ��ł��܂��B" );
    CALL_AC( CountingSubArrayImageArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingShapedSubString );
  }
}

AC( CountingMatchingSubString )
{
  CERR( "- �����ƃ}�b�`���O���镔��������̐����グ����Z�A���S���Y��" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- �񕶂ł��镔��������̐����グ����" );
  CERR( "  - O(N^2)���ʂ肻���Ȃ�΁A�ڎ��@�ɂ��O�v�Z" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)���ʂ�Ȃ������Ȃ�΁A�}�i�`���[�̃A���S���Y����" );
  CERR( "    ���[�����O�n�b�V���őO�v�Z" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "���������܂��傤�B" );
}

AC( CountingShapedSubString )
{
  CERR( "ABC�i�R�������قȂ�j��AAB�i�擪�Q��������v���R�����ڂ��قȂ�j�Ȃ�" );
  CERR( "�����z�u���w�肳�ꂽ����L�̕���������̐����グ��" );
  CERR( "- O(26^L N)���ʂ肻���Ȃ�ΎR�^�z��Ɠ��l��" );
  CERR( "  �ui�����ڂ܂łɒ���L�ȉ��̊e������s������������Ƃ��ďo�������dp[i][s]�v" );
  CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
  CERR( "- O(L 26^L log_2 N)���ʂ肻���Ȃ��" );
  CERR( "  �u�e2㰋��I�ɒ���L�ȉ��̊e������s������������Ƃ��ďo�������dp[I][s]�v" );
  CERR( "  ���Ǘ�����I�Ɋւ��镪�������@" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "���������@�ŗp����dp[I]�͕�����S�̂̂Ȃ����m�C�h�̃��m�C�h��" );
  CERR( "������z�u�̕s�K�؂ȕ������Ȃ��Ă������\�ȕ�����S�̂̐�������C�f�A����" );
  CERR( "�����ē��������̋󕶎���W����1�ł�����̑S�̂̂Ȃ������@���m�C�h��" );
  CERR( "�l����邽�߁A������m�C�h�Œ��ۉ��\��BIT��Z�O�����g�؂�p���邱�Ƃ��\�ł��B" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
}

AC( CountingPartitionOfTree )
{
  CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "F(P)���Œ肳�ꂽ����P�̐����グ����" );
  CERR( "�u��i�����܂łŐ؂�������F(P)=v�𖞂���P�̌�dp[i][v]�v" );
  CERR( "���Ǘ�����i,v�Ɋւ��铮�I�v��@�iO(N^2 v_max�~f�̌v�Z��)�j" );
  CERR( "���������܂��傤�B" );
}

AC( CountingSubset )
{
  ASK_YES_NO( "�v�f���󂯎��֐��̕����a���Œ肵�������W���̐����グ���ł����H" );
  if( reply == "y" ){
    CERR( "�v�f�ɔԍ���U��A�W����z��Ƃ݂Ȃ��ĕ����a���ɋA�������܂��傤�B" );
    CALL_AC( CountingSumFixedSubArray );
  } else {
    CERR( "�^����ꂽ�W���̃T�C�Y��N�ƒu���܂��B" );
    CERR( "- O(2^N)���Ԃɍ��������Ȃ�΁Abit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(N2^N)���Ԃɍ��������Ȃ�΁A�����W���̕�ܑ΂�bit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "���������܂��傤�B" );
  };
}

AC( CountingStrategy )
{
  ASK_NUMBER(
	     "�������W����̈ړ��o�H�̐����グ���" ,
	     "���삷��Ώۂ̑I����@�̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "- �P�̎n�_����̈ړ����l����ꍇ��" );
    CERR( "  �u�e�_i�ւ̈ړ��o�H�̌�dp[i]�v" );
    CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
    CERR( "- �P�̏I�_�ւ̈ړ����l����ꍇ��" );
    CERR( "  �u�e�_i����̈ړ��o�H�̌�dp[i]�v" );
    CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
  } else if( num == num_temp++ ){
    CERR( "����Ώۂ��e�񕉐���i�œK�؂ɔԍ��t����" );
    CERR( "�ui�ȉ��̔ԍ��̑Ώۂ݂̂��l�������̑I����@�̌�dp[i]�v" );
    CERR( "���Ǘ�����i�Ɋւ��铮�I�v��@" );
  }
  CERR( "���������܂��傤�B" );
  ASK_YES_NO( "���`�Q�����ɋA������܂����H" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
    CERR( "���������܂��傤�B" );
  }
}

AC( CountingPath )
{
  ASK_NUMBER(
	     "�i�q�_��̌o�H�̐����グ" ,
	     "��ʂ̃O���t��̌o�H�̐����グ" ,
	     );
  if( num == num_temp++ ){
    CERR( "�n�_����e�_�ւ̌o�H���Ɋւ���Q�����𗧎����܂��傤�B" );
    CERR( "�Ⴆ�΃p�X�J���̎O�p�`��̌o�H���́A���̂܂܃p�X�J���̎O�p�`�ŗ^�����܂��B" );
    CERR( "- �o�H��������s�ϗʂɂ݈̂ˑ�����ꍇ�A�s�ϗʂ��ƂɊǗ����Čv�Z�ʂ��팸" );
    CERR( "- �̈�ɑΏ̐�������ꍇ�A�n�_���炠��_p�ւ̌o�H����p�̑Ώ̓_����I�_�ւ̌o�H��" );
    CERR( "  �̊Ԃ̊֌W���𗧎�" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "�K�X�J�^�������⃄���O�}�`�Ƃ̊֌W���������܂��傤�B" );
    CALL_AC( CountingYoundDiagram );
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CERR( "���[�v�̕s�\�ȗL���O���t�͐��b�Ȃ̂ŁA�e�_p���Ƃ�" );
    CERR( "-�up���T�����ꂽ���v��\��bool�l�z��" );
    CERR( "-�up�ւ̕ӂ������T���_�̌��v��\���z��" );
    CERR( "���Ǘ��������҂�S�T�􂷂邱�Ƃ�O(|V|^2+|E|)�őS�Ă̓_��T���ł��܂��B" );
  }
}

AC( CountingTiling )
{
  CERR( "- �[�_��O���̃T�C�Y�����������^�C���^�F�̎�ސ������Ȃ��Ȃ�΁A" );
  CERR( "  �[�_��O���̃^�C�����O�^�h�蕪�����Œ肷�邱�Ƃŏ������T�C�Y�ɑ΂���" );
  CERR( "  �����グ�Ƃ̊֌W���𓱏o���A�T�C�Y�Ɋւ��铮�I�v��@" );
  CERR( "- �Q�̍�p�ɂ�铯�ꎋ������Ȃ�΁A�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "  https://ja.wikipedia.org/wiki/�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "���������܂��傤�B" );
}

AC( CountingYoundDiagram )
{
  CERR( "�W�������O�^�u���[�̌��̓t�b�N�������Ōv�Z�ł��܂��B" );
  CERR( "\\Mathematics\\Combinatorial\\YoungDiagram\\a.hpp" );
  CERR( "- 2�~n�̕W�������O�^�u���[�Ƒ�n�J�^�������̊֌W" );
  CERR( "- RS�Ή��i�^�̓����������O�^�u���[�Ə���̑Ή��j" );
  CERR( "  https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence" );
  CERR( "- ���W�������O�^�u���[�Ɣ�����ȃp�X�̑g�Ƃ̑Ή�" );
  CERR( "���������܂��傤�B")
}

AC( CountingParenthesisSequence )
{
  CERR( "��n�J�^������Cn��(2n)!/(n+1)!n!�ł��B" );
  CERR( "- n�΂̃J�b�R��ł����đS�ẴJ�b�R����������" );
  CERR( "- 2n�����̑��a��0�ō��[����̎n�[�a���񕉂ȁ}1��" );
  CERR( "- n�m�[�h�̓񕪖�" );
  CERR( "- n�~n�i�q�ō�������E��܂őΊp�����ׂ����ŏ��ɉE�֍s���ŒZ�o�H" );
  CERR( "- 2�~n�̕W�������O�^�u���[�i�s�^��Ƃ��ɋ��`�P������ɂȂ�悤�Ȕԍ��Â��j" );
  CERR( "- �~���n���_�̑��p�`����" );
  CERR( "- �~���n+2�p�`�̎O�p�`����" );
  CERR( "- �~���2n���_�̔����������2�Ȗ����ӂ̒����" );
  CERR( "�̐����グ�Ȃǂ�Cn�ƈ�v���܂��B" );
  CERR( "https://en.wikipedia.org/wiki/Catalan_number#Applications_in_combinatorics" );
}

AC( Solving )
{
  ASK_NUMBER(
	     "�P�̕�����f(g(x),g(y),...) = c" ,
	     "M�̕�����f(x[a[i]],C^{d[i]}x[b[i]]) = c[i]" ,
	     "M�̕�����sum_{j=a[i]}^{b[i]} C^{j-a[i]} x[j] = c[i]" ,
	     "���̑��̕�����"
	     );
  if( num == num_temp++ ){
    CERR( "f,g��ʁX�Ɉȉ��̎菇�őO�v�Z" );
    CERR( "- �܂��eb in im(g)�ɑ΂�f(a,b) = c�𖞂���a in im(g)�S�̂�O�v�Z����B" );
    CERR( "- ����|dom(g)| = N�Amax im(g) = M�Ƃ��āA�ey in im(g)�ɑ΂���" );
    CERR( "  �t���̑�\�����Ǘ�����g_inv[y]��" );
    CERR( "  - O(N)���Ԃɍ��������Ȃ��unordered_map::g_inv[g[x]]=x" );
    CERR( "  - O(M+N)���Ԃɍ��������Ȃ�Δz��::g_inv[g[x]]=x" );
    CERR( "  - x,y�ɐ���h(x)<h(y)������ꍇ��h(x)�̏��c�ɂ��ă��[�v����" );
    CERR( "    g_inv[g(x)]=x���Ă����A����ƕ��s����y��c<h(y)�͈̔͂őS�T��" );
    CERR( "  �ɂ��Ǘ�����B" );
    CERR( "- �Ō�Ɋey���Ƃ�f(a,g(y)) = c�𖞂����ea in im(g)�ɑ΂�a = g(x)�𖞂���" );
    CERR( "  x��g_inv[a]�Ƃ��ė^����B" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "�ݐϘasum_{j=i}^{N} C^{j-i} x[j]��V���ɕϐ�X[i]�ƒu�����Ƃ�" );
    CERR( "M�̕�����X[a[i]]-C^{b[i]-a[i]+1}X[b[i]+1] = c[i]" );
    CERR( "�ɋA������܂��B�����f(x,y)=x-y�ƒu����" );
    CERR( "M�̕�����f(X[a[i]],d^{b[i]-a[i]+1}X[b[i]+1]) = c[i]" );
    CERR( "�ɑ��Ȃ�܂���B" );
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "- �P���֐��͓񕪒T��" );
    CERR( "- �����֐��̓j���[�g���@" );
    CERR( "- �A���ꎟ�������͑|���o���@" );
    CERR( "- �ϐ��̈ˑ��֌W���H�������Ȃ��Ȃ�΋t���Ɍ���" );
    CERR( "���������܂��傤�B" );
  }
}

AC( SolvingBinaryEquations )
{
  CERR( "f(x,C^j -)��f(-,C^j y)���P�˂ł���Ƃ��܂��B" );
  CERR( "- O(BMf(BN) + BN log B)���Ԃɍ��������Ȃ�Αf�W���f�[�^�\��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "- O(BM + BN log B)���Ԃɍ��������Ȃ�Ε��^�[���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst" );
  CERR( "- O(Mf(N) + N)���Ԃɍ���������f(x,y)=x-y����C=1�Ȃ��" );
  CERR( "  �|�e���V�����t���f�W���f�[�^�\��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "���������܂��傤�B" );
}

AC( Query )
{
  ASK_NUMBER(
	     "�z��͈͍̔X�V�^�擾�N�G�����" ,
	     "�؂͈͍̔X�V�^�擾�N�G�����" ,
	     "�O���b�h�͈͍̔X�V�^�擾�N�G�����" ,
	     "��ʂ̃O���t�͈͍̔X�V�^�擾�N�G�����" ,
	     "������͈͍̔X�V�^��r�N�G�����" ,
	     "�W���͈͍̔X�V�^��r�N�G�����" ,
	     "2�ϐ��֐��̌v�Z�N�G�����" ,
	     "���n��f�[�^�̃N�G�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QueryString );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTwoAryFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTime );
  }
}

AC( QueryArray )
{
  CERR( "�z���̃N�G���Ɛ����I�ȑ㐔�\�������t���邽�߂ɂ́A" );
  CERR( "��Ԏ擾�N�G�����Q�̋�Ԃ̃f�[�^����v�Z���A�K�v�ȃf�[�^����肵��" );
  CERR( "�����̉��Z���v�Z���܂��傤�B" );
  ASK_NUMBER(
	     "���Q�\��+���g�����" ,
	     "��㰓����m�C�h�\���ɂ��g�����" ,
	     "���m�C�h�\��*���g�����" ,
	     "�񌋍��I�}�O�}�\��*���g�����" ,
	     "�W���ւ̃}�O�}��p(*,\\cdot)���g�����" ,
	     "�W���ւ̉��}�O�}��p(*,\\cdot)���g�����" ,
	     "���m�C�h�ւ̃}�O�}��p(+,\\cdot)���g�����" ,
	     "�������������" ,
	     "���̗v�f�����������" ,
	     "�ꎟ�֐��Ƃ�max��������l���g�����" ,
	     "�萔�Ƃ�max��������l�̋�ԉ��Z�擾���g�����" ,
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArrayAbelianGroup );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayCommutativeIdempotentMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayNonAssociativeMagma );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayCommutativeMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxLinearFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxConstant );
  }
}

AC( QueryArrayAbelianGroup )
{
  CERR( "- ���Z�^�S�X�V��̈�_�擾O(1)�݂̂��K�v�Ȃ�ΊK������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- ���Z�^�S�X�V�Ȃ��ŋ�Ԏ擾O(1)�݂̂��K�v�Ȃ�Ηݐϐ�" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "- ��_���ZO(log N)�^��_���O(log N)�^��Ԏ擾O(log N)���K�v�Ȃ��BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- ��ԉ��ZO(log N)�^��_���O(log N)�^��Ԏ擾O(log N)���K�v�Ȃ��" );
  CERR( "  ��ԉ��ZBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\InteralAdd" );
  CERR( "- ��_���ZO(1)�^��_���O(��N)�^��Ԏ擾O(��N)���K�v�Ȃ�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition" );
  CERR( "- ��_���ZO(1)�^��ԉ��ZO(��N)�^��_���O(1)�^��_�擾O(1)���K�v�Ȃ��" );
  CERR( "  ���o�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "- ��_���ZO(1)�^��ԉ��ZO(��N)�^��_���O(1)�^��_�擾O(1)�^��Ԏ擾O(��N)" );
  CERR( "  ���K�v�Ȃ�΋�ԉ��Z��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\IntervalAdd" );
  CERR( "- ��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ�Βx����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "- ��ԉ��ZO(��N)�^��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ��" );
  CERR( "  ��ԏ�Z�x����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation\\IntervalMultiply" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayCommutativeIdempotentMonoid )
{
  CERR( "- ��_��ZO(log N)�^��_���O((log N)^2)�^��Ԏ擾O(log N)���K�v�Ȃ��" );
  CERR( "  ���maxBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- ��_��ZO(1)�^��ԏ�ZO(��N)�^��_���O(��N)�^��_�擾O(1)���K�v�Ȃ��" );
  CERR( "  ���o�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMonoid )
{
  CERR( "- ��_���O((log N)^2)�^��Ԏ擾O(log N)���K�v�Ȃ�΃��m�C�hBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "- ��_��ZO(1)�^��_���O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ��" );
  CERR( "  ���m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "- ��_��ZO(1)�^��ԏ�ZO(��N)�^��_���O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)" );
  CERR( "  ���K�v�Ȃ�΋�ԏ�Z���m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalMultiply" );
  CERR( "- ��_���O(log N)�^��Ԏ擾O(log N)���K�v�Ȃ�΃Z�O�����g��" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayNonAssociativeMagma )
{
  CERR( "- �ʑ��̃R�[�h���ɂ�郂�m�C�h�ւ̋A��" );
  CERR( "  \\Mathematics\\Function\\Encoder" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "���m�C�h�ɑ΂��Ă�" );
  CALL_AC( QueryArrayMonoid );
}

AC( QueryArrayMagmaSet )
{
  CERR( "- ��ԍ�pO(��N)�^��_���O(��N)�^��_�擾O(1)���K�v�Ȃ�Αo�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayCommutativeMagmaSet )
{
  CERR( "- ��ԍ�pO(��N)�^��_���O(��N)�^��_�擾O(1)���K�v�Ȃ�Αo�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "- ��_��pO(1)�^��ԍ�pO(��N)�^��_���O(��N)�^��_�擾O(1)���K�v�Ȃ��" );
  CERR( "  ���o�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMagmaMonoid )
{
  CERR( "- ��ԍ�pO(��N)�^��ԏ�ZO(��N)�^��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)" );
  CERR( "  ���K�v�Ȃ�Βx���]����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayCommutativeMagmaMonoid )
{
  CERR( "- ��ԍ�pO(��N)�^��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ��" );
  CERR( "  �x���]����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "- ��ԍ�pO(��N)�^��ԏ�ZO(��N)�^��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)" );
  CERR( "  ���K�v�Ȃ�΋�ԏ�Z�x���]����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayOrder )
{
  CERR( "- �n�ؕГ��ł̈�_�����擾O(log N)�^���������l�擾O(log N)���K�v�Ȃ��" );
  CERR( "  �E�[�̑傫���ŃN�G�����\�[�g����BIT�ő����Ǘ���" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - ��_�����擾�͕��ʑ���" );
  CERR( "  - ���������l�擾�͕��ʑ����{�񕪒T��" );
  CERR( "- ��Ԃł̏��������_�擾O(ord log N)���K�v�Ȃ�΋��maxBIT��" );
  CERR( "  ��ԍő�^�ŏ��l�{�񕪒T���ŋ�Ԃ𕪊�" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayImageSize )
{
  CERR( "- ��Ԃł̑��̗v�f���擾���K�v�Ȃ�Δ��̃A���S���Y��" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- �ꎟ�֐��ɂ��S��max�X�VO(log N)�^��_�擾O(log N)���K�v�Ȃ��" );
  CERR( "  Convex Hull Trick" );
  CERR( "  \\Mathematics\\Function\\MaxLinearFunction" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMaxConstant )
{
  CERR( "max�őS�̍X�V�����Ȃ��ꍇ�A�܂肽���z��ƒ萔��max�̋�ԉ��Z��" );
  CERR( "�������邾���̏ꍇ�A�N�G���̏��Ԃ����ւ��邱�ƂőS�̍X�V������ꍇ��" );
  CERR( "�A���ł��܂��B�]���Ĉȉ��ł͑S�̍X�V�̖����l���܂��B" );
  CERR( "" );
  CALL_AC( QueryTimeMax );
}

AC( QueryTree )
{
  CERR( "- ���Q�\���Ɋւ�����ZO(1)�^�S�X�V��̈�_�擾O(1)���K�v�Ȃ�ΊK������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- ���Q�\���Ɋւ���͈͎擾O(1)�݂̂��K�v�Ȃ�ΗݐϘa" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\Tree" );
  CERR( "- �����m�C�h�\���Ɋւ��镔���؂ł̑���O(N)���K�v�Ȃ�ΑS���DP" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
  CERR( "- ���m�C�h�\���Ɋւ���p�X�ł̑���O(log N)���K�v�Ȃ�Ώd�ݕt��LCA" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree\\Weighted" );
  CERR( "���������܂��傤�B" );  
}

AC( QueryGrid )
{
  CERR( "- ���Q�\���Ɋւ�����ZO(1)�^�S�X�V��̈�_�擾O(1)���K�v�Ȃ�Γ񎟌��K������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����ZO(1)�^�S�X�V�Ȃ��̋�`�擾O(1)���K�v�Ȃ�Γ񎟌��ݐϘa" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����ZO(1)�^�S�X�V��̋�`�擾O(1)���K�v�Ȃ�Γ񎟌��K�������" );
  CERR( "  �񎟌��ݐϘa�̕��p" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- �����v�Z�������ɉ\�Ȃ�Δ��̃A���S���Y��" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "���������܂��傤�B" );
}

AC( QueryGraph )
{
  CERR( "�O���t�̒��_����V�A�ӂ̖{����E�A�N�G������Q�ƒu���܂��B" );
  CERR( "- �ӂ̒ǉ���O(V+(E+Q)��(V))���Ԃɍ��������Ȃ��UnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "- �ӂ̍폜��O(V+E��(V))���Ԃɍ��������Ȃ�΃N�G���t�ǂ݂�UnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "- ����̕ӂ��܂ލŏ��S��X�擾��O((V+Q)log V + E log E)���Ԃɍ��������Ȃ��" );
  CERR( "  �S�̂ɑ΂���ŏ��S��X���N���X�J���@�őO�v�Z���d�ݕt��LCA�ɂ��" );
  CERR( "  �ő�R�X�g�ӌv�Z" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest\\Kruscal" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree\\Weighted" );
  CERR( "- �ӏW���̍ʐF��ς����ŏ��S��X�擾��O(V + E log E + Q��(V))���Ԃɍ�������" );
  CERR( "  �Ȃ�ΑS�̂ɑ΂���ӂ̃\�[�g��O�v�Z���N���X�J���@�̔���" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\UnionFindForest\\Kruscal" );
  CERR( "���������܂��傤�B" );  
}

AC( QueryString )
{
  CERR( "������̈�_�X�V�i�ꕶ���X�V�^�����j�^��r�̓��[�����O�n�b�V��" );
  CERR( "\\Utility\\String\\RollingHash" );
  CERR( "���������܂��傤�B����ɕ�����͈͍̔X�V���K�v�ȏꍇ��" );
  CERR( "- �Œ�ʒu�̕����̃V�t�g�ɂ��ꕶ���X�V�Ȃ�Ή��Z�X�V" );
  CERR( "- �����Ȃ�Ή��Z�X�V�Ə�Z�ɂ���p�X�V" );
  CERR( "�ɑΉ�����f�[�^�\���Ƃ̕��p���������܂��傤�B" );
}

AC( QuerySet )
{
  CERR( "�W���̈�_�X�V�i��v�f�X�V�^�Ώ̍��j�^��r�̓]�u���X�g�n�b�V��" );
  CERR( "\\Utility\\Set\\ZobristHash" );
  CERR( "���������܂��傤�B����ɏW���͈͍̔X�V���K�v�ȏꍇ��" );
  CERR( "- �Œ�v�f�̗L���̔��]�ɂ���_�X�V" );
  CERR( "- �Ώ̍�" );
  CERR( "�Ƃ��ɉ��Z�X�V�ɑΉ�����f�[�^�\���Ƃ̕��p���������܂��傤�B" );
}

AC( QueryTwoAryFunction )
{
  CERR( "- ���Q�ɒl�����z��͈͎̔擾�͗ݐϐ�" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct" );
  CERR( "- �Б�������O(1)�Ōv�Z�ł���2�ϐ��֐��̌v�Z�͔��̃A���S���Y��" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "���������܂��傤�B" );
}

AC( QueryTime )
{
  ASK_NUMBER(
	     "max�ɂ�鎞�n��X�V" ,
	     "���Z�ɂ�鎞�n��X�V"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTimeMax );
  } else {
    CALL_AC( QueryTimeAddition );
  }
}

AC( QueryTimeMax )
{
  ASK_NUMBER(
	     "�S��max�X�V�^���max�擾" ,
	     "�͈�max�X�V�^��_�擾"
	     );
  if( num == num_temp++ ){
    CERR( "�^����ꂽ�z���(A_i)_i�A�N�G���őS��max�X�V�����l��(M_q)_q�A" );
    CERR( "�N�G���ŋ�ԉ��Z�����͈͂�(I_q)_q�A�ƒu���܂��B" );
    CERR( "- (A_i)_i�ŏ��������ꂽ�z��(a_i)_i�i�����̓s���B���ۂ�(A_i)_i���g���j" );
    CERR( "- (A_i,i)_i���\�[�g�����z��A'�i�\�zO(N log N)�j" );
    CERR( "- 0�ŏ��������ꂽ{0,1}�l�z��(B_i)_i�i�\�zO(N)�j" );
    CERR( "- (A_i)_i��(M_q)_q�̍ŏ��l��菬�����l�ŏ��������ꂽ�����ϐ�M" );
    CERR( "��p�ӂ��܂��B" );
    CERR( "" );
    CERR( "�eq���ƂɁA�ȉ��̏������s���܂��F" );
    CERR( "- M < M_q�Ȃ�΁A�ȉ��̏������s���F" );
    CERR( "  - M��M_q�ɕύX����B" );
    CERR( "  - A'�̐擪(x,i)��x < M�𖞂�������ȉ��̏������J��Ԃ��F" );
    CERR( "    - a_i����ԉ��Z�̒P�ʌ��ɕύX����B�i�N�G�����vO(N log N)�j" );
    CERR( "    - B_i��1�ɕύX����B�i�N�G�����vO(N log N)�j" );
    CERR( "    - A'����(x,i)���폜����B�i�N�G�����vO(N log N)�j" );
    CERR( "- �ei in S�ɑ΂���max(A_i,M)��" );
    CERR( "  - ��Ԙa���K�v�Ȃ��a_i+B_i*M" );
    CERR( "  - ��Ԑς��K�v�Ȃ��a_i*M^{B_i}" );
    CERR( "  �ɓǂݑւ���I_q�ł̋�ԉ��Z�擾������B�i�e�N�G��O(log N)�j" );
    CERR( "����ɂ�荇�vO((N + Q)log N)�ŏ����ł��܂��B" );
  } else {
    CERR( "����t�ɂ������i������A[t][i]�ƒu���܂��B" );
    CERR( "A[-][i]���P�����傷�邱�Ƃɒ��ڂ���x��A[t][i]>=x�𖞂������������肵�A" );
    CERR( "���̂悤��x�̍ő�l�𖾎����ŏ��������܂��傤�B" );
    CERR( "" );
    CERR( "A[t][i]�̖�������max�������ꍇ�͏ꍇ������max���O���A" );
    CERR( "���ꂼ��̏ꍇ�̒l���e��f�[�^�\���ŏ������܂��傤�B" );
  }
}

AC( QueryTimeAddition )
{
  CERR( "��i�������ω����������Ԃ����̌���I�ƒu���܂��B" );
  CERR( "�e��Ԃ��X�ɕω��̎d���̈Ⴂ�ōו��������̂̌���J�ƒu���܂��B" );
  CERR( "- J��O(N)�Ȃ�Ίe�ו��ł̕ω��ʂ����߂܂��傤�B" );
  CERR( "- J��O(N)�łȂ�I��O(N)�Ȃ�Ίe��Ԃł̕ω��ʂ����߂܂��傤�B" );
  CERR( "�ω��ʂ̌v�Z��" );
  CERR( "- �K�������ݐϘa��BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- �C�x���g�\�[�g" );
  CERR( "���������܂��傤�B" );
}

AC( Decision )
{
  ASK_NUMBER(
	     "0���A�������" ,
	     "�����A�������" ,
	     "�K�������" ,
	     "���B�\�����" ,
	     "�`��\�����" ,
	     "���ݔ�����" ,
	     "�[���\�����" ,
	     "��v������" ,
	     "�\���\�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionHigherConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionExistence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionCoincidence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  }
}

AC( DecisionConnectedness )
{
  CERR( "���D��T����UnionFind" );
  CERR( "\\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "\\Mathematics\\Geometry\\Graph\\UnionFindForest" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
}

AC( DecisionHigherConnectedness )
{
  CERR( "- ���A��������͐[���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst" );
  CERR( "- �����z�����W�[�v�Z�͓K���Ȗ@�ł̑|���o���@" );
  CERR( "���������܂��傤�B" );
}

AC( DecisionGame )
{
  ASK_NUMBER(
	     "����̌p����ڎw���Q�[��" ,
	     "���_�̑召�������Q�[��"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionContinuingGame );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "����񐔂����Ȃ����s���������ł����H" );
    if( reply == "y" ){
      CERR( "�ǖʂ̑Ώ̐��Ȃǂɒ��ڂ��ē��l�ȋǖʂ𓯈ꎋ���A" );
      CERR( "���ꂼ��ɂ��Ă���ݒׂ��ɏ��s���l�@���Ă݂܂��傤�B" );
    } else {
      CERR( "�Q�v���C���[�̓��_�����P�̓_���Ƃ݂Ȃ��A���̍ő剻���s���܂��傤�B" );
      CALL_AC( ConstructionMaximisation );
    }
  }
}

AC( DecisionContinuingGame )
{
  CERR( "�܂��Q�[�����Ȃ�ׂ��ȒP�Ȑݒ�ɓ��l�ό`���܂��傤�B" );
  CERR( "- �P�������͊K�������܂��傤�B" );
  CERR( "- �ǂ��s�ϗʂ�T���A�s�ϗʂ�ς��Ȃ��悤�ȉ��V���\�ȑ���𖳎����邱�Ƃ�" );
  CERR( "  �s�ϗʂ̐��ڂ݂̂��ώ@���܂��傤�B�Ⴆ�Έȉ��̕s�ϗʂɒ��ڂ��܂��傤�B" );
  CERR( "  - ���炩�̐��l�̓K���Ȗ@�ł̒l" );
  CERR( "  - ����̓񕔃}�b�`���O��ł̊e�g���ł̉��炩�̐��l�i���B���Ȃǁj�̋��" );
  CERR( "    - �O���b�h�ŁA�P��̈ړ��ňڂ荇����Q�}�X�̑g�ɂ��^�C�����O" );
  CERR( "    - �z��ŁA�P��̑���ŉe�����󂯂鐬������ɂQ�Ȃ�΁A���̂悤��" );
  CERR( "      �Q�������ɂ��^�C�����O" );
  CERR( "  - ���鐬���𖳎����铯�l�֌W�ł̏�]��" );
  CERR( "  - ���ɓ����Ă���s�ϗʂ�ς��Ȃ�����ŉ��V�ł��鑀��𖳎����铯�l�֌W" );
  CERR( "���̌�A�Q�[���̐����ɒ��ڂ��ēT�^�l�@�ɋA�������܂��傤�B" );
  CERR( "- �Q�[���̘a�ɕ����ł���Ȃ�΁A�ŏ��P�ʂ�Ȃ�ׂ��������P�ʂ�" );
  CERR( "  �l�@�����܂��傤�B" );
  CERR( "  - ������̏�Ԑ���J�ډ񐔏�������Ȃ��Ȃ�Ȃ�΁A�O�����f�B����" );
  CERR( "    �v�Z���܂��傤" );
  CERR( "    \\Utility\\Set\\Mex" );
  CERR( "  - ������̏��s�̎������������ł������Ȃ�΁A���b�\����T���ď�������" );
  CERR( "    ���������Ɏ��������܂��傤�B" );
  CERR( "  - ������̏��s�̎������������ł��Ȃ������Ȃ�΁A��v�Z�ł̎�������" );
  CERR( "    �l�@�R�ꂪ�����₷���̂ő��̍l�@��D�悵�܂��傤�B" );
  CERR( "- ��肵���\�łȂ��J�ڂł����đ��̂ǂ̑J�ڂւ��o�R�ł�����̂�����Ȃ��" );
  CERR( "  strategy-stealing argument" );
  CERR( "  https://en.wikipedia.org/wiki/Strategy-stealing_argument" );
  CERR( "- �����I�ȑS�����\��������Ȃ�΁A���s�ŋ�Ԃ�A�������ɕ���" );
  CERR( "���������܂��傤�B" );
}

AC( DecisionAccessibility )
{
  CERR( "�ړ��̑O��ŕω����Ȃ��l������ꍇ�A���̒l���������_�ɍi���čl���܂��傤�B" );
  ASK_NUMBER(
	     "��`�̈�̓��B�\���i���H�j���" ,
	     "�O���t��̓��B�\�����" ,
	     "�S�_�ԗ��\�����"
	     );
  if( num == num_temp++ ){
    CERR( "���H�̍U���\����" );
    CERR( "- �X�^�[�g�ƃS�[��������̌ʏ�A�������ɑ�������" );
    CERR( "- �X�^�[�g�ƃS�[���𕪒f����ǂ̃p�X�̔񑶍ݐ�" );
    CERR( "�Ȃǂɖ|�󂵃O���t��̍ŏ��R�X�g�ړ����ɋA�������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "�O���t��̍ŏ��R�X�g�ړ����ɋA�������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "�ړ��̑O��ŕω����Ȃ��l������ꍇ�A���̒l���������_�ɍi���čl���܂��傤�B" );
    CERR( "- �̈�ƈړ��ɑΏ̐�������Ȃ�΁A�^�C�����O�ƃ}�b�`���O" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
    CERR( "- O(N^3)���ʂ肻���ōė��K�����e����Ȃ�΁A���[�V�����t���C�h�@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
    CERR( "���������܂��傤�B" );
  }
  CERR( "" );
}

AC( DecisionDrawability )
{
  CERR( "- �T�C�Y�Œ�̐}�`�ɂ��`��\�����l����ꍇ�́A" );
  CERR( "  �}�`��K�v�Ȃ�Ή�]��������ŁA�}�`���������̋�`�̈�̘a�W���ɕ������A" );
  CERR( "  �`��̈���ɐ}�`��u���邩�ۂ���}�`�̈ʒu���ƂɂQ�����ݐϘa��؏�̗ݐϘa�Ȃǂ�" );
  CERR( "  ����" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProduct\\Tree" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProduct\\TwoDimensional" );
  CERR( "- �T�C�Y�ς̐}�`�ɂ��`��\�����l����ꍇ�́A" );
  CERR( "  �`��̈���ɐ}�`��u����T�C�Y�̍ő�l��}�`�̈ʒu���ƂɎڎ��@�ȂǂŌv�Z" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "�`��̈���ɂǂ̂悤�ɐ}�`��u���������߂���́A�Q�����K�������X��̊K������Ȃǂ�" );
  CERR( "���ۂɕ`������A�`�悵�����}�`�ƈ�v���邩�𔻒肵�܂��傤�B" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
}

AC( DecisionExistence )
{
  ASK_NUMBER(
	     "���̕������̉��̑���" ,
	     "F_2��̕������̉��̑���" ,
	     "�P���ȏ����𖞂�������z��╶����̑���" ,
	     "�����͈͂̋����ϐ��̑g�ݍ��킹�ŕ\����T�O�̑���" ,
	     "�o�H�̑���" ,
	     "�`����@�̑���" ,
	     "����x�N�g���̕\�����@�̑���" ,
	     "�W���̕������@�̑���"
	     );
  if( num == num_temp++ ){
    CALL_AC( Solving );
    CERR( "" );
    CERR( "�������̐�������Ȃ�����ɕψ�ɐ���������ꍇ�A�m�肵�Ȃ��ϐ�x��p����" );
    CERR( "���̕ϐ���\���A�e��������x�̕s�����ɖ|�󂵂ĕψ�̔�󔻒�����܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "bool�l�̕������͖���̏[���\���ɋA�������܂��傤�B" );
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CERR( "�ϐ��̑g�ݍ��킹�ŕ\���đS�T����������܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPartition );
  }
}

AC( DecisionSatisfiability )
{
  ASK_NUMBER(
	     "����_���̏[����������" ,
	     "�񕔃O���t�̏[���\�����"
	     );
  if( num == num_temp++ ){
    CERR( "�e����ϐ��̐^���l�𒸓_�Ƃ���O���t���l���A��������ɋA��������" );
    CALL_AC( DecisionConnectedness );
    CERR( "" );
    CERR( "��ԏ����ɂ��^���l�X�V�͊e��㐔�I�f�[�^�\����p���܂��傤�B" );
    AC( QueryArray );
  } else if( num == num_temp++ ){
    CERR( "���S�񕔃}�b�`���O����͍ő�񕔃}�b�`���O�ɋA��������" );
    AC( MaximisationBipartiteMatching );
  }
}

AC( DecisionCoincidence )
{
  CERR( "- ������̈�v����̓��[�����O�n�b�V��" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- ����������Ƃ̈�v�����Z�A���S���Y��" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- �W���̈�v����̓]�u���X�g�n�b�V��" );
  CERR( "  \\Utility\\Set\\ZobristHash" );
  CERR( "- ���d�W���̈�v����͏d���x��pair�ɂ��ďW���̈�v����ɋA��" );
  CERR( "- �z��̕��ъ����ɂ���v�����" );
  CERR( "  - �e�O����O(����log����)���Ԃɍ��������Ȃ�΃\�[�g����̕������v����ɋA��" );
  CERR( "  - �e�O����O(����log������ސ�)���Ԃɍ��������Ȃ�Α��d�W���̈�v����ɋA��" );
  CERR( "���������܂��傤�B" );
}

AC( DecisionPresentability )
{
  ASK_NUMBER(
	     "�P��̉��Z�ɂ��\���\���i���������}�O�}���j" ,
	     "�����̉��Z�ɂ��\���\���i�e���p�Y�����j"
	     );
  if( num == num_temp++ ){
    CERR( "���Q�̗v�f�́A���f������Ȃ�ɏ������n�̗v�f�̘a�ŕ\���܂��B" );
    CERR( "- ���f���̘a�ŕ\���Ȃ�΁A���Q���������̉���Ԃŗ^������ꍇ�ɂ�" );
    CERR( "  Q�̒��a�ɖ��ߍ��߂Ή���1/n�����ł��邱�Ƃɒ��ڂ��A�����͈̔͂ł̏���" );
    CERR( "  ���܂��[���𑵂��ĉ����\���ł��邩������܂���B" );
    CERR( "- ����f���̘a�ŕ\���Ȃ�΁AKlove����ŕK�v�ȑf���̌������ς�܂��傤�B" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\KloveSequence\\a.hpp" );
    CERR( "- ���𑽊p���̘a�ŕ\���Ȃ�΁A�񕽕��藝�Ȃǂ��Q�l�ɂ��܂��傤�B" );
    CERR( "  https://ja.wikipedia.org/wiki/��̕������̘a#�f���ɂ��Ă̏ؖ�" );
    CERR( "  https://ja.wikipedia.org/wiki/�O�̕������̘a#�ؖ�" );
    CERR( "  https://ja.wikipedia.org/wiki/�l�����藝#���O�����W���̎l�����藝�̏ؖ�" );
    CERR( "  https://ja.wikipedia.org/wiki/���p���藝#�ؖ�" );
  } else if( num == num_temp++ ){
    CERR( "- �������I�Ɋ֐��^���Z����������ꍇ��" );
    CERR( "  �u��i�����^�����܂łőł��؂������ɕ\���ł�����̑S�̂̏W��dp[i]�v" );
    CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
    CERR( "- �֐��^���Z�̓K�p���@�ɂ��I��������ꍇ��2����I��œK�p������" );
    CERR( "  ���ʓ����鐔�^������̍ċA�I�ȑS�T��" );
  }
  CERR( "���������܂��傤�B" );
}

AC( Construction )
{
  CERR( "���ݒ藝�ɋA���ł�����͍\���I�ؖ����������܂��傤�B" );
  ASK_NUMBER(
	     "����z��╶����̍\�z" ,
	     "�������̉��̍\�z" ,
	     "�ʑ��̍\�z" ,
	     "�o�H�̍\�z" ,
	     "�K���헪�̍\�z" ,
	     "�ő剻�헪�̍\�z" ,
	     "�O���b�h����̍\�z" ,
	     "����x�N�g���̕\�����@�̍\�z" ,
	     "�W���̕������@�̍\�z" ,
	     "�\�[�X�R�[�h�̍\�z"
	     );
  if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMap );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPath );
  } else if( num == num_temp++ ){
    CERR( "�Q�[���̖��ɋA�������܂��傤�B" );
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMaximisation );
  } else if( num == num_temp++ ){
    CERR( "HW���������P�[�X�����Ƃ܂��͑S�T��ŋ��߁A" );
    CERR( "�����̔������������܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPartition );
  } else if( num == num_temp++ ){
    CERR( "�������o�͂�����\�[�X�R�[�h���o���܂��傤�B" );
  }
}

AC( ConstructionArray )
{
  CERR( "p�i�@��K������ւ̖|����������܂��傤�B" );
}

AC( ConstructionMap )
{
  CERR( "- �P�˂̍\�z�ɂ�Hall�̌����藝" );
  CERR( "  https://ja.wikipedia.org/wiki/�z�[���̒藝" );
  CERR( "- �S�P�˂̍\�z�ɂ̓z�b�v�N���t�g�J�[�v�@��J���g�[���x�����V���^�C���̒藝" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
  CERR( "  https://ja.wikipedia.org/wiki/�x�����V���^�C���̒藝#�ؖ�" );
  CERR( "- �S�˂̍\�z�ɂ͕����W���𐧌����đS�P�˂̍\�z�̔���" );
  CERR( "���������܂��傤�B" )
}

AC( ConstructionPath )
{
  ASK_NUMBER(
	     "�ŒZ�o�H�̍\�z" ,
	     "�O���b�h��̏���Z�[���X�}�����ɑ΂���ǂ����̍\�z"
	     );
  if( num == num_temp++ ){
    CERR( "�\�Ȍo�H�̒�߂�O���t�̖��ɋA�������܂��傤�B" );
    CALL_AC( DecisionAccessibility );
  } else {
    CERR( "���̃A���S���Y���ɂ��\�[�g" );
    CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
    CERR( "���������܂��傤�B" );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "���삲�ƂɌ��܂�l���ő剻���邽�߂ɂ́A����̐��b�ȕό`�菇�ł�����" );
  CERR( "�l�����炳�Ȃ����̂�T���A���̕ό`�����S�ɍs���ē����鑀��݂̂�" );
  CERR( "�i���čl���܂��傤�B" );
  CALL_AC( Maximisation );
}

AC( ConstructionPartition )
{
  CERR( "�W���╶�����z��̕����͎ʑ��̈��ł��B" );
  AC( ConstructionMap );
}

AC( Deduction )
{
  CERR( "���A�N�e�B�u���Ŏ��������ۂ�" );
  CERR( "- ���炩�̏����ɂ�����ɑ匳�ɐG��長����" );
  CERR( "- �Ȃ�ׂ������̐��l�Ɉˑ�������ɐG��長����" );
  CERR( "- N^2�̐��l�ɑ΂���O(N)��̎���ł͑Ίp���ɐG��長����" );
  CERR( "���������܂��傤�B" );
}

