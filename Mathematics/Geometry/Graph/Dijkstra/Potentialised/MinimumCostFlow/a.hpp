// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/a.hpp

#pragma once
#include "../../../../../Algebra/Monoid/Semirng/Ring/a.hpp"

// verify:
// https://yukicoder.me/submissions/969256�imany_edges=false�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U(�R�X�g) \times U(�e��))^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) R�͑S�����\���ł���B
// (1) E_G�̒l�̊e�����̑�2������M.Zero()�ȏ�ł���B
// (2) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a��f�{�ŕ\���邢���Ȃ鐔�����傫���B
// (3) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂��Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŏ���p���H�T��O(F min(|V_G|^2+|E_G|,(|V_G|+|E_G|)log |V_G|))
template <typename T , typename GRAPH , typename U , typename RING>
class AbstractMinimumCostFlow :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  RING m_R;

public:
  inline AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty );

  // ���͈͓͂̔��ŗv��
  // (1) many_edges=true����path_length!=-1�Ȃ�΁A�n�_����̃p�X�̕ӂ̖{����path_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Apath_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  pair<U,vector<vector<tuple<T,U>>>> GetFlow( const T& t_start , const T& t_final , U f , const bool& many_edges = true , int path_length = -1 );

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
