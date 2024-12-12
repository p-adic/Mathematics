// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/Restfree/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/1031012

// N>0?max(value):0��value_bound�ƒu���B

// ���͈͓͂̔��ŗv��
// (1) N�����̊ei�ɑ΂�value[i]��0�ȏ�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �v�Z��O(N min(value_bound,2^{N/2}))��
// �����Q�O���[�v�ɕ����A�Q�O���[�v�̉��l�̑��a�̍��ł�����dif_opt�ɍł��߂����̂����߂�B
template <typename INT> inline INT CostfreeRestfreeDifferenceKnapsack( const vector<INT>& value , const INT& dif_opt = 0 );
