// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961450�iReducedRowEchelonForm�j

// ��^�e���v���[�g������int�ɂ��Ă��܂��Ǝ���������e���v���[�g�����������_�ł��Ȃ����Ƃɒ��ӁB
// �ȉ�L <= bound_L����M <= bound_M����N <= bound_N�̏ꍇ�̂݃T�|�[�g�B

// A��F_2�W��L�~M�s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɑ΂����[��됬����1�ł���K�i�����{��rank��Ԃ��B
template <uint bound_L , uint bound_M>
uint RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M );

// A��F_2�W��L�~M�s���F_2�W��L���c�x�N�g��N�����������g��W���s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɑ΂��W���s�񕔕��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i�����{��
// { �W���s��̊K�� , �u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U } ��Ԃ��B
template <uint bound_L , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const uint& L , const uint& M , const uint& N );
template <uint bound_L , uint bound_M , uint bound_N , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const uint& L , const uint& M , const uint& N );

// A��F_2�W��L�~M�s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A�ɊȖ񉻂��{��rank��Ԃ��B
template <uint bound_L , uint bound_M> inline uint ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M );

// A��F_2�W��L�������s��ł���ꍇ�ɂ̂݃T�|�[�g�B
// A_inv��A�̋t�s����i�[���uL>0����A�������v�̐^�U��Ԃ��B
template <uint bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const uint& L );
