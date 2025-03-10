// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/a_Body.hpp

#pragma once
#include "a.hpp"

inline MexSet::MexSet( const int& QuerySize ) : m_QuerySize( QuerySize ) , m_in( m_QuerySize + 1 ) , m_mex( 0 ) {}

inline void MexSet::insert( const int& i ) { assert( i >= 0 ); if( i < m_QuerySize ){ m_in[i] = true; while( m_in[m_mex] ){ m_mex++; } } }
inline const int& MexSet::mex() const noexcept { return m_mex; }
