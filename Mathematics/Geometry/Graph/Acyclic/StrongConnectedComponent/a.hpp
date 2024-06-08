// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/987407

// GRAPH�͕�Edge:T->(T \times ...)^{< \omega}�����O���t�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) G�͗L���O���t�ł���B
// (2) not_found��G�̒��_�łȂ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// G�̋��A���������Ȃ���֏�L���O���t���g�|���W�J���\�[�g����B�iO(V+E)�j
template <typename T , typename GRAPH> vector<vector<T>> StrongConnectedComponent( GRAPH& G , const T& not_found );
// �X�ɃO���t���\�z�������ꍇ�͊et���Ƃɋ��A�������ԍ����i�[����i�A�z�j�z������A
// G�̕ӂ𑖂点�ĕӂ�set��unordered_set��i���d�ӂ������Ȃ�jvector�ōč\�z����Ƃ悢�B
