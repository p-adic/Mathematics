// c:/Users/user/Documents/Programming/Mathematics/Game/FinalStateInvariant/a.hpp

#pragma once

// 着手が存在しない局面tの{0,1}値不変量invariant(t)が最初に与えられる定数Cと一致する場合に
// 勝ちとなる無限ループのないゲームで必勝となるC全体の集合を2進法で計算する。
template <typename Edge , typename T , typename INVARIANT> const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset = false );
