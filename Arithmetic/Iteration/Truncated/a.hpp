// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Truncated/a.hpp

#pragma once
#include "a_Macro.hpp"

// DiscreteLogarithmの実用時に使う。
#include "../../../Algebra/Monoid/a.hpp"

// O(log_2 e + 1)
// 値の上限付き繰り返し二乗法で羃乗を計算する。
template <typename INT1 , typename INT2> ll TruncatedPower( ll n , INT1 e , const INT2& bound );

// O(log_2 e log_2 n + 1)
// 値の上限付き繰り返し二乗法の二分探索で累乗根を計算する。
template <typename INT1 , typename INT2> INT2 RoundDownRoot( const INT1& e , const INT2& n );

// O(log_2 e log_2 n + 1)
// 値の上限付き繰り返し二乗法の二分探索で累乗数判定をする。
template <typename INT1 , typename INT2> inline bool IsThPower( const INT1& e , const INT2& n );
// 前計算O(nの最大値 log_2 e)／クエリexpected O(1)
// 累乗数列挙で累乗数判定をする。
template <typename INT1 , typename INT2> bool IsThPowerMemorisation( const INT1& e , const INT2& n );

// expected O(√n)
// baby step giant stepでu^i=vとなるn以下の最小のiを計算する。存在しなければ-1を返す。
template <typename MONOID , typename U> int DiscreteLogarithm( MONOID M , const U& u , const U& v , const int& n );
// mod base乗算に関する離散対数は
// ../../Mod/Function/DiscreteLog/a_Body.hpp
// のDiscreteModの方が定数倍早い。
