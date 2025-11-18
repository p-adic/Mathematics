// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957397（RootingDP）

#include "../a.hpp"

// Uは適当な型、Fは写像f:(U^{< \omega}の右辺値) \times N -> Uに相当する型。
// 型推論のためにfはデフォルト引数で呼び出し可能とする。
// 入力の範囲内で要件
// (1) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
//     その並び換え(v1,...,vn)に対しf((u1,...,un),i)=f((v1,...,vn),i)である。
// を満たす場合のみサポート。
// dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
// を満たす配列dpをO(|V_T|)で求める。
template <typename DFST , typename F> vector<ret_t<F>> RootingDP( DFST& dfst , F f );
// - ノードiにU型の値A[i]が定まっておりその部分木和をdp[i]に格納する場合：
//   auto f = [&]( vector<U> u = {} , const int& i = 0 ){
//     U answer = A[i];
//     for( auto& x : u ){ answer += x; }
//     return answer;
//   };
// - 辺mにU型の値A[m]が定まっており、ノードiの部分木和+(iが根?U{}:A[iの親への辺番号])を
//   dp[i]に格納する場合：
//   auto f = [&]( vector<U> u = [] , const int& i = 0 ){
//     U answer = i == root ? U{} : A[UV_inv[{i,dfst.Parent(i)}]];
//     for( auto& x : u ){ answer += x; }
//     return answer;
//   };
// - ノードiにU型の値A[i]が定まっており型Uの非可換モノイド構造Mが与えられノード番号の全順序ordが定義されておりiの子ノードをわたるノード番号jのord昇順のMに関するdp[j]の総乗をA[i]に右から掛けたものをdp[i]に格納する場合：
//   auto f = [&]( vector<Pair<U,int>> u = {} , const int& i = 0 ){
//     U answer = A[i];
//     sort( u.begin() , u.end() , [&]( const pair<U,int>& u0 , const pair<U,int>& u1 ){ return ord( get<1>( u0 ) , get<1>( u1 ) ); } );
//     for( auto& [x,j] : u ){ answer = M.Product( move( answer ) , x ); }
//     return pair{ move( answer ) , i };
//   };
// 他のメンバを使わないのであれば、定数倍の軽い再帰版
// Recursion/a_Body.hpp
// の使用を検討する。

