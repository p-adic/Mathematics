// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/ShortestCycle/Odd/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1124648

// ���͈͓͂̔��ŗv��
// (1) G�͖����O���t�i���ȃ��[�v�⑽�d�ӂȂ��j�̗L�����ł���B
// (2) not_found��G�̒��_�łȂ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// O(V+E)��t_start��ʂ�ŏ��̊�H�𒸓_�̗�Ƃ��ďo�͂���B
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found , const inner_t<GRAPH>& t_start );

// O(V(V+E))�ōŏ��̊�H�𒸓_�̗�Ƃ��ďo�͂���B
template <typename GRAPH> vector<inner_t<GRAPH>> ShortestOddCycle( GRAPH& G , const inner_t<GRAPH>& not_found );
// ���ȃ��[�v������΂��ꂪ�ŏ��A�Ȃ��đ��d�ӂ������Ă���H�ɉe�����Ȃ��̂ō폜���Ă悢�B

