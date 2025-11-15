// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Circle/Partition/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1081998 (NoncrossingPartition, colour_edge=false)

// chordが円周上のN点の弦M本による非交叉分割を与えるとする。
// 弦が端点を共有する本数の最大値をDとし、O(N + M log D)で各頂点iを、
// l<=i<rを満たす各弦{l,r}のうち最も内側にあるもの（最もlが大きくrが小さいもの）
// の弦番号（1-indexed）で色分けする。そのような弦が存在しない場合は0で色分けする。
// ただしcolour_edgeがfalseである時は弦の端点を-1で色分けする。
template <template <typename...> typename PAIR , typename INT> vector<int> NoncrossingPartition( const int& N , const vector<PAIR<INT,INT>>& chord , const bool& colour_edge = false );
