// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void AutoCheck( bool& auto_checked )
{
  int num = 0;
  int num_temp = 0;
  string reply{};
  vector<string> problems{};
  int problems_size = 0;
  ASK_NUMBER(
	     "��o�p�t�@�C�������s����B" ,
	     "��o�ς݃t�@�C�����f�o�b�O����B" ,
	     "���C�u�����[��T������B"
	     );
  if( num == num_temp++ ){
    auto_checked = false;
    CERR( "��o�p�t�@�C�������s���܂��B" );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHint );
  } else if( num == num_temp++ ){
    CALL_AC( LibrarySearch );
  }
  CERR( "" );
}

AC( DebugHint )
{
  ASK_NUMBER(
	     "WA�̃f�o�b�O" ,
	     "RE�̃f�o�b�O" ,
	     "TLE�̃f�o�b�O" ,
	     "MLE�̃f�o�b�O"
	     );
  if( num == num_temp++ ){
    CERR( "- operator<<()��int�^�ɓK�p���Ă��܂��񂩁H" );
    CERR( "- �C�x���g�Ǘ���set���g���Ă��܂��񂩁H" );
    CERR( "  - key�ɋ��`�S������p����ꍇ�A" );
    CERR( "    - ����key�̏����𓯎��ɍs���Ȃ��map���������܂��傤�B" );
    CERR( "    - ����key�̏����𓯎��ɍs��Ȃ��Ȃ��multiset���������܂��傤�B" );
    CERR( "  - key�ɋ��`�S�����̐Ϗ�����p����ꍇ�Amap�̓���q���������܂��傤�B" );
    CERR( "- ���I�v��@�ɂ�����index��swap��mod��p���ă������팸���s���ꍇ�A" );
    CERR( "  �e���[�v�̍ŏ���dp�e�[�u���̏����������Y��Ă��܂��񂩁H" );
    CERR( "- �ԕ��̐ݒ�Y�ꂩ�ݒ�~�X�����Ă��܂��񂩁H" );
    CERR( "- �}���`�e�X�g�P�[�X�Ŕz���static�����Ēl�������z����Ă��܂��񂩁H" );
    CERR( "- cLay�g�p�^��setmod�ȑO��10^9+7���傫���l�������Ă��܂��񂩁H" );
    CERR( "" );
    CERR( "�����ɐS�����肪�Ȃ��ꍇ�̓����_���e�X�g���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- ������ԈႦ��assert���Ă��܂��񂩁H" );
    CERR( "- �z��O�Q�Ƃ��Ă��܂��񂩁H" );
    CERR( "  - ���W���k�^�Ɉ��k�O�̓Y������ƈ��k��̓Y��������������Ă��܂��񂩁H" );
    CERR( "  - �O���t����W���k�̑���ő��݂��Ȃ����W-1�̏ꍇ������Y��Ă��܂��񂩁H" );
    CERR( "- �񕪒T���}�N���ŒT���l�����݂��Ȃ��ꍇ��������Y��Ă��܂��񂩁H" );
    CERR( "- �C�e���[�^��͈͊O�܂�--/++���Ă��܂��񂩁H" );
    CERR( "- multiset��count���g���Ă��܂��񂩁H" );
    CERR( "- 0�Ŋ����Ă��܂��񂩁H" );
  } else if( num == num_temp++ ){
    CERR( "- �}���`�e�X�g�P�[�X�Ńf�[�^�\���̏���������������Ă��܂��񂩁H" );
    CERR( "- while���[�v�œY�����̍X�V�Y��ɂ�閳�����[�v�͂���܂��񂩁H" );
    CERR( "- �d�߂���萔�{���l�����Y��Ă܂��񂩁H" );
    CERR( "  - bool�l�̏�����bit���Z�ɂ����񉻂��������܂��傤�B" );
    CERR( "  - �ϐ��̘a��ςɏ��������O���b�h���͓��I�z����������܂��傤�B" );
    CERR( "- ���A�N�e�B�u����flush�Ɖ��s�����Y��Ă��܂��񂩁H" );
  } else if( num == num_temp++ ){
    CERR( "- �O���t�ŕӂ������߂��Ă��܂��񂩁H" );
    CERR( "- �i���d�j�z��ŃT�C�Y��10^6��啝�ɏ����Ă܂��񂩁H" );
    CERR( "  - �f�[�^�\���͍��W���k���������܂��傤�B" );
    CERR( "  - ���I�v��@�͏������Y��ɒ��ӂ��ēY����swap��mod���������܂��傤�B" );
    CERR( "- Python�g�p�^�ɕϐ����̏d���ɂ��^�G���[���N���Ă܂��񂩁H" );
    CERR( "  - range��R��[L,R)��R�̏d���͌�҂�[l,r)��p���ĉ������܂��傤�B" );
    CERR( "  - �f����P�Ə����P�̏d���͌�҂�A��Q��p���ĉ������܂��傤�B" );
    CERR( "- Python�g�p�^�Ɍ������傫���Ȃ�߂��Ă��܂��񂩁H" );
  }
  CERR( "" );
  CERR( "��o�ς݃t�@�C���̃f�o�b�O�͈ȏ�ł��B�I�����܂��B" );
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
	     "�z���̊֐��̑��a�̌v�Z���" ,
	     "�����̊֐��̌v�Z���" ,
	     "�؏�̊֐��̑��a�̌v�Z���" ,
	     "�؈ȊO�̃O���t��̊֐��̌v�Z���" ,
	     "�����̌v�Z���" ,
	     "�m���^���Ғl�̌v�Z���" ,
	     "����񐔂̌v�Z���" ,
	     "���̑��̖������̌v�Z���"
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
    CALL_AC( ExplicitExpressionOther );
  }
}

AC( ExplicitExpressionUnary )
{
  ASK_NUMBER(
	     "���`�Q�����̖��" ,
	     "�P�ϐ��֐��̔��������̖��" ,
	     "���̑��̂P�ϐ��֐��̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryIteration );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryOther );
  }
  CERR( "���������܂��傤�B" );
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
}

AC( ExplicitExpressionUnaryIteration )
{
  CERR( "��`��̗v�f��N�A�e�X�g�P�[�X��T�A�����񐔂̏��K�Ƃ��܂��B" );
  CERR( "- O((N + T)log_2 K)���ʂ肻���Ȃ�΃_�u�����O" );
  CERR( "  \\Mathematics\\Function\\Iteration\\Doubling" );
  CERR( "- O(TN)���ʂ肻���Ȃ�΃��[�v���o" );
  CERR( "  \\Mathematics\\Function\\Iteration\\LoopDetection" );
  CERR( "- O(N)����ʂ�Ȃ������Ȃ�Ί֐��̋K���������t���邽�߂̎���" );
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
  CERR( "�O�v�Z�̌��Ƃ��Ă�" );
  CERR( "- �f����" );
  CERR( "- �P�܂��͕����̐����̖񐔗�" );
  CERR( "- �I�C���[�֐��̒l�̗�" );
  CERR( "- �T�u�S�[���ƂȂ�֌W���𖞂������̗�" );
}

AC( ExplicitExpressionArraySum )
{
  ASK_NUMBER(
	     "�������󂯎��֐��̑��a�̌v�Z���" ,
	     "��������󂯎��֐��̑��a�̌v�Z���"
	     );
  if( num == num_temp++ ){
    CERR( "�������󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
    CERR( "f���ꎟ���̏ꍇ�A�������ςƒ萔�̘a�ƂȂ�܂��B" );
    CERR( "���ς͕Е��̓Y�����𔽓]�����邱�Ƃŏ�ݍ��݂ɋA�������邱�Ƃ��ł��܂��B" );
    CERR( "�z��ւ̑��삪�V�t�g�ł���ꍇ�͌J��Ԃ����ς����߂邱�ƂɂȂ�̂ŁA" );
    CERR( "�K���Ȗ@�ł̍����t�[���G�ϊ�" );
    CERR( "\\Mathematics\\Arithmetic\\Mod" );
    CERR( "\\Mathematics\\Polynoial" );
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
  }
  CERR( "" );
  CERR( "���͂��傫���ꍇ�Ə������ꍇ�ŉ�@��ς���l�@��Y��Ȃ��悤�ɂ��܂��傤�B" );
}

AC( ExplicitExpressionFunctionOnPermutation )
{
  CERR( "- �������̂��̂̌v�Z����" );
  CERR( "  - O(N log_2 N)��O(N^2)���Ԃɍ��������Ȃ�]�|���̌v�Z" );
  CERR( "  - O(N log_2 N)���Ԃɍ���Ȃ������Ȃ�݊��\���iO(N)�j" );
  CERR( "- �����Ɖ����̐ς̘a�͍s�񎮂ɋA�������A" );
  CERR( "  - �s�񎮂��̂��̂Ȃ�s��{�ό`�iO(N^3)�j" );
  CERR( "  - �]���q�W�J�̓r���̒l���K�v�Ȃ烁�����ċA�iO(N 2^N)�j" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "�P�̏���̓]�|���́A" );
  CERR( "- O(N^2)���ʂ肻���Ȃ�΋𒼂ȓ�d���[�v" );
  CERR( "- O(N log_2 N)���ʂ肻���Ȃ�Ή��QBIT" );
  CERR( "  \\Mathematics\\Combinatorial\\Permutation" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "�Ōv�Z���܂��傤�B" );
  CERR( "" );
  CERR( "�����𖞂�������S�̂��킽��]�|���̑��a�^���Ғl�́A" );
  CERR( "�ei<j���Ƃɂ����œ]�|�������鏇��̌����v�Z���A���̑��a�^���Ғl��" );
  CERR( "���܂��傤�B�������ǂ���΁A�]�|�������鏇��̌��͓]�|��������Ƃ�" );
  CERR( "����Ȃ�����̌��̔����ƂȂ�܂��B" );
}

AC( ExplicitExpressionFunctionOnTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "�����؂Ɋւ���ǂ��J�ڊ֌W��T���A�i�S���ʁj��DP" );
  CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree" );
  CERR( "���������܂��傤�B" );
  ASK_YES_NO( "f��bit���Z�ł�����ł����H" );
  if( reply == "y" ){
    CERR( "�uT�̊e�m�[�hv�����Ƃ��镔���؂ł�j���ڂ�bit���s�̌�dp[v][s][j]�v" );
    CERR( "���Ǘ�����v,s,j�Ɋւ��铮�I�v��@���������܂��傤�B" );
    CERR( "�����T���S�����W����bit���Z��1��ނȂ�" );
    CERR( "�u��i�����Ő؂���������ł�j���ڂ�bit��s�i=0,1�j�ł����dp[i][s][j]�v" );
    CERR( "���Ǘ����邱�Ƃɑ��Ȃ�܂���B" );
  }
}

AC( FunctionOnTree )
{
  CERR( "�؂��󂯎��֐�f���^�����Ă���Ƃ��܂��B" );
  CERR( "" );
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
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionOrder )
{
  CERR( "�W��S�����炩�̏����Ń\�[�g�����z��a�Ɋւ�����ŁA" );
  CERR( "- �^����ꂽ�v�fs�������牽�Ԗڂ��𓚂���ꍇ�́A" );
  CERR( "  - �ei���Ƃ�a[i]�����߂���Ȃ�΁Ai�Ɋւ���񕪒T��" );
  CERR( "  - �����łȂ��Ȃ�΁As�����̍��̐����グ" );
  CERR( "- �^����ꂽi�ɑ΂���a[i]�𓚂���ꍇ�́A" );
  CERR( "  S�̊e�v�fs���Ƃ�s�����̍��𐔂��グ��s�Ɋւ���񕪒T��" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "������������s�����̍��̐����グ������ۂ́A" );
  CERR( "�us��d�����ڂŏ��߂ăY����l�����̍��̑���count[d][l]�v" );
  CERR( "��d��l���킽�鑍�a�����߂܂��傤�B" );
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

AC( ExplicitExpressionOther )
{
  CERR( "- �o�͂̒�`�Ɠ����Ȏ��ւ̕ό`" );
  CERR( "  - �a�̏�������" );
  CERR( "  - �����l�ɂȂ鍀�̓Z�ߏグ" );
  CERR( "  - �񍀓W�J��ς̘a�T�^�Ȃǂ̑g�ݍ��킹�_�I����" );
  CERR( "    https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "- �a�̓����͈͂̍����ɒ��ڂ������I�v��@" );
  CERR( "���������܂��傤�B" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "�᎟���A�t�B����ԏ�̊֐��̍ő�^�ŏ������" ,
	     "�z���̊֐��̍ő�^�ŏ������" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̍Œ������" ,
	     "�؏�̊֐��̍ő�^�ŏ������" ,
	     "�ړ��R�X�g�ŏ������" ,
	     "������̃}�b�`���O�Ɋւ���ő�^�Œ������" ,
	     "�ő�񕔃}�b�`���O���" ,
	     "�m���^���Ғl�̍ő剻���" ,
	     "����񐔂̍ŏ������"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
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
  CERR( "����N�A�I���񐔏��M�A���l�i�a�����l�j���V�Ƃ��܂��B" );
  ASK_NUMBER(
	     "�e�I���̃R�X�g��������݂��Ȃ������̖��" ,
	     "�I�����ƂɃR�X�g�̏�����قȂ���"
	     );
  if( num == num_temp++ ){
    CERR( "�e�I���̃R�X�g��������݂���ꍇ�A���̏���ȉ��̍��������l���܂��傤�B" );
    CERR( "�R�X�g�̑��a���C�Ƃ��܂��BC=���Ȃ�Βʏ�̃i�b�v�T�b�N����" );
    CERR( "���l�̓��I�v��@�ŗǂ��̂ŁA�ȉ�C<���̏ꍇ���l���܂��B" );
    CERR( "- O(2^N)���ʂ肻���Ȃ�΋𒼂ɑS�T��" );
    CERR( "- O(N 2^{N/2})���ʂ肻���Ȃ�Δ����S��" );
    CERR( "- �R�X�g�Ɖ��l��������O(NV)���ʂ肻���Ȃ��[C-V,C+V]�ł̎����\����" );
    CERR( "  �J�ڂ��铮�I�v��@" );
    CERR( "  https://stackoverflow.com/a/18949218" );
    CERR( "- �R�X�g�Ɖ��l��������O((N+C)log_2 C)���ʂ肻���Ȃ��" );
    CERR( "  �K���Ȗ@�ł̏�ݍ��݁i�m���I��@�j" );
    CERR( "  \\Mathematics\\Polynomial" );
    CERR( "- �R�X�g�Ɖ��l���������Ȃ�O(C^2)���ʂ肻���Ȃ��" );
    CERR( "  �u�R�X�gc�̍��̉��l�̍ő�lv[c]�v" );
    CERR( "  ��O�v�Z��" );
    CERR( "  �u�R�X�g�̑��a��c�ȉ��̎��̉��l�̍ő�ldp[c]�v" );
    CERR( "  ���Ǘ�����c�Ɋւ��铮�I�v��@" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�R�X�g�̎�����K<=2�An���ڂ̃R�X�g��C_n�Ƃ��A" );
    CERR( "m�I��ڂł�C_n[k_m]<=D_m�𖞂�����n��I�ׂ�Ƃ��܂��B" );
    CERR( "" );
    CERR( "��{C_n,n}�ƑI��{k_m,D_m}�����ꂼ�ꎫ���������Ń\�[�g���A" );
    CERR( "�ȉ��̎菇�őI���������Ɍ��肵�Ă����܂��傤�B" );
    CERR( "- K=1�̏ꍇ�A�e�I���ł͉\�ȑI���̒��ōő�̂��̂��̗p���܂��傤�B" );
    CERR( "- K=2�̏ꍇ�A�e�I���ł͉\�ȑI����{��2����,���ԍ�}��set�ŊǗ�����" );
    CERR( "  ���̒��ōő�̂��̂��̗p���܂��傤�B" );
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

AC( MaximisationFunctionOnTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "�u��i���_�܂łŐ؂�������F(P)�����̍ő�ldp[i]�v" );
  CERR( "���Ǘ�����i�Ɋւ��铮�I�v��@�iO(N^2�~f�̌v�Z��)�j" );
  CERR( "���������܂��傤�B" );
}

AC( MinimisationMovingCost )
{
  ASK_NUMBER(
	     "�Q�_�ŏ��R�X�g�ړ��i���H�j���" ,
	     "���_�ŏ��R�X�g�ړ��i�X�^���v�����[�j���"
	     );
  if( num == num_temp++ ){
    CERR( "����̌o�H��i�ނƎv������ōl�@�R�������\��������܂��B" );
    CERR( "�Ȃ�ׂ��S�Ă̌o�H���������T���A���S���Y����K�p������������ł��B" );
    CERR( "- ����̂Q�_�݂̂��l����ꍇ�ABFS��Dijkstra" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "- �S�Ă̂Q�_�̑g�ݍ��킹���l����ꍇ�A" );
    CERR( "  - ��ʂ̃��m�C�h���Z���l���Ă���O(V^3)���ʂ肻���Ȃ�΁AFloydWarshall" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
    CERR( "  - max���Z���l���Ă���O(E(log_2 E + ��(V)))���ʂ肻���Ȃ�΁AUnionFind" );
    CERR( "    \\Utility\\VLTree\\UnionFindForest" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "�_�̍��W�ƍŏ������ׂ��R�X�g�ȊO�̐��l�ω�������ꍇ�A�ŏ��R�X�g�ړ��ɂ�����" );
    CERR( "���̐��l�̓����͈͂��i���ē_�̍��W�Ƃ̑g�𒸓_�Ƃ���O���t���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "HeldKarp��A�ړ����@�𕪗ނ���p�����[�^�̑S�T��Ȃǂ��������܂��傤�B" );
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
  CERR( "HopcroftKarp��ő嗬" );
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
	     "�Œ蒷�ϐ��֐��ŗ^�����閾�����̒l�̐����グ���" ,
	     "�z��̕�����Ɋւ��鐔���グ���" ,
	     "�����Ɋւ��鐔���グ���" ,
	     "������̐����グ���" ,
	     "�헪�̐����グ���" ,
	     "����񐔂̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- �ϐ��̑Ώ̐�������Α召�֌W�𐧌������S�T��" );
  CERR( "- ���炩�̖񐔂ƂȂ�ȂǓ����͈͂������ϐ�������΂��������ߑł����S�T��" );
  CERR( "- ���ϐ��̍����֐��ŕ\����ꍇ�͔����S��" );
  CERR( "���������܂��傤�B" );
}

AC( CountingArray )
{
  ASK_NUMBER(
	     "��蕶�܂��͓��͂ŗ^������P�̔z��Ɋւ�����" ,
	     "�����𖞂����C�ӂ̔z��Ɋւ�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArbitraryArray );
  }
}

AC( CountingSubArray )
{
  ASK_NUMBER(
	     "�z��̐������󂯎��֐��̕����a���Œ肵��������̐����グ���" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̐����グ���" ,
	     "�z��̕����񂩂�擾�ʒu���𗎂Ƃ����z��̐����グ���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArrayImage );
  }
}

AC( CountingSumFixedSubArray )
{
  CERR( "����N�A�R�X�g�̑��a�̏��C�Ƃ��܂��B" );
  CERR( "- �R�X�g�Ɖ��l���قȂ�O(2^N)���ʂ肻���Ȃ�΋𒼂ȂQ�ϐ���������Z" );
  CERR( "- �R�X�g�Ɖ��l��������O(2^N)���ʂ肻���Ȃ�΋𒼂ȂP�ϐ���������Z" );
  CERR( "- �R�X�g�Ɖ��l��������O(2^{N/2}N)���ʂ肻���Ȃ�Δ�������������Z��" );
  CERR( "  ���čŌ�ɂ����̐ς̂P�W���݂̂̌v�Z" );
  CERR( "- �R�X�g�Ɖ��l��������C��10^5�I�[�_�[�Ŗ@���^�����Ă���O((N+C)log_2 C)��" );
  CERR( "  �ʂ肻���Ȃ�ΓK���Ȗ@�ł̍����t�[���G�ϊ�" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
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

AC( CountingArbitraryArray )
{
  ASK_NUMBER(
	     "�z����󂯎��֐��̒l�̐����グ���" ,
	     "�אڐ����Ԋ֌W���𖞂����z��̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "- �z��̎�ނ����Ȃ��ꍇ�́A�S�Ă̔z��ɑ΂���֐��̒l�̑O�v�Z" );
    CERR( "- ��蓾��l�����Ȃ��֐��������Ɋւ��čċA�I�\�������ꍇ�́A" );
    CERR( "  �u����i�̎��ɒlv�ł���z��̑���dp[i][v]�v" );
    CERR( "  ���Ǘ�����i,v�Ɋւ��铮�I�v��@" );
  } else if( num == num_temp++ ){
    CERR( "- �������̏����̏d�ˍ��킹�̎��͕����" );
    CERR( "- �S�����̏ꍇ�͐��̕������@�Ȃǂւ̖|��" );
    CERR( "- �a�Ȕ������̏ꍇ�̓O���t�̑O�v�Z" );
  }
  CERR( "���������܂��傤�B" );
}

AC( CountingSubArrayImage )
{
  CERR( "���͂ŗ^������z���A�ƒu���܂��B" );
  CERR( "�z��Ƃ��ē�����A�̕�����̂��������������ŏ��̂��̂𐔂��グ��" );
  CERR( "������DP���������܂��傤�B��̓I�ɂ�" );
  CERR( "�u��������i�����R���Ŏ������ŏ���A�̕�����̌�dp[i]�v" );
  CERR( "�us=A[j]�𖞂���j<i�̍ő�llast[i][s]�v" );
  CERR( "�̂Q���Ǘ�����i�Ɋւ��铮�I�v��@���������܂��傤�B" );
}

AC( CountingPartitionOfTree )
{
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "F(P)���Œ肳�ꂽ����P�̐����グ����" );
  CERR( "�u��i�����܂łŐ؂�������F(P)=v�𖞂���P�̌�dp[i][v]�v" );
  CERR( "���Ǘ�����i,v�Ɋւ��铮�I�v��@�iO(N^2 v_max�~f�̌v�Z��)�j" );
  CERR( "���������܂��傤�B" );
}

AC( CountingString )
{
  ASK_NUMBER(
	     "���������񂩂�擾�ʒu���𗎂Ƃ���������S�̂̐����グ���" ,
	     "�}�b�`���O�Ɋւ��鐫���𖞂�������������̐����グ���"
	     );
  if( num == num_temp++ ){
    CERR( "������𕶎��̔z��Ƃ݂Ȃ����ƂŁA�z��̖��ɋA�������邱�Ƃ��ł��܂��B" );
    CALL_AC( CountingSubArrayImage );
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

AC( CountingStrategy )
{
  CERR( "- �������W����̈ړ��o�H�̐����グ����" );
  CERR( "  �u�e�_i�ւ̈ړ��o�H�̌�dp[i]�v" );
  CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
  CERR( "- ���삷��Ώۂ̑I����@�̐����グ����" );
  CERR( "  ����Ώۂ��e�񕉐���i�œK�؂ɔԍ��t����" );
  CERR( "  �ui�ȉ��̔ԍ��̑Ώۂ݂̂��l�������̑I����@�̌�dp[i]�v" );
  CERR( "  ���Ǘ�����i�Ɋւ��铮�I�v��@" );
  CERR( "���������܂��傤�B" );
  ASK_YES_NO( "���`�Q�����ɋA������܂����H" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
    CERR( "���������܂��傤�B" );
  }
}

AC( Solving )
{
  CERR( "- �P���֐��͓񕪒T��" );
  CERR( "- �����֐��̓j���[�g���@" );
  CERR( "- �ꎟ�֐��͑|���o���@" );
  CERR( "���������܂��傤�B" );
}

AC( Query )
{
  ASK_NUMBER(
	     "�z��͈͍̔X�V�^�擾�N�G�����" ,
	     "�O���t�͈͍̔X�V�^�擾�N�G�����" ,
	     "�O���b�h�͈͍̔X�V�^�擾�N�G�����" ,
	     "���n��X�V�^�擾�N�G�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
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
	     "�ꎟ�֐��Ƃ�max��������l���g�����" ,
	     "�萔�Ƃ�max��������l�̋�Ԙa�擾���g�����"
	     );
  if( num == num_temp++ ){
    CERR( "- ���Z�^�S�X�V��̈�_�擾�݂̂��K�v�Ȃ�ΊK������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence" );
    CERR( "- ���Z�^�S�X�V�Ȃ��ŋ�Ԏ擾�݂̂��K�v�Ȃ�Ηݐϐ�" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\CumulativeProd" );
    CERR( "- ��ԉ��Z�^��Ԏ擾���K�v�Ȃ�Ή��QBIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template" );
    CERR( "- ��_����^��_���Z�^��Ԏ擾���K�v�Ȃ�Ή��Q��������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- ��_����^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�Ȃ�Ή�㰓����m�C�hBIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- ��_����^��Ԏ擾���K�v�Ȃ�΃��m�C�hBIT" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template\\Monoid" );
    CERR( "- ��_���Z�^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�Ȃ�΃��m�C�h��������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Monoid" );
    CERR( "- ��_����^��_�擾�^��Ԏ擾���K�v�Ȃ�΃��m�C�h�Z�O�����g��" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- �ʑ��̃R�[�h��" );
    CERR( "  \\Mathematics\\Function\\Encoder" );
    CERR( "�ɂ�胂�m�C�h�ɋA�������邱�Ƃ��������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- ��_��p�^��ԍ�p�^��_�擾���K�v�Ȃ�Αo�Ε�������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Dual" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- ��ԑ���^��ԍ�p�^��ԉ��Z�^��_�擾�^��Ԏ擾���K�v�ȏꍇ�͒x���]����������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\LazyEvaluation" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- �ꎟ�֐��ɂ��S��max�X�V�^��_�擾���K�v�ȏꍇ��Convex Hull Trick" );
    CERR( "  \\Mathematics\\Function\\MaxLinearFunction" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "max�őS�̍X�V�łȂ���ԍX�V������ꍇ�̔ėp�I�ȉ�@�͕�����܂���B" );
    CERR( "�Ⴆ�΋�Ԃ���܂ɂ��ĒP����max�����l���P���ł���ΑS�̍X�V��" );
    CERR( "���l�̏������ł��܂��B�󋵂ɉ������l�@�����܂��傤�B" );
    CERR( "" );
    CERR( "max�őS�̍X�V������ꍇ�Amax�����l�͒P���ł���ꍇ�ɋA���ł��܂��B" );
    CERR( "max�őS�̍X�V�����Ȃ��ꍇ�A�܂肽��max�̋�Ԙa���������邾���̏ꍇ�A" );
    CERR( "�N�G���̏��Ԃ����ւ��邱�Ƃ��ł���̂ŁA�P���ȑS�̍X�V�ɋA���ł��܂��B" );
    CERR( "�]���Ĉȉ��ł͒P���ȑS�̍X�V�̖����l���܂��B" );
    CERR( "" );
    CERR( "max�����萔��ϐ������A���̒l�Ƃ̑召��\��{0,1}�l�̌W�����l���܂��B" );
    CERR( "����Ƌ�ԍ�p�O��̒l�͓���I�ɂ��̌W���ƕϐ����g���ĕ\���܂��B" );
    CERR( "�z��̊e�����̌W���̒l���ω�����C�x���g�ƃN�G�����\�[�g���ĊǗ����A" );
    CERR( "�N�G�����C�x���g���ׂ����тɌW�����X�V���邱�Ƃ��������܂��傤�B" );
    CERR( "" );
    CERR( "�Ⴆ�΃N�G��B_q�ɑ΂���max(A_i,B_q)�̋�Ԙa�́A" );
    CERR( "- �D��x���L���[A'={(A_i,i)|i}�i�\�zO(N log N)�j" );
    CERR( "- (B_q,q)_q���\�[�g����B'�i�\�zO(Q log Q)�j" );
    CERR( "- ����N�̐���C=(0,...,0)�i�\�zO(N)�j" );
    CERR( "��p�ӂ��AB'��O����T�����ď��Ɋe�N�G��(B_q,q)���������܂��B" );
    CERR( "��̓I�ɂ�A'��O����T�����ď���A_i<B_q�ƂȂ�ei�ɑ΂�" );
    CERR( "- A'����(A_i,i)���폜�i�N�G�����vO(N)�j" );
    CERR( "- A_i��0�ɍX�V�i�N�G�����vO(N log N)�j" );
    CERR( "- C_i��1�ɍX�V�i�e�N�G��O(log N)�j" );
    CERR( "- A+C�~B_q�̋�Ԙa�擾�i�e�N�G��O(log N)�j" );
    CERR( "�Ƃ���΍��vO((N + Q)log N + Q log Q)�ŏ����ł��܂��B" );
  }
}

AC( QueryGraph )
{
  ASK_YES_NO( "�㐔�\�����������ł����H" );
  if( reply == "yes" ){
    CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V��̈�_�擾�݂̂��K�v�Ȃ�ΊK������" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence" );
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
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V�Ȃ��̋�Ԏ擾�݂̂��K�v�Ȃ�Γ񎟌��ݐϘa" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\CulmulativeProd\\TwoDimentioal" );
  CERR( "- ���Q�\���Ɋւ�����Z�^�S�X�V��̋�Ԏ擾���K�v�Ȃ�Γ񎟌��K������^�ݐϘa�̕��p" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\CulmulativeProd\\TwoDimentioal" );
  CERR( "���������܂��傤�B" );
}

AC( QueryTime )
{
  CERR( "��i�������ω����������Ԃ����̌���I�ƒu���܂��B" );
  CERR( "�e��Ԃ��X�ɕω��̎d���̈Ⴂ�ōו��������̂̌���J�ƒu���܂��B" );
  CERR( "- J��O(N)�Ȃ�Ίe�ו��ł̕ω��ʂ����߂܂��傤�B" );
  CERR( "- J��O(N)�łȂ�I��O(N)�Ȃ�Ίe��Ԃł̕ω��ʂ����߂܂��傤�B" );
  CERR( "�ω��ʂ̌v�Z��" );
  CERR( "- �K�������ݐϘa��BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\DifferenceSeqeuence" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\Tree\\CumulativeProd" );
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
}

AC( DecisionAccessibility )
{
  ASK_YES_NO( "��`�̈�̓��B�\�����ł����H" );
  if( reply == "yes" ){
    CERR( "���H�̍U���\����" );
    CERR( "- �X�^�[�g�ƃS�[��������̌ʏ�A�������ɑ�������" );
    CERR( "- �X�^�[�g�ƃS�[���𕪒f����ǂ̃p�X�̔񑶍ݐ�" );
    CERR( "�Ȃǂɖ|�󂵃O���t��̍ŏ��R�X�g�ړ����ɋA�������܂��傤�B" );
  } else {
    CERR( "�K�؂ȃO���t��̍ŏ��R�X�g�ړ����ɋA�������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
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

AC( DecisionPresentability )
{
  CERR( "����╶������g���ē���̐��╶����\���ł��邩�̔����" );
  CERR( "�u��i�����^�����܂łőł��؂������ɕ\���ł�����̑S�̂̏W��dp[i]�v" );
  CERR( "���Ǘ�����i�Ɋւ��铮�I�v��@���������܂��傤�B" );
  CERR( "" );
  CERR( "�֐��≉�Z�ւ̓K�p������ꍇ�͓K�X�����\���^������̏���" );
  CERR( "�������ē��I�v��@���������܂��傤�B" );
}

AC( Construction )
{
  ASK_NUMBER(
	     "����z��╶����̍\�z" ,
	     "�o�H�̍\�z" ,
	     "�헪�̍\�z" ,
	     "�\�[�X�R�[�h�̍\�z" ,
	     "�\���\���̔���"
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
    CERR( "�������o�͂�����\�[�X�R�[�h���o���܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  }
}
