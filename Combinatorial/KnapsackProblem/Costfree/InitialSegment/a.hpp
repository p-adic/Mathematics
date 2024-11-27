// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/InitialSegment/a.hpp

#pragma once
// verify:
// CostfreeInitialSegmentDoubleKnapsack�iN,N_1,N_2,N_3,V_min�j
// https://yukicoder.me/submissions/978628�i1817121,12,7,1e9+1,1e18�j

// VALUE�͊֐�value:N_{<N}->N�܂��͂��̗ݐϘa�ɑ�������^�B
// sum_{i=0}^{n} value(i) > unpresentable_max�𖞂����ŏ���n<N�i���݂��Ȃ�����N�j��N_0�ƒu���B

// �v�Z��O(cumulative?log N:N_0)��
// value�̎n�ؕЂ݂̂��I���\�ł���������Ńi�b�v�T�b�N���l�̍ő�l����������n�ؕЂ̏I�[�l�����߂�B
template <typename INT , typename VALUE> int CostfreeInitialSegmentKnapsack( const ll& N , VALUE value , const INT& value_sum_bound , const bool& cumulative = false );

// ���͈͓͂̔��ŗv��
// (1) value�͒P�����傷��B
// (2) unpresentability_max < v <= value_sum_bound_0 + value_sum_bound_1�𖞂���
//     �C�ӂ�v�ɑ΂��Av��value�̕����a�ŕ\����B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// min(value_sum_bound_0,value_sum_bound_1)��V_min�ƒu���A
// value(n) > unpresentable_max�𖞂����ŏ���n<N�i���݂��Ȃ����N�j��N_1�ƒu���A
// sum_{i=0}^{n} value(i) > V_min�𖞂����ŏ���n<N�i���݂��Ȃ����N�j��N_2�ƒu���A
// value(n) > V_min�𖞂����ŏ���n<N�i���݂��Ȃ����N�j��N_3�ƒu���B

// �v�Z��O(log N+(cumulative?0:N_0+N_2)+(N_1<=N_2?0:N_3*V_min))��
// �i�b�v�T�b�N�Q�̉��l��������ꂼ��value_sum_bound_0,value_sum_bound_1�Ƃ��A
// value�̎n�ؕЂ݂̂��I���\�ł���������ŁA�i�b�v�T�b�N�P�̏ꍇ�ɋA��������ۂ�
// ���l�̍ő�l����������n�ؕЂ̏I�[�l�����߂�B
template <typename INT , typename VALUE>
int CostfreeInitialSegmentDoubleKnapsack( const ll& N , VALUE value , const INT& value_sum_bound_0 , const INT& value_sum_bound_1 , const INT& unpresentable_max , const bool& cumulative );
