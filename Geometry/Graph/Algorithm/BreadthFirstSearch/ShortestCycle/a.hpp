// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) G�͖����O���t�i���ȃ��[�v�⑽�d�ӂȂ��j�̗L�����ł���B
// (2) not_found��G�̒��_�łȂ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// O(V(V+E))�ōŏ��̕H�𒸓_�̗�Ƃ��ďo�͂���B
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestCycle( GRAPH& G , const inner_t<GRAPH>& not_found );
// ���ȃ��[�v������΂��ꂪ�ŏ��A�Ȃ��đ��d�ӂ�����΂��ꂪ�ŏ��B
