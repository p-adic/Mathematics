// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/Costfree/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i] >= 0�ł���B
// (2) 0 <= value_sum_bound�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N + value_sum_bound^2)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł���Ƃ��āA
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
// �v�Z��O(N + value_sum_bound^2)��
// �ei�ɑ΂�����i�𖳐����ɏd���I���ł���Ƃ��āA
// value_sum_bound�ȉ��ɂ����鉿�l�̍ő�l�����߂�B
template <typename INT> inline INT UnboundedChoiceCostfreeBoundedValueSumKnapsack( const vector<INT>& value , const INT& value_sum_bound );
