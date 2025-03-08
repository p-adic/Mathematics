// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/FixedSize/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1051073 (CostfreeFixedSizeInitialSegmentwiseKnapsack)

// ���͈͓͂̔��ŗv��
// (1) G��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N log subset_size)��
// �ei<N�ɑ΂�answer[i]��(value[0],...,value[i])�̗v�f��subset_size�̕����W���̉��l��
// ���a�̍ő�l���i�[����B������i<subset_size�ɂ����Ă�G.zero()���i�[����B
template <typename U , typename COMM_GROUP> vector<U> AbstractCostfreeFixedSizeInitialSegmentwiseKnapsack( COMM_GROUP G , const vector<U>& value , const int& subset_size );
template <typename INT> inline vector<INT> CostfreeFixedSizeInitialSegmentwiseKnapsack( const vector<INT>& value , const int& subset_size );
// �v�Z��O(N log subset_size)��
// �ei<N�ɑ΂�answer[i]��(value[i-interval_size+1],...,value[i])�̗v�f��subset_size��
// �����W���̉��l�̑��a�̍ő�l���i�[����B������i<interval_size-1||inteval_size<subset_size
// �ɂ����Ă�G.zero()���i�[����B
template <typename U , typename COMM_GROUP> vector<U> AbstractCostfreeFixedSizeIntervalwiseKnapsack( COMM_GROUP G , const vector<U>& value , const int& interval_size , const int& subset_size );
template <typename INT> inline vector<INT> CostfreeFixedSizeIntervalwiseKnapsack( const vector<INT>& value , const int& interval_size ,  const int& subset_size );
