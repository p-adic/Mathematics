// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/IntervalSort/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename STR> inline LexicographicIntervalSort<STR>::LexicographicIntervalSort( const STR& S ) : m_p_S( &S ) , m_N( S.size() ) , m_sa( ManberMyers( S ) ) , m_cs( m_N + 1 ) { assert( m_N > 0 ); for( int i = 0 ; i < m_N ; i++ ){ m_cs[i+1] = m_cs[i] + ( m_N - m_sa[i] ); } }

template <typename STR> inline pair<int,int> LexicographicIntervalSort<STR>::Get( ll k ) const { return operator[]( move( k ) ); }

template <typename STR> pair<int,int> LexicographicIntervalSort<STR>::operator[]( ll k ) const
{

  assert( k <= m_N * ll( m_N + 1 ) / 2 );
  const STR& S = *m_p_S;
  int L = 0 , R = m_N , shift = -1;

  while( k > 0 ){

    shift++;
    int l = L - 1, r = R - 1;

    // shift+1•¶Žš–Úc‚Ì“Á’è
    while( l + 1 < r ){

      const int m = ( l + r ) >> 1;
      ( CountIntervals( L , m , shift ) >= k ? r : l ) = m;

    }

    auto& c = S.at( m_sa[r] + shift );
    l = r;

    // shift+1•¶Žš–Ú‚ªc‚Å‚ ‚é‹æŠÔ‚Ì‰E’[‚ð“Á’è
    while( l < R - 1 ){

      const int m = ( l + R ) >> 1 , i = m_sa[m] + shift;
      ( i < m_N && S[i] == c ? l : R ) = m;

    }

    R = l + 1;
    l = L - 1;

    // shift+1•¶Žš–Ú‚ªc‚Å‚ ‚é‹æŠÔ‚Ì¶’[‚ð“Á’è
    while( l + 1 < r ){

      const int m = ( l + r ) >> 1 , i = m_sa[m] + shift;
      ( i < m_N && S[i] == c ? r : l ) = m;

    }

    k -= CountIntervals( L , r - 1 , shift );
    assert( k >= 0 );
    L = r;
    k -= R - L;

  }

  vector<int> v( R - L );

  for( int i = L ; i < R ; i++ ){

    v[i - L] = m_sa[i];

  }

  sort( v.begin() , v.end() );
  L = v[R - L - 1 + k];
  R = L + shift;
  return {L,R};

}

template <typename STR> inline ll LexicographicIntervalSort<STR>::CountIntervals( const int& l , const int r , const int& shift ) const { assert( 0 <= l && l - 1 <= r && r < m_N ); return ( m_cs[r + 1] - m_cs[l] ) - ll( r - l + 1 ) * shift; }
