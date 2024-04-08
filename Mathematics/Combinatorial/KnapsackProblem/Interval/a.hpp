// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/a.hpp

#pragma once

// diff_max = -1�Ȃ��diff_max��N - 1�ɒu��������B
// ���͈͓͂̔��ŗv��
// (1) M1��operator<(const U1&,const U1&)�Ɋւ���U1�̑S�������Q�\���ł���B
// (2) M2��operator<(const U2&,const U2&)�Ɋւ���U2�̑S�������Q�\���ł���B
// (3) diff_min <= diff_max < N�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// cost��value�̊e�������񕉂̎��͌v�Z��O(N)�A��ʂɂ�O(N(diff_max - diff_min + 1))��
// ����diff_min�ȏ�diff_max�ȉ���value�̘A�������a��value_sum_bound�ȉ��ł̍ő�l��
// �������������R�X�g�̍ŏ��l�����߂�B
template <typename U1 , typename ABEL_GROUP1 , typename U2 , typename ABEL_GROUP2>
pair<U1,U2> AbstractIntervalKnapsack( ABEL_GROUP1 M1 , ABEL_GROUP1 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> IntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const int& diff_min = 0 , int diff_max = -1 );


// diff_max = -1�Ȃ��diff_max��N - 1�ɒu��������B
// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S�������Q�\���ł���B
// (2) diff_min <= diff_max < N�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// value�̊e�������񕉂̎��͌v�Z��O(N)�A��ʂɂ�O(N(diff_max - diff_min + 1))��
// ����diff_min�ȏ�diff_max�ȉ���value�̘A�������a��value_sum_bound�ȉ��ł̍ő�l�����߂�B
template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP1 M , const vector<U>& value , const U& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
