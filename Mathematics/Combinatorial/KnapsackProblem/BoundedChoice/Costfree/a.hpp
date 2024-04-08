// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Costfree/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * value_sum_bound log_2 cn_max)��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł���Ƃ��āA
// ���l0 <= v <= value_sum_bound���Ƃ�v��value�̕����a�ŕ\���邩�ۂ��𔻒肷��B
template <typename INT1 , typename INT2> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound );
// �v�Z��O(min(N min(value_sum_bound,cn_max 2^{N/2}) log_2 cn_max,
//   N^2 v_max^2 log_2 v_max))��
// �ei�ɑ΂�����i��choice_num_bound(i)��܂ŏd���I���ł���Ƃ��āA
// ���l�̑��a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename INT1 , typename INT2> inline INT1 BoundedChoiceCostfreeBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound ) { return BoundedChoiceKnapsack( value , value , value_sum_bound , choice_num_bound ); }
