// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/MultipleLength/65536adic/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../../Mod/Function/Residue/Debug/a_Body.hpp"
#else
  #include "../../Mod/Function/Residue/a_Body.hpp"
#endif
#include "../../../Polynomial/FFT/Double/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"

template <int w> inline Int<w>::Int() noexcept : m_neg() , m_n() {}
template <int w> inline Int<w>::Int( const Int<w>& n ) noexcept : m_neg( n.m_neg ) , m_n( n.m_n ) {}
template <int w> inline Int<w>::Int( Int<w>&& n ) noexcept : m_neg( move( n.m_neg ) ) , m_n( move( n.m_n ) ) {}

template <int w>
Int<w>::Int( bool neg , const vector<bool>& n ) noexcept : m_neg( move( neg ) ) , m_n()
{

  const int L = n.size();
  m_n.resize( ( L + w - 1 ) / w );
  int q = 0 , r = 0;

  for( int e = 0 ; e < L ; e++ ){

    m_n[q] |= n[e] << r;

    if( ++r == w ){

      r = 0;
      q++;

    }

  }

  RemoveRedundantZero();

}

template <int w> template <typename T> Int<w>::Int( T n ) noexcept : m_neg( n < 0 ) , m_n()
{

  if( m_neg ){

    n *= -1;

  }

  while( n != 0 ){

    m_n <<= n & ConstantsForInt<w>::mask;
    n >>= w;

  }

}

template <int w> inline Int<w>& Int<w>::operator=( Int<w> n ) noexcept { m_neg = move( n.m_neg ); m_n = move( n.m_n ); return *this; }

template <int w> void Int<w>::RemoveRedundantZero() noexcept { while( !m_n.empty() && m_n.back() == 0 ){ m_n.pop_back(); } if( m_n.empty() ){ m_neg = false; } }

template <int w> Int<w>& Int<w>::Reduce( const int& e0 ) noexcept
{

  RemoveRedundantZero();
  
  if( !m_n.empty() && m_n.back() < 0 ){

    m_neg = !m_neg;

    for( auto& d : m_n ){

      d *= -1;

    }

  }

  int L = m_n.size();

  for( int e = 0 ; e < L ; e++ ){

    int t = m_n[e] >> w;
    m_n[e] &= ConstantsForInt<w>::mask;

    if( t == 0 ){

      if( e >= e0 ){

        break;

      }

    } else {

      if( e == L - 1 ){

        m_n <<= move( t );
        L++;

      } else {

        m_n[e+1] += t;

      }

    }

  }

  RemoveRedundantZero();
  return *this;

}

template <int w> inline Int<w>& Int<w>::AbsPlus( const vector<int>& n , const bool& neg ) noexcept { DEFINITION_OF_ENTRYWISE_ACTION_FOR_INT( n , for( int e = L0 ; e < L1 ; e++ ){ m_n <<= 0; } , neg ? m_n[e] -= n[e] : m_n[e] += n[e] , L1 - 1 ); }

template <int w> inline Int<w>& Int<w>::operator+=( const Int<w>& n ) noexcept { return  AbsPlus( n.m_n , m_neg != n.m_neg ); }
template <int w> inline Int<w>& Int<w>::operator-=( const Int<w>& n ) noexcept { return  AbsPlus( n.m_n , m_neg == n.m_neg ); }

template <int w>
Int<w>& Int<w>::operator*=( const Int<w>& n )
{

  assert( int( m_n.size() + n.m_n.size() ) <= 1 << ( 52 - w * 2 ) );
  m_neg ^= n.m_neg;
  auto f = Convolution( m_n , n.m_n );
  m_n = {0};

  for( auto& d : f ){

    m_n.back() += d & ConstantsForInt<w>::mask;
    m_n <<= d >> w;

  }

  return Reduce( int( m_n.size() ) - 1 );

}

template <int w>
Int<w> Int<w>::LongDivision( const Int<w>& n )
{

  vector<bool> n0 = bit() , n1 = n.bit();
  const int L0 = n0.size() , L1 = n1.size();
  assert( L1 > 0 );
  vector<bool> q( max( 0 , L0 - L1 + 1 ) );    

  if( L0 >= L1 ){

    int rest = 0;
    
    for( int e0 = L0 - L1 ; e0 >= 0 ; e0-- ){

      ( rest <<= 1 ) |= n0.back();
      n0.pop_back();
      q[e0] = rest > 0;

      if( rest == 1 ){
      
        for( int e1 = L1 - 2 ; e1 >= 0 ; e1-- ){

          if( n0[e0+e1] != n1[e1] ){

            q[e0] = n0[e0+e1] > n1[e1];
            break;
          
          }

        }

      }

      if( q[e0] ){

        int up = 0;

        for( int e1 = 0 ; e1 <= L1 - 2 ; e1++ ){

          up += n0[e0+e1] - n1[e1];
          n0[e0+e1] = up & 1;
          up >>= 1;
          assert( -1 <= up && up <= 0 );

        }

        up += rest - n1[L1-1];
        rest = up & 1;
        up >>= 1;
        assert( up == 0 && 0 <= rest && rest <= 1 );

      }
    
    }

    if( rest > 0 ){

      n0 <<= rest;
    
    }

  }

  Int<w> answer{ m_neg != n.m_neg , q };
  *this = Int<w>{ move( m_neg ) , n0 };

  if( m_neg ){

    if( n.m_neg ){

      *this -= n;
      ++answer;

    } else {

      *this += n;
      --answer;
      
    }

  }

  assert( !m_neg );
  return answer;

}

template <int w> inline Int<w>& Int<w>::operator/=( const Int<w>& n ) { return *this = LongDivision( n ); }
template <int w> inline Int<w>& Int<w>::operator%=( const Int<w>& n ) { LongDivision( n ); return *this; }

template <int w>
Int<w>& Int<w>::operator<<=( int n )
{

  const int d = n % w , L = m_n.size();
  n /= w;

  for( int e = 0 ; e < n ; e++ ){

    m_n <<= 0;

  }

  for( int e = L - 1 ; e >= 0 ; e-- ){

    m_n[e+n] = move( m_n[e] <<= d );

  }

  for( int e = 0 ; e < n ; e++ ){

    m_n[e] = 0;

  }
  
  return RemoveRedundantZero();

}

template <int w>
Int<w>& Int<w>::operator>>=( int n )
{

  const int d = n % w , L = m_n.size() , m = ( 1 << d ) - 1;
  n /= w;
  m_n <<= 0;

  for( int e = n ; e < L ; e++ ){

    m_n[e-n] = ( ( m_n[e+1] & m ) << ( w - d ) ) | ( m_n[e] >> d );

  }

  for( int e = n ; e >= 0 ; e-- ){

    m_n.pop_back();

  }
  
  return RemoveRedundantZero();

}

template <int w> inline Int<w>& Int<w>::operator^=( const Int<w>& n ) noexcept { DEFINITION_OF_ENTRYWISE_ACTION_FOR_INT( n.m_n , for( int e = L0 ; e < L1 ; e++ ){ m_n <<= 0; } , m_n[e] ^= n.m_n[e] , -1 ); }
template <int w> inline Int<w>& Int<w>::operator&=( const Int<w>& n ) noexcept { DEFINITION_OF_ENTRYWISE_ACTION_FOR_INT( n.m_n , for( int e = L0 ; e > L1 ; e-- ){ m_n.pop_back(); } SetMin( L1 , L0 ) , m_n[e] &= n.m_n[e] , -1 ); }
template <int w> inline Int<w>& Int<w>::operator|=( const Int<w>& n ) noexcept { DEFINITION_OF_ENTRYWISE_ACTION_FOR_INT( n.m_n , for( int e = L0 ; e < L1 ; e++ ){ m_n <<= 0; } , m_n[e] |= n.m_n[e] , -1 ); }

template <int w> inline Int<w>& Int<w>::operator++() noexcept { return *this += 1; }
template <int w> inline Int<w> Int<w>::operator++( int ) noexcept { Int<w> n{ *this }; operator++(); return n; }
template <int w> inline Int<w>& Int<w>::operator--() noexcept { return *this -= 1; }
template <int w> inline Int<w> Int<w>::operator--( int ) noexcept { Int<w> n{ *this }; operator--(); return n; }

template <int w>
int Int<w>::AbsComp( const vector<int>& n ) const noexcept
{

  const int L0 = m_n.size() , L1 = n.size();

  if( L0 != L1 ){

    return L0 < L1 ? 1 : -1;

  }

  for( int e = L0 - 1 ; e >= 0 ; e-- ){

    if( m_n[e] != n[e] ){

      return m_n[e] < n[e] ? 1 : -1;

    }

  }

  return 0;
    
}

template <int w> inline int Int<w>::Comp( const Int<w>& n ) const noexcept { return m_neg == n.m_neg ? AbsComp( n.m_n ) * ( m_neg ? -1 : 1 ) : m_neg ? 1 : -1; }

DEFINITION_OF_COMPARISON_FOR_INT( == );
DEFINITION_OF_COMPARISON_FOR_INT( != );
DEFINITION_OF_COMPARISON_FOR_INT( < );
DEFINITION_OF_COMPARISON_FOR_INT( <= );
DEFINITION_OF_COMPARISON_FOR_INT( > );
DEFINITION_OF_COMPARISON_FOR_INT( >= );

DEFINITION_OF_ARITHMETIC_FOR_INT( + , noexcept );
DEFINITION_OF_ARITHMETIC_FOR_INT( - , noexcept );
DEFINITION_OF_ARITHMETIC_FOR_INT( * , );
DEFINITION_OF_ARITHMETIC_FOR_INT( / , );
DEFINITION_OF_ARITHMETIC_FOR_INT( % , );
DEFINITION_OF_ARITHMETIC_FOR_INT( ^ , noexcept );
DEFINITION_OF_ARITHMETIC_FOR_INT( & , noexcept );
DEFINITION_OF_ARITHMETIC_FOR_INT( | , noexcept );

template <int w> inline Int<w> Int<w>::operator<<( int n ) const { return move( Int<w>( *this ) <<= move( n ) ); }
template <int w> inline Int<w> Int<w>::operator>>( int n ) const { return move( Int<w>( *this ) >>= move( n ) ); }

template <int w> inline Int<w> Int<w>::operator-() const noexcept { Int<w> n{ *this }; if( !m_n.empty() ){ n.m_neg = !n.m_neg; } return n; }

template <int w> inline void Int<w>::swap( Int<w>& n ) noexcept { std::swap( m_neg , n.m_neg ); std::swap( m_n , n.m_n ); }

template <int w>
ll Int<w>::Get() const
{

  const int L = m_n.size();
  assert( L * w <= 64 );
  ll a = 0;

  for( int e = 0 ; e < L ; e++ ){

    a |= ll{ m_n[e] } << ( e * w );

  }

  if( m_neg ){

    a *= -1;

  }

  return a;

}

template <int w>
vector<bool> Int<w>::bit() const
{

  const int L = m_n.size();
  vector<bool> a( L * w );

  for( int e = 0 ; e < L ; e++ ){

    for( int f = 0 ; f < w ; f++ ){
      
      a[e*w+f] = ( ( m_n[e] >> f ) & 1 ) == 1;

    }

  }

  while( !a.empty() && !a.back() ){

    pop( a );
    
  }
  
  return a;

}

template <int w> inline void swap( Int<w>& n0 , Int<w>& n1 ) noexcept { n0.swap( n1 ); }
  
template <int w> inline string to_string( Int<w> n ) noexcept
{

  bool neg = n < 0;

  if( neg ){

    n *= -1;

  }

  static const Int<w> ten{ 10 };
  string a{};

  while( n != 0 ){

    auto q = n.LongDivision( ten );
    a <<= n.Get() + '0';
    n = move( q );

  }

  if( neg ){

    a <<= '-';

  }

  if( a.empty() ){

    a <<= '0';

  }

  Reverse( a );
  return a;

}

template <class Traits , int w> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Int<w>& n ) { ll m; is >> m; n = m; return is; }
template <class Traits , int w> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , Int<w> n ) { return os << to_string( move( n ) ); }

