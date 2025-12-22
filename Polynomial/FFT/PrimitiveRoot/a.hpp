// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/PrimitiveRoot/a.hpp

#pragma once
#include "../../../Utiliity/Tuple/Wrap/a.hpp"

// 計算量が大きいので主に埋め込みに使う。
template <typename T> T PrimitiveRoot( const int& ord );

// O(ord^3)でDFTとIDFTにおける変換行列を返す。
template <typename T> T2<vector<vector<T>> DFTMatrix( const T& root , const int& ord );
