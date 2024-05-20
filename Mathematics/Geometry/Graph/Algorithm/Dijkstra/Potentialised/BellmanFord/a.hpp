// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/BellmanFord/a.hpp

#pragma once
#include "../a.hpp"

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B
// On�͎ʑ�on:im(edge)->\{0,1\}�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S�����A�[�x���Q�\���ł���B
// (1) infty���uE_G�̒l�̊e�����̑�2������2�_�ԃ|�e���V�������̘a�v��|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// (2) ���e����ӂ̓|�e���V�����ɑ΂��O�p�s�����𖞂����B�i�]���ĕ��̕H�����݂��Ȃ��j
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// ���ӂ��܂ޏꍇ/�܂܂Ȃ��ꍇ
// �\�zO(|V_G| |E_G|)/O(|V_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((min(|V_G|^2+|E_G|,|V_G|+|E_G|)log |V_G|))
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename U , typename GROUP , typename On>
class AbstractBellmanFordPotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>
{

public:
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on );
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential );

private:
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP& M , const T& t_start , const U& infty , On& on , tuple<vector<bool>,vector<U>> potential );

};

template <typename T , typename GRAPH , typename On>
class BellmanFordPotentialisedDijkstra :
  public AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>
{

public:
  template <typename...Args> inline BellmanFordPotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );

};
