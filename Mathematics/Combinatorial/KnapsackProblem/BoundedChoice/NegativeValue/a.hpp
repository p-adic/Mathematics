// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/NegativeValue/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S����N���Q�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���A0�Ȃ��value[i] = M.One()�ł���B
// (3) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound log_2 cn_max)��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline vector<U> AbstractBoundedChoiceMulticaseNegativeValueKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline vector<INT1> BoundedChoiceMulticaseNegativeValueKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const INT1& exceptional , const vector<INT1>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
// �v�Z��O(N min(cost_sum_bound,cn_max 2^{N/2}) log_2 cn_max)��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA�R�X�g�̑��acost_sum_bound
// �ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline pair<U,INT1> AbstractBoundedChoiceNegativeValueKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> BoundedChoiceNegativeValueKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
