// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
T CoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , ll i )
{

  int f_size = f.size();

  if( f_size > i + 1 ){

    f.resize( f_size = i + 1 );

  }
  
  f.Reduce();
  f_size = f.size();

  if( f_size == 0 ){

    return move( f[0] );
    
  }
  
  int g_size = g.size();

  if( g_size > i + 1 ){

    g.resize( g_size = i + 1 );

  }

  g.Reduce();
  g_size = g.size();

  for( int d = 0 ; d < g_size ; d++ ){

    if( g[d] == 0 ){

      assert( d >= f_size || f[d] == 0 );

    } else {

      if( d > 0 ){

        Polynomial<T> f_new{};
        f_size < d ? f_size = 0 : f_size -= d;
        
        for( int e = 0 ; e < f_size ; e++ ){

          f_new[e] = move( f[e+d] );

        }

        f = move( f_new );
        Polynomial<T> g_new{};
        g_size -= d;
        
        for( int e = 0 ; e < g_size ; e++ ){

          g_new[e] = move( g[e+d] );

        }

        g = move( g_new );

      }
      
      break;

    }

  }
  
  const Polynomial<T> f_div = f / g;
  f -= f_div * g;
  f.Reduce();
  f_size = f.size();
  assert( f_size <= g_size );
  T answer = i < f_size ? f_div[i] : f.c_zero();

  while( i > 0 ){

    Polynomial<T> g_sym{};

    for( int d = 0 ; d < g_size ; d++ ){

      ( d & 1 ) == 0 ? g_sym[d] += g[d] : g_sym[d] -= g[d];

    }

    f *= g_sym;
    g *= g_sym;

    if( i == 1 ){

      break;
      
    }
    
    const int c = i & 1;
    i >>= 1;
    f_size = min( ll( ( f.size() + ( c ^ 1 ) ) >> 1 ) , i + 1 );
    Polynomial<T> f_new{};

    for( int d = 0 ; d < f_size ; d++ ){

      f_new[d] = move( f[( d << 1 ) | c] );

    }

    f = move( f_new );
    g_size = min( ll( g_size ) , i + 1 );
    Polynomial<T> g_new{};

    for( int d = 0 ; d < g_size ; d++ ){

      g_new[d] = move( g[d << 1] );

    }

    g = move( g_new );

  }

  return move( answer += f[i] / g[0] );

}
