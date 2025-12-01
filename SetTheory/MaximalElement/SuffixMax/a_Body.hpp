// c:/Users/user/Documents/Programming/Mathematics/SetTheory/MaximalElement/SuffixMax/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , typename Y , typename RET> inline DynamicSuffixMax<INT,Y,RET>::DynamicSuffixMax( INT i_llim , Y y_ulim ) : m_i_llim( move( i_llim ) ) , m_i_max( m_i_llim ) , m_y_ulim( move( y_ulim ) ) , m_me( 1 , { m_i_llim , m_y_ulim } ) , m_ps( 1 ) {}

template <typename INT , typename Y , typename RET> void DynamicSuffixMax<INT,Y,RET>::insert( const INT& i , const Y& y )
{

  assert( m_i_max < i && y < m_y_ulim );
  m_i_max = i;

  while( !( y < m_me.back()[I] ) ){

    pop( m_me );
    pop( m_ps );

  }

  m_ps <<= m_ps.back() + RET{ i - m_me.back()[O] } * y;
  m_me <<= {i,y};

}

template <typename INT , typename Y , typename RET> inline void DynamicSuffixMax<INT,Y,RET>::clear() { m_ps.clear(); m_me.clear(); }

template <typename INT , typename Y , typename RET> inline T2<INT> DynamicSuffixMax<INT,Y,RET>::GetInterval( const INT& i ) { assert( m_i_llim < i && i <= m_i_max ); int l = 0 , size = m_me.size() , r = size; while( l < r - 1 ){ const int m = ( l + r ) >> 1; ( i < m_me[m][O] ? r : l ) = m; } if( m_me[l][O] == i ){ r = l; } assert( r < size ); return {l,r}; }
template <typename INT , typename Y , typename RET> inline Y DynamicSuffixMax<INT,Y,RET>::FinalSegmentMax( const INT& i ) { auto [l,r] = GetInterval( i ); return m_me[r][I]; }
template <typename INT , typename Y , typename RET> inline RET DynamicSuffixMax<INT,Y,RET>::FinalSegmentMaxSum( const INT& i ) { if( m_i_max < i ){ return Y{}; } auto [l,r] = GetInterval( i ); return m_ps.back() - m_ps[l] + RET{ l == r ? 1 : - ( i - 1 - m_me[l][O] ) } * m_me[r][I]; }
