// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/Chain/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline AscendingChainSemilattice<U>::AscendingChainSemilattice( int length ) : m_length( move( length ) ) {}
template <typename U> inline DescendingChainSemilattice<U>::DescendingChainSemilattice( int length ) : m_length( move( length ) ) {}

template <typename U> inline vector<U> AscendingChainSemilattice<U>::Product( vector<U> a0 , const vector<U>& a1 ) { const int size0 = a0.size(); for( auto& u : a1 ){ a0.push_back( u ); } auto begin = a0.begin(); inplace_merge( begin , begin + size0 , a0.end() ); if( size0 + int( a1.size() ) > m_length ){ a0.resize( m_length ); } return move( a0 ); }
template <typename U> inline vector<U> DescendingChainSemilattice<U>::Product( vector<U> a0 , const vector<U>& a1 ) { static auto comp = []( const U& u0 , const U& u1 ){ return u1 < u0; }; const int size0 = a0.size(); for( auto& u : a1 ){ a0.push_back( u ); } auto begin = a0.begin(); inplace_merge( begin , begin + size0 , a0.end() , comp ); if( size0 + int( a1.size() ) > m_length ){ a0.resize( m_length ); } return move( a0 ); }
