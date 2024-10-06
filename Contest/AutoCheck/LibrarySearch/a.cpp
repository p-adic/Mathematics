// c:/Users/user/Documents/Programming/Contest/AutoCheck/LibrarySearch/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../SampleAnalyser/a_Body.hpp"

AC( LibrarySearch )
{
  ASK_NUMBER(
	     "�������̌v�Z���" ,
	     "�ő�^�ŏ������" ,
	     "�����グ���" ,
	     "������" ,
	     "�N�G���������" ,
	     "�Q�[�����" ,
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
    CALL_AC( Game );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  } else if( num == num_temp++ ){
    CALL_AC( Deduction );
  }
  CERR( "" );
  CERR( "���C�u�����[�T���͈ȏ�ł��B�I�����܂��B" );
}

AC( ExplicitExpression )
{
  ASK_NUMBER(
	     "�P�ϐ��֐��^����̌v�Z���" ,
	     "�z���p�����֐��̑��a�̌v�Z���" ,
	     "��d�a���d�ςȂǂ̌v�Z���" ,
	     "�����̊֐��̌v�Z���" ,
	     "�؏�̊֐��̑��a�̌v�Z���" ,
	     "�؈ȊO�̃O���t��̊֐��̌v�Z���" ,
	     "�����̌v�Z���" ,
	     "�m���^���Ғl�̌v�Z���" ,
	     "����񐔂̌v�Z���" ,
	     "�n�^�I�ؕИa���ݍ��݂̌v�Z���" ,
	     "�ʐς̌v�Z���" ,
	     "�Ɍ��̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnary );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSum );
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
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionLimit );
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
	     "�P�̔z��̐������󂯎��֐��̑��a�̌v�Z���" ,
	     "�Q�̔z��̓��ς̌v�Z���" ,
	     "�P�̔z��̕�������󂯎��֐��̑��a�̌v�Z���" ,
	     "�z����󂯎��֐��̔z����킽�鑍�a�̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOneArrayEntrySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionInnerProduct );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOneArraySubArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
  }
}

AC( ExplicitExpressionOneArrayEntrySum )
{
  CERR( "1�ϐ��֐�f(x)�Ɣz��(a_i)_{i=0}^{N-1}�ɑ΂���sum_i f(a_i)�Ȃǂ��l����" );
  CERR( "�Ƃ��܂��B�K�v�Ȃ��(a_i)_i���\�[�g���čL�`�P������Ƃ��܂��B" );
  CERR( "- f(a_{i+1}) - f(a_i)��O(1)�Ōv�Z�ł�O(N)���Ԃɍ��������Ȃ�΁A" );
  CERR( "  f(a_i)�̍����v�Z�ɂ�鍂����" );
  CERR( "- f(a_i)��i�Ɋւ��铙�䐔��K�̘a�ŕ\��O(K log N)���Ԃɍ��������Ȃ��" );
  CERR( "  ���䐔��̑��a�̌���" );
  CERR( "  \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "- f(a_i)��K�������s��A��K�����x�N�g��v��p����(A^i v)[0]�ƕ\��" );
  CERR( "  - A-E��������O(K^3 log N)���Ԃɍ��������Ȃ�΁A���䐔��̑��a�̌���" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "  - A-E�������Ƃ͌��炸O(K^3 log N)���Ԃɍ��������Ȃ�΁Av��f(a_i)��" );
  CERR( "    �ݐϘa�𖖔��}�����A�s��ݏ�" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "- #im(f)��������f(a_)�̊e�_�t�����v�Z���₷���Ȃ��" );
  CERR( "  f�̊e�_�t���ɂ��Z�ߏグ" );
  CERR( "  sum_i f(a_i)=sum_y #f(a_)^{-1}(y) y" );
  CERR( "- #im(f)��������f���񕉂�f(a_)�̎n�ؕЋt�����v�Z���₷���Ȃ��" );
  CERR( "  f�̎n�ؕЋt���ɂ��Z�ߏグ" );
  CERR( "  sum_i f(a_i)=sum_{y>=1} #f(a_)^{-1}([y,��))" );
  CERR( "- #dom(f)��������(a_)�̋t�����v�Z���₷���Ȃ��" );
  CERR( "  (a_)�̊e�_�t���ɂ��Z�ߏグ" );
  CERR( "  sum_i f(a_i)=sum_x #(a_)^{-1}(x) f(x)" );
  CERR( "- i%j = i - floor(i/j)j��p���ď�]�����ɋA��" );
  CERR( "  - i�Ɋւ���a��floor_sum" );
  CERR( "    \\Mathematics\\Combinatorial\\FloorSum" );
  CERR( "  - j�Ɋւ���a�͕�������" );
  CERR( "    \\Mathematics\\Combinatorial\\ResidueSum" );
  CERR( "- N���傫���ꍇ�Ə������ꍇ�ŉ�@�̐ܒ�" );
  CERR( "���������܂��傤�B" );
  CERR( "" );
}

AC( ExplicitExpressionInnerProduct )
{
  CERR( "����(a_i)_i��(b_i)_i���^������Ƃ��܂��B" );
  CERR( "f(X) = sum_{i=0}^{N-1} a_i X^i" );
  CERR( "g(X) = sum_{i=0}^{N-1} b_{N-i-1} X^i" );
  CERR( "�ƒu���܂��B" );
  ASK_NUMBER(
             "(sum_{i=0}^{N-i-j} a_i b_{i+j})_{j=0}^{N-1}�̌v�Z"
             "(sum_{i=0}^{N-1} a_i b_{i+j})_{j=0}^{N-1}�̌v�Z"
             );
  if( num == num_temp++ ){
    CERR( "f(X)g(X)mod X^N = sum_{i=0}^{N-1} c_i X^i" );
    CERR( "�ƒu����" );
    CERR( "(c_{N-1-j})_{j=0}^{N-1}" );
    CERR( "�������ł��B" );
  } else if( num == num_temp++ ){
    CERR( "f(X)g(X) = sum_{i=0}^{2N-2} c_i X^i" );
    CERR( "�ƒu����" );
    CERR( "(sum_{k \equiv -1-j mod N}c_k)_{j=0}^{N-1}" );
    CERR( "�������ł��B" );
  }
  CERR( "\\Mathematics\\Polynoial\\Truncate" );
}

AC( ExplicitExpressionOneArraySubArraySum )
{
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

AC( ExplicitExpressionDoubleSum )
{
  CERR( "2�ϐ��֐�f(x,y)�Ɣz��(a_i)_{i=0}^{N-1}, (b_j)_{j=0}^{M-1}�ɑ΂���" );
  CERR( "��d�asum_i sum_j f(a_i,b_j)�Ȃǂ��l����Ƃ��܂��B" );
  CERR( "�K�v�Ȃ��(a_i)_i��(b_j)���\�[�g���ĂƂ��ɍL�`�P������Ƃ��܂��B" );
  CERR( "- sum_i f(a_i,b_j)�̌v�Z�ʂ�O(g(N))�Ƃ���O(g(N)M)���Ԃɍ��������Ȃ�΁A" );
  CERR( "  �a�̏�������sum_i sum_j f(a_i,b_j) = sum_j sum_i f(a_i,b_j)" );
  CERR( "- sum_j (f(a_i,b_{j+1}) - f(a_i,b_j))�̌v�Z�ʂ�O(g(N))�Ƃ���O(g(N)M)��" );
  CERR( "  �Ԃɍ��������Ȃ�΁Asum_j f(a_i,b_j)�̍����v�Z�ɂ�鍂����" );
  CERR( "- f(x,y)=sum_k g_k(x) h_k(y)�ƕ\���ł�O(K(N+M))���Ԃɍ��������Ȃ��" );
  CERR( "  �ϐ�����sum_{i,j} f(a_i,b_j)=sum_k(sum_i g_k(a_i))(sum_j h_k(b_j))" );
  CERR( "- #im(f)��������f(a_,b_)�̊e�_�t�����v�Z���₷���Ȃ��" );
  CERR( "  f�̊e�_�t���ɂ��Z�ߏグ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_z #f(a_,b_)^{-1}(z) z" );
  CERR( "- #im(f)��������f���񕉂�f(a_,b_)�̎n�ؕЋt�����v�Z���₷���Ȃ��" );
  CERR( "  f�̎n�ؕЋt���ɂ��Z�ߏグ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_{z>0} #f(a_,b_)^{-1}([z,��))" );
  CERR( "- #dom(f)��������(a_,b_)�̊e�_�t�����v�Z���₷���Ȃ��" );
  CERR( "  (a_,b_)�̊e�_�t���ɂ��Z�ߏグ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_v #(a_,b_)^{-1}(v) f(v)" );
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
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
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
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "  - �d�݂��u�P�ʌ����ŏ����ł���meet�������m�C�h�v�ɒl������" );
  CERR( "    O(V^3)���Ԃɍ��������Ȃ�΃��[�V�����t���C�h�@" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
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
      CALL_AC( ExplicitExpressionOrderOfElement );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionRandomAccess );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionTotalAccess );
    }
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  }
}

AC( ExplicitExpressionOrderOfElement )
{
  ASK_YES_NO( "�ei���Ƃ�a[i]�������ɋ��߂�����ł����H" );
  if( reply == "y" ){
    CERR( "i�Ɋւ���񕪒T�����������܂��傤�B" );
  } else {
    CERR( "s������S�̍��̐����グ���������܂��傤�B" );
    CALL_AC( CountingArrayBoundedTotal );
    ASK_YES_NO( "S���Œ蒷�ϐ��֐��̑��ŗ^�����܂����H" );
    if( reply == "y" ){
      CERR( "�Œ蒷�ϐ��֐��̋t���̐����グ���́A" );
      CALL_AC( CountingExplicitExpression );
    }
  }
}

AC( ExplicitExpressionRandomAccess )
{
  CERR( "S�̊e�v�fs���Ƃ�s������S�̍��𐔂��グ�����l���āA" );
  CERR( "s�Ɋւ���񕪒T�����������܂��傤�B" );
  CALL_AC( CountingArrayBoundedTotal );
  ASK_YES_NO( "S���Œ蒷�ϐ��֐��̑��ŗ^�����܂����H" );
  if( reply == "y" ){
    CERR( "�Œ蒷�ϐ��֐��̋t���̐����グ���́A" );
    CALL_AC( CountingExplicitExpression );
  }
}

AC( ExplicitExpressionTotalAccess )
{
  CERR( "- �ei���Ƃ�a[i]�������ɋ��߂���Ȃ�΁Aa[i]�ȉ���S�̗v�f�̑S��" );
  CERR( "- S�����d�W��M�̘a�W���ł���Ȃ�΁A�e���d�W�����\�[�g����M��priority_queue�ŃC�x���g�\�[�g" );
}

AC( ExplicitExpressionProbability )
{
  CERR( "- �m���v�Z��" );
  CERR( "  - ���ۂ�S�T�􂵂Ă��ꂼ��̊m�����v�Z" );;
  CERR( "  - �]���ۂ������i�����[�[�^�ϊ��^���r�E�X�ϊ��j" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - �Ώۂ�Ɨ��ϐ��̐ςŕ\���ď�@��" );
  CERR( "    - �O���b�h�̃}�X�Ȃǂ̒��ϏW���̗v�f����`�̈�ɑ������ۂ��̊m����" );
  CERR( "      �������Ƃ̊m���̐ςɋA��" );
  CERR( "  - ���l�Ɋm���炵�����ۂ̓���" );
  CERR( "  - �x�C�Y�̒藝" );
  CERR( "- ���Ғl�v�Z��" );
  CERR( "  - �m����p�����𒼂Ȍv�Z" );
  CERR( "  - �Ώۂ�a�ŕ\���Đ��`��" );
  CERR( "    - �]�|����O���b�h�̍��}�X�̌��ȂǕ����W���̗v�f���̊��Ғl��" );
  CERR( "      �e�v�f�������W���ɑ����m���̘a�ɋA��" );
  CERR( "    - �P�ʎ��Ԃɍ��X1��N���鎖�ۂ̋N�����񐔂́A�e����t���Ƃ�" );
  CERR( "      +1�̋N����m��p(t)�̑��a" );
  CERR( "    - �����o��܂ł̃R�C�������񐔂Ȃ�n��ȏ�\���o��m��p(n)�̑��a" );
  CERR( "  - ����^�J�ډ񐔂Ȃ���Ғl�Ԃ̊֌W�������ߍs��ݏ��{�X�^���X�@" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Polynomial\\BostanMori" );
  CERR( "  - �O���b�h�̓h��ׂ��Ȃ�x���k�[�C���O�v�Z�ɂ��p��֐��̑��a��p����������" );
  CERR( "    \\Mathematics\\Polynomial\\Cumulative\\GridStampCoveringExpectation" );
  CERR( "���������܂��傤�B" );
}

AC( ExplicitExpressionCountingOperation )
{
  CALL_AC( ReducingOperation );
  CERR( "���̏�őI���̗]�n�̂Ȃ�����񐔂����߂�ۂ́A" );
  CERR( "- �������C�x���g�Ƃ݂Ȃ����n��ɕ��ׁA�u��Ăɏ����ł����ԁv������" );
  CERR( "  �ɕ������A���ꂼ��̋�Ԃł̏������܂Ƃ߂Čv�Z" );
  CERR( "- ����Ώۂ�����D��x���ŕ�������ꍇ�́A�e����Ώۂ̑���񐔂Ɋւ��铮�I�v��@" );
  CERR( "- ���삪�������̑ΏیQ�ɓ����ɍs����Ȃ�΁A�e�ΏیQ���Ƃɉ񐔌v�Z" );
  CERR( "- ���삪�ӂ̍폜�Ȃ�΁A�t�����ɏ������Ċe�A���������Ƃɑ���񐔂��L�^" );
  CERR( "���������܂��傤�B" );
}

AC( ReducingOperation )
{
  CERR( "����Ώۂ����炩�̕s�ϗʂŕ��ނ��A�����s�ϗʊԂ̑J�ڂƂ݂Ȃ����Ƃ�" );
  CERR( "�Ȃ�ׂ��ȒP�Ȗ��ɋA�������܂��傤�B" );
  CERR( "- ����ŊK������̊����������Ȃ�΁A���̑��a�ɒ���" );
  CERR( "- ����ŗݐϘa�̍ő�l�ƍŏ��l�̍�������Ȃ�΁A���̍��ɒ���" );
  CERR( "- ����ŗאڐ����Ƃ̑召���ς��Ȃ�΁A���̑召�֌W���Ǘ�����01��ɒ���" );
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
    CERR( "- �����W���̊e�����W����n�鑍�a�͍����[�[�^�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- �֐��l���v�f���Ɉˑ�����ꍇ�̏�ݍ��݂͍����[�[�^�ϊ��^�������r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- �֐��l���v�f���Ɉˑ����Ȃ��ꍇ�̏�ݍ��݂̓}�[���[�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  } else if( num == num_temp++ ){
    CERR( "- N�̊e�񐔂�n�鑍�a�͖񐔗񋓂ő��a�v�Z" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
    CERR( "- [1,N]��̊֐��̏�ݍ��݂͖񐔃[�[�^�ϊ��^�񐔃��r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\Divisor" );
    CERR( "- N�̖񐔏�̊֐��̏�ݍ��݂�N��f��������������Ŗ񐔃[�[�^�ϊ���" );
    CERR( "  N/����ł̒l�݂̂����ό`�Ōv�Z���e�_��Z������" );
    CERR( "  ����̑f�����̌����g�������r�E�X�֐��ō������r�E�X�ϊ��̌v�Z" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
  } else if( num == num_temp++ ){
    CERR( "- �v�fs�̏I�ؕЂł̑��a�͗אڑ㐔��̃[�[�^�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- join�Ɋւ����ݍ��݂͗אڑ㐔��̃[�[�^�ϊ��^���r�E�X�ϊ�" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
  }
  CERR( "���������܂��傤�B" );
  CERR( "" );
  CERR( "������̏�Z�͕�������" );
  CERR( "Mathematics\\Arithmetic\\a.hpp" );
  CERR( "���������܂��傤�B" );
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

AC( ExplicitExpressionLimit )
{
  CERR( "- lim_{T->infty} \frac{1}{T} sum_{t=1}^{T} a_t�̌`�̌v�Z��" );
  CERR( "  - a_t����������Ȃ�΂��̒l�̌v�Z" );
  CERR( "  - a_t���������Ȃ��������I�Ȃ�Ύ�����P�Ƃ���" );
  CERR( "    lim_{T->infty} \frac{1}{P} sum_{t=T+1}^{T+P} a_t�̌v�Z" );
  CERR( "    - �������Z���ꍇ�͎��ۂɃV�~�����[�V�����ɂ��v�Z" );
  CERR( "    - ���̑������ȂǂŎ����I�ł��邱�Ƃ͕������Ă����̋�̓I�ȐU�镑����" );
  CERR( "      ������Ȃ��ꍇ�͏������P�[�X�Ŏ���" );
  CERR( "- lim_{N->infty} \frac{1}{N} sum_{i=1}^{N} f(i/N)�̌`�̌v�Z��" );
  CERR( "  �敪���ϖ@" );
  CERR( "  - �@P�v�Z�Ȃ�Δ��ϕ��w�̊�{�藝��p���Č��n�֐��̌v�Z�ɋA��" );
  CERR( "  - �덷���Ȃ�΃����e�J�����@��p���ċߎ��v�Z" );
  CERR( "���������܂��傤�B" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "�ړ��R�X�g�̍ŏ������" ,
	     "�ړ����̍ő剻���" ,
	     "�i�b�v�T�b�N���" ,
	     "�z���̊֐��Ɋւ���ő�^�ŏ������" ,
	     "�z��̗אڐ����Ԋ֌W���𖞂���������̍Œ������" ,
	     "�᎟���A�t�B����ԏ�̊֐��̍ő�^�ŏ������" ,
	     "�W���̕����W���Ɋւ���ő�^�ŏ������" ,
	     "�O���t�̌o�H�Ɋւ���ő�^�ŏ������" ,
	     "�؏�̊֐��Ɋւ���ő�^�ŏ������" ,
	     "������̃}�b�`���O�Ɋւ���ő�^�Œ������" ,
	     "�m���^���Ғl�̍ő剻���" ,
	     "����R�X�g�̍ŏ������" ,
	     "����񐔂̍ő剻���" ,
	     "�핢���a�̍ŏ������" ,
	     "�`��T�C�Y�^���̍ő�^�ŏ������" ,
	     "�ŏ��l�̍ő剻���" ,
	     "�����a�̍ŏ������" ,
	     "2�l�Q�[���̍ŏI�I�ȕs�ϗʂ̍ő�^�ŏ������"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistance );
  } else if( num == num_temp++ ){
    CALL_AC( Knapsack );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationGraph );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationOperationCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationCoveringSize );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationDrawingImage );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMinimum );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSum );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  }
}

AC( MinimisationMovingCost )
{
  CERR( "�}���`�N�G���̏ꍇ�́A�X�̃N�G���P�ʂŎ��̎���ɓ����Ă��������B" );
  ASK_NUMBER(
	     "�P�n�_���I�_�R�X�g�ŏ����i���H�j���" ,
	     "�P�n�_�����ԓ_�P�I�_�R�X�g�ŏ����i��i�K���H�j���" ,
	     "�P�n�_���o�R�_���I�_�R�X�g�ŏ����i�X�^���v�����[�j���" ,
	     "���n�_�P�I�_�R�X�g�ŏ����i�����j���" ,
	     "���n�_���I�_�R�X�g�ő�l�ŏ����i�J�핢�j���" ,
	     "���v���C���[�R�X�g���a�ŏ����i�ŏ���p���j���" ,
	     "�ŋߐړ_���"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "�n�_����e���ԓ_�ւ̍ŒZ�o�H���ƁA�I�_����e���ԓ_�ւ̍ŒZ�a�H���" );
    CERR( "���������ƂłP�n�_���I�_�R�X�g�ŏ����i���H�j���ɋA������܂��B" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "- �o�R�_�̌o�R�������w�肳��Ă���Ȃ�΁A�O���t�̐��`�O���t�ɑ΂���" );
    CERR( "  ���������_�C�N�X�g���@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double\\Errand" );
    CERR( "- �o�R�_�̌o�R�������w�肳��Ă��炸���o�R�_�����_�S�̂Ȃ�΁AHeldKarp�@" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "- �ŒZ�o�H�̎n�_�̓��肪�s�v�Ȃ�΁A�n�_���P�ǉ����Č��̎n�_�փR�X�g0��" );
    CERR( "  �L���ӂ�ǉ�" );
    CERR( "- �ŒZ�o�H�̎n�_�̓��肪�K�v�Ȃ�΁A�ӂ𔽓]" );
    CERR( "�ɂ��P�n�_���I�_�R�X�g�ŏ��R�X�g���i���H�j���ɋA������܂��B" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingOpenCovering );
  } else if( num == num_temp++ ){
    CERR( "�e�I�_tj���S�[���Ƃ��ėǂ��l���̏����Nj�ƒu����" );
    CERR( "- �e�ӂ̗e�ʂ����ɐݒ�" );
    CERR( "- �e�n�_si�֗e��1�R�X�g0�̕ӂ������_S��ǉ�" );
    CERR( "- �e�I�_tj����e��Nj�R�X�g0�̕ӂ������_T��ǉ�" );
    CERR( "�Ƃ��邱�Ƃœ�����L�����O���t�ɑ΂�Primal-Dual�@��K�p���܂��傤�B" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Potentialised\\MinimumCostFlow" );
  } else if( num == num_temp++ ){
    CERR( "D�������[�N���b�h��ԓ���N�_���l���܂��B" );
    CERR( "- L^p�����Ɋւ���ŋߓ_�Ζ��ł���O(N log N)���Ԃɍ��������Ȃ��" );
    CERR( "  ��Ԃ��Q�����镪�������Ń}�[�W���Ɏ}����" );
    CERR( "  https://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf" );
    CERR( "- D=1�łP�_����_�Q�ւ̋����̍ŏ������ł���O(log N)���Ԃɍ��������Ȃ��" );
    CERR( "  set��̂Q���T��" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
    CERR( "- D=1�œ_�Q����_�Q�ւ̋����̍ŏ������ł���O(N log N)���Ԃɍ��������Ȃ��" );
    CERR( "  �\�[�g���č��E���瓥��" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
    CERR( "- D=2��x����̓_�Q����_�Q�ւ�L^1�����̍ŏ������ł���O(N log N)��" );
    CERR( "  �Ԃɍ��������Ȃ��x���W�Ń\�[�g���č��E����ݐ�min�v�Z" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance\\Li" );
    CERR( "- �n�C�u���b�h�����Ȃ�΋����̕ω��_�ŏꍇ���������āA���ꂼ��ɑ΂���" );
    CERR( "  �ŏ������ɋA��" );
    CERR( "- �O���t�ɂ��^�����鋗���Ōo�H��ɁiN�_�̊O�ɂ��邩������Ȃ��j�o�R�_�Q" );
    CERR( "  �����݂���Ȃ�Όo�R�_�Q����̋����̍ŏ������ɋA��" );
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
}

AC( MinimisationSolvingMaze )
{
  ASK_YES_NO( "����̕ӌQ�̍��v�g�p�񐔂ɐ���������܂����H" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeBoundedChoice );
  } else {
    ASK_YES_NO( "|E|��10^8�I�[�_�[�ŗ}�����܂����H" );
    if( reply == "y" ){
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceManyEdges );
    }
  }
}

AC( MinimisationSolvingMazeBoundedChoice )
{
  CERR( "���v�g�p�񐔂ɐ����̂Ȃ��ӂ�����E_0�A�����̂���ӂ�����E_1�A" );
  CERR( "�g�p�񐔂̏����C�ƒu���܂��B" );
  ASK_YES_NO( "|E_0|*(C+1)+|E_1|*C��10^8�I�[�_�[�ŗ}�����܂����H" );
  if( reply == "y" ){
    CERR( "�g�p�񐔂��Ƃɒ��_�𕡐����āA|V|���_|E_0|�ӂ̖����O���t|C+1|��" );
    CERR( "��֏�O���t���\�����邱�ƂŁA���v�g�p�񐔐����̂Ȃ����ɋA���ł��܂��B" );
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
  } else {
    ASK_YES_NO( "C=1����I�_�ł����H" );
    if( reply == "y" ){
      CERR( "(V,E_0)�ɑ΂��n�_�ƏI�_����̈�n�_���I�_�ŒZ�o�H���������A" );
      CERR( "�e2�_�Ԃ�E_1�Ō��񂾎��̍ŒZ�o�H��2�d���[�v�₻�̃f�[�^�\����������" );
      CERR( "�v�Z���邱�Ƃō��v�g�p�񐔐����̂Ȃ����ɋA���ł��܂��B" );
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CERR( "(V,E_0)�ɑ΂����n�_���I�_�ŒZ�o�H���������A�e2�_�Ԃ��P�񂾂�E_1��" );
      CERR( "���񂾎��̍ŒZ�o�H��2�d���[�v�₻�̃f�[�^�\���������Ōv�Z���܂��B" );
      CERR( "���̌�A���̌��ʂ�MinTropicalSemirng���|V|�������s��Ɋi�[���A" );
      CERR( "0�悩��C��܂ł̑�min��O(V^3 C)�Ōv�Z���邱�Ƃ�" );
      CERR( "���v�g�p�񐔐����̂Ȃ����ɋA���ł��܂��B" );
      CALL_AC( MinimisationSolvingOpenCovering );
    }
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdges )
{
  ASK_YES_NO( "���Z��㰓��I�ł����H" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent )
{
  CERR( "�R�X�g�����C�ƒu���܂��B" );
  ASK_YES_NO( "�}���`�N�G���ł����H" );
  if( reply == "y" ){
    CERR( "�N�G���񐔂�Q�ƒu���܂��B" );
    CERR( "- O(E log_2 E + (V + (E + Q)��(V) + min(C,Q log_2 Q))log_2 E)" );
    CERR( "  ���Ԃɍ��������Ȃ�΃R�X�g�ŕӂ��\�[�g����UnionFind����񕪒T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\ParallelBinarySearch" );
    CERR( "- �����łȂ��n�_�����ʂȂ�΁A�V���O���N�G���̉�@�ő��I�_����v�Z" );
    CERR( "- �����łȂ��Ȃ�΁A�V���O���N�G���̉�@��Q�񔽕�" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "�ȉ��A�V���O���N�G���̉�@��������܂��B" );
  }
  CERR( "- O(min(V^2,(V+E)log_2 E))���Ԃɍ��������Ȃ�΃_�C�N�X�g���@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- O((V+E)C)���Ԃɍ��������Ȃ�΃R�X�g�ő�l����ԂɊ܂߂��O���t��ł�" );
  CERR( "  ���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "- O(V + E(log E + ��(V)))���Ԃɍ��������Ȃ��" );
  CERR( "  �R�X�g�ŕӂ��\�[�g����UnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind" );
  CERR( "- O(V + E��(V + log_2 E)))���Ԃɍ��������Ȃ��" );
  CERR( "  �N���X�J���@�ōŏ��S��؂܂ŕӂ��팸����BFS/DFS�{�o�H����" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\Kruscal" );
  CERR( "- G���O���t�̔�֏�O���t�Ȃ��" );
  CERR( "  - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))���Ԃɍ��������Ȃ��" );
  CERR( "    ���������_�C�N�X�g���@" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "  - �Ԃɍ���Ȃ������Ȃ�Ε��������𓮓I�v��@�ŏ��������f�[�^�\��������" );
  CERR( "- �ӂ̃R�X�g�̂���K�Ԗڂɑ傫���l�̍ŏ�����O((V+E)log C)���Ԃɍ�������" );
  CERR( "  �Ȃ�΁A�R�X�gc�����ߑł��ĕӂ̐V���ȏd�݂Ƃ��āu�R�X�g��c���傫���v��" );
  CERR( "  �^�U���l����01���D��T�����s���A�o�H�̏d�݂̑��a�̍ŏ��l��K�����ł���" );
  CERR( "  �悤��c�̍ŏ��l��񕪒T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BFS\\01" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent )
{
  ASK_YES_NO( "�R�X�g�͕��ɂȂ肦�܂����H" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative )
{
  CERR( "- O(VE)���Ԃɍ��������Ȃ�΁A�x���}���t�H�[�h�@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- �}���`�N�G���ŕӂ̍폜���s��O(VE+Q(V+E)log_2 E)���Ԃɍ��������Ȃ��" );
  CERR( "  �x���}���t�H�[�h�@�ɂ��|�e���V�����O�v�Z�{�|�e���V�����t���_�C�N�X�g���@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Potentialised\\BellmanFord" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative )
{
  ASK_YES_NO( "�}���`�N�G���ł����H" );
  if( reply == "y" ){
    CERR( "�N�G���񐔂�Q�ƒu���܂��B" );
    CERR( "- O(V^3 + Q)���Ԃɍ��������Ȃ�΃��[�V�����t���C�h�@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
    CERR( "- �����łȂ��n�_�����ʂȂ�΁A�V���O���N�G���̉�@�ő��I�_����v�Z" );
    CERR( "- �����łȂ��Ȃ�΁A�V���O���N�G���̉�@��Q�񔽕�" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "�ȉ��A�V���O���N�G���̉�@��������܂��B" );
  }
  CERR( "- �R�X�g��1�݂̂���O(V+E)���ʂ肻���Ȃ�΁A���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- �����łȂ��R�X�g��{0,1}�l����O(V+E)���ʂ肻���Ȃ�΁A01���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- �����łȂ��Ȃ�΃R�X�g���a�����C�Ƃ��A" );
  CERR( "  - O(min(V^2,(V+E)log_2 E))���Ԃɍ��������Ȃ�΃_�C�N�X�g���@" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "  - O((V+E)C)���Ԃɍ��������Ȃ�΁A�R�X�g���a����ԂɊ܂߂��O���t��" );
  CERR( "    �ł̕��D��T��" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "  - G���O���t�̔�֏�O���t�Ȃ��" );
  CERR( "    - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))���Ԃɍ�������" );
  CERR( "      �Ȃ�Ε��������_�C�N�X�g���@" );
  CERR( "      \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "    - �Ԃɍ���Ȃ������Ȃ�΁A���������𓮓I�v��@�ŏ��������f�[�^�\��������" );
}

AC( MinimisationSolvingMazeUnboundedChoiceManyEdges )
{
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
  CERR( "�Ⴆ�Όo�H��ۓ�������@�ł����ăR�X�g���傫���Ȃ�Ȃ����̂���肵�A" );
  CERR( "�ۓ��\�łȂ��o�H�݂̂ɍi�邱�Ƃ�E�����炵�܂��傤�B" );
}

AC( MinimisationSolvingOpenCovering )
{
  ASK_YES_NO( "�n�_�i�핢���S�j����܂��Ă��邩�A�܂���E���������ł����H" );
  if( reply == "y" ){
    CERR( "- �R�X�g���Ȃ�O(V+E)���ʂ肻���Ȃ�΁A���_���D��T����" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̕��D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
    CERR( "- �R�X�g��0��1��O(V+E)���ʂ肻���Ȃ�΁A���_01���D��T��" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł�01���D��T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
    CERR( "- max���Z���l���Ă���O(E(log_2 E + ��(V)))���ʂ肻���Ȃ�΁A" );
    CERR( "  �d�݂ŕӂ��\�[�g���đf�W���f�[�^�\��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
    CERR( "- O((V+E)log_2 E)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���_���P�ǉ����e�n�_�ɕӂ𒣂����O���t��ł̃_�C�N�X�g���@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
    CERR( "- O(V^3)���ʂ肻���Ȃ�΁A" );
    CERR( "  ���[�V�����t���C�h�@" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
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
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- �R�X�g�����ɂȂ肦��O(VE)���Ԃɍ��������Ȃ��1�{���ăx���}���t�H�[�h�@" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- �R�X�g��1�Ŗ����O���t�Ƃ��Ċ��S�ȗL���O���t��O(V log V)���Ԃɍ��������Ȃ��" );
  CERR( "  V�Ɋւ���ċA�I�\��" );
  CERR( "  https://yukicoder.me/submissions/916203" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "��蕶�܂��͓��͂ŗ^������P�̔z��Ɋւ�����" ,
	     "�����𖞂����C�ӂ̔z��Ɋւ�����"
	     );
  if( num == num_temp++ ){
    CERR( "�\�[�g���Ă��������ς��Ȃ��Ȃ�ΓK�X�\�[�g���܂��傤�B" );
    ASK_NUMBER(
	       "�������󂯎��֐��̕����a�̍ő剻���" ,
	       "�������󂯎��֐��̕����a�ƕʂ̊֐��̕╔���a�̘a�̍ő剻���" ,
	       "�������󂯎��֐��̕����a�ƕ╔���a�̍��̍ŏ������" ,
	       "0/1�{�ȊO�̔z��̕ύX�Ɣz����󂯎��֐��̍����̍ő�^�ŏ������"
	       );
    if( num == num_temp++ ){
      CALL_AC( Knapsack );
    } else if( num == num_temp++ ){
      CERR( "�֐���f��g�Ƃ������A" );
      CERR( "- f��g�ɑ�����鍀���ɐ������Ȃ��Ȃ�΁Amax(f(i),g(i))�̑��a" );
      CERR( "- f�ɑ�����鍀����K�ŌŒ�Ȃ�΁Af(i)-g(i)��傫������K��" );
      CERR( "  ���������̂�g�̑��a�̘a" );
      CERR( "�����߂�ő�l�ł�" );
    } else if( num == num_temp++ ){
      CERR( "�����a�Ƒ��a�̔����̍��̍ŏ������s���܂��傤�B" );
      CERR( "����͏����������l���邱�Ƃŏ���t�������a�̍ő剻���ƂȂ�܂��B" );
      CALL_AC( Knapsack );
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

AC( Knapsack )
{
  CERR( "���a�����l�����l�ƌĂԂ��Ƃɂ��܂��B" );
  CERR( "�z��̍���N�A��i�����̉��lA_i�A���l�̑��a�̏��V�Ƃ��܂��B" );
  CERR( "{0,...,N-1}�̕����W���܂��͏W���Ƃ��Ċ܂܂�鑽�d�W��I�ł����āA" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- ���̑��̏���" );
  CERR( "�𖞂������̂����݂���v <= V�̍ő剻���l���܂��B" );
  CERR( "" );
  CERR( "�R�X�g�̑��a���C�Ƃ��܂��B�R�X�g�̔��������m�C�h�ɂ�����C�ȉ��̌�" );
  CERR( "�S�̂̏W���̗v�f����|C|�ƒu���܂��B" );
  ASK_NUMBER(
	     "I���n�ؕЂɌ���ꍇ" ,
	     "�����łȂ�I����ԂɌ���ꍇ" ,
	     "�����łȂ�I�̘A���������ɏ��������ꍇ" ,
	     "�����łȂ��ꍇ"
	     );
  if( num == num_temp++ ){
    CALL_AC( KnapsackInitialSegment );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackInterval );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackBoundedIntervalLength );
  } else {
    ASK_YES_NO( "�e���ڂ�������I���ł��܂����H" );
    if( reply == "y" ){
      CALL_AC( KnapsackMultipleChoice );
    } else {
      ASK_YES_NO( "���ڂɑI�΂ꂽ���ɂ���č��ڂ̃R�X�g���ϓ����܂����H" );
      if( reply == "y" ){
	CALL_AC( KnapsackOrdered );
      } else {
	ASK_YES_NO( "�i�b�v�T�b�N�͂P�ł����H" );
	if( reply == "y" ){
	  CALL_AC( SingleKnapsack );
	} else {
	  CALL_AC( MultipleKnapsack );
	}
      }
    }
  }
}

AC( KnapsackInitialSegment )
{
  CERR( "���l���񕉂Ȃ�΁A�擪���牽���I�ׂ邩�������d�v�ł��邽��" );
  CERR( "���l�ƃR�X�g�̑g�����l�Ƃ݂Ȃ��������ƂŃR�X�g�̂Ȃ��i�b�v�T�b�N���Ƃ݂Ȃ��܂��B" );
  CERR( "���l(A_i)_i�̕����a�ŕ\���Ȃ����l�S�̂̏W�����L���̏��L�����Ƃ��܂��B" );
  ASK_YES_NO( "�i�b�v�T�b�N�͂P�ł����H" );
  if( reply == "y" ){
    CERR( "V>L�̏ꍇ��V�������ɂȂ�̂ŏꍇ������V<=L�̏ꍇ�ɋA�����A" );
    CERR( "��͋𒼂ɋ��߂邩���ό`�ŉ����܂��傤�B" );
  } else {
    CERR( "�i�b�v�T�b�N���Q�ł���Ƃ��A�����̉��l��������ꂼ��V_1 <= V_2�ƒu���A" );
    CERR( "�K�v�Ȃ�΃\�[�g����(A_i)_i�������ł���Ƃ��A�e�񕉐���n�ɑ΂�" );
    CERR( "s_n := sum_{i=0}^{n} A_i" );
    CERR( "�ƒu���AA_n > 2L�𖞂����ŏ���n��N_1�ƒu���As_n > V_1�𖞂���" );
    CERR( "�ő��n��N_2�ƒu���AA_n > V_1�𖞂����ő��n��N_3�ƒu���܂��B" );
    CERR( "�I�����鍀�ڑS�̂̏W�����n�ؕЂłȂ���΂Ȃ�Ȃ��Ȃ�΁A" );
    CERR( "- N_1 <= N_2�Ȃ��max(V_1-s_n,s_{n+1}-V_1) > L�Ȃ̂�n+1�܂ł�" );
    CERR( "  ���ڂ����܂��g�ݍ��킹��V_1���\���邽�߉��l���V = V_1 + V_2��" );
    CERR( "  �ꍇ�ɋA��" );
    CERR( "- N_1 > N_2�Ȃ�΁AN_3�����̊ei�ɑ΂�[0,i]�܂ł̑I���\���y��" );
    CERR( "  �I���\���̃i�b�v�T�b�N�P�݂̂̉��l�̍ő�l��V_1'�Ƃ���ƁA" );
    CERR( "  N_3�����̐�����O���Ă�V_1���傫���l�̓i�b�v�T�b�N�P�ɓ���Ȃ�" );
    CERR( "  ���߉��l���V = V_1' + V_2�̏ꍇ�ɋA��" );
    CERR( "���������܂��傤�B" );
  }
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree\\InitialSegment" );
}

AC( KnapsackInterval )
{
  ASK_YES_NO( "��Ԓ��͌Œ�ł����H" );
  if( reply == "y" ){
    CERR( "��Ԃ��X���C�h���Ă����A���[�̍X�V�l��p���čő�l���Ǘ����܂��傤�B" );
  } else {
    CERR( "- ��Ԃɑ����ׂ��_���^�����Ă���Ȃ�΁A���̓_�̗����Ŏn�ؕИa�ƏI�ؕИa��" );
    CERR( "  �ŏ��l�̑��a�����ߑS�̂̑��a��������΂悢�̂ŁA�n�ؕИa�̎n�ؕЍő�l��" );
    CERR( "  �I�ؕИa�̏I�ؕЍő�l��O�v�Z���܂��傤�B" );
    CERR( "- �����łȂ��Ȃ�΁A�ڎ��@�ŋ�Ԃ�L�΂����[�̍X�V�l��p���čő�l���Ǘ����܂��傤�B" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Interval" );
  }
}

AC( KnapsackBoundedIntervalLength )
{
  CERR( "I�̊e�A�������̒����̏����L�ł���Ƃ��܂��B�I�����鍀�ڂ̉��l���a�̍ő剻��" );
  CERR( "�I�����Ȃ����l���a�̍ŏ����ɋA�������̂ŁAN�����̊ei�ɑ΂��A" );
  CERR( "dp[i] = �u[0,i)�őI�����Ȃ����ڂ̉��l���a�̍ŏ��l�v" );
  CERR( "�ƒ�߁A�Q����" );
  CERR( "dp[i+L] = (min_{j=i}^{i+L-1} dp[j]) + A[i+L]" );
  CERR( "��" );
  CERR( "- O(N log N)���Ԃɍ��������Ȃ�΁AIntervalMinBIT�ɂ���_min�X�V��" );
  CERR( "  ���min�擾" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- O(N log L)���Ԃɍ��������Ȃ�΁Amap<�l,��>�ɂ�钼��L�̊Ǘ�" );
  CERR( "�ō��������邱�Ƃ�i�Ɋւ��铮�I�v��@���������܂��傤�B" );
}

AC( KnapsackMultipleChoice )
{
  ASK_YES_NO( "�e���ڂ��������ɑI���ł��܂����H" );
  if( reply == "y" ){
    CALL_AC( KnapsackUnboundedChoice );
  } else {
    CERR( "�e���̑I���񐔂̏����H�ƒu���܂��B" );
    ASK_YES_NO( "���̉��l�����e����܂����H" );
    if( reply == "y" ){
      CALL_AC( KnapsackBoundedChoiceNegativeValue );
    } else {
      ASK_YES_NO( "�R�X�g������܂����H" );
      if( reply == "y" ){
	CALL_AC( KnapsackBoundedChoiceUnstable );
      } else {
	CALL_AC( KnapsackBoundedChoiceCostfree );
      }
    }
  }
}

AC( KnapsackUnboundedChoice )
{
  CERR( "S��ڂ̑I���ȍ~�R�X�g���萔�ɂȂ�Ƃ��āA" );
  CERR( "O(N S |C|)���ʂ肻���Ȃ��" );
  CERR( " �ui�ڂ܂ł̍����g���ăR�X�g�̑��a��c�ȉ��̎��̉��l�̍ő�ldp[i][c]�v" );
  CERR( "  ���Ǘ�����i,c�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Unstable" );
  CERR( "���������܂��傤�B" );
}

AC( KnapsackUnboundedChoiceStable )
{
  CERR( "�R�X�g����I���񐔏����ݒ肷�邱�ƂőI���񐔏�����̖���" );
  CERR( "�A��������܂��B����ŉ����Ȃ���΁A" );
  CERR( "- O(N + V^2)���ʂ肻���ŃR�X�g���Ȃ��Ȃ�΁A" );
  CERR( " �ui�ڂ܂ł̍����g���ĉ��l�̑��a��v�̎��̃R�X�g�̍ŏ��ldp[i][v]�v" );
  CERR( "  ���Ǘ�����i,v�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\Costfree" );
  CERR( "- O(N + |C|^2)���ʂ肻���Ȃ�΁A" );
  CERR( " �u�R�X�gc�̍��̉��l�̍ő�lv[c]�v" );
  CERR( "  ��O�v�Z��" );
  CERR( " �u�R�X�g�̑��a��c�ȉ��̎��̉��l�̍ő�ldp[c]�v" );
  CERR( "  ���Ǘ�����c�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\NegativeValue" );
  CERR( "���������܂��傤�B" );
}

AC( KnapsackBoundedChoiceNegativeValue )
{
  CERR( "- O(N min(|C|,H 2^{N/2}) log_2 H)���ʂ肻���Ȃ��" );
  CERR( "  �d���񐔂��i�@�ŕ������Ă܂Ƃ߁A�d�����Ȃ��ꍇ�ɋA�������܂��傤�A" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Boundedchoice\\NegativeValue" );
  CALL_AC( SingleKnapsack );
}

AC( KnapsackBoundedChoiceUnstable )
{
  CERR( "S��ڂ̑I���ȍ~�R�X�g���萔�ɂȂ�Ƃ��āA" );
  CERR( "O(N S |C|)���ʂ肻���Ȃ��" );
  CERR( " �ui�ڂ܂ł̍����g���ăR�X�g�̑��a��c�ȉ��̎��̉��l�̍ő�ldp[i][c]�v" );
  CERR( "  ���Ǘ�����i,c�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Unstable" );
  CERR( "���������܂��傤�B" );
}

AC( KnapsackBoundedChoiceCostfree )
{
  CERR( "���l���R�X�g�Ƃ݂Ȃ��ăR�X�g������ꍇ�ɋA�������܂��傤�B" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Costfree" );
}

AC( KnapsackOrdered )
{
  ASK_YES_NO( "����ڂɑI�΂ꂽ���ɂ���č��ڂ̃R�X�g���ϓ����܂����H" );
  if( reply == "y" ){
    CALL_AC( KnapsackOrderedUnstable );
  } else {
    CALL_AC( KnapsackOrderedStable );
  }
}

AC( KnapsackOrderedUnstable )
{
  CERR( "1 <= m <= M�ڂ̑I���ɂ�����R�X�g�����D_m�Ƃ��A" );
  CERR( "��i�̃R�X�g����肤��l��C_{i,1},C_{i,2}��2�ʂ�Ƃ��A" );
  CERR( "�S�̂�m��ڂ̑I���ɂ����鍀i�̃R�X�g��i�Ɉˑ����Ȃ���1 <= k_m <= K��p����" );
  CERR( "C_{i,k_m}�ƕ\����Ƃ��܂��B�܂�C_{i,k_m}<=D_m����i�̑I�𐧖�ł��B" );
  CERR( "������k_1 = 1�Ƃ��Ă���ʐ��������܂���B" );
  CERR( "" );
  CERR( "O((N log_2 N)+M)���Ԃɍ��������Ȃ�΁A(C_{i,k},i)_i�̎������\�[�g��" );
  CERR( "sC(k)�ƒu���A(k_m,D_m,m)_m�̎������\�[�g��(k_{m_j},D_{m_j},m_j)_j�ƒu���A" );
  CERR( "1 <= j <= M�����������ɒT�����AsC(k_{m_j})��p���đI���\�ȍ�i�ɑ΂���" );
  CERR( "{A_i,C_{i,2},i}��set�ŊǗ����A���̒��ōő�̗v�f���̗p���A�W������폜���邱�Ƃ�" );
  CERR( "m_j�ڂ̑I�������肵�܂��傤�B" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
}

AC( KnapsackOrderedStable )
{
  CERR( "1 <= m <= M�ڂ̑I���ɂ�����R�X�g�����D_m�Ƃ��A" );
  CERR( "��i�̃R�X�g��C_i�Ƃ��܂��B�܂�C_i<=D_m����i�̑I�𐧖�ł��B" );
  CERR( "" );
  CERR( "O((N log_2 N)+M)���Ԃɍ��������Ȃ�΁A(C_i,i)_i�̎������\�[�g��sC�A" );
  CERR( "(D_m)_m�̎������\�[�g��(D_{m_j})_j�ƒu���A" );
  CERR( "1 <= j <= M�����������ɒT�����AsC��p���đI���\�ȍ�i�ɑ΂���{A_i,i}��" );
  CERR( "set�ŊǗ����A���̒��ōő�̗v�f���̗p���A�W������폜���邱�Ƃ�" );
  CERR( "m_j�ڂ̑I�������肵�܂��傤�B" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
}

AC( SingleKnapsack )
{
  ASK_YES_NO( "�R�X�g������܂����H" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackWithCost );
  } else {
    CALL_AC( SingleKnapsackCostfree );
  }
}

AC( SingleKnapsackWithCost )
{
  ASK_YES_NO( "�R�X�g���P�����ł����H" );
  CERR( "- O(N 2^{N/2})���ʂ肻���Ȃ�Δ����S��" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative" );
  CERR( "- O(N |C|)���ʂ肻�����R�X�g���񕉂Ȃ�΁A" );
  CERR( "  �ui�Ԗڂ̍��܂Ŏg���ăR�X�g�̑��a��c�̎��̉��l�̍ő�ldp[i][c]�v" );
  CERR( "  ���Ǘ�����i,c�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value" );
  CERR( "- O(N 2^N)���ʂ肻�����R�X�g�̓����͈͂��J�ړr������������Ă���Ȃ�΁A" );
  CERR( "  bit�S�T��" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Restrictive" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackWithLinearCost );
  } else {
    CALL_AC( SingleKnapsackWithMultiCost );
  }
}

AC( SingleKnapsackWithLinearCost )
{
  CERR( "- O(N V)���ʂ肻�������l���񕉂Ȃ�΁A" );
  CERR( "  �ui�Ԗڂ̍��܂Ŏg���ĉ��l�̑��a��v�̎��̃R�X�g�̍ŏ��ldp[i][c]�v" );
  CERR( "  ���Ǘ�����i,v�Ɋւ��铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Cost" );
  CERR( "���������܂��傤�B" );
}

AC( SingleKnapsackWithMultiCost )
{
  CERR( "- C=[0,W]^D��O(N W + W^{D-1}(D + log(1+W)))���ʂ肻������" );
  CERR( "  �e�R�X�g���P�����񎩖������������Ȃ��Ȃ�΁A" );
  CERR( "  �P�����񎩖������������Ȃ��R�X�g���Ƃɉ��l�̍ő�l�����߂ċ��MaxBIT" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value\\Multicost" );
  CERR( "���������܂��傤�B" );
}

AC( SingleKnapsackCostfree )
{
  CERR( "- O(N 2^{N/2})���ʂ肻���Ȃ�Δ����S��" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
  CERR( "- O(N v_max)���ʂ肻�����񕉂Ȃ��[V-v_max,V+v_max]�ł̎����\����" );
  CERR( "  �Ǘ����铮�I�v��@" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
  CERR( "- O(N^4)���Ԃɍ����������I���ɕ����l�̗v�f�Ɣ񕉉��l�̗v�f�Ԃň������" );
  CERR( "  ���񂪂���Ȃ�΁A�����e�ʁ��̗L���ӂɑΉ������I�����邩�ۂ���" );
  CERR( "  �񕔃}�b�`���O�ɖ|�󂵍ŏ��J�b�g�i�ő嗬�j�v�Z" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
  CERR( "- O((N+V)log_2 V)���ʂ肻�����񕉂���V��10^5�I�[�_�[�Ńv���X�f��P��" );
  CERR( "  �@�Ƃ���Ȃ�Ζ@P�ł̍����t�[���G�ϊ��ɂ��exp(log�̑��a)�v�Z" );
  CERR( "  \\Mathematics\\Polynomial\\Truncate" );
  CERR( "���������܂��傤�B" );
}

AC( MultipleKnapsack )
{
  CERR( "�i�b�v�T�b�N�̌���K�ƒu���܂��B" );
  CERR( "- O(K(N 2^N + K^N))���ʂ肻���Ȃ�΁A�����[�[�^�ϊ�" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Subsetwise\\Multiknapsack" );
  CERR( "- �e�i�b�v�T�b�N�̗e�ʂ����ɏ������Ȃ�΁A�R�X�g�̑傫���ō��ڂ𕪂���" );
  CERR( "  �R�X�g�̑傫�����ɂ����̑I�𐔂�S�T��܂��͓񕪒T��" );
  CERR( "  �Q�l�Fhttps://yukicoder.me/problems/no/2617/editorial" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationArrayFunction )
{
  CERR( "�z����󂯎��֐�F���^�����Ă���Ƃ��܂��B�^����ꂽ�z��A��" );
  CERR( "���炩�̏��������ē�����z��B�ɑ΂���F(B)�̍ő剻�����l���܂��B" );
  CERR( "�ŏ�������-1�{����Ηǂ��ł��B" );
  CERR( "" );
  CERR( "A�̃T�C�YN���������ꍇ�A����̑S�T����������܂��傤�B" );
  CERR( "" );
  CERR( "F�̏I��M�̗L���������Q�\��(|,R)��" );
  CERR( "(1) R��<���܈ӂ�����<�Ɋւ���ő匳��R�Ɋւ���ő匳�ł�����B" );
  CERR( "(2) �C�ӂ�m,n in M�ɑ΂�m = m|n�܂���m R m|n�ł���B" );
  CERR( "(3) F��|�Ɋւ��鑍�a�֐��ł���B" );
  CERR( "(4) �z��̃T�C�YN��R�̍Œ�������L�ȉ��Ȃ�΁AB��|�Ɋւ���ݐϘa��" );
  CERR( "    R�Ɋւ��ċ��`�P����������悤��B���\���ł���" );
  CERR( "�𖞂����Ȃ�΁AN>=L�̏ꍇ�ɋ��߂�<�Ɋւ���ő�l��<�Ɋւ���ő匳��" );
  CERR( "��v����̂ŁAN<L�̏ꍇ�ɋA������܂��B" );
  ASK_YES_NO( "����͐����𐬕��̈ꎟ�����Œu����������̂ł����H" );
  if( reply == "y" ){
    CALL_AC( MaximisationArrayFunctionLinearCombination );
  } else {
    CALL_AC( MaximisationArrayFunctionGeneralOperation );
  }
}

AC( MaximisationArrayFunctionLinearCombination )
{
  CERR( "�����̐�������C�f�A���␬���̍�����������C�f�A���ɒ��ڂ���" );
  CERR( "gcd���v�Z���܂��傤�B" );
}

AC( MaximisationArrayFunctionGeneralOperation )
{
  CERR( "�ő剻���ׂ����̃T�u�S�[��f�ɕ\��鍀x�̂������ߑł��₷�����̂�T���܂��傤�B" );
  CERR( "�z��̒�����i�őł��؂�������x�̌�␔��X(i)�A" );
  CERR( "�z��̒�����i�őł��؂���x�����ߑł������̔z��̒���i+1�ł�x�̌�␔��dX(i)" );
  CERR( "�ƒu���܂��B" );
  CERR( "- O(sum_i X(i) dX(i))���ʂ肻����f��x����O(1)�Ōv�Z�ł���Ȃ�΁A" );
  CERR( "  i��x�Ɋւ��铮�I�v��@" );
  CERR( "- O(N log_2 X(N))���ʂ肻����" );
  CERR( "  - f��x����O(N)�Ōv�Z�ł�x�Ɋւ��ĒP���Ȃ�΁Ax�̓񕪒T��" );
  CERR( "  - f��x����O(N/x)�Ōv�Z�ł���Ȃ�΁Ax�̑S�T��" );
  CERR( "- O(N log_2 N)���ʂ肻����x����ёւ����f��x����O(log_2 N)�Ōv�Z�ł���" );
  CERR( "  �Ȃ�΁A�D��x���L���[�Ȃǂł�x�̊Ǘ�" );
  CERR( "���������܂��傤�B" );
}

AC( MaximisationArrayLength )
{
  CERR( "�z��̃T�C�Y��N�A�z��̊e�����̉��E�̗v�f���̑��a��E�A�����W���̗v�f����C�ƒu���܂��B" );
  CERR( "- �S������O(N log_2 N)���Ԃɍ��������Ȃ�΁A�����𖞂���������̒����̍ő�l��" );
  CERR( "  �C���f�b�N�X�Ɏ���BIT��p���āA�����̕�����̖����ł��鍀���L�^" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- �a�Ȕ�������O(E log_2 N)���Ԃɍ��������Ȃ�΁A�����𖞂���������̖�����" );
  CERR( "  �C���f�b�N�X�Ɏ��A�z�z���p���āA����畔����̒����̍ő�l���L�^" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})���Ԃɍ��������Ȃ�΁A�����W���̊e�v�fc < d�ɑ΂���" );
  CERR( "  �u�n�[�̒l��c�A�I�[�̒l��d�ȉ��ł���P�����啔����̒����v���Ǘ�����" );
  CERR( "  C���㔼�s����ڂ������m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
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
  ASK_NUMBER(
	     "�����W���̗v�f���̍ő剻���" ,
	     "���̑��̕����W���̉��l�ő剻���" ,
	     "�����W���ւ̕����̍ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "�^����ꂽ�W���̃T�C�Y��N�ƒu���܂��B" );
    CERR( "- O(2^N)���Ԃɍ��������Ȃ�΁Abit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(N2^N)���Ԃɍ��������Ȃ�΁A�����W���̕�ܑ΂�bit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- �������̋ɑ卽�Ȃ�΁A�㑱�֐����`���Ă��̋t����ӂƂ����֏�L���O���t" );
    CERR( "  ���\�z���A�ɑ匳����̍Œ������v�Z" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\LongestWalk\\a.hpp" );
    CERR( "- �������̋ɑ唽���Ȃ�΁A" );
    CERR( "  - ���ւ̋ɏ��ȕ��������܂�Ȃ�΁ADilworth�̒藝�̏ؖ��Ɋ�\�z" );
    CERR( "    https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
    CERR( "  - �g�|���W�J���\�[�g����Ă���Ȃ�΁A�n�ؕЂƂ���N�ɖ��ߍ��݁A" );
    CERR( "    �������Ɛ����I�Ȍ㑱�֐�S:N->N���`���āAS�̒l�����̏W���ɓ���Ȃ�" );
    CERR( "    �v�f�S�̂̏W����S�̒P������p���ē񕪒T���Ōv�Z" );
    CERR( "- ���J��Ԃ̋ɑ�r���I�W���Ȃ�΁A��ԃX�P�W���[�����O" );
    CERR( "  \\Mathematics\\Combinatorial\\IntervalScheduling\\a.hpp" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "�R�X�g�Ȃ��̃i�b�v�T�b�N���ɑ��Ȃ�܂���B" );
    CALL_AC( SingleKnapsackCostfree );
  } else {
    CERR( "- ���ւ̕����̍ŏ����Ȃ�΁A�ɑ唽������Dilworth�̒藝�̏ؖ��Ɋ�\�z" );
    CERR( "  https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
    CERR( "- ���S��\�n�̌v�Z�Ȃ�΁A���D��T����UnionFind�ɂ��A�������v�Z" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  }
}

AC( MinimisationGraph )
{

  ASK_NUMBER(
             "�R�X�g�̍ŏ������" ,
             "���l�̍ő剻���"
             );
  if( num == num_temp++ ){
    CALL_AC( MinimisationGraphCost );
  } else {
    CALL_AC( MaximisationGraphValue );
  }
}

AC( MinimisationGraphCost )
{
  ASK_NUMBER(
	     "�S��X�̃R�X�g�ŏ������" ,
	     "�p�X�̃R�X�g�ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "�N���X�J���@" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
    CERR( "���������܂��傤�B" );
  } else if( num == num_temp++ ){
    CERR( "����͍ŒZ�o�H��肻�̂��̂ł��B" );
    AC( MinimisationMovingCost );
  }
}

AC( MaximisationGraphValue )
{
  ASK_NUMBER(
	     "�ӂ̉��l�ő剻���" ,
	     "���_�̉��l�ő剻���"
	     );
  if( num == num_temp++ ){
    CERR( "���l��-1�{�����R�X�g���l���邱�Ƃŕӂ̃R�X�g�ŏ������ɋA������܂��B" );
    CALL_AC( MinimisationGraphCost );
  } else {
    ASK_NUMBER(
               "��֏�O���b�h�O���t�ɖ��ߍ��݉\�ȃO���t" ,
               "���̑��̃O���t"
               );
    if( num == num_temp++ ){
      CERR( "��֏�O���b�h�O���t�ɖ��ߍ��݁A���ʑ����Ƌ��max�X�V" );
      CERR( "\\Mathematics\\Geometry\\Graph\\Grid\\ValueMaximisation" );
      CERR( "���������܂��傤�B" );
    } else {
      CERR( "- ���Z�����@�Ȃ�΁A�n�[�̏d��*(�n�_?2:1)�ƏI�[�̏d��*(�I�_?2:1)" );
      CERR( "  �̘a��-1�{���e�ӂ̏d�݂Ƃ��ĕӂ̃R�X�g�ŏ������ɋA��" );
      CERR( "- ���Z��max�Ȃ�΁A�n�[�̏d�݂ƏI�[�̏d�݂̍ő�l��" );
      CERR( "  �e�ӂ�-1�{�̏d�݂Ƃ��ĕӂ̃R�X�g�ŏ������ɋA��" );
      CERR( "���������܂��傤�B" );
      CALL_AC( MinimisationGraphCost );
    }
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

AC( MaximisationProbability )
{
  CERR( "����^�헪��I��Ŋm���^���Ғl���ő剻����ꍇ�A" );
  CERR( "�푀��Ώۂ�\�ȑ���^�헪�̃f�[�^�Ȃǂ���ԂƂ��Ē莮�����A" );
  CERR( "�us���o�R����ꍇ�̊m���^���Ғl�̍ő�ldp[s]�v" );
  CERR( "���Ǘ�����s�Ɋւ��铮�I�v��@���������܂��傤�B" );
}

AC( MinimisationOperationCost )
{
  CERR( "����R�X�g�̍ŏ����́A����ɂ���ԑJ�ڂ�L���O���t��̈ړ��Ƃ݂Ȃ����Ƃ�" );
  CERR( "�ŒZ�o�H���ɋA�������邱�Ƃ��\�ł��B" );
  CALL_AC( MinimisationMovingCost );
}

AC( MaximisationCountingOperation )
{
  CALL_AC( ReducingOperation );
  ASK_YES_NO( "���̏�ŏ�Ԃ�10^6�I�[�_�[�ł����H" );
  if( reply == "y" ){
    CERR( "��Ԃ̑J�ڂ��O���t��̈ړ��Ƃ݂Ȃ��A�Œ��o�H���ɋA�������܂��傤�B" );
    CALL_AC( MaximisationMovingDistance );
  } else {
    CERR( "������@�̒T���ɂ�" );
    CERR( "- ����ɂ���ĕs�ϗʂ�����ʂ��ŏ��ɂȂ�悤�ȑ���̔���" );
    CERR( "- �قƂ�Ǔ�������̔���" );
    CERR( "- ����Ώۂ���������Ȃ��" );
    CERR( "  - �Ώۂɑ���D��x������Ȃ�΁A�e�Ώۂ̑���񐔍ő�l�Ɋւ���" );
    CERR( "    ���I�v��@" );
    CERR( "  - ���쏇�ɈӖ����Ȃ��e�Ώۂɍ��X�P�񂵂����삵�Ȃ��Ȃ�΁A" );
    CERR( "    ���삷��ΏۑS�̂̂Ȃ������W���̑S�T��┼���S��" );
    CERR( "���������܂��傤�B" );
  }
}

AC( MinimisationCoveringSize )
{
  CERR( "�T�C�Y�����ߑł����񕪒T���Ŕ핢�\����������܂��傤�B" );
  ASK_YES_NO( "�핢���S�͌Œ�ł����H" );
  if( reply == "y" ){
    CERR( "�핢�\����`��}�`�̈�v����ɖ|�󂵂܂��傤�B" );
    CALL_AC( DecisionImageCoincidence );
  } else {
    CERR( "�핢�\����`��\���ɖ|�󂵂܂��傤�B" );
    CALL_AC( DecisionDrawability );
  }
}

AC( MaximisationDrawingImage )
{
  CERR( "�`����̍ő�^�ŏ����͕`��T�C�Y�̍ŏ��^�ő剻�ɋA�������܂��傤�B" );
  CERR( "�`��T�C�Y�̍ő�^�ŏ������̓T�C�Y�����ߑł����񕪒T����e�_�ł̃T�C�Y�̍ő剻" );
  CERR( "�Ȃǂ��s���`��\������ɋA�������܂��傤�B" );
  CALL_AC( DecisionDrawability );
}

AC( MaximisationMinimum )
{
  CERR( "�S�Ă�-1�{���邱�Ƃōő�l�����Z�Ƃ��鑍�a�̍ŏ������ɋA�������܂��B" );
  CALL_AC( MinimisationSubsetSum );
}

AC( MinimisationSubsetSum )
{
  ASK_NUMBER(
	     "�O���t�̕ӏW��E��̊֐��̕����a�̍ŏ������" ,
	     "��ʂ̏W����̊֐��̕����a�̍ŏ������"
	     );
  if( num == num_temp++ ){
    CERR( "�ŒZ�o�H���ɋA�������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "�����a���Œ肵�ĕ����W���̑��݂𔻒肷��" );
    CERR( "�񕪒T�����������܂��傤�B" );
  }
}

AC( MaximisationGame )
{
  ASK_YES_NO( "���b�ȃQ�[���ł����H" );
  if( reply == "y" ){
    CERR( "����⑽�d�W�����琬����v�f�ł��鍀�����݂ɍ폜���Ă����A��i��" );
    CERR( "��s���폜�����ꍇ�͐�s��A[i]�_�A��s���폜�����ꍇ�͌�s��B[i]�_" );
    CERR( "���^������Ƃ��A��s�̑����_��X�A��s�̑����_��Y�ƒu���܂��B" );
    CERR( "- ��s��X-Y�̍ő剻���A��s��X-Y�̍ŏ�����ڎw�����Ȃ�΁A" );
    CERR( "  �o����A[i]+B[i]�̑傫�������×~�ɑI�ԏꍇ���o���̍őP�ł��B" );
    CERR( "- ��s��X-Y�̍ŏ������A��s��X-Y�̍ő剻��ڎw�����Ȃ�΁A" );
    CERR( "  �o����A[i]+B[i]�̏����������×~�ɑI�ԏꍇ���o���̍őP�ł��B" );
    CERR( "- ��s��X+Y�̍ő剻���A��s��X+Y�̍ŏ�����ڎw�����Ȃ�΁A" );
    CERR( "  �o����A[i]-B[i]�̑傫�������×~�ɑI�ԏꍇ���o���̍őP�ł��B" );
    CERR( "- ��s��X+Y�̍ŏ������A��s��X+Y�̍ő剻��ڎw�����Ȃ�΁A" );
    CERR( "  �o����A[i]-B[i]�̏����������×~�ɑI�ԏꍇ���o���̍őP�ł��B" );
    CERR( "����ɏ]���Ĕz��̘a�^�����\�[�g���Ď��ۂɑ�������s���܂��傤�B" );
  } else {
    CERR( "�ǖʂ𔽕��\�ȃQ�[���͔����헪����邱�Ƃŏ����ǖʂɋA������܂��B" );
    CERR( "- ��s���ŏI������s���ꍇ�A����ł̍ő剻���ɋA����" );
    CERR( "  ����̂������ʂ��Ȃ����̂�S�T��" );
    CERR( "- ��s���ŏI������s���ꍇ�A�Q��ڂł̍ŏ��l�̍ő剻���ɋA����" );
    CERR( "  ����̂������ʂ��Ȃ����̂��Œ肷�邲�ƂɂQ��ڂ̍ŏ��l���v�Z" );
    CERR( "- �ŏI�I�ȕs�ϗʂ̉��E�����ߑł������ɂ���ȏ�̕s�ϗʂ𓾂邱�Ƃ�" );
    CERR( "  �����\�ȕK�v�\������������ł���ꍇ�A����ɂ��ő�l�̌v�Z" );
    CERR( "���������܂��傤�B" );
    CERR( "" );
    CERR( "���l��u��������Q�[���͕p�x�\��p���Đ��l���ړ�����Q�[����" );
    CERR( "�|��ł��邱�Ƃ�����܂����A���̏ꍇ�͐��l�̈ړ������ʓI��" );
    CERR( "�N����Ȃ������������邩�ۂ��ɒ��ӂ��܂��傤�B" );
  }
}

AC( Counting )
{
  CERR( "���I�v��@�Ōv�Z�ʂ��傫���ꍇ�A" );
  CERR( "- dp[i]�̑����" );
  CERR( "  - sum_{j<=i}dp[j]���l����B" );
  CERR( "  - i�Ԗڂ̏�Ԃ�dp[i+1]�ւ̊�^C(k)�����������k�֍ו�����dp[i][k]���l����B" );
  CERR( "  - i�Ԗڂ̏�Ԃ�dp[i+1]�ւ̊�^��c�ł����Ԃ̘a�W���֍ו�����dp[i][c]���l����B" );
  CERR( "- dp[i][k]�̑����dp[i][0]�݂̂ɒ��ڂ���BIT�Ȃǂō������B" );
  CERR( "���������܂��傤�B" );
  ASK_NUMBER(
	     "���̐����グ���" ,
	     "�z��̐����グ���" ,
	     "������̐����グ���" ,
	     "�O���t�̐����グ���" ,
	     "�����W���̐����グ���" ,
	     "�헪�^������@�̐����グ���" ,
	     "�o�H�̐����グ���" ,
	     "�^�C�����O�^�h�蕪���̐����グ���" ,
	     "�����O�}�`�̐����グ���" ,
	     "�J�^�������̌v�Z���" ,
	     "����񐔂̌v�Z���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingNumber );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGraph );
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
    CALL_AC( ExplicitExpressionCountingOperation );
  }
  ASK_YES_NO( "�T���v������͂��܂����H" );
  if( reply == "y" ){
    CALL_AC( SampleAnalyser );
  }
}

AC( CountingNumber )
{
  CERR( "���炩�̏����𖞂������̐����グ�����l���܂��B" );
  ASK_NUMBER(
	     "�Œ蒷�ϐ��֐��̒l�Ɋւ������" ,
	     "�e���̐����Ɋւ������" ,
	     "���̑��̏���"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CERR( "�����\�i�@�Ȃǂŕ�����Ƃ݂Ȃ��܂��B" );
    CALL_AC( CountingArray );    
  } else {
    CERR( "����P(n)�𖞂���N�ȉ��̔񕉐���n�̐����グ�́A�֐�f(n) = P(n)?1:0�Ȃǂ�" );
    CERR( "���a�̌v�Z���ɋA������܂��B" );
    CALL_AC( ExplicitExpressionOneArrayEntrySum );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- �ϐ��̑Ώ̐�������Α召�֌W�𐧌������S�T��" );
  CERR( "- ���炩�̖񐔂ƂȂ�ȂǓ����͈͂������ϐ�������΂��������ߑł����S�T��" );
  CERR( "- �������W���ւ̓���̎ʑ��̋t���Ȃ�΃[�[�^�ϊ��^���r�E�X�ϊ�" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- gcd(n,x)=1����1<=x<=n�𖞂���x�̐����グ�̓I�C���[�֐�" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod\\Function\\Euler" );
  CERR( "- f(g(x),g(y))=c�̌`�Ȃ��" );
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
  CERR( "- f(g(x),g(y))<=c�̌`����f��g���P����������Ȃ��" );
  CERR( "  - �܂��eb in im(g)�ɑ΂�f(a,b) <= c�𖞂���a�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - ���ɂ������ē�����ea�ɑ΂�g(x)<=a�𖞂���x�̏����񕪒T���őO�v�Z����B" );
  CERR( "  - �Ō�Ɋey���Ƃ�b = g(y)�ɑ΂���O�v�Z���ʂ̑��a�����߂�B" );
  CERR( "- �������̘a�Ȃ�΃��R�r�̓񕽕��藝" );
  CERR( "  https://ja.wikipedia.org/wiki/���R�r�̓񕽕��藝" );
  CERR( "���������܂��傤�B" );
}

AC( CountingArray )
{
  ASK_NUMBER(
             "�����𖞂����z��̐����グ���" ,
             "�^����ꂽ�z��̕�����̐����グ���"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayConditional );
  } else {
    CALL_AC( CountingSubArray );
  }
}

AC( CountingArrayConditional )
{
  ASK_NUMBER(
	     "�z����󂯎��֐��̒l���Œ肳�ꂽ�z��̐����グ���" ,
	     "�אڐ����Ԋ֌W���𖞂����z��̐����グ���" ,
	     "�����������ȂǂŌŒ蒷�̕���������ɏ�����^����ꂽ�z��̐����グ���" ,
             "�����J�b�R��̐����グ���" ,
	     "���̑��̊֌W���𖞂����z��̐����グ���"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayInverseImage );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayAdjacentRelation );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayBounded );
  } else if( num == num_temp++ ){
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayOtherRelation );
  }
}

AC( CountingArrayInverseImage )
{
  CERR( "�z��̒�����N�A�����̎�肦��l�̌���K�A�z����󂯎��֐���f�A" );
  CERR( "f�̎��l�̂����l�����ׂ�����V�Ƃ��܂��B" );
  CERR( "- O(K^N)���Ԃɍ��������Ȃ�΁A�S�Ă̔z��ɑ΂���֐��̒l�̑O�v�Z" );
  CERR( "- O(NV)���Ԃɍ��������ł���f��N�Ɋւ��čċA�I�\�������Ȃ�΁A" );
  CERR( "  �u����i�̎��ɒlv�ł���z��̑���dp[i][v]�v" );
  CERR( "  ���Ǘ�����i,v�Ɋւ��铮�I�v��@" );
  CERR( "  - ���ɔ񕉐����l�֐�g��p����f(A)=sum_i g(A[i])�ƕ\����Ȃ�΁A" );
  CERR( "    g�̕p�x�\��O�v�Z���ĕp�x�ŏd�ݕt����dp�X�V" );
  CERR( "  - ���ɔ񕉗L�����l�֐�g��p����f(A)=sum_i g(A[i])�ƕ\����Ȃ�΁A" );
  CERR( "    g�̒l�̕��ꂪ�傫�ȑf���ɂȂ鐬�������ʌɍl����g�̒l�̕����" );
  CERR( "    �ŏ����{�����������ꍇ�ɋA�������A�ʕ����Đ����l�̏ꍇ�ɋA��" );
  CERR( "- �z�񂪗L�E������Ŋ֐�����됮���W���x�N�g��B�ɂ����ςł���Ȃ�΁A" );
  CERR( "  �u����i�̎��ɒlv�ł���z��̑���dp[i][v]�v" );
  CERR( "  ���Q����dp[i+1][v] = sum_{j<=v/B[i+1]} dp[i][v-j*B[i+1]]��" );
  CERR( "  ���������Ƃ���f_i(x,v)=dp[i][v-x*B[i+1]]�ƒu���Ă��̗ݐϘa��" );
  CERR( "  S(f_i,v)(x)�ƒu���ē�����Q����" );
  CERR( "  f_{i+1}(x,v) = S(f_i,v)((v-x*B[i+2])/B[i+1])" );
  CERR( "  �𕽍s�ړ��ŏ���" );
  CERR( "  \\Mathematics\\Polynomial\\ParallelTranslation" );
  CERR( "  \\Mathematics\\Polynomial\\CumulativeSum" );
  CERR( "- �֐�����Ԙa�Ȃǃf�[�^�\���Ōv�Z�ł���l�ŕ\����Ȃ�΁A" );
  CERR( "  �f�[�^�\���ɖ|�󂵂���ł̐����グ" );
  CERR( "���������܂��傤�B" );
}

AC( CountingArrayAdjacentRelation )
{
  CERR( "- �������ł̒P�����̏ꍇ�A" );
  CERR( "  - �S�����Ȃ�΁A���̕������@�Ȃǂւ̖|��" );
  CERR( "  - �a�Ȕ������Ȃ�΁A�O���t�̑O�v�Z" );
  CERR( "- ���̑��̏����̏ꍇ�͓��I�v��@�ŁA" );
  CERR( "  - �֎~�����̎��͗]���ۂ������X�V" );
  CERR( "  - ���������̎��͕�����ɂ��X�V" );
  CERR( "  - ����̕�����i�Ⴆ��aba�j���܂ނƂ��������̎���" );
  CERR( "    (1) ����i����aba���܂܂Ȃ���������a�Ȃ��̂̌�dpa[i]" );
  CERR( "    (2) ����i����aba���܂܂Ȃ���������ab�Ȃ��̂̌�dpab[i]" );
  CERR( "    (3) ����i����aba���܂ނ��̂̌�dpaba[i]" );
  CERR( "    ���ċA��" );
  CERR( "    (1) dpa[i] = (26^{i-1}-dpaba[i-1]-dpab[i-1])*1" );
  CERR( "    (2) dpab[i] = (26^{i-2}-dpaba[i-2]*26 + dpab[i-2])*1" );
  CERR( "    (3) dpaba[i] = dpaba[i-1]*26 + dpab[i-1]*1" );
  CERR( "    ��p����i�Ɋւ��铮�I�v��@�Ōv�Z" );
  CERR( "���������܂��傤�B" );
}

AC( CountingArrayBounded )
{
  CERR( "�����s�ƒu���As�̒�����L�A�����グ�镶����̒�����N�ƒu���A" );
  CERR( "�����グ�镶����̑����W����S�ƒu���܂��B" );
  ASK_YES_NO( "L == N�ł����H" );
  if( reply == "y" ){
    CALL_AC( CountingArrayBoundedTotal );
  } else {
    CALL_AC( CountingArrayBoundedSub );
  }
}

AC( CountingArrayBoundedTotal )
{
  CERR( "������W��S����s�����̍��̐����グ������ۂ́A" );
  CERR( "�����╶����ސ��Ȃǂ̏�Ԃ��l����" );
  CERR( "dp[d][n] = �uS�Ɛ擪d�����ڂŏ��߂ăY������n�̍��̑����v" );
  CERR( "��d��n�Ɋւ��铮�I�v��@�ŋ��߂܂��傤�B" );
}

AC( CountingArrayBoundedSub )
{
  CERR( "����L�̑S�Ă̕���������s�����ł���Ƃ����������AS�̒�`��p����" );
  CERR( "�ȒP�ȏ����ɖ|�󂵂܂��傤�B" );
  CERR( "���̂��߂ɂ�L����������̓I��s�ɑ΂��Ď������A�@�����������t���܂��傤�B" );
  CERR( "���̍ۂɎ����������ƐϏ������������Ȃ��悤�ɒ��ӂ��܂��傤�B" );
}

AC( CountingArrayOtherRelation )
{
  ASK_YES_NO( "�z��ւ̊i�[�����֌W����܂����H" );
  if( reply == "y" ){
    ASK_YES_NO( "���a��0�ō��[����̎n�[�a���񕉂ȁ}1��ł����H" );
    if( reply == "y" ){
      CERR( "����2N�̕����J�b�R��ɑΉ����܂��B" );
      CALL_AC( CountingParenthesisSequence );
    } else {
      CERR( "�Y���ɔ��������\�����O���t�̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
      CALL_AC( CountingGraph );
    }
  } else {
    CERR( "�i���d�j�W����\�[�g���ꂽ�z��̐����グ�ɋA�����邱�Ƃ��������܂��傤�B" );
    CALL_AC( CountingSubset );
  }
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
  CERR( "- �S������O(N log_2 N)���Ԃɍ��������Ȃ�΁A�ʏ�̔z��œ񕪒T��" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- �a�Ȕ�������O((N+E)log_2 N)���Ԃɍ��������Ȃ�΁A�A�z�z��" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})���Ԃɍ��������Ȃ�΁A�����W���̊e�v�fc < d�ɑ΂���" );
  CERR( "  �u�n�[�̒l��c�A�I�[�̒l��d�ȉ��ł���P�����啔����̌��v���Ǘ�����" );
  CERR( "  C���㔼�s����ڂ������m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
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

AC( CountingString )
{
  ASK_NUMBER(
	     "�����𖞂���������̐����グ���" ,
	     "�^����ꂽ������̕���������̐����グ���"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingStringConditional );
  } else {
    CALL_AC( CountingSubString );
  }
}

AC( CountingStringConditional )
{
  CERR( "������͕����̔z��Ƃ݂Ȃ��܂��B" );
  CALL_AC( CountingArray );
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

AC( CountingGraph )
{
  ASK_NUMBER(
             "�����𖞂��������O���t�̐����グ���" ,
             "�����𖞂����L���O���t�̐����グ���" ,
	     "�^����ꂽ�؂̕����̐����グ���"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingUndirectedGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingDirectedGraph );
  } else {
    CALL_AC( CountingPartitionOfTree );
  }
}

AC( CountingUndirectedGraph )
{
  CERR( "- ���x���t�������؂̓P�[���[�̌���N^{N-2}" );
  CERR( "  https://oeis.org/A000272" );
  CERR( "- �e�m�[�h�̎}�ɍ��E�̋�ʂ�����N�m�[�hN+1�t�̓񕪖؂�" );
  CERR( "  �~���2N���_�ɔ����������2�Ȗ����ӂ𒣂��ē����閳���O���t��" );
  CERR( "  ��N�J�^������C(N)=(2N)!/((N+1)!N!)" );
  CERR( "  https://ja.wikipedia.org/wiki/�J�^������#�J�^�������̈Ӗ�" );
  CERR( "- �Ȃ���O���t�̓T�C�N���iN!/(N-C)!�j�Ƃ���ȊO�ւ̕����iC^{N-C}�j" );
  CERR( "���������܂��傤�B" );
}

AC( CountingDirectedGraph )
{
  CERR( "- ���x���t���L���؁i���t���؁j�̓P�[���[�̌����̈���N^{N-1}" );
  CERR( "  https://oeis.org/A000169" );
  CERR( "- K�̃T�C�N���̘a�͑�1��X�^�[�����O��s(N,K)" );
  CERR( "  https://�X�^�[�����O��#�g�ݍ��킹���w�ɂ�����Ӗ�" );
  CERR( "���������܂��傤�B" );
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
  ASK_NUMBER(
             "�v�f���󂯎��֐��̕����a���Œ肵�������W���̐����グ���" ,
             "���̑��̕����W���̐����グ���" ,
             "�����W���ւ̕����̐����グ���"
             );
  if( num == num_temp++ ){
    CERR( "�v�f�ɔԍ���U��A�W����z��Ƃ݂Ȃ��ĕ����a���ɋA�������܂��傤�B" );
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CERR( "�^����ꂽ�W���̃T�C�Y��N�ƒu���܂��B" );
    CERR( "- O(2^N)���Ԃɍ��������Ȃ�΁Abit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(N2^N)���Ԃɍ��������Ȃ�΁A�����W���̕�ܑ΂�bit�S�T��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "���������܂��傤�B" );
  } else {
    CERR( "- �C�ӗL���̕����W���ւ̔r���I�����Ȃ�΃x����B(N)" );
    CERR( "  https://ja.wikipedia.org/wiki/�x����" );
    CERR( "- �C�ӗL���̕����W���ւ̔����������A�~���N���_�̑��p�`������" );
    CERR( "  �~���N+2�p�`�̎O�p�`�����Ȃ�Α�N�J�^������C(N)=(2N)!/((N+1)!N!)" );
    CERR( "  https://ja.wikipedia.org/wiki/�J�^������" );
    CERR( "  https://ja.wikipedia.org/wiki/���������" );
    CERR( "- K�̕����W���ւ̔r���I�����Ȃ�Α�2��X�^�[�����O��s(N,K)" );
    CERR( "  \\Mathematics\\Combinatorial\\StirlingNumber\\SecondKind" );
    CERR( "  https://ja.wikipedia.org/wiki/�X�^�[�����O��#�g�ݍ��킹���w�ɂ�����Ӗ�_2" );
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
    CERR( "�̈悩��O�ɏo��o�H�̐����グ�́A�o�钼�O�̌o�H�ɋA�������܂��傤�B" );
    CERR( "�K�X�J�^�������⃄���O�}�`�Ƃ̊֌W���������܂��傤�B�Ⴆ��" );
    CERR( "N�~N�i�q�ō�������E��܂őΊp�����ׂ����ŏ��ɉE�֍s���ŒZ�o�H�̌���" );
    CERR( "��N�J�^������C(N)=(2N)!/((N+1)!N!)�ł��B" );
    CALL_AC( CountingYoundDiagram );
  } else if( num == num_temp++ ){
    CERR( "���[�v�̕s�\�ȗL���O���t�͐��b�Ȃ̂ŁA�e�_p���Ƃ�" );
    CERR( "-�up���T�����ꂽ���v��\��bool�l�z��" );
    CERR( "-�up�ւ̕ӂ������T���_�̌��v��\���z��" );
    CERR( "���Ǘ��������҂�S�T�􂷂邱�Ƃ�O(|V|^2+|E|)�őS�Ă̓_��T���ł��܂��B" );
  }
}

AC( CountingTiling )
{
  ASK_NUMBER(
	     "�אڐ����ƈقȂ�F�œh�蕪������" ,
	     "�^����ꂽ�}�`�ŕ`��\�ɂȂ�悤�ɓh�蕪������" ,
	     "�^����ꂽ�����ɏ]���ēh�蕪���\�ɂȂ�悤�ɐ}�`�ŕ`�悷����"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingColouringDistinct );
  } else if( num == num_temp++ ){
    CALL_AC( CountingColouringDrawable );
  } else if( num == num_temp++ ){
    CALL_AC( CountingTilingPaintable );
  }
}

AC( CountingColouringDistinct )
{
  CALL_AC( CountingColouring );
  CERR( "- �Q�̍�p�ɂ�铯�ꎋ������Ȃ�΁A�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "  https://ja.wikipedia.org/wiki/�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "���������܂��傤�B" );
}

AC( CountingColouring )
{
  CERR( "- �h�蕪����}�`�Q�̊O���Ⓒ�_�Ɉʒu����}�`��̌������Ȃ���" );
  CERR( "  �F�̎�ސ������Ȃ��Ȃ�΁A�O���Ⓒ�_�̐}�`�Q�̓h�蕪�����Œ肷�邱�Ƃ�" );
  CERR( "  ���菬�����}�`�Q�ɑ΂��鐔���グ�Ƃ̊֌W���𓱏o���A" );
  CERR( "  �T�C�Y�Ɋւ��铮�I�v��@" );
}

AC( CountingColouringDrawable )
{
  CERR( "�`��\�����ȒP�ȏ����ɖ|�󂵁A���̏����𖞂����h�蕪����" );
  CERR( "�����グ�܂��傤�B" );
  ASK_YES_NO( "�d�Ȃ�������Đ}�`��u���`����@�ł����H" );
  if( reply == "y" ){
    CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( CountingTilingPaintable )
{
  CERR( "�h�蕪�����Ƃɐ}�`�̕`����@����ӂɒ�܂�Ȃ�΁A" );
  CERR( "�h�蕪�����@�̓��l�ނƂ��ĕ`����@�𐔂��グ���܂��傤�B" );
  CERR( "- ���l�ނ̗v�f�������Ȃ�ΒP���ȏ�" );
  CERR( "- �Q�̍�p�ɂ�铯�ꎋ������Ȃ�΁A�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "  https://ja.wikipedia.org/wiki/�R�[�V�[�E�t���x�j�E�X�̕��" );
  CERR( "�ŏ��W�����v�Z���܂��傤�B�������̓h�蕪����" );
  CERR( "- �O���b�h�̕����W���̃}�X��ӂ̓h�蕪���́A��������P����2�d���[�v" );
  CALL_AC( CountingColouring );
  CERR( "���������܂��傤�B" );
}

AC( CountingYoundDiagram )
{
  CERR( "�W�������O�^�u���[�̌��̓t�b�N�������Ōv�Z�ł��܂��B" );
  CERR( "\\Mathematics\\Combinatorial\\YoungDiagram\\a.hpp" );
  CERR( "- 2�~N�̕W�������O�^�u���[�i�s�^��Ƃ��ɋ��`�P������ɂȂ�悤�Ȕԍ��Â��j" );
  CERR( "  �̌�=��N�J�^������C(N)=(2N)!/((N+1)!N!)" );
  CERR( "- RS�Ή��i�^�̓����������O�^�u���[�Ə���̑Ή��j" );
  CERR( "  https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence" );
  CERR( "- ���W�������O�^�u���[�Ɣ�����ȃp�X�̑g�Ƃ̑Ή�" );
  CERR( "���������܂��傤�B" );
}

AC( CountingParenthesisSequence )
{
  CERR( "2N�����̕����J�b�R��̌��͑�N�J�^������C(N)=(2N)!/((N+1)!N!)�ł��B" );
}

AC( Solving )
{
  ASK_NUMBER(
	     "�P�̕�����f(x,y,...) = c" ,
	     "M�̕�����f(x[a[i]],C^{d[i]}x[b[i]]) = c[i]" ,
	     "M�̕�����sum_{j=a[i]}^{b[i]} C^{j-a[i]} x[j] = c[i]" ,
	     "���̑��̕�����"
	     );
  if( num == num_temp++ ){
    CERR( "- �ȉ~�^�̕s��������Ȃ�΁A" );
    CERR( "  - �L�E�ȗ̈��S�T��" );
    CERR( "  - �Е��̕ϐ����Œ肵�Đ����͈̔͂Ŏ������̋ߖT�v�Z" );
    CERR( "- �����^�̕s��������Ȃ�΁A���������ŕϐ��ϊ����ē�����2�ϐ���" );
    CERR( "  �|���o���A�P�ϐ����ƂɌ���" );
    CERR( "- �o�Ȍ^�̕s��������Ȃ�΁A" );
    CERR( "  - ���萔�{�ƈڍ��ŕϐ����܂ސ�=�萔�̌`�ɂȂ�Β萔�̖񐔗�" );
    CERR( "  - �Ȃ�Ȃ���΃y���������ɋA��" );
    ASK_YES_NO( "f(x,y,...) = h(g(x),g(y),...)�̌`�ł����H" );
    if( reply == "y" ){
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
    }
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
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- O(BM + BN log B)���Ԃɍ��������Ȃ�Ε��^�[���D��T��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch" );
  CERR( "- O(Mf(N) + N)���Ԃɍ���������f(x,y)=x-y����C=1�Ȃ��" );
  CERR( "  �|�e���V�����t���f�W���f�[�^�\��" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
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
	     "��Ԃ̑��̗v�f�����������" ,
	     "��ԂƋt���̋��ʕ����̗v�f�����������" ,
	     "2�����֐��ɂ����max�^min�X�V���g�����" ,
	     "�����֐��ƒ萔�̘a�ɂ����min�X�V���g�����" ,
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
    CALL_AC( QueryArrayImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayInverseImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxLinearFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMinDistance );
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
  CERR( "- ��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ�΋�ԑ�����m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
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
  CERR( "- ��ԑ��O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ�΋�ԑ�����m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "- ��_��ZO(1)�^��_���O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)���K�v�Ȃ��" );
  CERR( "  �����m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative" );
  CERR( "- ��_��ZO(1)�^��ԏ�ZO(��N)�^��_���O(��N)�^��_�擾O(1)�^��Ԏ擾O(��N)" );
  CERR( "  ���K�v�Ȃ�΋�ԏ�Z�����m�C�h��������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative\\IntervalMultiply" );
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
  CERR( "��Ԃ̑��̗v�f���擾���K�v�Ȃ�Δ��̃A���S���Y��" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayInverseImageSize )
{
  CERR( "q�Ԗڂ̃N�G���ŋ��ʕ��������W����S_q�ƒu���܂��B" );
  CERR( "- �ei�ɑ΂���A_i���eq�ɑ΂���S_q�̓����֐������̒l�̘A�z�z��ŊǗ��������āA" );
  CERR( "  �I�t���C���ݐϐςŌ��擾�܂��͔��̃A���S���Y���ŘA�z�z��̗ݐϘa�v�Z" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativePrpdict\\Offline" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "- �eq���Ƃ�vector I_q��p�ӂ��āA�ei�ɑ΂�A_i��S_q�ɑ����Ȃ�" );
  CERR( "  I_q��i��push_back���AI_q�Ƌ�Ԃ̋��ʕ�����񕪒T���Ōv�Z");
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- �ŏ��l���ő�l�ɋA��������ɂ́A�񕪒T�����s�v�ł����Reversed<T>���A" );
  CERR( "  �񕪒T�����s�v�ł����-1�{���������܂��傤�B" );
  CERR( "  \\Utility\\Reverse" );
  CERR( "- �ꎟ�֐���x�z�֌W�𖞂�������ʂ�2�p�����[�^�֐��K�w�ɂ��" );
  CERR( "  �S��max�X�VO(log N)�^��_�擾O(log N)���K�v�Ȃ��Convex Hull Trick" );
  CERR( "  \\Mathematics\\Function\\MaxTwoAryHierarchy" );
  CERR( "- �X���̌�₪C�̈ꎟ�֐��ɂ����min�X�VO(N^{1/2})�^��_�擾O(C)��" );
  CERR( "  �K�v�Ȃ�Γ��䐔��min�X�V�o�Ε�������" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Dual\\GeometricProgressionMin" );
  CERR( "���������܂��傤�B" );
}

AC( QueryArrayMinDistance )
{
  CERR( "�����֐��ƒ萔�̘a�ɂ����min�X�V�͌X���}1�̈ꎟ�֐��ɂ����min�X�V" );
  CERR( "�ɑ��Ȃ�܂���B" );
  CALL_AC( QueryArrayMaxLinearFunction );
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
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree" );
  CERR( "- ���m�C�h�\���Ɋւ���p�X�ł̑���O(log N)���K�v�Ȃ�Ώd�ݕt��LCA" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree\\Weighted" );
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
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- �ӂ̍폜��O(V+E��(V))���Ԃɍ��������Ȃ�΃N�G���t�ǂ݂�UnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- ����̕ӂ��܂ލŏ��S��X�擾��O((V+Q)log V + E log E)���Ԃɍ��������Ȃ��" );
  CERR( "  �S�̂ɑ΂���ŏ��S��X���N���X�J���@�őO�v�Z���d�ݕt��LCA�ɂ��" );
  CERR( "  �ő�R�X�g�ӌv�Z" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree\\Weighted" );
  CERR( "- �ӏW���̍ʐF��ς����ŏ��S��X�擾��O(V + E log E + Q��(V))���Ԃɍ�������" );
  CERR( "  �Ȃ�ΑS�̂ɑ΂���ӂ̃\�[�g��O�v�Z���N���X�J���@�̔���" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "���������܂��傤�B" );  
}

AC( QueryString )
{
  CERR( "������̈�_�X�V�i�ꕶ���X�V�j�^�����^��r�̓��[�����O�n�b�V��" );
  CERR( "\\Utility\\String\\RollingHash" );
  CERR( "�ŃR�[�h�����A�ǉ��ōX�V�N�G���^�擾�N�G����" );
  CERR( "- ���[����̘A��������������Ǘ�����ꍇ�̈�_�X�V�͕�����̗ݐσR�[�h��" );
  CERR( "  ��ԉ��ZBIT�ɏ悹�ďI�ؕЉ��Z�Ǝn�ؕИa�擾�iO(log N)/O(log N)�j�ŏ���" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\IntervalAdd" );
  CERR( "- �A��������������Ǘ�����ꍇ�A" );
  CERR( "  - �n�b�V���ƌ���̙p��͉��Q" );
  CERR( "  - �R�[�h�͔���Q" );
  CERR( "  ��p���邱�Ƃɒ��ӂ���" );
  CERR( "  - ��_�X�V�݂̂��K�v�Ȃ��" );
  CERR( "    - ������̊e�����̃n�b�V���ƌ���̙p��̐ς�" );
  CERR( "      - BIT�ɏ悹�Ĉ�_�X�V�Ƌ�Ԙa�擾�iO(log N)/O(log N)�j" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT" );
  CERR( "      - �Z�O�����g�؂ɏ悹�Ĉ�_�X�V�Ƌ�Ԙa�擾�iO(log N)/O(log N)�j" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - ���������ɏ悹�Ĉ�_�X�V�Ƌ�Ԙa�擾�iO(1)/O(N^{1/2})�j" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition" );
  CERR( "      �ŏ���" );
  CERR( "    - ������̊e�����̃R�[�h��" );
  CERR( "      - �Z�O�����g�؂ɏ悹�Ĉ�_�X�V�Ƌ�Ԑώ擾�iO(log N)/O(log N)�j" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - ���m�C�h���������ɏ悹�Ĉ�_�X�V�Ƌ�Ԑώ擾�iO(1)/O(N^{1/2})�j" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "      �ŏ���" );
  CERR( "  - ��ԑ���X�V���K�v�Ȃ�Ε�����̊e�����̃R�[�h��" );
  CERR( "    - �x���Z�O�����g�؂ɏ悹�ċ�ԑ���X�V�Ƌ�Ԑώ擾�iO(log N)/O(log N)�j" );
  CERR( "    - ��ԑ�����m�C�h���������ɏ悹�ċ�ԑ���X�V�Ƌ�Ԑώ擾�iO(N^{1/2})/O(N^{1/2})�j" );
  CERR( "      \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "    �ŏ���" );
  CERR( "���������܂��傤�B" );
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
	     "�S��max�X�V�^��Ԙa�擾" ,
	     "�͈�max�X�V�^��_�擾"
	     );
  if( num == num_temp++ ){
    CERR( "�S��max�X�V�N�G���Ƌ�Ԙa�擾�N�G�������n�񏇂ɕ��הԍ���U��܂��B" );
    CERR( "����ɂ��z��̓��莞���ł̋�Ԙa�����߂���ɋA������A" );
    CERR( "���vO((N + Q)log N + Q log Q)�ŏ����ł��܂��B" );
    CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\TimeSeriesSetMax" );
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
  CERR( "�e�����������̊֐��Ƃ݂Ȃ������A�O���t��O(N)�̒P���ȃp�[�c�ɕ������Ƃ��܂��B" );
  CERR( "�e�p�[�c�ł̕ω��ʂ̗ݐϒl��" );
  CERR( "- �K�������ݐϘa��BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- �C�x���g�\�[�g" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\TimeSeriesAdd" );
  CERR( "�Ōv�Z���܂��傤�B" );
}

AC( Game )
{
  ASK_NUMBER(
	     "���s�����߂�2�l�Q�[��" ,
	     "�ŏI�I�ȕs�ϗʂ̍ő剻�ƍŏ������s�ƌ�s���ڎw��2�l�Q�[��"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  }
}

AC( Decision )
{
  CERR( "�ꍇ�����̕��G�Ȗ��͏ؖ��̊T�����R�����g���Ȃ��ƃo�O�����߂₷���ł��B" );
  CERR( "�Ȃ�ׂ��R�����g�������悤�ɂ��܂��傤�B" );
  ASK_NUMBER(
	     "�K�������" ,
	     "�A�������" ,
	     "���B�\�����" ,
	     "�`��\�����" ,
	     "���ݔ�����" ,
	     "�[���\�����" ,
	     "��v������" ,
	     "�\���\�����"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
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

AC( DecisionGame )
{
  ASK_NUMBER(
	     "����̌p����ڎw���Q�[��" ,
	     "�ŏI�ǖʂł̕s�ϗʂ̋����w�肷��Q�[��" ,
	     "���_�̑召�������Q�[��"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionContinuingGame );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    CERR( "dp[t] = �������t����m���ɍŏI�ǖʂł̕s�ϗʂ̒l�ɂł��鐔�l�̑S�̏W��" );
    CERR( "�ƒ�߂�t�Ɋւ��铮�I�v��@���������A�K�v�Ȃ�΂��̎������ʂ���" );
    CERR( "�K�������t������f�[�^�\�����������s���܂��傤�B" );
    CERR( "\\Mathematics\\Game" );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "����񐔂����Ȃ����s���������ł����H" );
    if( reply == "y" ){
      CERR( "�ǖʂ̑Ώ̐��Ȃǂɒ��ڂ��ē��l�ȋǖʂ𓯈ꎋ���A" );
      CERR( "���ꂼ��ɂ��Ă���ݒׂ��ɏ��s���l�@���Ă݂܂��傤�B" );
    } else {
      CERR( "�Q�v���C���[�̓��_�����P�̕s�ϗʂƂ݂Ȃ��A���̍ő剻���s����" );
      CERR( "�����𔻒肵�܂��傤�B" );
      CALL_AC( MaximisationGame );
    }
  }
}

AC( DecisionContinuingGame )
{
  CERR( "�Q�[����胉�C�u������OEIS�̊��p��Y��Ȃ��悤�ɋC��t���܂��傤�B" );
  CERR( "\\Mathematics\\Game" );
  CERR( "https://oeis.org/?language=japanese" );
  ASK_YES_NO( "���͂̌��͈��ł����H" );
  if( reply == "y" ){
    CERR( "�܂��𒼉��𓮓I�v��@�ŏ����Ď������A���s�̋K�������t���܂��傤�B" );
    CERR( "�f�o�b�O���[�h�ŏ��s���v�Z����ۂ͎����̏o�͂ƍ�����Ȃ��悤��" );
    CERR( "���s��z��Ɋi�[���Ă���z����o�͂��܂��傤�B" );
    CERR( "" );
    CERR( "�K���������t����Ȃ����́A" );
    CERR( "- �A�����đI���ł��Ȃ�����͕����^�[���܂Ƃ߂ď������邱�Ƃ�" );
    CERR( "  �ϐ��̏��Ȃ����I�v��@�ɖ|��" );
    CERR( "- �𒼉��܂��͂��̏��ϐ����ɂ����铮�I�v��@�̃f�[�^�\��������" );
    CERR( "- �K����ԂɑΉ�����ϐ����OEIS������T���v�����" );
  } else {
    CERR( "�܂��Q�[�����Ȃ�ׂ��ȒP�Ȑݒ�ɓ��l�ό`���܂��傤�B" );
    CERR( "- �P�������͊K�������܂��傤�B" );
    CERR( "- ����łP�������X�V�����薖���ǉ������肷�邾���Ȃ�a�ɕ������܂��傤�B" );
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
  }
  CERR( "- �Q�[���̘a�ɕ����ł���Ȃ�΃O�����f�B�����v�Z�A" );
  CERR( "  �ł��Ȃ��Ȃ�ΕK����Ԕ���" );
  CERR( "  - ��Ԑ���J�ډ񐔏�������Ȃ��Ȃ�΁A�O�����f�B����K����Ԕ�����ċA��" );
  CERR( "    �v�Z���܂��傤" );
  CERR( "  - �Q�[���̏�ԑJ�ڂ̑S�T�􂪎������ł������Ȃ�΁A" );
  CERR( "    ���b�\����T���ď������̏��������Ɏ��������A" );
  CERR( "    OEIS��p���ăO�����f�B����K����Ԕ���𐄑����܂��傤�B" );
  CERR( "  - �Q�[���̏�ԑJ�ڂ̑S�T�����������ł��Ȃ������Ȃ�΁A��v�Z�ł̎�������" );
  CERR( "    �l�@�R�ꂪ�����₷���̂ő��̍l�@��D�悵�܂��傤�B" );
  CERR( "- ��肵���\�łȂ��J�ڂł����đ��̂ǂ̑J�ڂւ��o�R�ł�����̂�����Ȃ��" );
  CERR( "  strategy-stealing argument" );
  CERR( "  https://en.wikipedia.org/wiki/Strategy-stealing_argument" );
  CERR( "- ��肪���̑I���𔽕��ł���Ȃ�΁A�����헪" );
  CERR( "- �Q�[���̏�ԂɑS�����\�������菟�s���\��������Ԃň��Ȃ�΁A" );
  CERR( "  ���s�ŋ�Ԃ�A�������ɕ���" );
  CERR( "���������܂��傤�B" );
}

AC( DecisionContinuingGameCheck )
{
  CERR( "�����~�X�����łȂ��l�@�~�X�����₷���̂ŁA�T���v�����ʂ��Ă�WA�ƂȂ�����" );
  CERR( "�����ɋ𒼉��Ƃ̔�r�����݂܂��傤�B" );
}

AC( DecisionConnectedness )
{
  CERR( "- �����O���t�̌ʏ�A�����͕��D��T����UnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- �L���O���t�̋��A�����͐[���D��T���ɂ�鋭�A����������" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent" );
  CERR( "- �����O���t�̍����z�����W�[�v�Z�͎�����K���Ȗ@�ł̑|���o���@" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Mod" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Real" );
  CERR( "���������܂��傤�B" );
}

AC( DecisionAccessibility )
{
  CERR( "�ړ��̑O��ŕω����Ȃ��l������ꍇ�A���̒l���������_�ɍi���čl���܂��傤�B" );
  CERR( "�R�X�g�̃p���e�B�ɐ���������ꍇ�͉����ɂ�钲�����������܂��傤�B" );
  ASK_NUMBER(
	     "��`�̈�̓��B�\���i���H�j���" ,
	     "�O���t��̓��B�\�����" ,
	     "�S���_�K��\�����"
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
    CERR( "- �ė��K�����e���Ȃ��Ȃ�΁A" );
    CERR( "  - ��֏�L���O���t�ł���O(V+E)���Ԃɍ��������Ȃ�΁A" );
    CERR( "    �g�|���W�J���\�[�g���Ďn�_���擪�ɂ��邩�ƃ\�[�g���ɑJ�ډ\���Ŕ���" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Acyclic\\HamiltonPath" );
    CERR( "  - �̈�ƈړ��ɑΏ̐�������Ȃ�΁A�^�C�����O�Ɠ񕔃}�b�`���O�ɂ�锽���헪" );
    CERR( "  - O(V^2 2^V)���Ԃɍ��������Ȃ�΁A�w���h�J�[�v�@" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\HeldKarp" );
    CERR( "- �ė��K�����e��O(V+E)���Ԃɍ��������Ȃ�΁A���A��������������" );
    CERR( "  ��֏�L���O���t�ōė��K�����e���Ȃ��ꍇ�ɋA��" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent\\HamiltonWalk" );
    CERR( "���������܂��傤�B" );
  }
  CERR( "" );
}

AC( DecisionDrawability )
{
  CERR( "�܂��͕`��̈���ɂǂ̂悤�ɐ}�`��u���������肵�܂��傤�B" );
  ASK_YES_NO( "�}�`��u���ۂɏd�Ȃ�������܂����H" );
  if( reply == "y" ){
    ASK_NUMBER(
	       "���s�ړ��݂̂������ĒP��̐}�`��u�����" ,
	       "���s�ړ��ƃT�C�Y�ύX�݂̂������ĒP��̐}�`��u�����" ,
	       "������ނ̓���T�C�Y�̐}�`�������Ēu�����"
	       );
    if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityUnique );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityExtension );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
    }
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( DecisionDrawabilityUnique )
{
  CERR( "�}�`��K�v�Ȃ�Ή�]��������ŁA�}�`���������̋�`�̈�̘a�W���ɕ�����" );
  CERR( "�`��̈���ɐ}�`��u���邩�ۂ���}�`�̈ʒu���ƂɂQ�����ݐϘa��" );
  CERR( "�Q�������K�K������ȂǂŔ��肵�܂��傤�B" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProduct\\TwoDimensional" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilityExtension )
{
  CERR( "�`��̈���ɐ}�`��u����T�C�Y�̍ő�l��}�`�̈ʒu���ƂɎڎ��@�Ȃǂ�" );
  CERR( "�O�v�Z���A�ő�T�C�Y�Œu�����Ƃ��l���܂��傤�B" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilitySameSizeOverdrawn )
{
  CERR( "������B�ƕ`��̈�̓��l�֌W�ł����Ĉȉ���2�����𖞂������̂�T���܂��傤�B" );
  CERR( "- �ǂ̂悤�ɐ}�`��u���Ă����̐}�`��mod B�œ��T�C�Y�̐}�`�ɕ��������B" );
  CERR( "- ���̔z�F�x�N�g��mod B���Ǘ����邱�Ƃœ�����K�v�������\�������ł�����B" );
}

AC( DecisionDrawabilitySameSizeUnoverdrawn )
{
  CERR( "�����m�C�hG�ƕ`��̈�̏��W��X�ƃ��m�C�h�����^f:N^X->G�ł�����" );
  CERR( "�ǂ̂悤�ɐ}�`��u���Ă����̐}�`�̏��̔Z�x�x�N�g����f�ł̒l��" );
  CERR( "���lc�ł�����̂�T���܂��傤�B" );
  CERR( "�����X�̔Z�x�x�N�g����f�ł̒lC��(�}�`��u����)c�ŕ\���邱�Ƃ�" );
  CERR( "�K�v�����ƂȂ�܂��B�Ⴆ��" );
  CERR( "- G���Q����C=0����(�}�`��u�����)��c�̈ʐ��̔{���ɂȂ肦�Ȃ��B" );
  CERR( "- G��N����(�}�`��u������̍ő�l)c��C�����ł���B" );
  CERR( "- G��N����(�}�`��u������̍ŏ��l)c��C���傫���B" );
  CERR( "�Ȃǂ̏ꍇ�͂��̕K�v���������藧���Ȃ��̂œh�蕪���s�\�ł��B" );
}

AC( DecisionImageCoincidence )
{
  CERR( "�`��̈���ɂǂ̂悤�ɐ}�`��u���������߂���͂Q�����K������Ȃǂ�" );
  CERR( "���ۂɕ`������A�`�悵�����}�`�ƈ�v���邩�𔻒肵�܂��傤�B" );
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
    CERR( "�z�b�v�N���t�g�J�[�v�@��ő嗬" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
    CERR( "���������܂��傤�B" );
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
    CERR( "- ����XOR�ŕ\���Ȃ�΁A" );
    CERR( "  - ��ʂ̐���\���Ȃ�Ίg��W���s��̊Ȗ�" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
    CERR( "  - 0��񎩖���XOR�ŕ\���Ȃ�Έꎟ�Ɨ�������" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
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
  CERR( "���͂Ɋւ��čċA�I�ɍ\�z������@��T�����߂ɁA���͐������ʉ�����" );
  CERR( "�i�Ⴆ�Α��ϐ������āj�l�@���A�������P�[�X�̎��������܂��傤�B" );
  ASK_NUMBER(
	     "����x�N�g���Ɋւ���\�z" ,
	     "�z��╶����Ɋւ���\�z" ,
	     "�ʑ��̍\�z" ,
             "�O���t��̑���̍\�z" ,
	     "�헪�̍\�z" ,
             "�W���Ɋւ���\�z" ,
	     "�\�[�X�R�[�h�̍\�z"
	     );
  if( num == num_temp++ ){
    CALL_AC( ConstructionNumber );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMap );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionOperationOnGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionSet );
  } else if( num == num_temp++ ){
    CERR( "�������o�͂�����\�[�X�R�[�h���o���܂��傤�B" );
  }
}

AC( ConstructionNumber )
{
  ASK_NUMBER(
	     "����Œ蒷�x�N�g���̕\�����@�̍\�z" ,
	     "�������̉��̍\�z"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else {
    CALL_AC( Solving );
  }
}

AC( ConstructionArray )
{
  ASK_NUMBER(
	     "�����𖞂����z��╶����̍\�z" ,
	     "�^����ꂽ�z��╶����̏����𖞂���������̍\�z"
             );
  if( num == num_temp++ ){
    CERR( "- �P�̔z��̍\���́Ap�i�@��K������ւ̖|����������܂��傤�B" );
    CERR( "- ���炩�̊֐��l����v����Q�̔z��̍\���́A���̑����������Ƃ�" );
    CERR( "  �������p�����[�^��ݒ肵�A�S�T����������܂��傤�B" );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionMap )
{
  CERR( "- �P�˂̍\�z�ɂ�Hall�̌����藝" );
  CERR( "  https://ja.wikipedia.org/wiki/�z�[���̒藝" );
  CERR( "- �S�P�˂̍\�z�ɂ̓z�b�v�N���t�g�J�[�v�@��J���g�[���x�����V���^�C���̒藝" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
  CERR( "  https://ja.wikipedia.org/wiki/�x�����V���^�C���̒藝#�ؖ�" );
  CERR( "- �S�˂̍\�z�ɂ͕����W���𐧌����đS�P�˂̍\�z�̔���" );
  CERR( "���������܂��傤�B" );
}

AC( ConstructionOperationOnGraph )
{
  ASK_NUMBER(
	     "�ŒZ�o�H�̍\�z" ,
	     "�Œ��o�H�̍\�z" ,
	     "�O���b�h����̍\�z"
	     );
  if( num == num_temp++ ){
    CERR( "�ŒZ�o�H�T���A���S���Y���Ōo�H���������܂��傤�B" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "�Œ��o�H�T���A���S���Y���Ōo�H���������܂��傤�B" );
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else {
    CERR( "- HW���������P�[�X�����Ƃ܂��͑S�T��ŋ��߂āA" );
    CERR( "  ��ʂ�HW�͏������P�[�X�̔���" );
    CERR( "- �K���I�ȑ����(mod H,mod W)���A�K�Xunordered_set<T2<int>>��" );
    CERR( "  �d���Ǘ����d�����ɂ͂��炷" );
    CERR( "- �O���b�h��̏���Z�[���X�}�����ɑ΂���q���[���X�e�B�b�N���̍\�z��" );
    CERR( "  ���̃A���S���Y���ɂ��\�[�g" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
    CERR( "���������܂��傤�B" );
  }
}

AC( ConstructionStrategy )
{
  ASK_NUMBER(
	     "�K���헪�̍\�z" ,
	     "�ő剻�헪�̍\�z"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else {
    CALL_AC( ConstructionMaximisation );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "�ŏI�I�ȕs�ϗʂ��ő剻���邽�߂ɂ́A����̐��b�ȕό`�菇�ł�����" );
  CERR( "�l�����炳�Ȃ����̂�T���A���̕ό`�����S�ɍs���ē����鑀��݂̂�" );
  CERR( "�i���čl���܂��傤�B���̕ό`�ɂ�����×~�ȑ��삪�\�ł����" );
  CERR( "�×~�@�ŉ������Ƃ��\�ł��B" );
  CERR( "" );
  CALL_AC( Maximisation );
}

AC( ConstructionSet )
{
  ASK_NUMBER(
	     "�^����ꂽ�񕔃O���t�̕����W���̍\�z" ,
	     "�^����ꂽ�W���̕������@�̍\�z"
             );
  if( num == num_temp++ ){
    CALL_AC( ConstructionSubset );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionSubset )
{
  CERR( "�A���񕔃O���t(S,T)�ƁAs in S��T�̕����W��T0�Ɋւ������P(s,T0)�ł�����" );
  CERR( "- �C�ӂ�s in S��T�̕����W��T0��d(s,t)=1�𖞂���t in T0�ɑ΂��A" );
  CERR( "  P(s,T0)<=>!P(s,T0-{t})�ł���B" );
  CERR( "�𖞂������̂��^�����Ă���Ƃ��āA" );
  CERR( "- �C�ӂ�s in U cap S�ɑ΂��AP(s,U cap T)�ł���B" );
  CERR( "�𖞂���S cup T�̕����W��U�ŔZ�x����W���ȏ�ł�����̂̍\�z���l���܂��B" );
  CERR( "" );
  CERR( "T�𐮗񂳂��A�es in S�ɑ΂�d(s,t)=1�𖞂����ő��t in T��f(s)�ƒu���܂��B" );
  CERR( "U��{}�ŏ���������t in T�̏���������" );
  CERR( "- {s in f^{-1}(t)|P(s,U cap T)}" );
  CERR( "- {s in f^{-1}(t)|P(s,(U cap T) cup {t})} cup {t}" );
  CERR( "�̂����Z�x���������Ȃ����̊e�v�f��U�ɒǉ����܂��Bf�̋t����S�̔r���I�핢��" );
  CERR( "�^����̂ŁA�ŏI�I��U�̔Z�x�͕�W���ȏ�ɂȂ�܂��B" );
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

