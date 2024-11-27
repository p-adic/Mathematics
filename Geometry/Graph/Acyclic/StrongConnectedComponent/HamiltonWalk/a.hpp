// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/HamiltonWalk/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/987414

// GRAPH�͕�Edge:T->(T \times ...)^{< \omega}�����O���t�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) G�͗L���O���t�ł���B
// (2) not_found��G�̒��_�łȂ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// G�̊e���_����x�ȏ�ʂ�����̎n�_�ƂȂ肦�钸�_�S�̂̂Ȃ��z���Ԃ��B�iO(V+E)�j
template <typename T , typename GRAPH> vector<T> StartPointsOfHamiltonWalk( GRAPH& G , const T& not_found );

