// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void AutoCheck( int& exec_mode )
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
    CERR( "- while���[�v�œY�����̍X�V�Y��ɂ�閳�����[�v�͂���܂��񂩁H" );
    CERR( "- cerr�̏����Y��͂���܂��񂩁H" );
    CERR( "- �d�߂���萔�{���l�����Y��Ă܂��񂩁H" );
    CERR( "  - bool�l�̏�����bit���Z�ɂ�����" );
    CERR( "  - �ϐ��̘a��ςɏ��������O���b�h���͓��I�z��" );
    CERR( "  ���������܂��傤�B" );
    CERR( "- �O�v�Z�ł��鏈�����J��Ԃ��Ă܂��񂩁H" );
    CERR( "  - �e(i,j)���Ƃ�S_ij���\�z�������Ɋei���Ƃ�S_i���\�z����S_i��S_j��" );
    CERR( "    S_ij��O(1)�ō\�z���邱�Ƃ��������܂��傤�B" );
    CERR( "- ���A�N�e�B�u����flush�Ɖ��s�����Y��Ă��܂��񂩁H" );
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
  CERR( "- �ϐ����̏Փ˂����Ǐ��ϐ��ɂ��铽�����󂯂Ă��܂��񂩁H" );
  CERR( "- �덷�]�������Y��Ă��܂��񂩁H" );
  CERR( "  - �����^�ւ̃L���X�g���̐؂�̂Ă��K�؂����m�F���܂��傤�B" );
  CERR( "  - �񕪒T�����Ō����l���������͑㐔�������������Č덷�������܂��傤�B" );
  CERR( "- �ԕ��Ȃǂɂ���O�����̃~�X�����Ă��܂��񂩁H" );
  CERR( "  - �P�Ȃ�萔�{��������ړI�Ƃ����O�����͍폜���Ď����Ă݂܂��傤�B" );
  CERR( "  - �����̍�������ړI�Ƃ����O�����͍폜�����������̏ؖ����Ċm�F���܂��傤�B" );
  CERR( "- �ʐόv�Z�Ŋi�q�_�̌��ƒ������������Ă��܂��񂩁H" );
  CERR( "  - �̈���Ǘ�����ۂ́u�E���̒P�ʋ�`���h���邩�v�̏����e�i�q�_�ɏ悹�܂��傤�B" );
  CERR( "  - ���W���k����ۂ́u�h��̈�̒[�_�v���}1�����ɊǗ����܂��傤�B" );
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
	     "�\�z���"
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
	     "�ʐς̌v�Z���" ,
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
  CERR( "  \\Mathematics\\Polynomial\\Mod" );
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
	     "�z����󂯎��֐��̑��a�̌v�Z���"
	     );
  if( num == num_temp++ ){
    CERR( "- �a�̏�������" );
    CERR( "- �����l�ɂȂ鍀�̓Z�ߏグ" );
    CERR( "- 2�ϐ��֐�f�Ɛ���(a_i)_i���^�����Asum_i f(a_i,i)�����߂�ꍇ�A" );
    CERR( "  f(x,i)=sum_k b_{i,k} g_k(x)�ƕ\���ł����" );
    CERR( "  (b_{i,k})_i��(g_k(a_i))_i�̓��ς̑��a�ɋA������܂��B" );
    CERR( "  ���ς͕Е��̓Y�����𔽓]�����邱�Ƃŏ�ݍ��݂ɋA�������邱�Ƃ��ł��܂��B" );
    CERR( "  �z��ւ̑��삪�V�t�g�ł���ꍇ�͌J��Ԃ����ς����߂邱�ƂɂȂ�̂ŁA" );
    CERR( "  �K���Ȗ@�ł̍����t�[���G�ϊ�" );
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynoial" );
    CERR( "- 2�ϐ��֐�f�Ɛ���(a_i)_i���^�����Asum_{i,j} f(a_i,a_j)�����߂�ꍇ�A" );
    CERR( "  f(x,y)=sum_k g_k(x) h_k(y)�ƕ\���ł����" );
    CERR( "  (g_k(a_i))_i�̗ݐϘa��(h_k(a_j))_j�̐ς̑��a�ɋA������܂��B" );
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
  CERR( "�񍀓W�J��ς̘a�T�^�Ȃǂ̑g�ݍ��킹�_�I����" );
  CERR( "https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "https://ladywingclover.hatenablog.com/entry/2022/11/24/084524" );
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
  CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "�����؂Ɋւ���ǂ��J�ڊ֌W��T���A�i�S���ʁj��DP" );
  CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree" );
  CERR( "���������܂��傤�B" );
  ASK_YES_NO( "f��bit���Z�̑��������ł�����ł����H" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionBitFunctionOnTree );
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
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionCountingOperation )
{
  CERR( "����񐔂����߂�ۂ́A�������u��Ăɏ����ł����ԁv�������ɕ������A" );
  CERR( "���ꂼ��̋�Ԃł̏������v�Z���邱�Ƃ��������܂��傤�B" );
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
	     "�᎟���A�t�B����ԏ�̊֐��̍ő�^�ŏ������" ,
	     "�z���̊֐��̍ő�^�ŏ������" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̍Œ������" ,
	     "�W���̕����W���̍ő剻���" ,
	     "�؏�̊֐��̍ő�^�ŏ������" ,
	     "�ړ��R�X�g�ŏ������" ,
	     "������̃}�b�`���O�Ɋւ���ő�^�Œ������" ,
	     "�ő�񕔃}�b�`���O���" ,
	     "�m���^���Ғl�̍ő剻���" ,
	     "����񐔂̍ŏ������" ,
	     "�ő剻�헪�̍\�z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationBipartiteMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMaximisation );
  }
}

AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "�ʊ֐��̍ŏ��^�ő剻���" ,
	     "�����֐��̍ŏ��^�ő剻���" ,
	     "��Βl�̍ŏ��^�ő剻���"
	     );
  if( num == num_temp++ ){
    CERR( "�O���T�����������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�j���[�g���@���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "������p���Đ�Βl���O���܂��傤�B" );
    CERR( "- �P���Ȏ��ɋA���ł���ꍇ�A�񕪒T��" );
    CERR( "- �ő剻���̏ꍇ�A�����p�^�[���̑S�T��" );
    CERR( "- �}���n�b�^�������Ȃǂ͈ꎟ�ϊ�" );
    CERR( "���������܂��傤�B" );
  }
  CERR( "" );
  CERR( "�����̃p�����[�^�����肷�ׂ��ꍇ�́A�T�u�S�[���̎��̒l�����ߑł��܂��傤�B" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "��蕶�܂��͓��͂ŗ^������P�̔z��Ɋւ�����" ,
	     "�����𖞂����C�ӂ̔z��Ɋւ�����"
	     );
  if( num == num_temp++ ){
    ASK_NUMBER(
	       "�������󂯎��֐��̕����a�̍ő剻���" ,
	       "�z��̕ύX�Ɣz����󂯎��֐��̍����̍ő剻���"
	       );
    if( num == num_temp++ ){
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
    CERR( "���������܂��傤�B" );
  }
}

AC( MaximisationSubArraySum )
{

  CERR( "�a�����l�����l�ƌĂԂ��Ƃɂ��܂��B" );
  CERR( "�z��̍���N�A��i�����̉��lA_i�A���l�̑��av�Av�̏��V�Ƃ��܂��B" );
  CERR( "{0,...,N-1}�̕����W��I�ł����āA" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- ���̑��̏���" );
  CERR( "�𖞂������̂̐����グ���l���܂��B" );
  ASK_NUMBER(
	     "I�ɃR�X�g���񂪂���d�������I���������ꍇ" ,
	     "I�ɃR�X�g���񂪂���d�������I���������Ȃ��ꍇ" ,
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
    CERR( "�R�X�g�̑��a���C<���Ƃ��܂��B" );
    CERR( "- O(C^2)���ʂ肻���Ȃ��" );
    CERR( "  �u�R�X�gc�̍��̉��l�̍ő�lv[c]�v" );
    CERR( "  ��O�v�Z��" );
    CERR( "  �u�R�X�g�̑��a��c�ȉ��̎��̉��l�̍ő�ldp[c]�v" );
    CERR( "  ���Ǘ�����c�Ɋւ��铮�I�v��@" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)���ʂ肻���Ȃ�΋𒼂ɑS�T��" );
    CERR( "- O(N 2^{N/2})���ʂ肻���Ȃ�Δ����S��" );
    CERR( "- O(NV)���ʂ肻���Ȃ��[v-V,v+V]�ł̎����\����" );
    CERR( "  �J�ڂ��铮�I�v��@" );
    CERR( "  https://stackoverflow.com/a/18949218" );
    CERR( "- O((N+V)log_2 V)���ʂ肻����V��10^5�I�[�_�[��" );
    CERR( "  �v���X�f��P��@�Ƃ���Ȃ�Ζ@P�ł̍����t�[���G�ϊ��ɂ��" );
    CERR( "  exp(log�̑��a)�v�Z" );
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynomial" );
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
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "- �a�Ȕ������Ȃ�΁A�����𖞂���������̖������C���f�b�N�X�Ɏ���" );
  CERR( "  �A�z�z���p���āA����畔����̒����̍ő�l���L�^���邱��" );
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
  CERR( "���������܂��傤�B" );
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
  CERR( "  \\Utility\\VLTree\\UnionFindForest" );
  CERR( "  " );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationFunctionOnTree )
{
  CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "�u��i���_�܂łŐ؂�������F(P)�����̍ő�ldp[i]�v" );
  CERR( "���Ǘ�����i�Ɋւ��铮�I�v��@�iO(N^2�~f�̌v�Z��)�j" );
  CERR( "���������܂��傤�B" );
}

AC( MinimisationMovingCost )
{
  ASK_NUMBER(
	     "�P�n�_���I�_�ŏ��R�X�g�ړ��i���H�j���" ,
	     "���n�_���I�_�ŏ��R�X�g�ړ��i�핢�j���" ,
	     "�P�n�_���o�R�_�ŏ��R�X�g�ړ��i�X�^���v�����[�j���"
	     );
  if( num == num_temp++ ){
    CERR( "- �R�X�g���Ȃ�O(V+E)���ʂ肻���Ȃ�Ε��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g��0��1��O(V+E)���ʂ肻���Ȃ��01���D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "- �R�X�g���a�����C�Ƃ�O((V+E)C)���Ԃɍ��������Ȃ��" );
    CERR( "  �R�X�g����ԂɊ܂߂��O���t��ł̕��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- O((V+E)log_2 E)���Ԃɍ��������Ȃ�΃_�C�N�X�g���@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
  } else if( num == num_temp++ ){
    CERR( "- �R�X�g���Ȃ�O(V+E)���ʂ肻���Ȃ�΁A���_���D��T����" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̕��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- �R�X�g��0��1��O(V+E)���ʂ肻���Ȃ�΁A���_01���D��T��" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł�01���D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "- max���Z���l���Ă���O(E(log_2 E + ��(V)))���ʂ肻���Ȃ�΁A" );
    CERR( "  �d�݂ŕӂ��\�[�g���đf�W���f�[�^�\��" );
    CERR( "  \\Utility\\VLTree\\UnionFindForest" );
    CERR( "- O((V+E)log_2 E)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̃_�C�N�X�g���@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "- O(V^3)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���[�V�����t���C�h�@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
  } else if( num == num_temp++ ){
    CERR( "- HeldKarp�@" );
    CERR( "- �ړ����@�𕪗ނ���p�����[�^�̑S�T��" );
  }
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "�_�̍��W�ƍŏ������ׂ��R�X�g�ȊO�̐��lx�ɕω�������ꍇ�A�ŏ��R�X�g�ړ��ɂ�����" );
  CERR( "x�̓����͈͂��i���ē_�̍��W��x�̑g�𒸓_�Ƃ���O���t���l���܂��傤�B" );
  CERR( "" );
  CERR( "�d�݂��ӂł͂Ȃ����_�ɂ��Ă���ꍇ" );
  CERR( "- 㰓����m�C�h�Ȃ�Γ��ɒ��_�͒ǉ�����" );
  CERR( "- 㰓��łȂ������m�C�h�Ȃ�Ώd�݂��P�ʌ��ł���n�_�ƏI�_��ǉ�����" );
  CERR( "�e�ӂ̏d�݂𗼒[�̏d�݂ɉ��Z��K�p�������̂Œ�`���܂��傤�B" );
  CERR( "" );
  CERR( "�ӏW��E���傫�߂���ꍇ�A�\�������������W��E'�ł����ď���" );
  CERR( "�u�C�ӂ̌o�Hp�ɑ΂��AE'�ɑ����ӂ݂̂�ʂ邠��o�Hp'�����݂��āA" );
  CERR( "  p�̃R�X�g>=p'�R�X�g�ł���v" );
  CERR( " �𖞂������̂�T�����Ƃ��������܂��傤�B" );
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
	     "����񐔂̌v�Z���" ,
	     "�J�^�������̌v�Z���"
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
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- �ϐ��̑Ώ̐�������Α召�֌W�𐧌������S�T��" );
  CERR( "- ���炩�̖񐔂ƂȂ�ȂǓ����͈͂������ϐ�������΂��������ߑł����S�T��" );
  CERR( "- f(g(x),g(y))=k�̌`��" );
  CERR( "  - �܂��eb in im(g)�ɑ΂�f(a,b) = k�𖞂���a in im(g)�S�̂�O�v�Z����B" );
  CERR( "  - ����|dom(g)| = N�Amax im(g) = M�Ƃ���im(g)�𑽏d�W���Ƃ���" );
  CERR( "    - O(N log_2 N)���Ԃɍ��������Ȃ��map iterator + map::lower_bound" );
  CERR( "    - O(N)���Ԃɍ��������Ȃ��unordered_map iterator + unordered_map::[]" );
  CERR( "    - O(M+N)���Ԃɍ��������Ȃ�Δz��S�T�� + �z��::[]" );
  CERR( "    - x,y�ɐ���h(x)<h(y)������ꍇ��h(x)�̏��c�ɂ��ă��[�v����" );
  CERR( "      g(x)�̏W�����X�V���Ă����A����ƕ��s����y��c<h(y)�͈̔͂őS�T��" );
  CERR( "    �ɂ��Ǘ�����B" );
  CERR( "  - �Ō�Ɋey���Ƃ�f(a,g(y)) = k�𖞂����ea in im(g)�ɑ΂�a = g(x)�𖞂���" );
  CERR( "    x��im(g)�̑��d�W���\�����g���Đ����グ��B" );
  CERR( "- f(g(x),g(y))<=k�̌`��f��g���P���������鎞��" );
  CERR( "  - �܂��eb in im(g)�ɑ΂�f(a,b) <= k�𖞂���a�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - ���ɂ������ē�����ea�ɑ΂�g(x)<=a�𖞂���x�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - �Ō�Ɋey���Ƃ�b = g(y)�ɑ΂���O�v�Z���ʂ̑��a�����߂�B" );
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
    ASK_NUMBER( "�z��ւ̊i�[�����֌W����܂����H" );
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
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynomial" );
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
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
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
	     "�}�b�`���O�Ɋւ��鐫���𖞂�������������̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "������𕶎��̔z��Ƃ݂Ȃ����ƂŁA�z��̖��ɋA�������邱�Ƃ��ł��܂��B" );
    CALL_AC( CountingSubArrayImageArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  }
}

AC( CountingMatchingSubString )
{
  CERR( "- �����ƃ}�b�`���O���镔��������̐����グ����Z�A���S���Y��" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- �񕶂ł��镔��������̐����グ����" );
  CERR( "  - O(N^2)���ʂ�ꍇ�A�ڎ��@�ɂ��O�v�Z" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)���ʂ�Ȃ��ꍇ�AManacher�̃A���S���Y���⃍�[�����O�n�b�V���őO�v�Z" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "���������܂��傤�B" );
}

AC( CountingPartitionOfTree )
{
  CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "F(P)���Œ肳�ꂽ����P�̐����グ����" );
  CERR( "�u��i�����܂łŐ؂�������F(P)=v�𖞂���P�̌�dp[i][v]�v" );
  CERR( "���Ǘ�����i,v�Ɋւ��铮�I�v��@�iO(N^2 v_max�~f�̌v�Z��)�j" );
  CERR( "���������܂��傤�B" );
}

AC( CountingSubset )
{
  CERR( "�^����ꂽ�W���̃T�C�Y��N�ƒu���܂��B" );
  CERR( "- O(2^N)���Ԃɍ��������Ȃ�΁Abit�S�T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- O(N2^N)���Ԃɍ��������Ȃ�΁A�����W���̕�ܑ΂�bit�S�T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "���������܂��傤�B" );
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
    CERR( "�K�X�J�^�������Ƃ̊֌W���������܂��傤�B" );
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CERR( "���[�v�̕s�\�ȗL���O���t�͐��b�Ȃ̂ŁA�e�_p���Ƃ�" );
    CERR( "-�up���T�����ꂽ���v��\��bool�l�z��" );
    CERR( "-�up�ւ̕ӂ������T���_�̌��v��\���z��" );
    CERR( "���Ǘ��������҂�S�T�􂷂邱�Ƃ�O(|V|^2+|E|)�őS�Ă̓_��T���ł��܂��B" );
  }
}

AC( CountingParenthesisSequence )
{
  CERR( "��n�J�^������Cn��(2n)!/(n+1)!n!�ł��B" );
  CERR( "- n�΂̃J�b�R��ł����đS�ẴJ�b�R����������" );
  CERR( "- 2n�����̑��a��0�ō��[����̎n�[�a���񕉂ȁ}1��" );
  CERR( "- n�m�[�h�̓񕪖�" );
  CERR( "- n�~n�i�q�ō�������E��܂őΊp�����ׂ����ŏ��ɉE�֍s���ŒZ�o�H" );
  CERR( "- 2�~n�̕W�������O�}�`�i�s�^��Ƃ��ɋ��`�P������ɂȂ�悤�Ȕԍ��Â��j" );
  CERR( "- �~���n���_�̑��p�`����" );
  CERR( "- �~���n+2�p�`�̎O�p�`����" );
  CERR( "- �~���2n���_�̔����������2�Ȗ����ӂ̒����" );
  CERR( "�̐����グ�Ȃǂ�Cn�ƈ�v���܂��B" );
  CERR( "https://en.wikipedia.org/wiki/Catalan_number#Applications_in_combinatorics" );
}

AC( Solving )
{
  CERR( "- �P���֐��͓񕪒T��" );
  CERR( "- �����֐��̓j���[�g���@" );
  CERR( "- �ꎟ�֐��͑|���o���@" );
  CERR( "- f(g(x),g(y),...)�̌`��f,g�ʁX�ɑO�v�Z" );
  CERR( "���������܂��傤�B" );
}

AC( Query )
{
  ASK_NUMBER(
	     "�z��͈͍̔X�V�^�擾�N�G�����" ,
	     "�O���t�͈͍̔X�V�^�擾�N�G�����" ,
	     "�O���b�h�͈͍̔X�V�^�擾�N�G�����" ,
	     "������͈͍̔X�V�^��r�N�G�����" ,
	     "�W���͈͍̔X�V�^��r�N�G�����" ,
	     "���n��f�[�^�̃N�G�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryString );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTime );
  }
}

AC( QueryArray )
{
  ASK_NUMBER(
	     "���Q�\��+���g�����" ,
	     "��㰓����m�C�h�\���ɂ��g�����" ,
	     "���m�C�h�\��*���g�����" ,
	     "�񌋍��I�}�O�}�\��*���g�����" ,
	     "�W���ւ̃}�O�}��p(*,\\cdot)���g�����" ,
	     "���m�C�h�ւ̃}�O�}��p(+,\\cdot)���g�����" ,
	     "�������������" ,
	     "�ꎟ�֐��Ƃ�max��������l���g�����" ,
	     "�萔�Ƃ�max��������l�̋�ԉ��Z�擾���g�����"
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
  CERR( "- ���Z�^�S�X�V��̈�_�擾�݂̂��K�v�Ȃ�ΊK������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- ���Z�^�S�X�V�Ȃ��ŋ�Ԏ擾�݂̂��K�v�Ȃ�Ηݐϐ�" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "- ��ԉ��Z�^��Ԏ擾���K�v�Ȃ�Βʏ��BIT����QBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template" );
  CERR( "- ��_����^��_���Z�^��Ԏ擾���K�v�Ȃ�Ή��Q��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayCommutativeIdempotentMonoid )
{
  CERR( "- ��_����^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�Ȃ�΋��maxBIT���㰓����m�C�hBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMonoid )
{
  CERR( "- ��_����^��Ԏ擾���K�v�Ȃ�΃��m�C�hBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template\\Monoid" );
  CERR( "- ��_���Z�^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�Ȃ�΃��m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Monoid" );
  CERR( "- ��_����^��_�擾�^��Ԏ擾���K�v�Ȃ�΃��m�C�h�Z�O�����g��" );
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
  CERR( "- ��_��p�^��ԍ�p�^��_�擾���K�v�Ȃ�Αo�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Dual" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMagmaMonoid )
{
  CERR( "- ��ԑ���^��ԍ�p�^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�ȏꍇ�͒x���]����������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\LazyEvaluation" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayOrder )
{
  CERR( "- ��_����^��_�����擾�^�S�̂ł̏�������������_�̎擾���K�v�Ȃ�Βʏ��BIT�ő����Ǘ���" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - ��_�����擾�͕��ʑ���" );
  CERR( "  - �S�̂ł̏�������������_�̎擾�͕��ʑ����{�񕪒T��" );
  CERR( "- ��_���Z�^��Ԃł̏�������������_�̎擾���K�v�Ȃ�΋��maxBIT���㰓����m�C�hBIT��" );
  CERR( "  ��ԍő�^�ŏ��l�{�񕪒T���ŋ�Ԃ𕪊�" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- �ꎟ�֐��ɂ��S��max�X�V�^��_�擾���K�v�ȏꍇ��Convex Hull Trick" );
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

AC( QueryGraph )
{
  ASK_YES_NO( "�㐔�\�����������ł����H" );
  if( reply == "yes" ){
    CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V��̈�_�擾�݂̂��K�v�Ȃ�ΊK������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\Tree" );
    CERR( "- �؏�ŉ����m�C�h�\���Ɋւ���ċA���K�v�Ȃ�ΑS���DP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
  } else {
    CERR( "�[���D��T���⓮�I�؂�UnionFind" );
    CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
    CERR( "\\Utility\\VLTree" );
    CERR( "\\Utility\\VLTree\\UnionFndForest" );
  }
  CERR( "���������܂��傤�B" );  
}

AC( QueryGrid )
{
  CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V��̈�_�擾�݂̂��K�v�Ȃ�Γ񎟌��K������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V�Ȃ��̋�`�擾�݂̂��K�v�Ȃ�Γ񎟌��ݐϘa" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CulmulativeProd\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V��̋�`�擾���K�v�Ȃ�Γ񎟌��K������^�ݐϘa�̕��p" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CulmulativeProd\\TwoDimentioal" );
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
	     "�[���\�����" ,
	     "��v������" ,
	     "�\�L�\�����"
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
  CERR( "\\Utility\\VLTree\\UnionFindForest" );
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
  CERR( "�Q�[���̘a�ɕ����ł���ꍇ�͍ŏ��P�ʂōl�@�����A�O�����f�B�����������܂��傤�B" );
  CERR( "����ȏ㕪���ł��Ȃ��Q�[���ɂ͐��b�\����T���A�������̏��������Ɏ��������܂��傤�B" );
  ASK_NUMBER(
	     "����̌p����ڎw���Q�[��" ,
	     "���_�̑召�������Q�[��"
	     );
  if( num == num_temp++ ){
    CERR( "�K���헪�̍\�z�ł�" );
    CERR( "- �s�k��Ԃ�������邽�߂́A���炩�̕s�ϗʂ�ۂ헪" );
    CERR( "- ��l�܂��������邽�߂́A�����炩�̓񕔃}�b�`���O����������헪" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�Q�v���C���[�̓��_�����P�̓_���Ƃ݂Ȃ��A���̍ő剻���s���܂��傤�B" );
    CALL_AC( ConstructionMaximisation );
  }
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
  CERR( "���^��������g���ē���̐��╶����\���ł��邩�̔����" );
  CERR( "- �������I�Ɋ֐��^���Z����������ꍇ��" );
  CERR( "  �u��i�����^�����܂łőł��؂������ɕ\���ł�����̑S�̂̏W��dp[i]�v" );
  CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
  CERR( "- �֐��^���Z�̓K�p���@�ɂ��I��������ꍇ��2����I��œK�p������" );
  CERR( "  ���ʓ����鐔�^������̍ċA�I�ȑS�T��" );
  CERR( "���������܂��傤�B" );
}

AC( Construction )
{
  CERR( "���ݒ藝�ɋA���ł�����͍\���I�ؖ����������܂��傤�B" );
  CERR( "���A�N�e�B�u���Ŏ��������ۂ�" );
  CERR( "- ���炩�̏����ɂ�����ɑ匳�ɐG��長����" );
  CERR( "- �Ȃ�ׂ������̐��l�Ɉˑ�������ɐG��長����" );
  CERR( "- N^2�̐��l�ɑ΂���O(N)��̎���ł͑Ίp���ɐG��長����" );
  CERR( "���������܂��傤�B" );
  ASK_NUMBER(
	     "����z��╶����̍\�z" ,
	     "�o�H�̍\�z" ,
	     "�K���헪�̍\�z" ,
	     "�ő剻�헪�̍\�z" ,
	     "�\���\���̔���" ,
	     "�\�[�X�R�[�h�̍\�z"
	     );
  if( num == num_temp++ ){
    CERR( "p�i�@��K��������������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�\�Ȍo�H�̒�߂�O���t�̖��ɋA�������܂��傤�B" );
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CERR( "�Q�[���̖��ɋA�������܂��傤�B" );
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMaximisation );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CERR( "�������o�͂�����\�[�X�R�[�h���o���܂��傤�B" );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "�_���̍ő剻�̂��߂ɂ́A�헪�̐��b�ȕό`�菇�ł����ē_���𗎂��Ȃ����̂�T��" );
  CERR( "���̕ό`�����S�ɍs���ē�����헪�݂̂ɍi���čl���܂��傤�B" );
}
