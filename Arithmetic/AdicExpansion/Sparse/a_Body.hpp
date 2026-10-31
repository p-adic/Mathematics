// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/Sparse/a_Body.hpp

#pragma once
#include "a.hpp"

template <int M , typename INT>
void SparseAdicExpansion<M,INT>::Add( INT d , INT c )
{

  while( c != 0 ){

    auto& c_d = m_digit[d];
    c = ( c_d += c ) / M;
    c_d %= M;

    if( c_d == 0 ){

      m_digit.erase( d );

    }

    d++;

  }

  return;

}

template <int M , typename INT> inline const map<INT,INT>& SparseAdicExpansion<M,INT>::GetDigit() const noexcept { return m_digit; }

template <int M , typename INT> template <typename MODINT>
MODINT SparseAdicExpansion<M,INT>::GetValue() const
{

  MODINT answer{} , m{ M };

  for( auto& [d,c] : m_digit ){

    answer += Power( m , d ) * c;

  }
  
  return answer;

}

template <int M , typename INT> inline bool SparseAdicExpansion<M,INT>::operator==( const SparseAdicExpansion<M,INT>& n ) const noexcept { return comp( n ) == 0; }
template <int M , typename INT> inline bool SparseAdicExpansion<M,INT>::operator!=( const SparseAdicExpansion<M,INT>& n ) const noexcept { return !( *this == n ); }
template <int M , typename INT> inline bool SparseAdicExpansion<M,INT>::operator<=( const SparseAdicExpansion<M,INT>& n ) const noexcept { return 0 <= comp( n ); }
template <int M , typename INT> inline bool SparseAdicExpansion<M,INT>::operator<( const SparseAdicExpansion<M,INT>& n ) const noexcept { return 0 < comp( n ); }

template <int M , typename INT>
int SparseAdicExpansion<M,INT>::comp( const SparseAdicExpansion<M,INT>& n ) const noexcept
{

  // 現在走査中の桁情報
  INT c = 0 , d;
  auto itr0 = m_digit.rbegin() , end0 = m_digit.rend() , itr1 = n.m_digit.rbegin() , end1 = n.m_digit.rend();

  // abs( c ) > 1の時、これ以降の繰り下がりでも消えない桁が確定するので大小が確定する。
  while( abs( c ) <= 1 && itr0 != end0 && itr1 != end1 ){

    auto& [d0,c0] = *itr0;
    auto& [d1,c1] = *itr1;

    if( c == 0 ){

      c = ( d0 <= d1 ? c1 : 0 ) - ( d1 <= d0 ? c0 : 0 );

      if( c == 0 ){

        itr0++;
        itr1++;

      } else {

        d = c < 0 ? d0 : d1;

      }

    } else {

      if( --d != ( c < 0 ? d0 : d1 ) ){

        break;

      }

      c = ( d1 == d ? c1 : 0 ) - ( d0 == d ? c0 : 0 ) + ( c < 0 ? -M : M );

    }
    
  }

  // itr0かitr1のいずれかがendに達した場合。
  if( c == 0 ){

    c = ( itr1 == end1 ? 0 : itr1->second ) - ( itr0 == end0 ? 0 : itr0->second );

  }

  return c > 0 ? 1 : c < 0 ? -1 : 0;

}
