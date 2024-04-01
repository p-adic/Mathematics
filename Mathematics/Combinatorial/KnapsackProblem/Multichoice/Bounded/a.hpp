// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Bounded/a.hpp

#pragma once

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_G/judge/9047304/C++17�iBoundedChoiceKnapsack, N<=100,value_bound<=1e3,value_sum_bound<=1e9,cost[i]<=1e3,choice_num_bound_max<=1e4,cost_sum_bound<=1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_I/judge/9047292/C++17�iBoundedChoiceKnapsack, N<=50,value_bound<=50,cost[i]<=1e9,choice_num_bound_max<=1e9,cost_sum_bound<=1e9�j

// CHOICE_NUM_BOUND�͎ʑ�choice_num_bound:N->N�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S����N���Q�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���A0�Ȃ��value[i] = M.One()�ł���B
// (3) N�����̊ei�ɑ΂�value[i]��M.One()�ȏ�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(min(N + cost_sum_bound^2,N * cost_sum_bound log_2 cost_sum_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline vector<U> AbstractBoundedChoiceMulticaseKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename CHOICE_NUM_BOUND , typename INT2> inline vector<INT2> BoundedChoiceMulticaseKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , const vector<INT1>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(min(N + value_sum_bound^2,N * value_sum_bound log_2 value_sum_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT , typename CHOICE_NUM_BOUND> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT>& value , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max );
// �v�Z��O(min(N + cost_sum_bound^2,N * cost_sum_bound log_2 cost_sum_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA�R�X�g�̑��acost_sum_bound
// �ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��1�ȏ�ł���B
// (2) N�����̊ei�ɑ΂�choice_num_bound(i) <= choice_num_bound_max�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(min(N + cost_sum_bound^2,
//   N min(cost_sum_bound,value_sum_bound,2^{(N log_2 choice_sum_bound_max)/2}) log_2 choice_sum_bound_max,
//   N^2 value_bound^2 log_2 value_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA�R�X�g�̑��acost_sum_bound
// �ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename INT1 , typename INT2 , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT2& cost_sum_bound );
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(min(N + value_sum_bound^2,
//   N min(value_sum_bound,2^{N/2}) log_2 value_sum_bound,
//   N^2 value_bound^2 log_2 value_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// ���l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename INT , typename CHOICE_NUM_BOUND> inline INT BoundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max );


// COST�͎ʑ�cost:N^2->N�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei��choice_num_bound(i)�ȉ��̊em�ɑ΂�cost(i,m)��1�ȏ�ł���B
// (2) N�����̊ei�ɑ΂�value[i]��M.One()�ȏ�ł���B
// (3) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound^2)��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i�̃R�X�g��
// cost(i,m)�ł���Ƃ��āA�R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃ�
// ���l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND>
vector<U> AbstractBoundedChoiceUnstableCostMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline vector<INT1> BoundedChoiceUnstableCostMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );
// �v�Z��O(N * cost_sum_bound^2)��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i�̃R�X�g��
// cost(i,m)�ł���Ƃ��āA�R�X�g�̑��acost_sum_bound�ȉ��Ƃ���value_sum_bound�ȉ��ł̍ő�l��
// ���߂�B
template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceUnstableCostKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceUnstableCostKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );

