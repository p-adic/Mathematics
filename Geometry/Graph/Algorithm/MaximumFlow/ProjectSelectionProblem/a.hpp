// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/ProjectSelectionProblem/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1104412 (dependency_penalty={},set_reject_score={})
// https://yukicoder.me/submissions/1104408（set_reject_score={}）

// V0はUに変換できる型のvector型とし、
// V1はUに変換できる型Tを用いてTuple<int,int,T>の形式の型のvector型とする。
// V2,V3はUに変換できる型Tを用いてpair<vector<int>,T>の形式の型のvector型とする。

// 以下score.size()をNと置き、
// dependency_penalty.size()をMと置き、
// set_accept_score.size()+set_reject_score.size()をLと置き、
// Uを整数型とした時の答えの上限をFと置く。

// 入力の範囲内で要件
// (0) Rは全順序アーベル群構造である。
// (1) dependency_penaltyとset_accept/reject_scoreの値の各成分の第2成分がR.Zero()以上である。
// (2) inftyが「入力の各成分の絶対値とNの和」のN個以下の和よりも大きい。
// (3) dependency_penaltyに{i,i,u}の形の成分は存在しない。
// (4) set_accept/reject_scoreの各成分の第1成分は長さ正かつ単射である。
// が成り立つ場合にのみサポート。

// {0,1,...,N-1}の部分集合Sに対する
// sum_{i in S} score[i]
// - sum_{(i,j,u) in dependency_penalty and i in S and j notin S} u
// + sum_{(v,u) in set_accept_score and forall i in v[i in S]} u
// + sum_{(v,u) in set_accept_score and forall i in v[i notin S]} u
// の最大値をO(min((N+L)^2,F)(M+L))で求める。
template <typename U , typename ABEL_GROUP , typename V0 , typename V1 , typename V2 , typename V3> U AbstractProjectSelectionProblem( ABEL_GROUP R , const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score );
template <typename U , typename V0 , typename V1 , typename V2 , typename V3> inline U ProjectSelectionProblem( const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score );
