// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/ValueSumBound/a.hpp

#pragma once


// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U1�̑S����N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N)��
// �ei�ɑ΂�����i��choice_num_bound[i]��܂ŏd���I���ł���Ƃ��āA�e�R�X�g��1�ȏ�ł���ꍇ��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̏�E�����߂�B
template <typename U , typename N_MODULE , typename INT1 , typename INT2>
U AbstractValueBoundedChoiceValueSumBound( N_MODULE M , const vector<U>& value , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline INT1 BoundedChoiceValueSumBound( const vector<INT1>& value , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
