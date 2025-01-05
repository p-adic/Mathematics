// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/DivideConquer/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , template <typename...> typename V , typename MONOID>
T DivideConquerMonoidalProd( MONOID M , V<T> f )
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

