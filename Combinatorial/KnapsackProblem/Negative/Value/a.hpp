// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���B
// (3) 0 <= cost_sum_bound�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N min(cost_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeValueKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );

