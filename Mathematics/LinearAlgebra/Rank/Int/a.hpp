// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a.hpp

#pragma once

// �ȉ�L <= bound_L����M <= bound_M�̏ꍇ�̂݃T�|�[�g�B


// ���[��됬������̍ő���񐔂ł���K�i���i�߂�l��rank�j

// A�͗v�f�̐�Βl���\��������INT�W��L�~M�s��ł���AINT��int��ll�ł���B
template <typename INT , int bound_L , int bound_M>
int EuclideanRowEchelonForm( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );
