// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/IntervalSort/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100475

// 入力の範囲内で要件
// (1) operator<(const STR&,const STR&)が全順序である。
// を満たす場合にのみサポート。

// 長さNの列Sに対し、0<=l<=r<Nを渡る(S[l,r],l)全体において
// 辞書式順序でk番目の値に対応するl,rの組を計算する。

// 構築O(N(log N)^2)
// ランダムアクセスO(N(log N)^2)
template <typename STR> 
class LexicographicIntervalSort
{

private:
  const STR* m_p_S;
  int m_N;
  vector<int> m_sa;
  vector<ll> m_cs;

public:
  inline LexicographicIntervalSort( const STR& S );

  inline pair<int,int> Get( ll k ) const;
  pair<int,int> operator[]( ll k ) const;

private:
  // sum_{i=l}^{r} (S[m_sa[i],N)の長さshift+1以上の部分列の部分列の個数)
  // = sum_{i=l}^{r} ( N - m_sa[i] - shift )
  // をO(1)で求める。
  inline ll CountIntervals( const int& l , const int r , const int& shift ) const;
  
};
