// c:/Users/user/Documents/Programming/Mathematics/Analysis/Probability/ExpectedTrialCount/a.hpp

#pragma once
// veirfy:
// https://yukicoder.me/submissions/1139039 (ExpectedCompleteCollectionTrialCount,ExpectedCompletePairCollectionTrialCount)

// n種類から1種類ランダムに引いて戻す試行で、特定のm種類のうちl種類以上を1回以上ずつ引く
// までに掛かる試行回数の期待値を返す。（O(l log m)）
// i=m-lに関する帰納法で答えはsum_{i=0}^{l-1} n/(m-i)になる。
template <typename MODINT> MODINT ExpectedCompleteCollectionTrialCount( const MODINT& n , const int& m , const int& l );

// n種類から1種類ランダムに引いて戻す試行で、特定のm種類のうちl種類を2回以上引く
// までに掛かる試行回数の期待値を返す。（O(ml)）
template <typename MODINT> MODINT ExpectedDoubleCollectionTrialCount( const MODINT& n , const int& m , const int& l );

// n種類から1種類ランダムに引いて戻す試行で、特定の2m種類からなるm組のうちl組を双方1回以上引く
// までに掛かる試行回数の期待値を返す。（O(ml)）
template <typename MODINT> MODINT ExpectedCompletePairCollectionTrialCount( const MODINT& n , const int& m , const int& l );


// n種類から1種類ランダムに引いて戻す試行c回で、特定のm種類のうち何種類が1回以上引かれるか
// の期待値を返す。（O(log n + log c)）
// 漸化式dp[0]=0、dp[c+1]=dp[c]+(m-dp[c])/n=((n-1)/n)dp[c]+(m/n)
// からdp[c]=(1-((n-1)/n)^c)mと求まる。
template <typename MODINT , typename INT> inline MODINT ExpectedNumberOfTypes( const MODINT& n , const int& m , INT c );
