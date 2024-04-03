// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Ordered/a.hpp

#pragma once

// cost_bound�̃T�C�Y��K�ƒu���B
// ���͈͓͂̔��ŗv��
// (1) K <= N�ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// (3) chosen_zero�̓T�C�YK��bool�l�z��ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N log_2 N)��
// 1 <= k <= K�ڂ̑I���̃R�X�g�����cost_bound[k-1]�Ƃ��A����0 <= i < N�̃R�X�g��
// (chosen_zero[k]?cost0:cost1)[i]�Ƃ���󋵂ŁA���XK��̑I�������鎞��
// ���l�̑��a�̍ő�l�����߂�B
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedUnstableCostKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost0 , const vector<U2>& cost1 , const vector<bool>& chosen_zero , const vector<U2>& cost_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> OrderedUnstableCostKnapsack( const vector<INT1>& value , const vector<INT2>& cost0 , const vector<INT2>& cost1 , const vector<bool>& chosen_zero , const vector<INT2>& cost_bound );


// cost_bound�̃T�C�Y��K�ƒu���B
// (1) K <= N�ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �v�Z��O(N log_2 N)��
// 1 <= k <= K�ڂ̑I���̃R�X�g�����cost_bound[k-1]�Ƃ��A���XK��̑I�������鎞��
// ���l�̑��a�̍ő�l�����߂�B
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost , const vector<U2>& cost_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> OrderedKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const vector<INT2>& cost_bound )x;

