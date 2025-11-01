// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Expand/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1130768
// https://yukicoder.me/submissions/1130767
// https://yukicoder.me/submissions/1130766

// 以下S.size()をN、Sの成分の文字列長の総和をL、Sとtransの合成の文字列長の最大値をL'、
// source.size()をM、query.size()をQと置く。
// queryの各成分{j,t,k}のkの最大値をK、展開で長さがKを超える回数の最大値をTと置く。
// - 被展開文字の展開が被展開項を複数含むならばTはO(log_2 K)
// - そうでないならばTはO(K/1文字の展開による長さの増分)

// 制約
// (1) sourceは各文字が異なる。
// (2) 任意のq<Qに対し、query[q]={i,t,k}としてS[i]にt回変換を施して得られる文字列は
//     長さがk以上である。
// (3) 任意のq<Qに対し、query[q]={i,t,k}としてS[i]はsourceと文字を共有し、そのような文字の
//     S[i]での最左の出現文字をsource[j]とすると、S[trans[j]]もsourceと文字を共有し、
//     そのような文字のS[trans[j]]での最左の出現文字もsource[j]である。
// を満たす場合にのみサポート。

// source[j]をS[trans[j]]に置き換える変換を考える。
// 各q<Qに対し、query[q]={i,t,k}としてS[i]に変換をt回施して得られる文字列のk文字目（1-indexed）を
// answer[q]に記録する。(O(N+(L+T(L'+M^2))M+QM^2(log_2 L + T log_2 L')))
template <template <typename...> typename TUPLE> string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , vector<TUPLE<int,ll,ll>> query );
// query[q]の第1成分を0に固定したバージョン。
template <template <typename...> typename PAIR> inline string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , const vector<PAIR<ll,ll>>& query );
