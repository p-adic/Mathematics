// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// 着手が存在しない場合に負けとなる無限ループのないゲームの勝敗を計算する。
// Edgeはゲームの状態遷移を表す写像edge:T->T^{<\infty}に相当する型。
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );
// 着手が存在しない場合に負けとなる無限ループのないゲームのグランディ数を計算する。
template <typename Edge , typename T> const int& GrundyNumber( Edge& edge , const T& t , const bool& reset = false );

// - ゲームの状態遷移の和への分解aedge:T->(T^{<\infty})^{<\infty}が与えられる場合は
//   ./AdditiveTransfer
// - 着手が存在しない局面tの{0,1}値不変量invariant(t)が最初に与えられる定数Cと一致する場合に
//   勝ちとなる無限ループのないゲームで必勝となるC全体の集合は
//   ./FinalState/Invariant
// - 無限ループがありえる場合は
//   ./NonAcyclic
// - 着手の集合の候補から相手が１つ選択した上でその集合から着手を取れる場合は
//   ./OptionalEdge
// を参照。
