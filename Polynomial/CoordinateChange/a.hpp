// c:/Users/user/Documents/Programming/Mathematics/Polynomial/CoordinateChange/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://judge.yosupo.jp/submission/276549 (平行移動)

// 平行移動f(x+t)（O(D log D)）
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
// アフィン変換f(tx+u)（O(D log D)）
template <typename T> void AffineTransformation( Polynomial<T>& f , const T& t , const T& u = Polynomial<T>::c_zero() , const bool& exponential = false );
// メビウス変換f((ax+b)/(cx+d))をh(x)/(ux+v)^eの形で表示して{h,u,v,e}を返す。（O((D log D))）
template <typename T> tuple<Polynomial<T>,T,T,int> MoeviusTransformation( Polynomial<T> f , T a , T b , T c , T d );
