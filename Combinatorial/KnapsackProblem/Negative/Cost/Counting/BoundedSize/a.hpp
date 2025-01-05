// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Counting/BoundedSize/a.hpp

#pragma once

// value��cost�̃T�C�Y��N�ƒu���Avalue_sum_bound�̒�����Q�ƒu���A
// size_bound��[size_min,size_max]�ƕ\���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// (3) 0 <= value_sum_bound�ł���B
// (4) M.One() <= cost_sum_bound�ł���B
// (5) 0 <= size_min <= size_max <= N�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// O(size_max + (size_max-size_min+1)Q(log Q + N)2^{N/2})��
// �eq<Q�ɑ΂����l�̑��a�����value_sum_bound[q]�ɑ����R�X�g�̑��a��cost_sum_bound�ȉ��ł���
// �I��size�����size_bound�ɑ����I����@�̌���answer[size][q]�Ɋi�[����B
template <typename INT , typename U , typename COMM_MONOID> vector<vector<ll>> AbstractCountingNegativeCostBoundedValueSumBoundedSizeKnapsack( COMM_MONOID M , const vector<INT>& value , const vector<pair<INT,INT>>& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const pair<int,int>& size_bound );
template <typename INT1 , typename INT2> inline vector<vector<ll>> CountingNegativeCostBoundedValueSumBoundedSizeKnapsack( const vector<INT1>& value , const vector<pair<INT1,INT1>>& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const pair<int,int>& size_bound );
// �R�X�g���Ȃ��ꍇ�͉��l���R�X�g�Ƃ݂Ȃ���
// CountingNegativeCostBoundedValueSumKnapsack( value , value_sum_bound , value , value_sum_bound_max , size_bound );
// �Ƃ���Ηǂ��B
