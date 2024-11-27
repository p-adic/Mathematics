// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:
// Knapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/976637�i1e3,1e6,1e3�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9056881/C++17�i100,1e5,1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9056887/C++17�i100,1e4,1e9�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9056888/C++17�i40,4e16,1e15�j


// �ȉ�value�̃T�C�Y��N�ƒu���Acost��p����ꍇ��cost�̃T�C�Y��N�Ɠ������Ƃ���B
// ValueSumBound(value)��value_sum_bound�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�M.One() <= value[i]�ł���B
// (3) N�����̊ei�ɑ΂�0 <= cost[i]�ł���B
// (4) 0 <= cost_sum_bound�ł���B
// (5) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N min(value_sum_bound,cost_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// �v�Z��O(N min(,cost_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound );

// ���l�̏�����w�肳��Ă���ꍇ��
// - Costfree
// - Interval
// - Negative/Cost
// �̂����ꂩ��p����B
