// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/945877�iPotentialisedDijkstra�j
// https://yukicoder.me/submissions/945876�iAbstractPotentalisedDijkstra�j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B
// On�͎ʑ�on:im(edge)->\{0,1\}�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S�����A�[�x���Q�\���ł���B
// (1) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// ���ӂ��܂ޏꍇ/�܂܂Ȃ��ꍇ
// �\�zO(|V_G| |E_G|)/O(|V_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((|V_G|+|E_G|)log |V_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G|^2 + |E_G| log |V_G|)
template <typename T , typename GRAPH , typename GROUP , typename U , typename On>
class AbstractPotentialisedDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  GROUP m_M;
  T m_t_start;
  // �S�Ă̕ӂ����e����ꍇ�Ɏn�_���畉�̃��[�v�ɓ��B�\���ۂ��B
  bool m_valid;
  // �S�Ă̕ӂ����e����ꍇ�̎n�_����̃R�X�g�B
  vector<U> m_potential;
  // �ǂ̕ӂ����e���邩�����߂�֐��I�u�W�F�N�g�B
  On m_on;

public:
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& negative = true );
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& valid , vector<U> potential );

  inline const bool& Valid() const noexcept;
  inline const vector<U>& Potential() const noexcept;
  inline void SetPotential( const bool& valid , vector<U> potential );

  tuple<bool,vector<U>> GetDistance( const bool& many_edges = true );
  template <typename...Args> tuple<bool,vector<U>,vector<list<T>>> GetPath( const Args&... args );

};

template <typename T , typename GRAPH , typename On>
class PotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,AdditiveGroup<>,ll,On>
{

public:
  template <typename...Args> inline PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );
};
