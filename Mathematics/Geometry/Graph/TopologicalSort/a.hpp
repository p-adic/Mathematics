// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/TopologicalSort/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/953259�iGetLongestWalk�j

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times U)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// (2) M��operator<(const U&,const U&)�Ɋւ���U�̏������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
template <typename GRAPH> list<inner_t<GRAPH>> TopologicalSort( GRAPH& G );

// ���͈͓͂̔��ŗv��
// (1) G����Edge:T->(T \times U)^{< \omega}�������H�������Ȃ��L���O���t�ł���B
// (2) M��operator<(const U&,const U&)�Ɋւ���U�̏������m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
template <typename GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<GRAPH>>> GetLongestWalk( GRAPH& G , MONOID M );
