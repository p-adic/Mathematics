// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// ABACount = tuple<vector<int>,vector<vector<ll>>,ll>��
// �������{�eA�̌�,�eAB�̌�,�eABA�̌��̑��a}���Ǘ��܂���
// ������{�����ԍ�,���,0}���Ǘ�
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
// �𖞂�������������s�̌����Ǘ����郂�m�C�h
template <int n = 26 , int AltB = 0>
class ABASubsequenceCounter :
  public AbstractMonoid<ABACount,ABACount(*)(ABACount,const ABACount&)>
{

public:
  inline ABASubsequenceCounter();

};

// �������g�p�ʂ��������ꍇ�͑����A,B���ߑł��̃��m�C�habaSubsequenceCounter��
// ABA�𐔂��グ�AA,B��S�T�􂷂�B
// ./abaSubsequenceCounter/a.hpp

template <int n = 10> inline ABACount ToABACount( const int& c );
template <int n = 26> inline ABACount ToABACount( const char& c );
// O(n*S.size())
template <int n , int AltB , template <typename...> typename VEC , typename INT> ABACount ToABACount( const VEC<INT>& S );
