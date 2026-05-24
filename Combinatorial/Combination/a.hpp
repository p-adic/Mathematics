// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a.hpp

#pragma once
// verify:
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
// (1) INT1で[1,min(m,n-m)]の要素の階乗による商が実行できる。
// (2) INT1がintならばn<=12、llならばn<=20である。
// のもとでO(1)（前計算O(n)）で階乗と階乗逆元を用いて計算する。
template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m );

// 要件
// (1) RETがintならばn<=31、llならばn<=63である。
// のもとでO(1)（前計算O(n^2)）でパスカルの三角形を用いて計算する。
template <typename RET> RET CombinationPascal( const int& n , const int& m );

// この他に付値計算を用いる
// - CombinationCumulativeProductValuative
// - CombinationFactorialValuative
// が
// ./Valuative/
// で定義されている。

