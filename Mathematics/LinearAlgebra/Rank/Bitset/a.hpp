// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once


// �ȉ�L <= bound_L����M <= bound_M����N <= bound_N�̏ꍇ�̂݃T�|�[�g�B


// ���[��됬����1�ł���K�i���i�߂�l��rank�j

// A��F_2�W��L�~M�s��ł���B
template <int bound_L , int bound_M>
int RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );


// �W���s��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i��
// { �W���s��̊K�� , �u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U } ��Ԃ��B

// A��F_2�W��L�~M�s���F_2�W��L���c�x�N�g��N�����������g��W���s��ł���B
template <int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const int& L , const int& M , const int& N );
template <int bound_L , int bound_M , int bound_N , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const int& L , const int& M , const int& N );

// �Ȗ񉻁i�߂�l��rank�j

// A��F_2�W��L�~M�s��ł���B
template <int bound_L , int bound_M> inline int ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );


// �t�s��i�߂�l�́uL>0����A�������v�̐^�U�j

// A��F_2�W��L�������s��ł���B
template <int bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const int& L );
