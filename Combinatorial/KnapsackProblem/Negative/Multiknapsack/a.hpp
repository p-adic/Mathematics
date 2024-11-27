// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Multiknapsack/a.hpp

#pragma once
// verify:
// NegativeBoundedValueMultiknapsack�iN,K�j
// https://yukicoder.me/submissions/970796�i20,2�j

// �ȉ�cost_sum_bound�̃T�C�Y��K�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) M1��operator<(const U1&,const U1&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) M2��operator<(const U2&,const U2&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (3) M1.One() <= value_sum_bound�ł���B
// (4) K�����̊ek�ɑ΂�M2.One() <= cost_sum_bound[k]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(K(N 2^N + K^N))��
// K�����̊ek�ɑ΂��i�b�v�T�b�Nk�̗e�ʂ�cost_sum_bound[k]�Ƃ����ꍇ�̉��l�̑��a��
// value_sum_bound�ȉ��ł̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeBoundedValueSumMultiknapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const vector<U2>& cost_sum_bound );

template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeBoundedValueMultiknapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound );
