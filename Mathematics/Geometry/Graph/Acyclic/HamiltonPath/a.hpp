// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/HamiltonPath/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times ...)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// G�̊e���_���d���Ȃ��o�R�����ӂȃp�X�i���݂��Ȃ��ꍇ�͋��j��Ԃ��B�iO(V+E)�j
template <typename ACYCLIC_GRAPH> vector<inner_t<ACYCLIC_GRAPH>> HamiltonPath( ACYCLIC_GRAPH& G );
