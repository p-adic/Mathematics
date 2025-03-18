// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// 合計計算量O(p_i) = O(i log i)で1+i番目の素数p_iを返す。
int GetPrime( const int& i );

// T=20などとし、O(T log n)で誤判定率を4^{-T}に抑える。
// ただし乗算の計算量をO(1)とみなした。
bool MillerRabin( const int& n );
