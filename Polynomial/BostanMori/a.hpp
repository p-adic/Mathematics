// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/a.hpp

#pragma once
#include "../a.hpp"

//verify:https://yukicoder.me/submissions/937650

// O(max(deg(f),deg(g)) log_2 max(deg(f),deg(g)) log_2 sup(coeff��key))��
// coeff�̊ekey�������Ƃ���f/g�̌W�����擾
// A. Bostan and R. Mori, A Simple and Fast Algorithm for Computing the N-th Term of a Linearly Recurrent Sequence, Proceedings of SIAM Symposium on Simplicity in Algorithms (SOSA21), 2021, 118--132.
// �����ƂɎ���
template <typename T , typename INT>
void MultiCoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , unordered_map<INT,T>& coeff );
