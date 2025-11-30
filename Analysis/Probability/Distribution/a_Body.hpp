// c:/Users/user/Documents/Programming/Mathematics/Analysis/Probability/Distribution/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT> inline Distribution<MODINT>::Distribution( vector<MODINT> val , vector<MODINT> freq ) : m_val( move( val ) ) , m_freq( move( freq ) ) { assert( m_val.size() == m_freq.size() ); }
template <typename MODINT> inline Distribution<MODINT>::Distribution( const Distribution<MODINT>& d ) : m_val( d.m_val ) , m_freq( d.m_freq ) {}

template <typename MODINT> inline Distribution<MODINT>& Distribution<MODINT>::operator+=( const Distribution<MODINT>& d ) { assert( m_freq == d.m_freq ); m_val += d.m_val; return *this; }
template <typename MODINT> inline Distribution<MODINT>& Distribution<MODINT>::operator-=( const Distribution<MODINT>& d ) { assert( m_freq == d.m_freq ); m_val -= d.m_val; return *this; }
template <typename MODINT> inline Distribution<MODINT>& Distribution<MODINT>::operator*=( const MODINT& c ) { m_val *= c; return *this; }
template <typename MODINT> inline Distribution<MODINT>& Distribution<MODINT>::operator/=( const MODINT& c ) { m_val /= c; return *this; }

template <typename MODINT> inline Distribution<MODINT> Distribution<MODINT>::operator+( const Distribution<MODINT>& d ) const { auto copy = *this; return move( copy += d ); }
template <typename MODINT> inline Distribution<MODINT> Distribution<MODINT>::operator-( const Distribution<MODINT>& d ) const { auto copy = *this; return move( copy -= d ); }
template <typename MODINT> inline Distribution<MODINT> Distribution<MODINT>::operator*( const MODINT& c ) const { auto copy = *this; return move( copy *= c ); }
template <typename MODINT> inline Distribution<MODINT> Distribution<MODINT>::operator/( const MODINT& c ) const { auto copy = *this; return move( copy /= c ); }

template <typename MODINT> template <typename INT> inline MODINT Distribution<MODINT>::E( const INT& exponent ) const { MODINT n{} , d{}; const int size = m_val.size(); for( int i = 0 ; i < size ; i++ ){ n += m_freq[i] * Power( m_val[i] , exponent ); d += m_freq[i]; } return n / d; }
template <typename MODINT> inline MODINT Distribution<MODINT>::V() const { return E( 2 ) - Power( E() , 2 ); }

template <typename MODINT> MODINT ExpectedSumSquare( const vector<Distribution<MODINT>>& d ) { MODINT E{} , E2_in{} , E2_out{}; for( auto& di : d ){ auto e = di.E(); E += e; E2_in += di.E( 2 ); E2_out += e * e; } return E2_in - E2_out + E * E; }
