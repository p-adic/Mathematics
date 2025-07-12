// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MinimumCostFlow/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/Semirng/Ring/a.hpp"

// verify:
// https://yukicoder.me/submissions/973370�imany_edges=false�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U(�R�X�g) \times U(�e��))^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) R�͑S�����\���ł���B
// (1) E_G�̒l�̊e�����̑�2������R.Zero()�ȏ�ł���B
// (2) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a��f�{�ŕ\����
//     �����Ȃ鐔�����傫���B
// (3) V�̊e�v�fu�ɑ΂��A��u->u�͑��݂��Ȃ��B
// (4) V�̊e�v�fu,v�ɑ΂��A��u->v�ƕ�v->u�͍��v���X�P�{�������݂��Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_G|^2)
// �P��n�_�P��I�_�ŏ���p���H�T��O(|V_G|^2 + F min(|V_G|^2+|E_G|,(|V_G|+|E_G|)log |V_G|))
template <typename T , typename GRAPH , typename U , typename RING>
class AbstractMinimumCostFlow
{

private:
  GRAPH& m_G;
  RING m_R;

  U m_infty;
  // m_full[i]�ɁAm_G.Enumeration(i)���n�_�Ƃ����m_G.Enumeration(i)->m_G.Enumeration(j)
  // �܂��͕�m_G.Enumeration(j)->m_G.Enumeration(i)�̔��]���Ƃ�
  // {j,�d��,�܂��������,m_flow[���]?j:i]�ɂ�����ʒu}�̃f�[�^���i�[����B
  vector<vector<tuple<int,U,U,int>>> m_full;
  // m_flow[i]�ɁAm_G.Enumeration(i)���n�_�Ƃ����m_G.Enumeration(i)->m_G.Enumeration(j)
  // ���Ƃ�{m_G.Enumeration(j),���ɗ�������}�̃f�[�^���i�[����B
  vector<vector<tuple<T,U>>> m_flow;
  vector<vector<int>> m_edge_num;
  vector<vector<int>> m_edge_rev_num;

public:
  inline AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty );

  // ���͈͓͂̔��ŗv��
  // (1) many_edges=true����path_length!=-1�Ȃ�΁A�n�_����̃p�X�̕ӂ̖{����path_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Apath_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  // ��1�����ɃR�X�g���a�̍ŏ��l�A��2������
  // ��i�����Ɂuvi���n�_�Ƃ����vi->vj���Ƃ�{vj,���ɗ�������}�̃f�[�^���i�[�����z��v���i�[�����z��
  // ��Ԃ��B
  pair<U,vector<vector<tuple<T,U>>>> GetFlow( const T& t_start , const T& t_final , U f , const bool& many_edges = false , int path_length = -1 );

};
template <typename GRAPH , typename U , typename RING>  AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty ) -> AbstractMinimumCostFlow<inner_t<GRAPH>,GRAPH,U,RING>;

template <typename T , typename GRAPH , typename U>
class MinimumCostFlow :
  public AbstractMinimumCostFlow<T,GRAPH,U,Ring<U>>
{

public:
  inline MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty );

};
template <typename GRAPH , typename U> MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty ) -> MinimumCostFlow<inner_t<GRAPH>,GRAPH,U>;
