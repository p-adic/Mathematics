// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABCSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// ABCCount = tuple<vector<int>,vector<vector<ll>>,ll>で
// 文字列の{各Aの個数,各ABの個数,各ABCの個数の総和}を管理または
// 文字の{文字番号,空列,0}を管理
template <int n , int AltB , int BltC>
class ABCSubsequenceCounterOperator
{

public:
  // O(n^3)
  static ABCCount Product( ABCCount v0 , const ABCCount& v1 );

};

// (1) s.size() == 3
// (2) AltB > 0 ? s[0] < s[1] : AltB < 0 ? s[0] > s[1] : s[0] != s[1]
// (2) BltC > 0 ? s[1] < s[2] : AltB < 0 ? s[1] > s[2] : s[1] != s[2]
// を満たす部分文字列sの個数を管理するモノイド
template <int n = 26 , int AltB = 0 , int BltC = 0>
class ABCSubsequenceCounter :
  public AbstractMonoid<ABCCount,ABCCount(*)(ABCCount,const ABCCount&)>
{

public:
  inline ABCSubsequenceCounter();

};

template <int n = 10> inline ABCCount ToABCCount( const int& c );
template <int n = 26> inline ABCCount ToABCCount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> ABCCount ToABCCount( const VEC<INT>& S );
// ただしAltB==0の場合はO(S.size())に高速化可能。
// https://yukicoder.me/submissions/904069
