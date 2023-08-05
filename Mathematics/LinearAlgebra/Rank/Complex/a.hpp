// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Complex/a.hpp

#pragma once

// �ȉ�L <= bound_L����M <= bound_M�̏ꍇ�̂݃T�|�[�g�B


// ���[��됬����1�ł���K�i���i�߂�l��rank�j

// A�͊Ȗ񉻂Ő����̐�Βl�̂Q�悪0(0,epsilon)�ɓ���Ȃ�L�~M�s��ł���B
template <int bound_L , int bound_M>
int RowEchelonForm( complex<double> ( &A )[bound_L][bound_M] , const int& L , const int& M , const double& epsilon );

