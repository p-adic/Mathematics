// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/Unstable/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// NegativeValueUnboundedChoiceMulticaseUnstableKnapsack�iCS,cost_sum_bound�j
// https://yukicoder.me/submissions/969029�i5e3,5e3�j

// �ȉ�sum_i choice_stability_num(i)��CS�ƒu���B

// VALUE�͎ʑ�Value:N^2->N�ɑ�������^�B
// COST�͎ʑ�cost:N^2->N�ɑ�������^�B
// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei��choice_stable_num[i]�ȉ��̊em�ɑ΂�0 <= cost(i,m)�ł���B
// (3) N�����̊ei�ɑ΂��AM.One() < value(i,choice_stable_num[i])�Ȃ��
//     0 < cost(i,choice_stable_num[i])�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(CS * cost_sum_bound)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i��
// ���l��value(i,min(m,choice_stable_num[i]))�ł���
// �R�X�g��cost(i,min(m,choice_stable_num[i]))�ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractNegativeValueUnboundedChoiceMulticaseUnstableKnapsack( COMM_MONOID M , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename INT1 , typename VALUE , typename INT2 , typename COST , typename INT3> inline vector<INT1> NegativeValueUnboundedChoiceMulticaseUnstableKnapsack( VALUE value , const INT1& exceptional , COST cost , const INT2& cost_sum_bound , const vector<INT3>& choice_stability_num );
// �v�Z��O(CS * cost_sum_bound)��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnstableKnapsack( COMM_MONOID M , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename INT1 , typename VALUE , typename INT2 , typename COST , typename INT3> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnstableKnapsack( VALUE value , const INT1& exceptional , COST cost , const INT2& cost_sum_bound , const vector<INT3>& choice_stability_num );

