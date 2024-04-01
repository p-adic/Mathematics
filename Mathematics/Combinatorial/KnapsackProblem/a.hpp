// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9047312/C++17�iKnapsack�AN<=100,value_sum_bound<=1e5,cost_sum_bound<=1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9046799/C++17�iKnapsack�AN<=100,value_sum_bound<=1e4,cost_sum_bound<=1e9�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9046714/C++17�iKnapsack�AN<=40,value_sum_bound<=4e16,cost_sum_bound<=1e15�j

// �ȉ�value��N�ƒu���Acost��p����ꍇ��cost�̃T�C�Y��N�Ɠ������Ƃ���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�cost[i]�̊e������0�ȏ�ł���B
// (3) N�����̊ei�ɑ΂�value[i]��M.One()�ȏ�ł���B
// (4) exceptional�͉��l�̑��a�ŕ\���Ȃ���value_sum_bound���傫���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * cost_sum_bound )��
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a��value_sum_bound�ȉ��ł�
// �ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> MulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// �v�Z��O(N * cost_sum_bound)��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// �v�Z��O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );

