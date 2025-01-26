// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , template <typename...> typename V , typename OPR> T LeftConnectiveProd( const V<T>& f , OPR opr ) { assert( !f.empty() ); auto itr = f.begin() , end = f.end(); T answer = *( itr++ ); while( itr != end ){ answer = opr( move( answer ) , *( itr++ ) ); } return answer; }
template <typename T , template <typename...> typename V> inline T Sum( const V<T>& f ) { return LeftConnectiveProd( f , []( T t0 , const T& t1 ){ return move( t0 += t1 ); } ); }
template <typename T , template <typename...> typename V> inline T Prod( const V<T>& f ) { return LeftConnectiveProd( f , []( T t0 , const T& t1 ){ return move( t0 *= t1 ); } ); }
template <typename T , template <typename...> typename V> inline T Max( const V<T>& f ) { return *max_element( f.begin() , f.end() ); }
template <typename T , template <typename...> typename V> inline T Min( const V<T>& f ) { return *min_element( f.begin() , f.end() ); }

template <typename T , typename U> inline T SetMax( T& n , const U& m ) { return n < m ? n = m : n; }
template <typename T , typename U> inline T SetMin( T& n , const U& m ) { return n > m ? n = m : n; }

template <typename T , typename UINT>
T Power( T t , UINT exponent , T init )
{

  ( exponent & 1 ) == 1 ? init *= t : init;
  exponent >>= 1;

  while( exponent > 0 ){

    // オーバーフロー対策で先に（必要な時だけ）2乗する。
    t *= t;
    ( exponent & 1 ) == 1 ? init *= t : init;
    exponent >>= 1;
    
  }

  return move( init );

}

template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d ) { assert( l <= r ); const INT c = ( r - l ) / d; return ( c & 1 ) == 0 ? ( c + 1 ) * ( l + d * ( c >> 1 ) ) : ( ( c + 1 ) >> 1 ) * ( ( l << 1 ) + d * c ); }
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r ) { return ArithmeticProgressionSum( INT{} , r ); }

template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init ) { T rate_minus = rate - 1; return rate_minus == 0 ? init * ++exponent_max : ( Power( move( rate ) , move( ++exponent_max ) ) - 1 ) / move( rate_minus ) * init; }

template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init )
{

  const int size = init.size();
  assert( int( rate.size() ) == size && int( exponent_max.size() ) == size );
  T answer{};

  for( int i = 0 ; i < size ; i++ ){

    answer += GeometricProgressionSum( move( rate[i] ) , move( exponent_max[i] ) , init[i] );

  }

  return answer;

}
