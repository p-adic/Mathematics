// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Palindrome/Total/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Even/a_Body.hpp"

template <typename STR>
TotalPalindrome::TotalPalindrome( const STR& S ) : m_N( S.size() ) , m_d()
{

  if( m_N > 0 ){
    
    STR S_copy( ( m_N << 1 ) - 1 , S[0] );

    for( int i = 1 ; i < m_N ; i++ ){

      S_copy[i*2] = S[i];

    }

    m_d = Manacher( S_copy );

  }

}

inline bool TotalPalindrome::IsPalindrome( const int& l , const int& r ) const noexcept { assert( 0 <= l && l <= r && r < m_N ); return r - l <= m_d[l+r]; }

inline ll TotalPalindrome::count() const noexcept { ll answer = 0; for( int i = 0 ; i < ( m_N << 1 ) - 1 ; i++ ){ answer += ( m_d[i] + 2 - ( i & 1 ) ) >> 1; } return answer; }
