// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline PowerMemoriser<INT>::PowerMemoriser( const INT& base ) : m_base( base ) , m_val( 1 ) {}

template <typename INT> inline INT PowerMemoriser<INT>::operator[]( const int& exponent ) noexcept { while( int( m_val.size() ) <= exponent ){ m_val.push_back( m_val.back() * m_base ); } return m_val[exponent]; }
