// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"
#include "../../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/969250�iGetDistance�Amany_edges=false�j
// https://yukicoder.me/submissions/961784�iGetDistance�Amany_edges=true�j
// https://yukicoder.me/submissions/961385�iSetDistance�Amany_edges=true�j
// https://yukicoder.me/submissions/961826�iGetPath�Amany_edged=false�j


// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S���������m�C�h�\���ł���B
// (1) E_G�̒l�̊e�����̑�2������M.One()�ȏ�ł���B
// (2) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
class AbstractDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // �R���X�g���N�^�Ɉ������K�v��MultiplicativeMonoid�Ȃǂ�static�����o�֐��ɂ��
  // �Q�ƕԂ������ɂ����A�R���X�g���N�^�̕Ԃ�l�ł���E�Ӓl���󂯎�邱�Ƃ����e�������̂�
  // ���Ӓl�Q�Ƃɂ͂��Ȃ��B
  COMM_MONOID m_M;

public:
  inline AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty );

  // ���͈͓͂̔��ŗv��
  // (1) many_edges=true����path_length!=-1�Ȃ�΁A�n�_����̃p�X�̕ӂ̖{����path_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Apath_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  // �o�H�����݂���ꍇ�͍ŒZ�a�H�����A���݂��Ȃ��ꍇ��infty��Ԃ��B
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = false , int path_length = -1 );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );
  // �ŒZ�o�H���̊m�肵�Ă���_�W����fixed�Ŏw�肵�Aweight�Ɋ��Ɋi�[����Ă���l���d�݂Ƃ���
  // t_start����̗L���ӂ�ǉ��������̍ŒZ�o�H�����i�[�������B
  void SetDistance( vector<U>& weight , vector<bool>& fixed , const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );

  // �o�H�����݂���ꍇ�͍ŒZ�a�H�����A���݂��Ȃ��ꍇ��infty���1�����ɁA
  // �o�H�����݂���ꍇ�͍ŒZ�a�H���A���݂��Ȃ��ꍇ�͋����2�����ɕԂ��B
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = false , int path_length = -1 );
  // t_finals�ɑ����Ƃ͌���Ȃ��i���ӁI�j�e�_�ɑ΂�
  //   �u�o�H�����݂���?�ŒZ�a�H��:infty�v���i�[�����z����1�����ɁA
  // t_finals�ɑ����e�_�ɑ΂�
  //   �u�o�H�����݂���?�ŒZ�a�H:���v���i�[�����z����2�����ɕԂ��B
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = false , int path_length = -1 );
  // �e�_�ɑ΂��u�o�H�����݂���?�ŒZ�a�H��:infty�v���i�[�����z����1�����ɁA
  // �e�_�ɑ΂��u�o�H�����݂���?�ŒZ�a�H:���v���i�[�����z����2�����ɕԂ��B
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );
  
};
template <typename GRAPH , typename U , typename COMM_MONOID> AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) -> AbstractDijkstra<inner_t<GRAPH>,GRAPH,U,COMM_MONOID>;

template <typename T , typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<T,GRAPH,ll,AdditiveMonoid<>>
{

public:
  inline Dijkstra( GRAPH& G );

};
template <typename GRAPH> Dijkstra( GRAPH& G ) -> Dijkstra<inner_t<GRAPH>,GRAPH>;
