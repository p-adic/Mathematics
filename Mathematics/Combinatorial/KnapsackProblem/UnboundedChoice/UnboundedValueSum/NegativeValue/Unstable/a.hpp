// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/NegativeValue/Unstable/a.hpp

#pragma once
#include "a_Macro.hpp"

// VALUE�͎ʑ�Value:N^2->N�ɑ�������^�B
// COST�͎ʑ�cost:N^2->N�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) N�����̊ei��choice_stable_num[i]�ȉ��̊em�ɑ΂�0 <= cost(i,m)�ł���B
// (2) N�����̊ei�ɑ΂��AM.One() < value(i,choice_stable_num[i])�Ȃ��
//     0 < cost(i,choice_stable_num[i])�ł���B
// (3) 0 <= cost_sum_bound�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * choice_stability_num * cost_sum_bound)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i��
// ���l��value(i,min(m,choice_stable_num[i]))�ł���
// �R�X�g��cost(i,min(m,choice_stable_num[i]))�ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractNegativeValueUnboundedChoiceMulticaseUnboundedValueSumUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline vector<ret_t<VALUE,int,int>> NegativeValueUnboundedChoiceMulticaseUnboundedValueSumUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
// �v�Z��O(N * choice_stability_num * cost_sum_bound)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i��
// ���l��value(i,min(m,choice_stable_num[i]))�ł���
// �R�X�g��cost(i,min(m,choice_stable_num[i]))�ł���Ƃ��āA
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnboundedValueSumUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<ret_t<VALUE,int,int>,INT1> NegativeValueUnboundedChoiceUnboundedValueSumUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );

