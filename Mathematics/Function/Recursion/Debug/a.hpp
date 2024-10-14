// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/Debug/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Utility/Tuple/a.hpp"

// �f�o�b�O�p�Ɋ֐�����t���悤�ɕύX�������́B

template <typename REC>
class NonMemorisationRecursion : REC
{

private:
  string m_name;
  
public:
  inline NonMemorisationRecursion( REC rec );
  template <typename...Args> inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> operator()( const Args&... args );

};

template <typename REC>
class MemorisationRecursion : REC
{

private:
  string m_name;
  int m_num;
  
public:
  inline MemorisationRecursion( REC rec );
  template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& operator()( const Args&... args );

};
