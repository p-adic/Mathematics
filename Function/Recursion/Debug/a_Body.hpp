// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Random/a_Body.hpp"

string CURRENT_NAME_FOR_RECURSION = "";
template <typename F , typename REC , typename...Args> unordered_map<F*,unordered_map<tuple<Args...>,ret_t<REC,MemorisationRecursion<REC>&,const Args&...>>> memo_for_recursion{};

template <typename REC> inline NonMemorisationRecursion<REC>::NonMemorisationRecursion( REC rec ) : REC( move( rec ) ) , m_name( CURRENT_NAME_FOR_RECURSION )
{

  static bool init = true;

  if( init ){
    
    DERR( "NonMemorisationRecursion" , m_name , "をデバッグモードで実行します。" );
    DERR( "エラー出力以外に変更はありません。" );
    init = false;

  }

}

template <typename REC> inline MemorisationRecursion<REC>::MemorisationRecursion( REC rec ) : REC( move( rec ) ) , m_name( CURRENT_NAME_FOR_RECURSION )
{

  static bool init = true;

  if( init ){
    
    DERR( "MemorisationRecursion" , m_name , "をデバッグモードで実行します。" );
    DERR( "エラー出力以外に変更はありません。" );
    init = false;

  }

}

template <typename REC> template <typename...Args>
inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> NonMemorisationRecursion<REC>::operator()( const Args&... args )
{

  auto answer = REC::operator()( *this , args... );
  DERR( "非メモ化再帰：" , m_name , "(" , tuple<Args...>{ args... } , ") =" , answer );
  return answer;

}

template <typename REC> template <typename...Args>
inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& MemorisationRecursion<REC>::operator()( const Args&... args )
{

  auto& memo = memo_for_recursion<decldecay_t(*this),REC,Args...>[this];
  const tuple<Args...> v{ args... };

  if( memo.count( v ) == 0 ){

    auto& answer = memo[v] = REC::operator()( *this , args... );
    DERR( "メモ化再帰：" , m_name , "(" , v , ") =" , answer );
    return answer;

  }
  
  return memo[v];

}

template <typename REC> template <typename...Args> inline void MemorisationRecursion<REC>::clear() { memo_for_recursion<decldecay_t(*this),REC,Args...>[this].clear(); }
