// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/Recursion/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1113759 (RecursionRootingDP)
// https://yukicoder.me/submissions/1113760 (BinaryRootingDP)

// 再帰による木DPの軽量化。
// Uは適当な型、Fは写像f:(U^{< \omega}の右辺値) \times N -> Uに相当する型。
// 型推論のためにfはデフォルト引数で呼び出し可能とする。
// 入力の範囲内で要件
// (1) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
//     その並び換え(v1,...,vn)に対しf((u1,...,un),i)=f((v1,...,vn),i)である。
// を満たす場合のみサポート。
// dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
// を満たす配列dpの根での値dp[root]をO(|V_T|)で求める。
template <typename TREE , typename F> inline ret_t<F> RecursionRootingDP( TREE& T , F& f , const int& root );
// - ノードiにU型の値A[i]が定まっておりその部分木和をdp[i]に格納する場合：
//   auto f = [&]( vector<U> u , const int& i ){
//     U answer = A[i];
//     for( auto& x : u ){ answer += x; }
//     return answer;
//   };
// - ノードiにU型の値A[i]が定まっており型Uの非可換モノイド構造Mが与えられノード番号の全順序ordが定義されておりiの子ノードをわたるノード番号jのord昇順のMに関するdp[j]の総乗をA[i]に右から掛けたものをdp[i]に格納する場合：
//   auto f = [&]( vector<pair<U,int>> u , const int& i ){
//     U answer = A[i];
//     sort( u.begin() , u.end() , [&]( const pair<U,int>& u0 , const pair<U,int>& u1 ){ return ord( get<1>( u0 ) , get<1>( u1 ) ); } );
//     for( auto& [x,j] : u ){ answer = M.Product( move( answer ) , x ); }
//     return pair{ move( answer ) , i };
//   };


// dp[i] = val( i )にprodで右からiの子ノードjをわたるdp[j]をord(i,j)順で掛けた値
// を計算する木DPの再帰による軽量化。
// Uは適当な型、VALは写像f:N -> Uに相当する型、RIGHT_ACTIONは写像f(U^2の右辺値) -> Uに相当する型。
// ord( i , j )はT.Edge( i )におけるjの格納順。
template <typename TREE , typename VAL , typename RIGHT_ACTION> inline ret_t<VAL,int> BinaryRootingDP( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& root );
