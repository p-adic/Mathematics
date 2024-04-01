// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Unbounded/a.hpp

#pragma once

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_C/judge/9047345/C++17�iUnboundedChoiceKnapsack�AN=100,value[i]<=1e3,value_sum_bound<=1e9,cost[i]<=1e3,cost_sum_bound<=1e4�j

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���A0�Ȃ��value[i] = M.One()�ł���B
// (3) N�����̊ei�ɑ΂�value[i]��M.One()�ȏ�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N + cost_sum_bound^2)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractUnboundedChoiceMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> UnboundedChoiceMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// �v�Z��O(N + cost_sum_bound^2)��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractUnboundedChoiceKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> UnboundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N + value_sum_bound^2)��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
template <typename INT> inline INT UnboundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound );
