// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/Kruscal/a.hpp

#pragma once
#include "../../../a.hpp"

// verify:
// https://yukicoder.me/submissions/957499
// https://yukicoder.me/submissions/1121192

// GRAPHは無向グラフの有向化G=(V_G,E_G)に相当する型。
// （辺番号を用いる都合で無向辺の片向きだけ恣意的に選んで登録しておく）
// ただし辺E_Gは写像T -> ( T \times U \times int \times ... )^{< \omega}に相当し、
// その値の第3成分は辺番号を表す。（無向化で得られる２辺共通の番号として用いる）

// 入力の範囲内で要件
// (1) Uはbool operator<(const U&,const U&)に関して全順序である。
// (2) E:N->N^2はE_Gを与える頂点対の頂点番号対(i,j)の番号付けである。
// を満たす場合にのみサポート。

// O(|E_G|α(|V_G| + log_2 |E_G|))でGの無向化の、answerに対応する辺集合を含む全域森のうち
// 重み（の<に関して全順序モノイドをなす可換モノイド構造に関する総和）が最小な全域無向森の
// {辺番号の配列（初期値以外は重み昇順）,連結成分の個数}を返す。
// そのような全域無向森が存在しない（初期値answerが閉路を含む）場合は{answer,-1}を返す。
template <typename GRAPH , typename PAIR> inline pair<vector<int>,int> Kruscal( GRAPH& G , const vector<PAIR>& E , vector<int> answer = {} );
// ただしここでは全域性に連結成分数の一致を課すことに注意。
// 課さない場合は重さ正の辺を全て削除すれば良い。

// OnはE_Gの{0,1}彩色on:int（辺番号）-> {0,1}に相当する型。

// 入力の範囲内で要件
// (1) E_sorted:N->N^3は{(i,j,n)|(i,j)=E[n]}を対応する重みに関してソートしたものでxある。
// を満たす場合にのみサポート。

// O(|E_G| α(|V_G|))でonで1に色付けされるGの辺のみからなる部分グラフの無向化の、
// answerに対応する辺集合を含む全域森のうち重み（の<に関して全順序モノイドをなす
// 可換モノイド構造に関する総和）が最小な全域無向森の
// {辺番号の配列（初期値以外は重み昇順）,連結成分の個数}
// を返す。そのような全域無向森が存在しない（answerが閉路を含むか0に色付けされる辺を含む）場合は
// {answer,-1}を返す。
template <typename On , typename PAIR , typename TUPLE> pair<vector<int>,int> Kruscal( const int& V , const vector<PAIR>& E , const list<TUPLE>& E_sorted , const On& on , vector<int> answer = {} );
