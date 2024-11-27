// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../../Algebra/Monoid/Group/a.hpp"

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B
// On�͎ʑ�on:im(edge)->\{0,1\}�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S�����A�[�x���Q�\���ł���B
// (1) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// (2) ���e����ӂ̓|�e���V�����ɑ΂��O�p�s�����𖞂����B�i�]���ĕ��̕H�����݂��Ȃ��j
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// ���ӂ����e����ꍇ�̓|�e���V�����������œn���K�v����B
// BellmanFord�@�Ŏ����Ōv�Z����ꍇ��AbstractBellmanFordPotentialisedDijkstra��p����B

// �\�zO(|V_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((min(|V_G|^2+|E_G|,|V_G|+|E_G|)log |V_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename U , typename GROUP , typename On>
class AbstractPotentialisedDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  GROUP m_M;
  T m_t_start;
  // �ǂ̕ӂ����e���邩�����߂�֐��I�u�W�F�N�g�B
  On m_on;
  // �i����SetPotential������܂ł̊ԂɁj���e������ӂ�S�ċ��e����ꍇ�̎n�_����̃R�X�g�B
  vector<U> m_potential;

public:
  // potential�̃f�t�H���g�����g�p�́i����SetPotential������܂ł̊ԂɁj���ӂ����e���Ȃ�
  // �ꍇ�̂݃T�|�[�g�B
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential = {} );

  inline const vector<U>& Potential() const noexcept;
  inline void SetPotential( vector<U> potential );

  // �u���B�\?�ŒZ�o�H��:infty�v���i�[�����z���Ԃ��B
  template <typename...Args> vector<U> GetDistance( Args&&... args );
  // �u���B�\?�ŒZ�o�H��:infty�v���i�[�����z����1�����ɁA
  // �u���B�\?�ŒZ�o�H:���v���i�[�����z����2�����ɕԂ��B
  template <typename...Args> pair<vector<U>,vector<list<T>>> GetPath( Args&&... args );
  // �Ԃ�l�̓s���At_final���P�ł�����ꉻ�͑��݂����A�z�񉻂���t_finals��n���B

};

template <typename T , typename GRAPH , typename On>
class PotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>
{

public:
  template <typename...Args> inline PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );
  
};
