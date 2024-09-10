// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Errand/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../Linear/a.hpp"

// verify:
// https://yukicoder.me/submissions/982995�idirection = 1 , many_edges = false�j

// �T�u�S�[���̌o�R���K�v�ȏꍇ�̍ŒZ�o�H�����������߂ɃO���t�𕡐������O���t�B

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������MemorisationGraph�łȂ��^�B
// SUBGOAL�͎ʑ�subgoal : int \times T -> \{0,1\}�ɑ�������^�B
template <typename T , typename GRAPH>
class ErrandEnumeration
{

private:
  GRAPH* m_p_G;
  
public:
  inline ErrandEnumeration( GRAPH& G );
  inline pair<int,T> operator()( const int& i );

};

template <typename T , typename GRAPH>
class ErrandEnumeration_inv
{

private:
  GRAPH* m_p_G;
  
public:
  inline ErrandEnumeration_inv( GRAPH& G );
  inline int operator()( const pair<int,T>& v );

};

template <typename T , typename U , typename GRAPH , typename SUBGOAL>
class ErrandEdge
{

private:
  GRAPH* m_p_G;
  SUBGOAL m_subgoal;
  U m_one;
  int m_goal_num;

public:
  inline ErrandEdge( GRAPH& G , SUBGOAL subgoal , const U& one , const int& goal_num );
  inline vector<pair<pair<int,T>,U>> operator()( const pair<int,T>& v );

};

template <typename T , typename GRAPH>
class ErrandVertex
{

private:
  GRAPH* m_p_G;
  vector<T> m_vertex;
  
public:
  inline ErrandVertex( GRAPH& G );
  inline const vector<T>& operator()( const int& );

};

template <typename T , typename GRAPH , typename U , typename COMM_MONOID , typename SUBGOAL>
class ErrandDijkstra :
  public DoubleDijkstra<int,LinearGraph,T,U,EnumerationGraph<pair<int,T>,ErrandEnumeration<T,GRAPH>,ErrandEnumeration_inv<T,GRAPH>,ErrandEdge<T,U,GRAPH,SUBGOAL>>,ErrandVertex<T,GRAPH>>
{

private:
  GRAPH m_G;
  COMM_MONOID m_M;
  U m_infty;
  
public:
  // 1:������
  // 2:������
  inline ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const int& goal_num , const U& infty , const int& direction = 1 );

  inline const U& infty() const noexcept;
  
  // ���͈͓͂̔��ŗv��
  // (0) M�͑S���������m�C�h�\���ł���B
  // (1) E_G�̒l�̊e�����̑�2������M.One()�ȏ�ł���B
  // (2) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
  // �����藧�ꍇ�ɂ̂݃T�|�[�g�B
  inline vector<U> GetDistance( const vector<T>& t_starts , const bool& many_edges = true );

};
template <typename GRAPH , typename COMM_MONOID , typename SUBGOAL , typename...Args> ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const Args&... ) -> ErrandDijkstra<inner_t<GRAPH>,GRAPH,inner_t<COMM_MONOID>,COMM_MONOID,SUBGOAL>;

