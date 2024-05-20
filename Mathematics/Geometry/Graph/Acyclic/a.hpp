// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/a.hpp

#pragma once
#include "../a.hpp"

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times ...)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// G�̃g�|���W�J���\�[�gts:N->T��O(|V_G|+|E_G|)�Ōv�Z����B
template <typename ACYCLIC_GRAPH> vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G );
// {G�̃g�|���W�J���\�[�gts:N->T,G.Enumeration_inv��ts�̍���:N->N�̋t�ʑ�ts_inv,
// ts�ɂ��ԍ��t���Ɋւ��鎟�m�[�h�Ή�}��
// O(|V_G|+|E_G|)�Ōv�Z����B
template <typename ACYCLIC_GRAPH> tuple<vector<inner_t<ACYCLIC_GRAPH>>,vector<int>,vector<vector<int>>> TopologicalSortedGraph( ACYCLIC_GRAPH& G );
