// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/LinearSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Random/a_Body.hpp"
#include "../../Vector/a_Body.hpp"

template <int digit> inline LinearSearchMultiset<digit>::LinearSearchMultiset() noexcept : LinearSearchMultiset( GetRand( 1 , 1LL << 60 ) * 2 - 1 , GetRand( 1 , 1LL << 60 ) ) {}
template <int digit> inline LinearSearchMultiset<digit>::LinearSearchMultiset( ull r , ull s ) noexcept : m_amb( ( 1 << digit ) - 1 ) , m_r( move( r ) ) , m_s( move( s ) ) , m_S( 1 << digit ) { static_assert( 0 <= digit && digit < 30 ); }

template <int digit> inline void LinearSearchMultiset<digit>::clear() noexcept { for( auto& v : m_S ){ v.clear(); } }

template <int digit> inline void LinearSearchMultiset<digit>::insert( ull n ) noexcept { ( n *= m_r ) += m_s; m_S[(n>>16)&m_amb] <<= n; }
template <int digit> inline LinearSearchMultiset<digit>& LinearSearchMultiset<digit>::operator<<=( ull n ) noexcept { this->insert( move( n ) ); return *this; }

template <int digit> inline bool LinearSearchMultiset<digit>::find( ull n ) const noexcept { ( n *= m_r ) += m_s; for( auto& x : m_S[(n>>16)&m_amb] ){ if( x == n ){ return true; } } return false; }
template <int digit> inline int LinearSearchMultiset<digit>::count( ull n ) const noexcept { ( n *= m_r ) += m_s; int answer = 0; for( auto& x : m_S[(n>>16)&m_amb] ){ answer += x == n; } return answer; }
