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

template <typename T , template <typename...> typename V> inline T Sum( V<T> f ) { return MonoidalProd( AdditiveMonoid<T>() , move( f ) ); }
template <typename T , template <typename...> typename V> inline T Prod( V<T> f , T unit ) { return MonoidalProd( MultiplicativeMonoid<T>( unit ) , move( f ) ); }

template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d ) { assert( l <= r ); const INT c = ( r - l ) / d; return ( c & 1 ) == 0 ? ( c + 1 ) * ( l + d * ( c >> 1 ) ) : ( ( c + 1 ) >> 1 ) * ( ( l << 1 ) + d * c ); }
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r ) { return ArithmeticProgressionSum( INT{} , r ); }
