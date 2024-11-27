// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a.hpp

#pragma once

// �ȉ�L <= bound_L����M <= bound_M�̏ꍇ�̂݃T�|�[�g�B


// ���[��됬����1�ł���K�i���i�߂�l��rank�j

// A�͊Ȗ񉻂Ő����̐�Βl��(0,epsilon)�ɓ���Ȃ�L�~M�s��ł���B
template <int bound_L , int bound_M>
int RowEchelonForm( double ( &A )[bound_L][bound_M] , const int& L , const int& M , const double& epsilon );
