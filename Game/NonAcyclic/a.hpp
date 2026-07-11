// c:/Users/user/Documents/Programming/Mathematics/Game/NonAcyclic/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1133020

// 着手が存在しない場合に負けとなるゲームの勝敗を各状態に対し計算する。
// GRAPHはゲームの状態遷移を表す、自然数を頂点とするグラフに相当する型。
// 格納値は-1:lose、0:draw、1:winで定める。（合計O(|V|+|E|)）
template <typename GRAPH> vector<int> NonAcyclicGameState( GRAPH& G );
