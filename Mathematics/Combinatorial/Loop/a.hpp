// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a.hpp

#pragma once

// �v��
// (1) lower_bound��upper_limit�̃T�C�Y��size�ȏ�ł���B
// (2) size�����̔C�ӂ̔񕉐���d�ɑ΂�lower_bound[d]<upper_limit[d]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ����q�̐[��d�ɂ����郋�[�v�͓Y����[lower_bound[d],upper_limit[d])�͈̔͂𓮂��悤��
// size�d��for���[�v���s���悤�ɓY���x�N�g��index�����v�v�Z��O(D N^D)�ōX�V����B
bool NextLoop( const int& size , const vector<int>& lower_bound , const vector<int>& upper_limit , vector<int>& index );
