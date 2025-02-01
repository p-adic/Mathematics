// c:/Users/user/Documents/Programming/Utility/Set/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename SET , typename T> inline typename SET::const_iterator MaximumLeq( const SET& S , const T& t ) { auto itr = S.upper_bound( t ); return itr == S.begin() ? S.end() : --itr; }
template <typename SET , typename T> inline typename SET::const_iterator MaximumLt( const SET& S , const T& t ) { auto itr = S.lower_bound( t ); return itr == S.begin() ? S.end() : --itr; }
template <typename SET , typename T> inline typename SET::const_iterator MinimumGeq( const SET& S , const T& t ) { return S.lower_bound( t ); }
template <typename SET , typename T> inline typename SET::const_iterator MinimumGt( const SET& S , const T& t ) { return S.upper_bound( t ); }

template <typename SET , typename ITERATOR> inline void EraseBack( SET& S , ITERATOR& itr ) { itr = S.erase( itr ); }
template <typename SET , typename ITERATOR> inline void EraseFront( SET& S , ITERATOR& itr ) { itr = S.erase( itr ); itr == S.begin() ? itr = S.end() : --itr; }

template <template <typename...> typename SET , typename T , typename...Args> inline bool In( const SET<T,Args...>& S , const T& t ) { return S.count( t ) == 1; }

DEFINITION_OF_POP_FOR_SET( set<T> );
DEFINITION_OF_POP_FOR_SET( unordered_set<T> );
DEFINITION_OF_POP_FOR_SET( multiset<T> );
DEFINITION_OF_POP_FOR_SET( unordered_multiset<T> );

DEFINITION_OF_UNION_FOR_SET( set<T> );
DEFINITION_OF_UNION_FOR_SET( unordered_set<T> );
DEFINITION_OF_UNION_FOR_SET( multiset<T> );
DEFINITION_OF_UNION_FOR_SET( unordered_multiset<T> );
DEFINITION_OF_UNION_FOR_SET( vector<T> );
DEFINITION_OF_UNION_FOR_SET( list<T> );
