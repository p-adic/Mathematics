// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// ABACount = tuple<vector<int>,vector<vector<ll>>,ll>で
// 文字列の{各Aの個数,各ABの個数,各ABAの個数の総和}を管理または
// 文字の{文字番号,空列,0}を管理
template <int n , int AltB>
class ABASubsequenceCounterOperator
{

public:
  // O(n^2)
  static ABACount Product( ABACount v0 , const ABACount& v1 );

};

// (1) s.size() == 3
// (2) AltB > 0 ? s[0] < s[1] : AltB < 0 ? s[0] > s[1] : s[0] != s[1]
// (3) s[0] == s[2]
// を満たす部分文字列sの個数を管理するモノイド
template <int n = 26 , int AltB = 0>
class ABASubsequenceCounter :
  public AbstractMonoid<ABACount,ABACount(*)(ABACount,const ABACount&)>
{

public:
  inline ABASubsequenceCounter();

};

// メモリ使用量が厳しい場合は代わりにA,B決め打ちのモノイドabaSubsequenceCounterで
// ABAを数え上げ、A,Bを全探策する。
// ./abaSubsequenceCounter/a.hpp

template <int n = 10> inline ABACount ToABACount( const int& c );
template <int n = 26> inline ABACount ToABACount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> ABACount ToABACount( const VEC<INT>& S );
