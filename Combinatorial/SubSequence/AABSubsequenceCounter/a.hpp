// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// verify:
// https://yukicoder.me/submissions/1060344 (n=26,AltB=0)

// AABCount = tuple<vector<int>,vector<vector<ll>>,ll>で
// 文字列の{各Aの個数,各ABの個数,各AABの個数の総和}または
// 文字の{文字番号,空列,0}を管理
template <int n , int AltB>
class AABSubsequenceCounterOperator
{

public:
  // O(n^2)
  static AABCount Product( AABCount v0 , const AABCount& v1 );

};

// (1) s.size() == 3
// (2) AltB > 0 ? s[0] < s[1] : AltB < 0 ? s[0] > s[1] : s[0] != s[1]
// (3) s[0] == s[2]
// を満たす部分文字列sの個数を管理するモノイド
template <int n = 26 , int AltB = 0>
class AABSubsequenceCounter :
  public AbstractMonoid<AABCount,AABCount(*)(AABCount,const AABCount&)>
{

public:
  inline AABSubsequenceCounter();

};

// メモリ使用量が厳しい場合は代わりにA,B決め打ちのモノイドaabSubsequenceCounterで
// AABを数え上げ、A,Bを全探策する。
// ./aabSubsequenceCounter/a.hpp

template <int n = 10> inline AABCount ToAABCount( const int& c );
template <int n = 26> inline AABCount ToAABCount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> AABCount ToAABCount( const VEC<INT>& S );
// ただしAltB==0の場合はO(S.size())に高速化可能。
// https://yukicoder.me/submissions/904069
