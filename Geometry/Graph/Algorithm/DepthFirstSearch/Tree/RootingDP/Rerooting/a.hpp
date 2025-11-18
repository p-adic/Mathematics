// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/Rerooting/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957399（RerootingDP）
// https://yukicoder.me/submissions/957400（RerootingDP）

#include "../../a.hpp"

// Uは適当な型、Fは写像f:U \times N ->Uに相当する型、
// Gは写像g:U \times \{0,1\} \times N^2 -> Uに相当する型。
// 入力の範囲内で要件
// (1) MがUのモノイド構造である。（以下演算を*と置く）
// を満たす場合のみサポート。
// dp[i][j] =
// f(iを根とみなした時のjの子ノードkをord(i,j)順でわたらせてg(dp[i][k],元の木構造でjはiの子孫,k,j)のMに関して右に掛けていく積,j)
// を満たす二重配列dpの対角成分dp[i][i]をO(|V_T|)で求めてanswer[i]に格納する。
// ただしord(i,j)はiを根とした時のjの子ノードkの順序づけで、
// - 元の木構造でjの親となるものを最初に
// - そうでないものはChildrenNumber()に関して昇順に
// として定義する。
template <typename DFST , typename MONOID , typename F , typename G> vector<inner_t<MONOID>> RerootingDP( DFST& dfst , MONOID M , F f , G g );
// fはノードjごとのデータ（グラフ構造に依存しないもの）しか使えず、
// gは有向辺is_child?(j,k):(k,j)ごとのデータ（グラフ構造、例えばkが葉か否かに依存できる）が使える。
// -「パスの数」を求める場合：
//   AdditiveMonoid<int> monoid{};
//   auto f = [&]( const int& u , const int& i ){ return u + 1; };
//   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
// -「パスの長さの最大値」を求める場合：
//   MaxSemilattive<int> monoid{ -1 };
//   auto f = [&]( const int& u , const int& i ){ return u + 1; };
//   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
// - ノードiにU型の値A[i]が定まっており型Uの可換モノイド構造monoidが与えられiを根としてノードjの
//   子ノードkをわたって(iを根としてkが葉?A[k]:dp[i][k])の総和をdp[i][j]に格納する場合：
//   auto f = [&]( const U& u , const int& i ){ return u; };
//   auto g = [&]( cost U& u , const bool& is_child , const int& k , const int& j ) { return dfst.IsLeaf( i , k ) ? A[k] : u; };
// - ノードiにU型の値A[i]が定まっており型Uの可換モノイド構造monoidが与えられiを根として
//   (ノードjが葉?A[j]:jの子ノードkをわたるdp[i][k]の総和)をdp[i][j]に格納する場合は、
//   dp[i][i]=(size=1?A[i]:上のケースのdp[i][i])で処理可能
// - 並び換え不変な関数h:U^{< omega} -> Uが与えられており
//   h(iを根とした時のjの子ノードkをわたるdp][i][k]たち)をdp[i][j]に格納する場合：
//   auto concate = [&]( vector<U> v0 ,  const vector<U>& v1 ){
//     RUN( v1 , u ){ v0 <<= u; }
//     return move( v0 );
//   };
//   vector<U> empty{}:
//   AbstractMonoid monoid{ concat , empty };
//   auto f = [&]( const vector<U>& v , const int& i ){ return vector<U>{ h( v ) }; };
//   auto g = [&]( cost vector<U>& v , const bool& is_child , const int& k , const int& j ) -> const vector<U>& { return v; };
