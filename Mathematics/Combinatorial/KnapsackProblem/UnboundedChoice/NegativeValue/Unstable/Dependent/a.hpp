// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/Unstable/Dependent/a.hpp

#pragma once

#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// NegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack�iCS,cost_sum_bound�j
// https://yukicoder.me/submissions/969032�i5e3,5e3�j

template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename INT2 , typename INT3>
class DependentItemData
{

private:
  N_MODULE m_M;
  int m_N1;
  VALUE1 m_value1;
  VALUE2 m_value2;
  const vector<INT1>* m_p_choice_stability_num1;
  const vector<INT2>* m_p_dependence;
  const vector<INT3>* m_p_init;
  const vector<INT3>* m_p_diff;

public:
  inline DependentItemData( N_MODULE M , int N1 , VALUE1 value1 , VALUE2 value2 , const vector<INT1>& choice_stability_num1 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff );
  U operator()( const int& i , const ll& m );

};

// VALUE1,2�͎ʑ�value1,2:N^2->U�ɑ�������^�B
// COST1,2�͎ʑ�cost1,2:N^2->N�ɑ�������^�B
// choice_stability_num1�̃T�C�Y��N1�Achoice_stability_num2�̃T�C�Y��N2�ƒu���A
// init��diff��dependence�̃T�C�Y��N2�Ɠ������Ƃ���B

// �ȉ�sum_i choice_stability_num1(i) + sum_i choice_stability_num2(i)��CS�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S����N���Q�\���ł���B
// (2) N2�����̊ei�ɑ΂�0 <= init[i]����1 <= diff[i]�ł���B
// (3) N2�����̊ei�ɑ΂�0 <= dependence[i] < N1�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(N2)��
// ��0�`N1-1���^�����Ă��āA��dependence[j]<N1��init[j]+m*diff[j]��I������Ă��Ȃ���
// 1+m��I���ł��Ȃ���N+j��j=0�`N2-1�ɑ΂��ǉ�����B
template <typename N_MODULE , typename VALUE1 , typename VALUE2 , typename COST1 , typename COST2 , typename INT1 , typename INT2 , typename INT3>
pair<DependentItemData<ret_t<VALUE1,int,ll>,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3>,DependentItemData<ret_t<COST1,int,ll>,Module<ll,ret_t<COST1,int,ll>>,COST1,COST2,INT1,INT2,INT3>> GetDependentItemData( N_MODULE M , VALUE1 value1 , VALUE2 value2 , COST1 cost1 , COST2 cost2 , vector<INT1>& choice_stability_num1 , const vector<INT1>& choice_stability_num2 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff );

// ���͈͓͂̔��ŗv��
// (1) M��operator<(const U&,const U&)�Ɋւ���U�̑S����N���Q�\���ł���B
// (2) N1�����̊ei��choice_stable_num1[i]�ȉ��̊em�ɑ΂�0 <= cost1(i,m)�ł���B
// (3) N2�����̊ei��choice_stable_num2[i]�ȉ��̊em�ɑ΂�0 <= cost2(i,m)�ł���B
// (4) N1�����̊ei�ɑ΂��AM.One() < value1(i,choice_stable_num1[i])�Ȃ��
//     0 < cost1(i,choice_stable_num2[i])�ł���B
// (5) N2�����̊ei�ɑ΂��A
//     diff[i]*value1(dependence[i],choice_stable_num1[i])��
//     value2(i,choice_stable_num2[i])�̘a��M.One()���傫���Ȃ�΁A
//     diff[i]*cost1(dependence[i],choice_stable_num1[i])��
//     cost2(i,choice_stable_num2[i])�̘a�����ł���B
// (6) 0 <= cost_sum_bound�ł���B
// (7) exceptional�͉��l�̑��a�ŕ\���Ȃ��B
// (8) N2�����̊ei�ɑ΂�0 <= init[i]����1 <= diff[i]�ł���B
// (9) N2�����̊ei�ɑ΂�0 <= dependence[i] < N1�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(CS * cost_sum_bound)��
// �ei<N1�ɑ΂���1�퍀��i�𖳐����ɏd���I���ł�1+m��ڂ̏d���I���ɂ����鍀��i��
// ���l��value1(i,min(m,choice_stable_num1[i]))�ł���
// �R�X�g��cost1(i,min(m,choice_stable_num1[i]))�ł���A
// �ei<N2�ɑ΂���2�퍀��i���d���I���ł�1+m��ڂ̏d���I���͑�1�퍀��dependence[i]��
// init[i]+m*diff[i]��I�����Ă���ꍇ�ɉ\�ł��肻�̍ۂ̑�2�퍀��i��
// ���l��value2(i,min(m,choice_stable_num2[i]))�ł���
// �R�X�g��cost2(i,min(m,choice_stable_num2[i]))�ł���Ƃ��āA
// �R�X�g�̑��a0 <= c <= cost_sum_bound���Ƃɉ��l�̑��a�̍ő�l�����߂�B
template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline vector<U> AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff );
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline vector<INT1> NegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff );
// �v�Z��O(CS * cost_sum_bound)��
// �R�X�g�̑��acost_sum_bound�ȉ��ɂ����鉿�l�̑��a�̍ő�l�Ƃ������������R�X�g�̍ŏ��l�����߂�B
template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnstableDependentKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff );
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnstableDependentKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff );


