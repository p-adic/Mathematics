// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Truncated/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/a_Body.hpp"
#include "../../../Utility/Set/Map/a_Body.hpp"

template <typename INT1 , typename INT2>
ll TruncatedPower( ll n , INT1 e , const INT2& bound )
{

  assert( n >= 0 && e >= 0 && bound >= 0 );

  if( e == 0 ){

    return 1;

  }

  if( n <= 1 ){

    return move( n );

  }

  if( e >= 63 ){

    return bound + 1;

  }

  ll answer = ( e & 1 ) == 0 ? 1 : n;
  e >>= 1;

  while( e > 0 ){

    if( n <= bound / n ){

      n *= n;

    } else {

      return bound + 1;

    }

    if( ( e & 1 ) == 1 ){

      if( answer <= bound / n ){

        answer *= n;

      } else {

        return bound + 1;

      }

    }

    e >>= 1;

  }

  return answer;

}

template <typename INT1 , typename INT2>
INT2 RoundDownRoot( const INT1& e , const INT2& n )
{

  assert( e >= 1 && n >= 0 );

  if( n == 0 || e == 1 ){

    return n;

  }

  INT2 l = 1 , r = n;

  while( l < r - 1 ){

    INT2 m = ( l + r ) >> 1;
    ( TruncatedPower( m , e , n ) <= n ? l : r ) = m;

  }

  return l;

}

template <typename INT1 , typename INT2> inline bool IsThPower( const INT1& e , const INT2& n ) { return Power( RoundDownRoot( e , n ) , e ) == n; }

template <typename INT1 , typename INT2>
bool IsThPowerMemorisation( const INT1& e , const INT2& n )
{

  assert( e > 0 && n >= 0 );
  
  if( e == 1 || n <= 1 ){

    return true;

  }

  // ll‚ÌãŒÀ‚Í2^63-1‚Å‚ ‚é‚±‚Æ‚É’ˆÓB
  if( 63 <= e ){

    return false;

  }

  Map<int,tuple<int,ll,Set<ll>>> power{};
  auto& [i_e,v_e,S_e] = power[e];

  while( v_e < n ){

    S_e.insert( v_e = Power<ll>( ++i_e , e ) );

  }

  return S_e.count( n ) == 1;

}

template <typename MONOID , typename U>
int DiscreteLogarithm( MONOID M , const U& u , const U& v , const int& n )
{

  static_assert( is_same_v<inner_t<MONOID>,U> );
  
  if( n < 0 ){

    return -1;

  }
  
  if( n == 0 ){

    return v == M.One() ? 0 : -1;

  }
  
  int sqrt_n = int( sqrt( n ) );
  vector<U> u_power( sqrt_n + 1 , M.One() );

  for( int i = 1 ; i <= sqrt_n ; i++ ){

    u_power[i] = M.Product( u_power[i-1] , u );

  }

  // u_power_v[w]‚Éu^i v = w‚ð–ž‚½‚·0<=i<sqrt_n‚ð¬‚³‚¢‡‚ÉŠi”[‚·‚éB
  Map<U,vector<int>> u_power_v{};
  
  for( int i = 0 ; i < sqrt_n ; i++ ){

    u_power_v[M.Product( u_power[i] , v )].push_back( i );

  }

  U curr = u_power[0];

  for( int j = 0 ; j <= n ; j += sqrt_n ){

    U next = curr * u_power[sqrt_n];
    
    if( u_power_v.count( next ) == 1 ){

      auto& index = u_power_v[next];

      if( index.size() == 1 ){

        const int i = sqrt_n - u_power_v[next][0];
        
        if( M.Product( u_power[i] , curr ) == v ){

          return ( j += i ) <= n ? j : -1;

        }

        continue;

      }

      // u^{index[0]} v = u^{index[1]} v = u^{j+sqrt_n}‚È‚Ì‚Å
      // u^{j+sqrt_n} = u^{j+sqrt_n+index[1]-index[0]}‚Æ‚È‚éB
      // ]‚Á‚Äu^{j+i} = v‚ð–ž‚½‚·i‚Ì’Tõ‚Í0<=i<i_ulim‚Ì”ÍˆÍ‚Ì‚Ý‚Å\•ª‚Å‚ ‚éB
      const int i_ulim = sqrt_n + index[1] - index[0];

      for( int i = 0 ; i < i_ulim ; i++ ){

        if( M.Product( i <= sqrt_n ? u_power[i] : M.Product( u_power[sqrt_n] , u_power[i - sqrt_n] ) , curr ) == v ){

          return ( j += i ) <= n ? j : -1;

        }

      }

      return -1;

    }

    curr = move( next );

  }

  return -1;

}
