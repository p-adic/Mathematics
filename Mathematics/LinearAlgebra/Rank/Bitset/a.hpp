// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961465�iReducedRowEchelonForm�j

// ��^�e���v���[�g������int��uint�ɂ��Ă��܂��Ǝ���������e���v���[�g�����������_�ł��Ȃ����Ƃɒ��ӁB
// �i�茳�̊��Ȃ�uint�ł��ʂ邪�I�����C�����s���ł͒ʂ�Ȃ��j
// �ȉ�M <= bound_M����M + N <= bound_M_N�̏ꍇ�̂݃T�|�[�g�B


// �K�i��

// A.size()��L�ƒu���B
// A��F_2�W��L�~M�s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɑ΂����[��됬����1�ł���K�i�����{��rank��Ԃ��B�iO(bound_M L min{L,M})�j
template <size_t bound_M> size_t RowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M );


// �g��W���s��̊Ȗ�K�i��

// A.size()��L�ƒu���B
// A��F_2�W��L�~M�s��i�W���s��j��F_2�W��L���c�x�N�g��N�i��Ď����s��j����������
// �g��W���s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɑ΂��W���s�񕔕��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i�����{��
// { �W���s��̊K�� , �u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U } ��Ԃ��B
// �iO(bound_M_N L min{L,M+N})�j
template <size_t bound_M_N> pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N );
// A�ɑ΂��W���s�񕔕��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i�����{��
// solution�ɘA���ꎟ�������̉����i�[��
// { �W���s��̊K�� , �u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U } ��Ԃ��B
// �iO(bound_M_N L min{L,M+N})�j
template <size_t bound_N , size_t bound_M_N> pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , vector<bitset<bound_N>>& solution , const size_t& M , const size_t& N );


// �Ȗ�

// A��F_2�W��L�~M�s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɊȖ񉻂��{��rank��Ԃ��B�iO(bound_M L min{L,M})�j
template <size_t bound_M> inline size_t ReducedRowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M );


// ���`�Ɨ�������

// A��F_2�W��L�~M�s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// �uA�̊e�s�����`�Ɨ��v�̐^�U��Ԃ��B�iO(bound_M min{L,M}^2)�j
template <size_t bound_L , size_t bound_M> inline bool LinearlyIndependent( const vector<bitset<bound_M>>& A , const size_t& M );


// ����������

// A��F_2�W��L�������s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A_inv��A�̋t�s����i�[���uL>0����A�������v�̐^�U��Ԃ��B�iO(bound_L L^2)�j
template <size_t bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const size_t& L );

