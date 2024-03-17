// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/961434�iGetDistance�Amany_edges=true�j
// https://yukicoder.me/submissions/961385�iSetDistance�Amany_edges=true�j
// https://yukicoder.me/submissions/949990�iGetDistance�Amany_edges=false�j
// https://yukicoder.me/submissions/949988�i������Abstract�AGetDistance�Amany_edges=true�j

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
template <typename GRAPH , typename COMM_MONOID , typename U>
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
  // (1) many_edges=true����edged_length=-1�Ȃ�΁A�n�_����̕����̕ӂ̖{����walk_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Aedged_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  // �o�H�����݂��Ȃ��ꍇ��infty��Ԃ��B
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true , int walk_length = -1 );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  // �ŒZ�o�H���̊m�肵�Ă���_�W����found�Ŏw�肵�Aweight�Ɋ��Ɋi�[����Ă���l���d�݂Ƃ���
  // t_start����̗L���ӂ�ǉ��������̍ŒZ�o�H�����i�[�������B
  void SetDistance( vector<U>& weight , vector<bool>& found , const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true , int walk_length = -1 );
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = true , int walk_length = -1 );
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  
};

template <typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline Dijkstra( GRAPH& G );

};
