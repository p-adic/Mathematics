// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// verify:
// https://yukicoder.me/submissions/1060344 (n=26,AltB=0)

// AABCount = tuple<vector<int>,vector<vector<ll>>,ll>��
// �������{�eA�̌�,�eAB�̌�,�eAAB�̌��̑��a}�܂���
// ������{�����ԍ�,���,0}���Ǘ�
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
// �𖞂�������������s�̌����Ǘ����郂�m�C�h
template <int n = 26 , int AltB = 0>
class AABSubsequenceCounter :
  public AbstractMonoid<AABCount,AABCount(*)(AABCount,const AABCount&)>
{

public:
  inline AABSubsequenceCounter();

};

// �������g�p�ʂ��������ꍇ�͑����A,B���ߑł��̃��m�C�haabSubsequenceCounter��
// AAB�𐔂��グ�AA,B��S�T�􂷂�B
// ./aabSubsequenceCounter/a.hpp

template <int n = 10> inline AABCount ToAABCount( const int& c );
template <int n = 26> inline AABCount ToAABCount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> AABCount ToAABCount( const VEC<INT>& S );
// ������AltB==0�̏ꍇ��O(S.size())�ɍ������\�B
// https://yukicoder.me/submissions/904069
