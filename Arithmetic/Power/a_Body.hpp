// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> template <typename VEC> inline PowerMemoriser<INT>::PowerMemoriser( const VEC& base ) : m_base() , m_val() { for( auto& n : base ){ m_base.push_back( n ); m_val.push_back( { 1 } ); } }

template <typename INT> inline INT PowerMemoriser<INT>::Get( const int& i , const int& j ) noexcept { while( int( m_val[i].size() ) <= j ){ m_val[i].push_back( m_val[i].back() * m_base[i] ); } return m_val[i][j]; }
