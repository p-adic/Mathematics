// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Costfree/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(min(N + value_sum_bound^2,N * value_sum_bound log_2 value_sum_bound))��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł���Ƃ��āA
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT1 , typename INT2> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound );
// �v�Z��O(min(N + value_sum_bound^2,
//   N * value_sum_bound log_2 value_sum_bound,
//   N^2 value_bound^2 log_2 value_bound))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// ���l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename INT1 , typename INT2> inline INT1 BoundedChoiceCostfreeKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound );
