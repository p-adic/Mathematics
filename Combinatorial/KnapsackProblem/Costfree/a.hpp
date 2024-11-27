// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�value_bound�ȉ��ł���B
// (2) 1 <= value_bound <= value_sum_bound�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// David Pisinger, "Linear Time Algorithms for Knapsack Problems with Bounded Weights, Journal of Algorithms", Volume 33, Issue 1, October 1999, Pages 1--14
// �̃A���S���Y��
// (�Q�l�Fhttps://stackoverflow.com/questions/18821453/bounded-knapsack-special-case-small-individual-item-weight-is-small-compared-t/18949218#18949218)
// �����ƂɎ����B
// �v�Z��O(N min(value_bound,2^{N/2}))��
// ���l�̑��a��value_sum_bound�ȉ��ɂ�����ő�l�����߂�B
template <typename INT> inline INT CostfreeKnapsack( const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound );
