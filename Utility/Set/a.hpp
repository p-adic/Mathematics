// c:/Users/user/Documents/Programming/Utility/Set/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1002390�iset��MaximumLeq, MinimumGeq�j
// https://yukicoder.me/submissions/1002389�imap��MaximumLeq�j
// https://atcoder.jp/contests/abc385/submissions/61103563 (set��MaximumLeq, MinimumLeq, EraseBack, EraseFront)

class is_ordered
{

private:
  is_ordered() = delete;
  template <typename T> static constexpr auto Check( const T& t ) -> decltype( t < t , true_type() );
  static constexpr false_type Check( ... );

public:
  template <typename T> static constexpr const bool value = is_same_v< decltype( Check( declval<T>() ) ) , true_type >;

};

#include "a_Alias.hpp"
// Set<T>��
// - unordered_set<T>()��well-formed�Ȃ��unordered_set<T>
// - �����łȂ�operator<(declval<T>(),declval<T>())��well-formed�Ȃ��set<T>
// - �����łȂ��Ȃ��void

template <typename SET , typename T> inline typename SET::const_iterator MaximumLeq( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MaximumLt( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MinimumGeq( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MinimumGt( const SET& S , const T& t );

template <typename SET , typename ITERATOR> inline void EraseBack( SET& S , ITERATOR& itr );
template <typename SET , typename ITERATOR> inline void EraseFront( SET& S , ITERATOR& itr );

template <typename SET , typename T> inline bool In( const SET& S , const T& t );
