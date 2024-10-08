// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a.hpp

#pragma once

// �v��
// (1) lower_bound��upper_limit��index�̃T�C�Y��size�ȏ�ł���B
// (2) size�����̔C�ӂ̔񕉐���d�ɑ΂�lower_bound[d]<upper_limit[d]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ����q�̐[��d�ɂ����郋�[�v�͓Y����[lower_bound[d],upper_limit[d])�͈̔͂𓮂��悤��
// size�d��for���[�v���s���悤�ɓY���x�N�g��index�����v�v�Z��O(size N^size)�ōX�V����B
template <typename INT> bool NextLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index );
template <typename INT> bool NextLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index );
template <typename INT> bool NextLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index );
template <typename INT> bool NextLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index );
