// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/MinimalCostSum/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// (3) 0 <= value_sum_bound�ł���B
// (5) exceptional�̓R�X�g�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * value_sum_bound)��
// ���l�̑��a0 <= v <= value_sum_bound���ƂɃR�X�g�̑��a�̍ŏ��l�����߂�B
template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractNegativeCostMulticaseMinimalCostSumKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& exceptional );
template <typename INT1 , typename INT2> inline vector<INT2> NegativeCostMulticaseMinimalCostSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& exceptional );
