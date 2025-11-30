// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/ZobristHash/a_Macro.hpp

#pragma once
#define DEFINITION_OF_HASH_FOR_SET( SET )                               \
  template <typename T> inline size_t hash<SET<T>>::operator()( const SET<T>& S ) const { static const ull r = GetRand( 1 , 1LL << 60 ) , s = GetRand( 1 , 1LL << 60 ); static const hash<T> h{}; size_t answer{}; for( auto& t : S ){ answer ^= ( h( t ) + 1 ) * r + s ; }  return answer; }

