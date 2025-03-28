// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// ABCount = pair<vector<int>,ll>で{各Aの個数,各ABの個数の総和}を管理
template <int n , int AltB>
class ABSubsequenceCounterOperator
{

public:
  // O(n^2)
  static ABCount Product( ABCount v0 , const ABCount& v1 );

};

// (1) s.size() == 2
// (2) AltB > 0 ? s[0] < s[1] : AltB < 0 ? s[0] > s[1] : s[0] != s[1]
// を満たす部分文字列sの個数を管理するモノイド
template <int n = 26 , int AltB = 0>
class ABSubsequenceCounter :
  public AbstractMonoid<ABCount,ABCount(*)(ABCount,const ABCount&)>
{

public:
  inline ABSubsequenceCounter();

};

template <int n = 10> inline ABCount ToABCount( const int& c );
template <int n = 26> inline ABCount ToABCount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> ABCount ToABCount( const VEC<INT>& S );
