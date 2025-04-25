// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S�������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// value�̔��A�������ρi�E����j�̍ő�l��O(N)�ŋ��߂�B
template <typename U , typename MONOID> U AbstractIntervalCostfreeUnboundedValueSumKnapsack( MONOID M , const vector<U>& value , const bool& non_empty = true );
template <typename INT> inline INT IntervalCostfreeUnboundedValueSumKnapsack( const vector<INT>& value , const bool& non_empty = true );
