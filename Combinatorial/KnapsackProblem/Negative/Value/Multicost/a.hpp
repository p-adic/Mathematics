// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Multicost/a.hpp

#pragma once
// verify:
// NegativeValueMulticostKnapsack�iN,W,D,L�j
// https://yukicoder.me/submissions/976638�i5e3,5e3,2,1�j


// �ȉ�cost_sum_bound�̃T�C�Y��D�ƒu���AD>=2�Ƃ���B
// max_{d=0}^{D-1} cost_sum_bound[d]��W�ƒu���B
// max_c valid(c).size()��L�ƒu���B
// VALID�͊֐�valid:N^{D-1} -> {(l,r) in N^2|l<=r}^{< omega}�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S���������m�C�h�\���ł���B
// (2) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// (3) N�����̊ei�ɑ΂�cord[i]��0�ȏ�D�����ł���B
// (4) N�����̊ei�ɑ΂�cost[i]��0�ȏ�ł���B
// (5) D�����̊ed�ɑ΂�0 <= cost_sum_bound[d]�ł���B
// (6) (0,r) in valid(0,...,0)�𖞂���r in N�����݂���
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N W
//   + sum_{c in prod_{d=0}^{D-2} [0,cost_sum_bound[d]]}
//     (D + valid(c).size() log (1+cost_sum_bound[D-1])))
// ����O(N W + W^{D-1}(D + L log (1+W)))��
// N�����̊ei�ɑ΂�����i�̃R�X�g��cost[i]*delta_{coord[i]} in N^D�Ƃ�����
// �R�X�g�̑��a(c_0,...,c_{D-1})��prod_d cost_sum_bound[d]�ɓ��肩��
// valid(c_0,...c_{D-2})�̒�߂��ԗ�̘a�W����c_{D-1}���������񉺂ɂ�����
// ���l�̑��a�̍ő�l�����߂�B
template <typename U , typename COMM_MONOID , typename INT1 , typename INT2 , typename VALID> U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT1>& coord , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound , VALID valid );
template <typename INT1 , typename INT2 , typename INT3 , typename VALID> inline INT1 NegativeValueMulticostKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& coord , const vector<INT3>& cost , const vector<INT3>& cost_sum_bound , VALID valid );

