// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1063416 (CombinationFactorialValuative, MOD=443*2253371)
// https://yukicoder.me/submissions/1082026 (CombinationCumulativeProduct, RET=MP)

// 主にINT1,INT2,INTはintやllを想定しているが、要件を満たせばModやDynamicModなどでも良い。
// 例えばCombinationCumulativeProductはn,m次第でMod::Combinationより高速になる。
// - intやllの時はオーバーフローしうることに注意。
// - Modは法pが素数でないと商の計算が合わないことに注意。
// - DyamicModは法nが素数でない時はSetModulo(n,φ(n)-1)としないと商の計算が合わないことに注意。

// 要件
// (1) INT1で[1,min(m,n-m)]の要素による商が実行できる。
// のもとで均しO(1)（nごとに合計O(min(m,n-m))）で積と商の反復による計算をメモ化再帰する。
template <typename RET , typename INT1 , typename INT2> inline RET CombinationCumulativeProduct( const INT1& n , INT2 m , const bool& reset = false );

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとで均しO(L)（前計算O(log n)、nごとに合計O(min(m,n-m)log MOD)）で
// 積と商の反復による計算をメモ化再帰する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler , const bool& reset = false );

// 要件
// (1) INT1で[1,min(m,n-m)]の要素の階乗による商が実行できる。
// (2) INT1がintやuintならばn<=12、llやullならばn<=20である。
// のもとでO(1)（前計算O(n)）で階乗を用いて計算する。
template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m );

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとでO(L)（前計算O(n log MOD)）で階乗を用いて計算する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler );
