// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/a.hpp

#pragma once

// verify:
// NegativeRestrictiveKnapsack
// https://yukicoder.me/submissions/968223�iN<=14�j


// ���͈͓͂̔��ŗv��
// (1) M1��operator<(const U1&,const U1&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) M2��operator<(const U2&,const U2&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (3) M1.One() <= value_sum_ubound�ł���B
// (4) M2.One() <= cost_sum_ubound�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N 2^{N/2})��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeBoundedValueSumKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
