// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/Recursion/a.hpp

#pragma once

// BEFORE��Arg(&before)(const int&,const int&,const Arg&)�ɑ�������^�B
// AFTERE��void(&after)(const int&,const int&,const Arg&)�ɑ�������^�B

// �v��
// (1) lower_bound��upper_limit�̃T�C�Y��size�ȏ�ł���B
// (2) size�����̔C�ӂ̔񕉐���d�ɑ΂�lower_bound[d]<upper_limit[d]�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ����q�̐[��d�ɂ����郋�[�v�͓Y��i��[lower_bound[d],upper_limit[d])�͈̔͂𓮂��A
// ���̓�����before(d,i,arg)��after(d,i,arg)�����q�̑O��Ŏ��s����悤��size�d��for���[�v��
// ���v�v�Z��O(size N^size)�ōs���B
template <typename INT , typename Arg , typename BEFORE , typename AFTER> Arg ExecuteLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , const int& d , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> Arg ExecuteLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , const int& d , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , const Arg& arg , const BEFORE& before , const AFTER& after );
