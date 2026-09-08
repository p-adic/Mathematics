// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/DynamicBitSet/a_Body.hpp

#pragma once
#include "a.hpp"

inline DynamicBitSet::DynamicBitSet( const int& size , const ull& S ) : m_size( size ) , m_d( ( size + 63 ) >> 6 ) , m_mask( ( size & 63 ) == 0 ? -1 : ( 1ULL << ( size & 63 ) ) - 1 ) , m_S( m_d ) { if( m_d > 0 ){ m_S[0] = S & m_mask; } }

inline void DynamicBitSet::Set( const int& i , const bool& b ) { if( Get( i ) != b ){ m_S[i>>6] ^= 1ULL << ( i & 63 ); } }
inline bool DynamicBitSet::Get( const int& i ) const { assert( 0 <= i && i < m_size ); return ( ( m_S[i>>6] >> ( i & 63 ) ) & 1 ) == 1; }

DEFINITION_OF_OPR_FOR_BITSET( & );
DEFINITION_OF_OPR_FOR_BITSET( | );
DEFINITION_OF_OPR_FOR_BITSET( ^ );
inline DynamicBitSet& DynamicBitSet::operator<<=( const int& i ) { if( i > 0 ){ const int di = i >> 6 , ri = i & 63; for( int d = m_d - 1 ; d > di ; d-- ){ m_S[d] = ( m_S[d-di] << ri ) | ( ri > 0 ? m_S[d-di-1] >> ( 64 - ri ) : 0 ); } if( di < m_d ){ m_S[di] = m_S[0] << ri; } for( int d = min( m_d , di ) - 1 ; d >= 0 ; d-- ){ m_S[d] = 0; } if( m_d > 0 ){ m_S[m_d-1] &= m_mask; } } return *this; }
inline DynamicBitSet& DynamicBitSet::operator>>=( const int& i ) { if( i > 0 ){ const int di = i >> 6 , ri = i & 63; m_S[m_d-1] &= ( 1ULL << ( m_size & 63 ) ) - 1; for( int d = 0 ; d < m_d - di - 1 ; d++ ){ m_S[d] = ( m_S[d+di] >> ri ) | ( ri > 0 ? m_S[d+di+1] << ( 64 - ri ) : 0 ); } if( di < m_d ){ m_S[m_d-di-1] = m_S[m_d-1] >> ri; } for( int d = max( 0 , m_d - di ) ; d < m_d ; d++ ){ m_S[d] = 0; } } return *this; }

inline DynamicBitSet DynamicBitSet::operator<<( const int& i ) const { return move( DynamicBitSet( *this ) <<= i ); }
inline DynamicBitSet DynamicBitSet::operator>>( const int& i ) const { return move( DynamicBitSet( *this ) >>= i ); }
inline DynamicBitSet DynamicBitSet::operator!() const { DynamicBitSet S{ *this }; for( int d = 0 ; d < m_d ; d++ ){ S.m_S[d] = !S.m_S[d]; } if( m_d > 0 ){ S.m_S[m_d-1] &= m_mask; } return S; }

inline int DynamicBitSet::Maximum() const { for( int d = m_d - 1 ; d >= 0 ; d-- ){ if( m_S[d] > 0 ){ return ( d << 6 ) | ( 63 - __builtin_clzll( m_S[d] ) ); } } return m_d; }
inline int DynamicBitSet::Minimum() const { for( int d = 0 ; d < m_d ; d++ ){ if( m_S[d] > 0 ){ return ( d << 6 ) | __builtin_ctzll( m_S[d] ); } } return m_d; }
