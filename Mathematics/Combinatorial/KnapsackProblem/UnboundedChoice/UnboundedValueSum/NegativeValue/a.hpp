// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/NegativeValue/a.hpp

#pragma once

// verify:
// UnboundedChoiceNegativeValueUnboundedValueSumKnapsack�iN,cost_sum_bound�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_C/judge/9054779/C++17�i100,1e4�j

// �R�X�g�����Ȃ�ΑI���񐔂�cost_sum_bound�ŗ}�����A
// ���l�̑��a��(max_i value[i])*cost_sum_bound�ŗ}������̂ŁA
// ���̏ꍇ��AbstractBoundedChoice(Multicase)NegativeValueKnapsack
// �Ɣ�r���đ�������p����B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���A0�Ȃ��value[i] <= M.One()�ł���B
// (3) 0 <= cost_sum_bound�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N + cost_sum_bound^2)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractNegativeValueUnboundedChoiceMulticaseUnboundedValueSumKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> NegativeValueUnboundedChoiceMulticaseUnboundedValueSumKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );
// �v�Z��O(N + cost_sum_bound^2)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł���Ƃ��āA
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueUnboundedChoiceUnboundedValueSumKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnboundedValueSumKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );
