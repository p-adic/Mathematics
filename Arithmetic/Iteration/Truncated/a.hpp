// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Truncated/a.hpp

#pragma once

// O(log_2 e + 1)
template <typename INT1 , typename INT2> ll TruncatedPower( ll n , INT1 e , const INT2& bound );

// O(log_2 e log_2 n + 1)
template <typename INT1 , typename INT2> INT2 RoundDownRoot( const INT1& e , const INT2& n );

// O(log_2 e log_2 n + 1)
template <typename INT1 , typename INT2> inline bool IsThPower( const INT1& e , const INT2& n );
// 前計算O(i log_2 e)／クエリamortised O(1)
template <typename INT1 , typename INT2> bool IsThPowerBelow( const INT1& e , const INT2& n , const int& i );

// expected O(√n)でu^i=vとなるn以下の最小のiを計算する。そのようなiが存在しなければ-1を返す。
template <typename MONOID , typename U> int DiscreteLogarithm( MONOID M , const U& u , const U& v , const int& n );
