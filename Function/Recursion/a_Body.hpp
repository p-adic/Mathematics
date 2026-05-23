// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Tuple/a_Body.hpp"

template <typename F , typename REC , typename...Args> unordered_map<F*,unordered_map<tuple<Args...>,ret_t<REC,MemorisationRecursion<REC>&,const Args&...>>> memo_for_recursion{};

template <typename REC> inline NonMemorisationRecursion<REC>::NonMemorisationRecursion( REC rec ) : REC( move( rec ) ) {}

template <typename REC> inline MemorisationRecursion<REC>::MemorisationRecursion( REC rec ) : REC( move( rec ) ) {}

template <typename REC> template <typename...Args> inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> NonMemorisationRecursion<REC>::operator()( const Args&... args ){ return REC::operator()( *this , args... ); }

template <typename REC> template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& MemorisationRecursion<REC>::operator()( const Args&... args )
{
  
  auto& memo = memo_for_recursion<decldecay_t(*this),REC,Args...>[this];
  const tuple<Args...> v{ args... };
  return memo.count( v ) == 0 ? memo[v] = REC::operator()( *this , args... ) : memo[v];

}

template <typename REC> template <typename...Args> inline void MemorisationRecursion<REC>::clear() { memo_for_recursion<decldecay_t(*this),REC,Args...>[this].clear(); }
