// c:/Users/user/Documents/Programming/Mathematics/Polynomial/CoordinateChange/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://judge.yosupo.jp/submission/276549 (���s�ړ�)

// ���s�ړ�f(x+t)�iO(D log D)�j
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
// �A�t�B���ϊ�f(tx+u)�iO(D log D)�j
template <typename T> void AffineTransformation( Polynomial<T>& f , const T& t , const T& u = Polynomial<T>::c_zero() , const bool& exponential = false );
// ���r�E�X�ϊ�f((ax+b)/(cx+d))��h(x)/(ux+v)^e�̌`�ŕ\������{h,u,v,e}��Ԃ��B�iO((D log D))�j
template <typename T> tuple<Polynomial<T>,T,T,int> MoeviusTransformation( Polynomial<T> f , T a , T b , T c , T d );
