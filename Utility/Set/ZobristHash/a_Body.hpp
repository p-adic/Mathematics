// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/ZobristHash/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Map/a_Body.hpp"
#include "../../Random/a_Body.hpp"

template <typename T> inline ZobristHashBody<T>::ZobristHashBody() : ZobristHashBody( GetRand( 1 , 1LL << 60 ) * 2 - 1 , GetRand( 1 , 1LL << 60 ) ) {}
template <typename T> inline ZobristHashBody<T>::ZobristHashBody( const ull& r , const ull& s ) : m_r( r ) , m_s( s ) {}
template <typename...Args> inline ZobristHash::ZobristHash( Args&&... args ) : ZobristHashBody<ull>( args... ) {}
template <typename T> template <typename...Args> inline MemorisationZobristHash<T>::MemorisationZobristHash( Args&&... args ) : ZobristHashBody<T>( args... ) {}
template <typename T , int enum_T_inv(const T&)> template <typename...Args> inline EnumerationZobristHash<T,enum_T_inv>::EnumerationZobristHash( Args&&... args ) : ZobristHashBody<T>( args... ) {}


template <typename T> ull ZobristHashBody<T>::Encode( const Set<T>& S )
{

  ull answer = 0;

  for( auto& t : S ){

    answer ^= Hash( t );

  }

  return answer;

}

template <typename T> template <template <typename...> typename V> inline ull ZobristHashBody<T>::Encode( const V<T>& S , const bool& non_overlapping ) { return non_overlapping ? NonOverlappingEncode( S ) : OverlappingEncode( S ); }

template <typename T> template <template <typename...> typename V> ull ZobristHashBody<T>::OverlappingEncode( const V<T>& S )
{

  Set<T> S_set{};

  for( auto& t : S ){

    S_set.insert( t );

  }

  return Encode( S_set );

}

template <typename T> template <template <typename...> typename V> ull ZobristHashBody<T>::NonOverlappingEncode( const V<T>& S )
{

  ull answer = 0;

  for( auto& t : S ){

    answer ^= Hash( t );

  }

  return answer;
  
}

template <typename T> inline ull ZobristHashBody<T>::SymmetricDifference( ull code0 , const ull& code1 ) { return move( code0 ^= code1 ); }
template <typename T> inline ull ZobristHashBody<T>::Add( Set<T>& S , ull code , const T& t ) { return move( S.count( t ) == 0 ? ( S.insert( t ) , code ^= Hash( t ) ) : code ); }
template <typename T> inline ull ZobristHashBody<T>::Erase( Set<T>& S , ull code , const T& t ) { return move( S.count( t ) == 0 ? code : ( S.erase( t ) , code ^= Hash( t ) ) ); }
template <typename T> inline ull ZobristHashBody<T>::AddErase( ull code , const T& t ){ return move( code ^= Hash( t ) ); }

inline ull ZobristHash::Hash( const ull& t ) { return ( t + 1 ) * this->m_r + this->m_s; }
template <typename T> inline ull MemorisationZobristHash<T>::Hash( const T& t ) { if( m_f.count( t ) == 0 ){ const ull size = m_f.size() + 1; return m_f[t] = size * this->m_r + this->m_s; } return m_f[t]; }
template <typename T , int enum_T_inv(const T&)> inline ull EnumerationZobristHash<T,enum_T_inv>::Hash( const T& t ) { return ( enum_T_inv( t ) + 1 ) * *this->m_r + this->m_s; }

DEFINITION_OF_HASH_FOR_SET( unordered_set );
DEFINITION_OF_HASH_FOR_SET( set );
