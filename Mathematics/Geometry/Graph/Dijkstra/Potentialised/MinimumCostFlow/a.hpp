// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/a.hpp"

// verify:
// https://yukicoder.me/submissions/949995�iMinimumCostFlow�Amany_edges=false�j
// https://yukicoder.me/submissions/949996�iAbstractMinimumCostFlow�Amany_edges=false�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U(�R�X�g) \times U(�e��))^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) R�͑S�����\���ł���B
// (1) E_G�̒l�̊e�����̑�2������M.Zero()�ȏ�ł���B
// (2) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a��f�{�ŕ\���邢���Ȃ鐔�����傫���B
// (3) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂��Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŏ���p���H�T��O(F min(|V_G|^2+|E_G|,(|V_G|+|E_G|)log |V_G|))
template <typename GRAPH , typename RING , typename U>
class AbstractMinimumCostFlow :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  RING m_R;

public:
  inline AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty );
  pair<U,vector<vector<tuple<inner_t<GRAPH>,U>>>> GetFlow( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , U f , const bool& many_edges = true );

};

template <typename GRAPH , typename U>
class MinimumCostFlow :
  public AbstractMinimumCostFlow<GRAPH,Ring<U>,U>
{

public:
  inline MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty );

};
