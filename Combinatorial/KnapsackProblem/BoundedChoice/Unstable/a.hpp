// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Unstable/a.hpp

#pragma once
#include "a_Macro.hpp"

// VALUE�͎ʑ�value:N^2->N�ɑ�������^�B
// COST�͎ʑ�cost:N^2->N�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei��choice_num_bound[i]�ȉ��̊em�ɑ΂�M.One() <= value(i,m)�ł���B
// (3) N�����̊ei��choice_num_bound[i]�ȉ��̊em�ɑ΂�0 <= cost(i,m)�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cn_max * cost_sum_bound)��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i��
// ���l��value(i,m)�ŃR�X�g��cost(i,m)�ł���Ƃ��āA�R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃ�
// ���l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractValueBoundedChoiceUnstableCostwiseKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline vector<ret_t<VALUE,int,int>> BoundedChoiceUnstableCostwiseKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
// �v�Z��O(N * cn_max * cost_sum_bound)��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i�̃R�X�g��
// cost(i,m)�ł���Ƃ��āA�R�X�g�̑��acost_sum_bound�ȉ��Ƃ���value_sum_bound�ȉ��ł̍ő�l��
// ���߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractBoundedChoiceUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<ret_t<VALUE,int,int>,INT1> BoundedChoiceUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );

