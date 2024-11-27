// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1016175 (N<=40,value_bound=8e5,size_diff_bound=0)

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�value_bound�ȉ��ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// https://yukicoder.me/problems/no/2918�̉�������ƂɎ����B

// �v�Z��O(N + size_diff_bound value_bound^{(log_2 3)/2} log value_bound)��
// �������Ȃ��Ƃ�����͔��ȂQ�O���[�v�Ɨ]��ɕ����A
// �Q�O���[�v�̗v�f���̍���size_diff_bound�ȉ��ł��鎞��
// �Q�O���[�v�̉��l�̑��a�̍��̐�Βl�̍ŏ��l�����߂�B
template <typename INT> INT CostfreeDifferenceKnapsack( const vector<INT>& value , const INT& value_bound , int size_diff_bound = 0 );
// �]���������C=N�̏ꍇ�͑��ɉ��l���a�̔���������Ƃ���i�b�v�T�b�N�����Z���Ηǂ��B
