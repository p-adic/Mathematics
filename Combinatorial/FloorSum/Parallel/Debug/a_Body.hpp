// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/Parallel/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/BinarySearch/Debug/a_Body.hpp"
#include "../../../../Utility/Vector/a_Body.hpp"
#include "../../../../Utility/Set/Map/a_Body.hpp"

template <typename INT1 , typename INT2 , typename RET>
vector<RET> NumeratorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den , vector<RET> coeff )
{

  vector<INT2> cc{};
  Map<INT2,int> cc_inv{};

  for( auto& m : den ){

    assert( m > 0 );
    cc_inv[m];

    if( cc_inv.size() > cc.size() ){

      cc.push_back( m );

    }

  }

  Sort( cc );
  const int N = num.size() , M = den.size() , L = cc.size();

  for( int j = 0 ; j < L ; j++ ){

    cc_inv[cc[j]] = j;

  }

  int logL = 1;

  while( L > 1 << logL ){

    logL++;
    
  }

  vector<RET> a( N );

  if( coeff.empty() ){

    coeff.resize( M , 1 );

  }

  for( int j = 1 ; j < M ; j++ ){

    coeff[j] += coeff[j-1];

  }

  for( int i = 0 ; i < N ; i++ ){

    auto& n = num[i];
    assert( n >= 0 );
    // floor(n/d)<B <-> floor(n/B)<d
    // B_div + B log L in O(n / B + B log L) = O(sqrt(n log L))
    const int B = max( int( sqrt( n / logL ) ) , 1 ) , B_div = n / B;
    MAX_LEQ( j0 , 0 , L - 1 , cc[j0] , B_div );

    for( int j = 0 ; j <= j0 ; j++ ){

      a[i] += n / cc[j] * ( j > 0 ? coeff[j] - coeff[j-1] : coeff[j] );

    }
    
    ll v_div = B_div;

    for( int v = B - 1 ; v >= 1 ; v-- ){
      
      // floor(n/Si)=v <-> v<=n/Si<v+1 <-> n/(v+1)<Si<=n/v
      // <-> floor(n/(v+1))<Si<=floor(n/v)
      v_div = n / v;
      MAX_LEQ( j , j0 , L - 1 , j >= 0 ? cc[j] : -1 , v_div );
      a[i] += v * ( j0 >= 0 ? coeff[j] - coeff[j0] : coeff[j] );
      j0 = j;

    }

  }

  return a;

}

template <typename INT1 , typename INT2>
vector<ll> DenominatorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den )
{

  vector<INT2> cc{};
  Map<INT2,int> cc_inv{};

  for( auto& m : den ){

    assert( m > 0 );
    cc_inv[m];

    if( cc_inv.size() > cc.size() ){

      cc.push_back( m );

    }

  }

  Sort( cc );
  const int N = num.size() , M = den.size() , L = cc.size();

  for( int j = 0 ; j < L ; j++ ){

    cc_inv[cc[j]] = j;

  }

  int logL = 1;

  while( L > 1 << logL ){

    logL++;
    
  }

  vector<ll> a_cc( L ) , a_cc_dif( L + 2 );

  for( int i = 0 ; i < N ; i++ ){

    auto& n = num[i];
    assert( n >= 0 );
    // floor(n/d)<B <-> floor(n/B)<d
    // B_div + B log L in O(n / B + B log L) = O(sqrt(n log L))
    const int B = max( int( sqrt( n / logL ) ) , 1 ) , B_div = n / B;
    MAX_LEQ( j0 , 0 , L - 1 , cc[j0] , B_div );

    for( int j = 0 ; j <= j0 ; j++ ){

      a_cc[j] += n / cc[j];

    }
    
    ll v_div = B_div;

    for( int v = B - 1 ; v >= 1 ; v-- ){
      
      // floor(n/Si)=v <-> v<=n/Si<v+1 <-> n/(v+1)<Si<=n/v
      // <-> floor(n/(v+1))<Si<=floor(n/v)
      v_div = n / v;
      MAX_LEQ( j , j0 , L - 1 , j >= 0 ? cc[j] : -1 , v_div );
      a_cc_dif[j0+1] += v;
      a_cc_dif[j+1] -= v;
      j0 = j;

    }

  }

  for( int j = 0 ; j < L ; j++ ){

    a_cc[j] += a_cc_dif[j] += j > 0 ? a_cc_dif[j-1] : 0;

  }

  vector<ll> answer( M );

  for( int j = 0 ; j < M ; j++ ){

    answer[j] = a_cc[cc_inv[den[j]]];

  }

  return answer;

}

