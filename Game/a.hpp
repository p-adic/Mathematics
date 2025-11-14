// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1133020 (GameState)


// 着手が存在しない場合に負けとなる無限ループのないゲームの勝敗を計算する。
// Edgeはゲームの状態遷移を表す写像edge:T->T^{<\infty}に相当する型。
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// 着手が存在しない場合に負けとなる無限ループのないゲームのグランディ数を計算する。
// AEdgeはゲームの状態遷移の和への分解を表す写像aedge:T->(T^{<\infty})^{<\infty}に相当する型。
// 各a in aedge(t)はそのゲーム和がtの遷移先に対応する配列。
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );

// 着手が存在しない局面の{0,1}値不変量が最初に与えられる定数Cと一致する場合に
// 勝ちとなる無限ループのないゲームで必勝となるC全体の集合を2進法で計算する。
template <typename Edge , typename T , typename INVARIANT> const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset = false );

// 着手が存在しない場合に負けとなるゲームの勝敗を各状態に対し計算する。
// GRAPHはゲームの状態遷移を表す、自然数を頂点とするグラフに相当する型。
// 格納値は-1:lose、0:draw、1:winで定める。（合計O(|V|+|E|)）
template <typename GRAPH> vector<int> GameState( GRAPH& G );
