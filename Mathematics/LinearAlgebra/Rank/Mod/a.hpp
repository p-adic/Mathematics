// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

// �ȉ�L <= bound_L����M <= bound_M����N <= bound_N�̏ꍇ�̂݃T�|�[�g�B
// INT��int��ll�ł���AP�͑f���ł���B


// ���[��됬����1�ł���K�i���i�߂�l��rank�j

// A��INT�W��L�~M�s��ł���B
template <typename INT1 , typename INT2 , int bound_L , int bound_M>
int RowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P );


// �W���s��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i��
// { �W���s��̊K�� , �u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U } ��Ԃ��B

// A��INT�W��L�~M�s���INT�W��L���c�x�N�g��N�����������g��W���s��ł���B
template <typename INT1 , typename INT2 , int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , const int& L , const int& M , const int& N , const INT2& P );
template <typename INT1 , typename INT2 , int bound_L , int bound_M , int bound_N, int bound_M_N = bound_M + bound_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , INT1 ( &solution )[bound_M][bound_N] , const int& L , const int& M , const int& N , const INT2& P );


// �Ȗ񉻁i�߂�l��rank�j

// A��INT�W��L�~M�s��ł���B
template <typename INT1 , typename INT2 , int bound_L , int bound_M> inline int ReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P );

// �t�s��i�߂�l�́uL>0����A�������v�̐^�U�j

// A��INT�W��L�������s��ł���B
template <typename INT1 , typename INT2 , int bound_L>
bool Invertible( const INT1 ( &A )[bound_L][bound_L] , INT1 ( &A_inv )[bound_L][bound_L] , const int& L , const INT2& P );

