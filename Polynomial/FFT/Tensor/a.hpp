// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/Tensor/a.hpp

#pragma once

// N:=f.size()と置き、非負整数Dを用いてN = base^Dと表せると仮定する。

// DFTMatrix(root,base)の返り値{F,F_inv}を第3引数に渡すとそれぞれ
// (Z/base Z)^DにおけるDFTとIDFTがO(base DN)で実行される。
template <typename T> void TensorFFT( vector<T>& f , const int& base , const vector<vector<T>>& F );
