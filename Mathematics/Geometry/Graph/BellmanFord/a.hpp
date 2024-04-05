// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/GRL_1_B/judge/9062333/C++17�iGetDistance�j
// https://yukicoder.me/submissions/969226�iGetDistance�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M��U�̑S���������m�C�h�\���ł���B
// (1) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(|V_G| |E_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G| |E_G|)
template <typename T , typename GRAPH , typename U , typename MONOID>
class AbstractBellmanFord :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // �R���X�g���N�^�Ɉ������K�v��MultiplicativeMonoid�Ȃǂ�static�����o�֐��ɂ��
  // �Q�ƕԂ������ɂ����A�R���X�g���N�^�̕Ԃ�l�ł���E�Ӓl���󂯎�邱�Ƃ����e�������̂�
  // ���Ӓl�Q�Ƃɂ͂��Ȃ��B
  MONOID m_M;
  // AbstractDijkstra�ƈ����|E_G|���������ꍇ�ɂ����K�p���Ȃ��̂�
  // E_G�̑O�v�Z�����e����B
  vector<tuple<int,int,U>> m_edge;

public:
  AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty );

  // ���͈͓͂̔��ŗv��
  // (1) many_edges=true����path_length!=-1�Ȃ�΁A�n�_����̃p�X�̕ӂ̖{����path_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Apath_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  // �u���B�\�Ȃ�Ε��̕H���o�R�ł��Ȃ��v�̐^�U���i�[�����z����1�����ɁA
  // �u���B�\?���̕H�����݂���?�ӂ̖{��path_length�ȉ��ł̍ŒZ�o�H��:�ŒZ�o�H��:infty�v��
  //  �i�[�����z����2�����ɕԂ��B
  tuple<vector<bool>,vector<U>> GetDistance( const T& t_start , const bool& many_edges = true , int path_length = -1 );
  
  // t_finals�ɑ����Ƃ͌���Ȃ��i���ӁI�j�e�_�ɑ΂�
  //   �u���B�\�Ȃ�Ε��̕H���o�R�ł��Ȃ��v�̐^�U���i�[�����z����1�����ɁA
  // t_finals�ɑ����Ƃ͌���Ȃ��i���ӁI�j�e�_�ɑ΂�
  //   �u���B�\?���̕H���o�R����?�ӂ̖{��path_length�ȉ��ł̍ŒZ�o�H��:�ŒZ�o�H��:infty�v��
  //    �i�[�����z����2�����ɁA
  // t_finals�ɑ����e�_�ɑ΂�
  //   �u���B�\�����̕H���o�R�ł��Ȃ�?�ŒZ�o�H:���v���i�[�����z����3�����ɕԂ��B
  template <template <typename...> typename V> tuple<vector<bool>,vector<U>,vector<list<T>>> GetPath( const T& t_start , const V<T>& t_finals , const bool& many_edges = true , int path_length = -1 );
  // �e�_�ɑ΂�
  //   �u���B�\�Ȃ�Ε��̕H���o�R�ł��Ȃ��v�̐^�U���i�[�����z����1�����ɁA
  // �e�_�ɑ΂�
  //   �u���B�\?���̕H���o�R����?�ӂ̖{��path_length�ȉ��ł̍ŒZ�o�H��:�ŒZ�o�H��:infty�v��
  //    �i�[�����z����2�����ɁA
  // �e�_�ɑ΂�
  //   �u���B�\�����̕H���o�R�ł��Ȃ�?�ŒZ�o�H:���v���i�[�����z����3�����ɕԂ��B
  tuple<vector<bool>,vector<U>,vector<list<T>>> GetPath( const T& t_start , const bool& many_edges = true , int path_length = -1 );
  // AbstractDijkstra�ɍ��킹��t_final���P�̓��ꉻ��p�ӂ��Ă�
  // AbstractPotentialisedDijkstra�œ��ꉻ�ł��Ȃ��̂ŗp�ӂ��Ȃ��B
  
};
template <typename GRAPH , typename U , typename MONOID> AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty ) -> AbstractBellmanFord<inner_t<GRAPH>,GRAPH,U,MONOID>;

template <typename T , typename GRAPH>
class BellmanFord :
  public AbstractBellmanFord<T,GRAPH,ll,AdditiveMonoid<>>
{

public:
  inline BellmanFord( GRAPH& G );
  
};
template <typename GRAPH> BellmanFord( GRAPH& G ) -> BellmanFord<inner_t<GRAPH>,GRAPH>;
