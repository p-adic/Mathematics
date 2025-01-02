// c:/Users/user/Documents/Programming/Utility/Set/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1002390（setのMaximumLeq, MinimumGeq）
// https://yukicoder.me/submissions/1002389（mapのMaximumLeq）
// https://atcoder.jp/contests/abc385/submissions/61103563 (setのMaximumLeq, MinimumLeq, EraseBack, EraseFront)

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
// Set<T>は
// - unordered_set<T>()がwell-formedならばunordered_set<T>
// - そうでなくoperator<(declval<T>(),declval<T>())がwell-formedならばset<T>
// - そうでないならばvoid

template <typename SET , typename T> inline typename SET::const_iterator MaximumLeq( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MaximumLt( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MinimumGeq( const SET& S , const T& t );
template <typename SET , typename T> inline typename SET::const_iterator MinimumGt( const SET& S , const T& t );

template <typename SET , typename ITERATOR> inline void EraseBack( SET& S , ITERATOR& itr );
template <typename SET , typename ITERATOR> inline void EraseFront( SET& S , ITERATOR& itr );

template <typename SET , typename T> inline bool In( const SET& S , const T& t );
