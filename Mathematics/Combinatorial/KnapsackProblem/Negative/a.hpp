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
pair<U1,U2> AbstractNegativeKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// ���͈͓͂̔��ŗv��
// (1) M1��operator<(const U1&,const U1&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) M2��operator<(const U2&,const U2&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (3) M1.One() <= value_sum_ubound�ł���B
// (4) cost_sum_lbound <= M2.One() <= cost_sum_ubound�ł���B
// (5) exceptional��value�̕����a�ŕ\���Ȃ����܂���value_sum_ubound�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N 2^N)��
// �R�X�g�̑��acost_sum_lbound�ȏォ��cost_sum_ubound�ȉ���ۂ����܂ܑJ�ڂ����鐧�񉺂�
// ���l�̑��a��value_sum_bound�ȉ��ł̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeRestrictiveKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_ubound , const U1& exceptional , const vector<U2>& cost , const U2& cost_sum_lbound , const U2& cost_sum_ubound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeStrictRestrictiveKnapsack( const vector<INT1>& value , const INT1& value_sum_ubound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& cost_sum_ubound );
