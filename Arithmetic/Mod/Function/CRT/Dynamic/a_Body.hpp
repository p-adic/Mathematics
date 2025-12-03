// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/Dynamic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Residue/Quotient/a_Body.hpp"
#include "../../../Divisor/GCD/a_Body.hpp"

inline void DynamicGarner::push_back( int base , int res )
{

  assert( 0 <= res && res < base );

  if( m_len > 0 ){

    m_len++;
    return;

  }

  auto [a,b_prod] = Solve( base );
  const int gcd = GCD( base , b_prod );

  if( ( res -= a ) % gcd == 0 ){

    res = ModularQuotient( base , res , b_prod );

    if( res != -1 ){

      m_base.push_back( base /= gcd );
      m_coef.push_back( res %= base );
      return;

    }

  }

  m_len = 1;
  return;

}

inline void DynamicGarner::pop_back() { if( m_len > 0 ){ m_len--; } else { m_base.pop_back(); m_coef.pop_back(); } }

inline int DynamicGarner::Get( const int& mod ) const { return m_len > 0 ? -1 : int( Solve( mod ).first ); }

inline pair<int,int> DynamicGarner::Solve( const int& mod ) const { const int size = m_base.size(); ll a = 0 , b_prod = 1; for( int i = 0 ; i < size ; i++ ){ ( a += m_coef[i] * b_prod ) %= mod; ( b_prod *= m_base[i] ) %= mod; } return {move(a),move(b_prod)}; }
