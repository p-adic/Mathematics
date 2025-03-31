// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1062292

// A. Bostan and R. Mori, A Simple and Fast Algorithm for Computing the N-th Term of a Linearly Recurrent Sequence, Proceedings of SIAM Symposium on Simplicity in Algorithms (SOSA21), 2021, 118--132.
// �����ƂɎ���

// O(max(deg(f),deg(g)) log_2 max(deg(f),deg(g)) log_2 i)��
// f/g��i���W�����擾
template <typename T>
T CoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , ll i );
