// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/ValueSumBound/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U1�̑S�������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N)��
// ���l�̑��a�̏�E�����߂�B
template <typename U , typename COMM_MONOID>
U AbstractValueSumBound( COMM_MONOID M , const vector<U>& value );
template <typename INT> inline INT ValueSumBound( const vector<INT>& value );

