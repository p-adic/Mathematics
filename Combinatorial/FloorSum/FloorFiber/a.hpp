// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorInverse/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1135328 (FloorComposition)

#include "a_Macro.hpp"

#include "../../../Utility/Tuple/Wrap/a.hpp"

// 以下n >= 1の場合のみサポート。

// [1,n] -> N, i mapsto floor( n / i ) の各点vのファイバー[l,r]をO(√n)で求め、
// [l,r]が空であるvに対する{v,l,r}の列を返す。
template <typename INT> vector<T3<INT>> FloorFiber( const INT& n );

// INTERVAL_SUMは写像f:N^3->RETに相当する型。

// 関数F(i)が各vと[l_v,r_v] \subset {i in N|floor(n/i)=v}に対し
// sum_{i=l_v}^{r_v} F(i) = f(v,l,r)を満たす時、sum_{i=l}^{r} F(i)をO(√n)で求める。
template <typename INTERVAL_SUM , typename INT , typename RET = ret_t<INTERVAL_SUM,INT,INT,INT>> RET FloorComposition( INTERVAL_SUM f , const INT& n , const ll& l , const ll& r );
