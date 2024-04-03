// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:

// Knapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/968875�i1e3,1e6,1e3�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9055342/C++17�i100,1e5,1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9055344/C++17�i100,1e4,1e9�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9055346/C++17�i40,4e16,1e15�j

// MulicaseKnapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/968878�i100,1e9,1e5�j


// �ȉ�value��N�ƒu���Acost��p����ꍇ��cost�̃T�C�Y��N�Ɠ������Ƃ���B


// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U1�̑S�������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N)��
// ���l�̑��a�̏�E�����߂�B
template <typename U , typename COMM_MONOID>
U AbstractValueSumBound( COMM_MONOID M , const vector<U>& value );
template <typename INT> inline INT ValueSumBound( const vector<INT>& value );


// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�M.One() <= value[i]�ł���B
// (3) N�����̊ei�ɑ΂�0 <= cost[i]�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) M.One <= value_sum_bound�ł���B
// (6) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractValueMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename INT1 , typename INT2> inline vector<INT1> MulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�M.One() <= value[i]�ł���B
// (3) N�����̊ei�ɑ΂�0 <= cost[i]�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) M.One <= value_sum_bound�ł���B
// (6) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N min(cost_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// �v�Z��O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// �v�Z�ʂ̎Z�o��value_sum_bound��cost_sum_bound�̑傫�����g���̂ŁAINT1��INT2�𒊏ۉ����Ȃ��B

