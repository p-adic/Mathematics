// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/DirectedForest/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times ...)^{< \omega}�����L���X�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// {G�̃g�|���W�J���\�[�gts:N->T,G.Enumeration_inv��ts�̍���:N->N�̋t�ʑ�ts_inv,
// ts�ɂ��ԍ��t���Ɋւ���e�m�[�h�Ή�,ts�ɂ��ԍ��t���Ɋւ���q�m�[�h�Ή�}��
// O(|V_G|+|E_G|)�Ōv�Z����B
template <typename DIRECTED_FOREST> tuple<vector<inner_t<DIRECTED_FOREST>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedForest( DIRECTED_FOREST& G );

