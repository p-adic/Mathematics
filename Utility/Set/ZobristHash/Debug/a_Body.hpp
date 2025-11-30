// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/ZobristHash/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Map/a_Body.hpp"

template <typename T> inline ZobristHashBody<T>::ZobristHashBody() : ZobristHashBody( GetRand( 1 , 1LL << 60 ) , GetRand( 1 , 1LL << 60 ) ) {}
template <typename T> inline ZobristHashBody<T>::ZobristHashBody( const ull& r , const ull& s ) : m_r( r ) , m_s( s )
{

  DERR( "ZobristHashをデバッグモードで実行します。" );
  DERR( "ハッシュ値がullでなくSet<T>型になることに注意してください。" );

}

template <typename...Args> inline ZobristHash::ZobristHash( Args&&... args ) : ZobristHashBody<ull>( args... ) {}
template <typename T> template <typename...Args> inline MemorisationZobristHash<T>::MemorisationZobristHash( Args&&... args ) : ZobristHashBody<T>( args... ) {}
template <typename T , int enum_T_inv(const T&)> template <typename...Args> inline EnumerationZobristHash<T,enum_T_inv>::EnumerationZobristHash( Args&&... args ) : ZobristHashBody<T>( args... ) {}


template <typename T> Set<T> ZobristHashBody<T>::Encode( const Set<T>& S )
{

  return S;

}

template <typename T> template <template <typename...> typename V> inline Set<T> ZobristHashBody<T>::Encode( const V<T>& S , const bool& non_overlapping ) { return non_overlapping ? NonOverlappingEncode( S ) : OverlappingEncode( S ); }

template <typename T> template <template <typename...> typename V> Set<T> ZobristHashBody<T>::OverlappingEncode( const V<T>& S )
{

  Set<T> answer{};

  for( auto& t : S ){

    answer.insert( t );

  }

  return answer;

}

template <typename T> template <template <typename...> typename V> Set<T> ZobristHashBody<T>::NonOverlappingEncode( const V<T>& S )
{

  Set<T> answer{};

  for( auto& t : S ){

    if( answer.count( t ) == 0 ){

      answer.insert( t );

    } else {

      answer.erase( t );

    }

  }

  return answer;
  
}

template <typename T> inline Set<T> ZobristHashBody<T>::SymmetricDifference( Set<T> code0 , const Set<T>& code1 )
{

  for( auto& t : code1 ){

    if( code0.count( t ) == 0 ){

      code0.insert( t );
      
    } else {

      code0.erase( t );

    }

  }
  
  return move( code0 );

}

template <typename T> inline Set<T> ZobristHashBody<T>::Add( Set<T>& S , Set<T> code , const T& t ) { assert( S == code ); S.insert( t ); code.insert( t ); return move( code ); }
template <typename T> inline Set<T> ZobristHashBody<T>::Erase( Set<T>& S , Set<T> code , const T& t ) { assert( S == code ); S.erase( t ); code.erase( t ); return move( code ); }
template <typename T> inline Set<T> ZobristHashBody<T>::AddErase( Set<T> code , const T& t ){ if( code.count( t ) == 0 ){ code.insert( t ); } else { code.erase( t ); } return move( code ); }

DEFINITION_OF_HASH_FOR_SET( unordered_set );
DEFINITION_OF_HASH_FOR_SET( set );
