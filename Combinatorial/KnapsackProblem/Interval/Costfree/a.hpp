// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/a.hpp

#pragma once

// diff_max = -1�Ȃ��diff_max��N - 1�ɒu��������B
// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S�������Q�\���ł���B
// (2) diff_min <= diff_max < N�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// value�̊e�������񕉂̎��͌v�Z��O(N)�A��ʂɂ�O(N(diff_max - diff_min + 1))��
// ����diff_min�ȏ�diff_max�ȉ���value�̘A�������a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP M , const vector<U>& value , const U& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
