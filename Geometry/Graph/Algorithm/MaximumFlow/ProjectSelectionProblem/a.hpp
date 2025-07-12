// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/ProjectSelectionProblem/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1104412 (dependency_penalty={},set_reject_score={})
// https://yukicoder.me/submissions/1104408�iset_reject_score={}�j

// V0��U�ɕϊ��ł���^��vector�^�Ƃ��A
// V1��U�ɕϊ��ł���^T��p����Tuple<int,int,T>�̌`���̌^��vector�^�Ƃ���B
// V2,V3��U�ɕϊ��ł���^T��p����pair<vector<int>,T>�̌`���̌^��vector�^�Ƃ���B

// �ȉ�score.size()��N�ƒu���A
// dependency_penalty.size()��M�ƒu���A
// set_accept_score.size()+set_reject_score.size()��L�ƒu���A
// U�𐮐��^�Ƃ������̓����̏����F�ƒu���B

// ���͈͓͂̔��ŗv��
// (0) R�͑S�����A�[�x���Q�\���ł���B
// (1) dependency_penalty��set_accept/reject_score�̒l�̊e�����̑�2������R.Zero()�ȏ�ł���B
// (2) infty���u���͂̊e�����̐�Βl��N�̘a�v��N�ȉ��̘a�����傫���B
// (3) dependency_penalty��{i,i,u}�̌`�̐����͑��݂��Ȃ��B
// (4) set_accept/reject_score�̊e�����̑�1�����͒��������P�˂ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// {0,1,...,N-1}�̕����W��S�ɑ΂���
// sum_{i in S} score[i]
// - sum_{(i,j,u) in dependency_penalty and i in S and j notin S} u
// + sum_{(v,u) in set_accept_score and forall i in v[i in S]} u
// + sum_{(v,u) in set_accept_score and forall i in v[i notin S]} u
// �̍ő�l��O(min((N+L)^2,F)(M+L))�ŋ��߂�B
template <typename U , typename ABEL_GROUP , typename V0 , typename V1 , typename V2 , typename V3> U AbstractProjectSelectionProblem( ABEL_GROUP R , const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score );
template <typename U , typename V0 , typename V1 , typename V2 , typename V3> inline U ProjectSelectionProblem( const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score );
