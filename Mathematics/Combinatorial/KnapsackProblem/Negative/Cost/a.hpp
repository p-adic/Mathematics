// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// (3) 0 <= value_sum_bound�ł���B
// (4) exceptional <= cost_sum_lbound <= M.One()�ł���B
// (5) exceptional�̓R�X�g�̑��a�ŕ\���Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N * value_sum_bound)��
// ���l�̑��a0 <= v <= value_sum_bound���ƂɃR�X�g�̑��a��cost_sum_lbound�ȏ�ł̍ŏ��l�����߂�B
template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractDualMulticaseNegativeCostKnapsack( COMM_MONOID M , const int& N , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional );
template <typename INT1 , typename INT2> inline vector<INT2> DualMulticaseNegativeCostKnapsack( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& exceptional );

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// (3) 0 <= value_sum_bound�ł���B
// (4) exceptional�̓R�X�g�̑��a�ŕ\���邢���Ȃ�l��菬�����B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N min(value_sum_bound,2^{N/2}))��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsack( COMM_MONOID M , const int& N , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeCostKnapsack( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const INT2 exceptional );
