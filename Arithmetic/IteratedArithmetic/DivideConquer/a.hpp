// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/DivideConquer/a.hpp

#pragma once

// MがTのモノイド構造である場合にのみサポート。
// Tの要素の列のMに関する総乗を分割統治で計算し、その結果を返す。
// V<T>はeraseを持つ必要がある。
template <typename T , template <typename...> typename V , typename MONOID> T DivideConquerMonoidalProd( MONOID M , V<T> f );
