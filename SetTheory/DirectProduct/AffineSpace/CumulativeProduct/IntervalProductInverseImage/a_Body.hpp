// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/IntervalProductInverseImage/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename GROUP , typename U>
ll CountIntervalProductInverseImage( GROUP M , const vector<U>& a , const U& u , const bool& right )
{

  ll answer = 0;
  const U& one = M.One();
  U prod = one;
  const int N = a.size();
  int L0 = 0 , L1 = 0;
  
  for( int R = 0 ; R < N ; R++ ){

    assert( !( a[R] < one ) );
    prod = right ? M.Product( move( prod ) , a[R] ) : M.Product( a[R] , prod );

    while( L0 <= R && u < prod ){

      prod = right ? M.Product( M.Inverse( a[L0] ) , prod ) : M.Product( move( prod ) , M.Inverse( a[L0] ) );
      L0++;

    }

    L1 = max( L0 , L1 );

    while( L1 <= R && a[L1] == one ){

      L1++;

    }

    answer += prod == u ? L1 - L0 : 0;

  }

  return answer;

}

template <typename GROUP , typename U>
vector<pair<int,int>> EnumerateIntervalProductInverseImage( GROUP M , const vector<U>& a , const U& u , const bool& right )
{

  vector<pair<int,int>> answer{};
  const U& one = M.One();
  U prod = one;
  const int N = a.size();
  int L = 0;
  
  for( int R = 0 ; R < N ; R++ ){

    assert( one < a[R] );
    prod = right ? M.Product( move( prod ) , a[R] ) : M.Product( a[R] , prod );

    while( L <= R && u < prod ){

      prod = right ? M.Product( M.Inverse( a[L] ) , prod ) : M.Product( move( prod ) , M.Inverse( a[L] ) );
      L++;

    }

    if( prod == u ){

      answer.push_back( { L  , R } );

    }

  }

  return answer;

}
