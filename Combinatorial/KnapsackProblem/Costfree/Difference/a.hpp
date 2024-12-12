// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1016175 (N<=40,value_bound=8e5,size_diff_bound=0)

// N>0?max(value):0��value_bound�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �v�Z��O(N + size_diff_bound value_bound^{(log_2 3)/2} log value_bound)��
// �������Ȃ��Ƃ�����͔��ȂQ�O���[�v�Ɨ]��ɕ����A
// �Q�O���[�v�̗v�f���̍���size_diff_bound�ȉ��ł��鎞��
// �Q�O���[�v�̉��l�̑��a�̍��̐�Βl�̍ŏ��l�����߂�B
// https://yukicoder.me/problems/no/2918�̉�������ƂɎ����B
template <typename INT> INT CostfreeDifferenceKnapsack( const vector<INT>& value , int size_diff_bound = 0 );
