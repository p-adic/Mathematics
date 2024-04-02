// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:

// Knapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/968656�i1e3,1e6,1e3�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9047312/C++17�i100,1e5,1e4�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9046799/C++17�i100,1e4,1e9�j
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9046714/C++17�i40,4e16,1e15�j

// MulicaseKnapsack�iN,value_sum_bound,cost_sum_bound�j
// https://yukicoder.me/submissions/968206�i100,1e9,1e5�j


// �ȉ�value��N�ƒu���Acost��p����ꍇ��cost�̃T�C�Y��N�Ɠ������Ƃ���B

// �v�Z��O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// �v�Z�ʂ̎Z�o��value_sum_bound��cost_sum_bound�̑傫�����g���̂ŁAINT1��INT2�𒊏ۉ����Ȃ��B

