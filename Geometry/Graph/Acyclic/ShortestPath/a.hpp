// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/ShortestPath/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G�̓g�|���W�J���\�[�g���ꂽ�L���O���t({0,...,V-1},{0,...,V-1}->({0,...,V-1}�~...)^{<��})
// (2) M�͑S�������m�C�h
// (3) weight�͒��_�΂̏d�݂�Ԃ��ʑ�{0,...,V-1}^2->M
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�BO(V+E)��start����̍ŒZ�o�H���ƍŒZ�o�H�ɂ�����prev��Ԃ��B
template <typename TOPOLOGICAL_SORTED_ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename U = inner_t<MONOID>> vector<pair<U,int>> TopologicalSortedShortestPath( TOPOLOGICAL_SORTED_ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const int& start );

// ���͈͓͂̔��ŗv��
// (1) G�͔�֏�L���O���t
// (2) M�͑S�������m�C�h
// (3) weight�͒��_�΂̏d�݂�Ԃ��ʑ�
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�BO(V+E)��start����̍ŒZ�o�H���ƍŒZ�o�H�ɂ�����prev��Ԃ��B
template <typename ACYCLIC_GRAPH , typename MONOID , typename WEIGHT , typename T = inner_t<ACYCLIC_GRAPH>, typename U = inner_t<MONOID>> vector<pair<U,T>> AcyclicGraphShortestPath( ACYCLIC_GRAPH& G , MONOID M , WEIGHT weight , const T& start , const T& external_point );
