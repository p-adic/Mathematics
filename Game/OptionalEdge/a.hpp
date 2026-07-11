// c:/Users/user/Documents/Programming/Mathematics/Game/OptionalEdge/a.hpp

#pragma once

// 着手の集合の候補から相手が１つ選択した上でその集合から着手を取れるとする。
// 着手が存在しない場合に負けとなる無限ループのないゲームのグランディ数を
// を「遷移先のグランディ数として確実に選択できるわけではない値の最小値」として計算する。
template <typename OEdge , typename T> const int& OptionalEdgeGrundyNumber( OEdge& oedge , const T& t , const bool& reset = false );
