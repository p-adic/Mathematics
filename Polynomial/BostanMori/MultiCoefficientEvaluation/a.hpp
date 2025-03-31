// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/MultiCoefficientEvaluation/a.hpp

#pragma once
#include "../../a.hpp"

//verify:
// https://yukicoder.me/submissions/1062302

// O(max(deg(f),deg(g)) log_2 max(deg(f),deg(g)) log_2 sup(coeff��key))��
// coeff�̊ekey�������Ƃ���f/g�̌W�����擾
template <typename T , typename INT>
void MultiCoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , unordered_map<INT,T>& coeff );
