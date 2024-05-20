// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Tree/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times ...)^{< \omega}���������؂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// root���n�_�Ƃ���G�̗L���O���t�\����G_dir�Ƃ���
// TopologicalSortedForest( G_dir )��O(|V_G|+|E_G|)�Ōv�Z����B
template <typename UNDIRECTED_TREE> tuple<vector<inner_t<UNDIRECTED_TREE>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedTree( UNDIRECTED_TREE& G , const inner_t<UNDIRECTED_TREE>& root );

