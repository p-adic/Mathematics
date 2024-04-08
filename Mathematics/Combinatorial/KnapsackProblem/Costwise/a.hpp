// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costwise/a.hpp

#pragma once

// verify:
// MulicaseKnapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/968878�i100,1e9,1e5�j

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�M.One() <= value[i]�ł���B
// (3) N�����̊ei�ɑ΂�0 <= cost[i]�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractValueCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename INT1 , typename INT2> inline vector<INT1> CostwiseKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound );
