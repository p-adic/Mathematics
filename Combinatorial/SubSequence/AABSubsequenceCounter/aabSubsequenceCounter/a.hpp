// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/aabSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// aabCount = tuple<int,ll,ll,ll>��
// {a�̌�,b�̌�,ab�̌�,ba�̌�,aab�̌��̑��a}���Ǘ�
class aabSubsequenceCounterOperator
{

public:
  // O(1)
  static aabCount Product( aabCount v0 , const aabCount& v1 );

};

// (1) s=="aab"
// �𖞂�������������s�̌����Ǘ����郂�m�C�h
class aabSubsequenceCounter :
  public AbstractMonoid<aabCount,aabCount(*)(aabCount,const aabCount&)>
{

public:
  inline aabSubsequenceCounter();

};
