// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/Valuative/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1123395 (CombinationFactorialValuative, MOD=443*2253371)
// https://atcoder.jp/contests/abc425/submissions/69702053 (CombinationFactorialValuative, MOD一般)

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとで均しO(L)（前計算O(log n)、nごとに合計O(min(m,n-m)log MOD)）で
// 積と商の反復による計算をメモ化再帰する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const bool& reset = false );

// 要件
// (1) factorは相異なる素数の列（長さをLと置く）である。
// (2) MODはfactorの正羃の積を法とする整数の型である。
// のもとでn個からm[0],m[1],...個ずつ選ぶ多項係数をO(L(1+m.size()))（前計算O(n log MOD)）
// で階乗を用いて計算する。（mの総和がnより大きい場合は0）
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> MultinomialFactorialValuative( const INT1& n , const vector<INT2> m , const VEC& factor , const int& euler );
// 二項係数をO(L)（前計算O(n log MOD)）で階乗を用いて計算する。
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler );

// いずれも以下と併用する。
// auto [factor,exponent] = PrimeFactorisation( pe , mod );
// 最終的な答えは以下のように算出する。
// auto [a,val] = CombinationFactorialValuative<MOD>( n , m , factor );
// FOR( i , 0 , L ){
//   a *= PowerMemorisation( MOD{ factor[i] } , val[i] );
//   // a *= Power( MOD{ factor[i] } , val[i] );
// }
