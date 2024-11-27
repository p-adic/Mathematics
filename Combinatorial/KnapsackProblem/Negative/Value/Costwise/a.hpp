// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Costwise/a.hpp

#pragma once
// verify:
// NegativeValueCostwiseKnapsack�iN,cost_sum_bound�j
// https://yukicoder.me/submissions/976636�i100,1e5�j

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���B
// (3) 0 <= cost_sum_bound�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractNegativeValueCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> NegativeValueCostwiseKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );
