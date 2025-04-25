// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/UnboundedValueSum/Segmentwise/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S�������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �ei�ɑ΂��Areversed?[i,N):[0,i]�Ɋ܂܂��value��(non_empty?���:��ł��悢)��Ԃ�
// �����ρi�E����j�̍ő�l�����vO(N)��answer[i]�Ɋi�[����B
template <typename U , typename MONOID> vector<U> AbstractIntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( MONOID M , const vector<U>& value , const bool& non_empty = true , const bool& reversed = false );
template <typename INT> inline vector<INT> IntervalCostfreeUnboundedValueSumSegmentwiseKnapsack( const vector<INT>& value , const bool& non_empty = true , const bool& reversed = false );
