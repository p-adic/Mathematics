// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/abaSubsequenceCounter/a.hpp

#pragma once
#include "a_Alias.hpp"

// abaCount = tuple<int,ll,ll,ll>��
// {a�̌�,b�̌�,ab�̌�,ba�̌�,aba�̌��̑��a}���Ǘ�
class abaSubsequenceCounterOperator
{

public:
  // O(1)
  static abaCount Product( abaCount v0 , const abaCount& v1 );

};

// (1) s=="aba"
// �𖞂�������������s�̌����Ǘ����郂�m�C�h
class abaSubsequenceCounter :
  public AbstractMonoid<abaCount,abaCount(*)(abaCount,const abaCount&)>
{

public:
  inline abaSubsequenceCounter();

};
