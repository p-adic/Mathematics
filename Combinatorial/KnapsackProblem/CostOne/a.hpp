// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/CostOne/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1053123 (CostOneKnapsack)

// cost_sum_bound�̃T�C�Y��N�Ɠ������Ƃ���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) N�����̊ei�ɑ΂�0 <= cost_sum_bound[i]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N log min( N , max_i cost_sum_bound[i] ))��
// i�Ԗڂ̍��ڑI�����ɑI�����̑��a��cost_sum_bound[i]�ȉ��ł���������ōŏI�I��
// {���l�̑��a�̍ő�l,�������������I�����̍ŏ��l}�����߂�B
template <typename U , typename COMM_MONOID> pair<U,int> AbstractValueCostOneKnapsack( COMM_MONOID M , const vector<U>& value , const vector<int>& cost_sum_bound );
template <typename INT> inline pair<INT,int> CostOneKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound );

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S�������Q�\���ł���B
// (2) N�����̊ei�ɑ΂�0 <= cost_sum_bound[i]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N log min( N , max_i cost_sum_bound[i] ))��
// i�Ԗڂ̍��ڑI�����ɑI�����̑��a��cost_sum_bound[i]�ȉ��ł����������
// {���l�̑��a�̍ő�l,�������������I�����̍ŏ��l}��answer[i]�Ɋi�[����B
template <typename U , typename ABEL_GROUP> vector<pair<U,int>> AbstractValueCostOneItemwiseKnapsack( ABEL_GROUP M , const vector<U>& value , const vector<int>& cost_sum_bound );
template <typename INT> inline vector<pair<INT,int>> CostOneItemwiseKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound );
