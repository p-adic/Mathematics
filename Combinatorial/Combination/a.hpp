// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1123395 (CombinationFactorialValuative, MOD=443*2253371)
// https://atcoder.jp/contests/abc425/submissions/69702053 (CombinationFactorialValuative, MOD一般)
// https://yukicoder.me/submissions/1082026 (CombinationCumulativeProduct, RET=MP)


// 主にINT1,INT2,INTはintやllを想定しているが、要件を満たせばModやDynamicModなどでも良い。
// 例えばCombinationCumulativeProductはn,m次第でMod::Combinationより高速になる。
// - intやllの時はオーバーフローしうることに注意。
// - Modは法pが素数でないと/の計算が合わないことに注意。
// - DyamicModはSetModuloでis_prime=trueを渡した時のみ/がメモ化再帰でO(1)で計算され、
//   一般には/がユークリッドの互除法でO(log_2 n)で計算されることに注意。

// 要件
// (1) INT1で[1,min(m,n-m)]の要素による商が実行できる。
// のもとで均しO(1)（nごとに合計O(min(m,n-m))）で積と商の反復による計算をメモ化再帰する。
template <typename RET , typename INT1 , typename INT2> inline RET CombinationCumulativeProduct( const INT1& n , INT2 m , const bool& reset = false );

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとで均しO(L)（前計算O(log n)、nごとに合計O(min(m,n-m)log MOD)）で
// 積と商の反復による計算をメモ化再帰する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const bool& reset = false );

// 要件
// (1) INT1で[1,min(m,n-m)]の要素の階乗による商が実行できる。
// (2) INT1がintやuintならばn<=12、llやullならばn<=20である。
// のもとでO(1)（前計算O(n)）で階乗を用いて計算する。
template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m );

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとで多項係数をO(L(1+m.size()))（前計算O(n log MOD)）で階乗を用いて計算する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , const vector<INT2> m , const VEC& factor , const int& euler );
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler );
// valutaiveは以下と併用する。
// auto [factor,exponent] = PrimeFactorisation( pe , mod );
// 最終的な答えは以下のように算出する。
// auto [a,val] = CombinationFactorialValuative<MOD>( n , m , factor );
// FOR( i , 0 , L ){
//   a *= PowerMemorisation( MOD{ factor[i] } , val[i] );
//   // a *= Power( MOD{ factor[i] } , val[i] );
// }
