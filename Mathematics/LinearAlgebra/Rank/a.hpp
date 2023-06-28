// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/a.hpp

#pragma once


// INT��int��ll�ł���AL <= bound_L����M <= bound_M�ł���AA�͗v�f�̐�Βl���\�������������W��L�~M�s��ł���B
template <typename INT , int bound_L , int bound_M>
int Rank( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );

// L <= bound_L����M <= bound_M�ł���AA��F_2�W��L�~M�s��ł���B
template <int bound_L , int bound_M>
int Rank( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );

// L <= bound_L����M <= bound_M�ł���AA��F_2�W��L�~M�s���F_2�W��L���c�x�N�g�������������s��ł���B
template <int bound_L , int bound_M>
int Reduce( bitset<bound_M + 1> ( &A )[bound_L] , bitset<bound_M + 1> &solution , const int& L , const int& M );

