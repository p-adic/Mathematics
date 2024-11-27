// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * value_sum_bound)��
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT> inline vector<bool> CostfreePresentabilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
