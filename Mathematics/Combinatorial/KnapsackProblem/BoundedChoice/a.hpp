// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/a.hpp

#pragma once

// verify:
// BoundedChoiceKnapsack�iN,v_max,value_sum_bound,cost_sum_bound,choice_num_bound_max�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_G/judge/9056997/C++17�i100,1e3,1e9,1e4,1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_I/judge/9056999/C++17�i50,50,25e11,1e9,1e9�j

// max_i value[i]��v_max�ƒu���Amax_i choice_num_bound[i]��cn_max�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U1�̑S����N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N)��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł���Ƃ��āA�e�R�X�g��1�ȏ�ł���ꍇ��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̏�E�����߂�B
template <typename U , typename N_MODULE , typename INT1 , typename INT2>
U AbstractValueBoundedChoiceValueSumBound( N_MODULE M , const vector<U>& value , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline INT1 BoundedChoiceValueSumBound( const vector<INT1>& value , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );

// ���͈͓͂̔��ŗv��
// (1) M1��operator<(const U1&,const U1&)�Ɋւ���U1�̑S����N���Q�\���ł���B
// (2) M2��operator<(const U2&,const U2&)�Ɋւ���U2�̑S����N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N log_2 cn_max)��
// value��cost�d���I���Ȃ��̓����ȓ��̓f�[�^�ɖ|��value_new��cost_new�Ɋi�[����B
template <typename U1 , typename N_MODULE1 , typename U2 , typename N_MODULE2 , typename INT>
void SetIteratedItem( N_MODULE1 M1 , N_MODULE2 M2 , const int& N , const vector<U1>& value , vector<U1>& value_new , const vector<U2>& cost , vector<U2>& cost_new , const vector<INT>& choice_num_bound );

// min(max_i value[i]>0?choice_num_bound(i):0,value_sum_bound)��cn_max���`�������B
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���B
// (2) 0 <= value_sum_bound�ł���B
// (3) 0 <= cost_sum_bound�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N min(cost_sum_bound,value_sum_bound,cn_max 2^{N/2}) log_2 cn_max,
//   N^2 v_max^2 log_2 v_max))��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł���Ƃ��āA�R�X�g�̑��acost_sum_bound
// �ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
