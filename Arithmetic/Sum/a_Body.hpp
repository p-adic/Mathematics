// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Algebra/Monoid/a_Body.hpp"

template <typename T , template <typename...> typename V , typename MONOID>
T MonoidalProd( MONOID M , V<T> f )
{

  if( f.empty() ){

    f.push_back( M.One() );

  }

  auto end = f.end();

  while( f.size() > 1 ){

    auto itr = f.begin();

    while( itr != end ){

      auto& t = *itr;
      itr++;

      if( itr != end ){

        t = M.Product( move( t ) , *itr );
        itr = f.erase( itr );

      }

    }

  }

  return move( f.front() );

}

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

template <typename T , template <typename...> typename V> inline T Sum( V<T> f ) { return MonoidalProd( AdditiveMonoid<T>() , move( f ) ); }
template <typename T , template <typename...> typename V> inline T Prod( V<T> f , T unit ) { return MonoidalProd( MultiplicativeMonoid<T>( unit ) , move( f ) ); }

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
