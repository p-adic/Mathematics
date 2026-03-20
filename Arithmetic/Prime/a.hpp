// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
// veirfy:
// https://yukicoder.me/submissions/1153315 (MillerRabin)

// 前計算の合計計算量O((p_i/log p_i)^2) = O(i^2)で1+i番目の素数p_iをO(1)返す。
// 特に前計算の合計計算量O((L/log L)^2)でL以下の素数を列挙する。
// https://math.stackexchange.com/a/1744146
int GetPrime( const int& i );

// O(T log n)で誤判定率を4^{-T}に抑える。
// ただし乗算の計算量をO(1)とみなした。
bool MillerRabin( const int& n , int T = 20 );
// 一般の素数判定はPrimeEnumerationを用いるため
// ./Factorisation/a_Body.hpp
// で定義。

// 2からの素数列挙で良い場合はエラトステネスの篩、
// 2からの素数列挙だとメモリが不足する場合はミラーラビン法を検討する。
