// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/949989�iDijstra�AGetDistance�Amany_edges=true�j
// https://yukicoder.me/submissions/949990�iDijstra�AGetDistance�Amany_edges=false�j
// https://yukicoder.me/submissions/949988�iAbstractDijkstraa�AGetDistance�Amany_edges=true�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S���������m�C�h�\���ł���B
// (1) E_G�̒l�̊e�����̑�2������M.Zero()�ȏ�ł���B
// (2) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G|^2+|E_G|)
template <typename GRAPH , typename MONOID , typename U>
class AbstractDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // �R���X�g���N�^�Ɉ������K�v��MultiplicativeMonoid�Ȃǂ�static�����o�֐��ɂ��
  // �Q�ƕԂ������ɂ����A�R���X�g���N�^�̕Ԃ�l�ł���E�Ӓl���󂯎�邱�Ƃ����e�������̂�
  // ���Ӓl�Q�Ƃɂ͂��Ȃ��B
  MONOID m_M;

public:
  inline AbstractDijkstra( GRAPH& G , MONOID M , const U& infty );

  // �o�H�����݂��Ȃ��ꍇ�̕Ԃ�l��infty
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = true );
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true );
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = true );
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start );
  
};

template <typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline Dijkstra( GRAPH& G );

};
