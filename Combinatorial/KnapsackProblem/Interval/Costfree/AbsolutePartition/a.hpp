// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/AbsolutePartition/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100699

// ���͈͓͂̔��ŗv��
// (1) INT�͕��������̌^�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �v�Z��O(partition_size*N)��answer[i]��value�̒���i�̎n�ؕЂ����Xpartition_size��
// ��Ԃɕ����������̋�Ԙa�̐�Θa�̍ő�l���i�[����B
template <typename INT> vector<INT> MaximisationIntervalSumAbsoluteSum( const vector<INT>& value , const int& partition_size );
// �O�p�s�������Ai>=partition_size�Ȃ�΍��Xpartition_size�Ƃ��傤��partition_size��
// �ő�l�͓����B
