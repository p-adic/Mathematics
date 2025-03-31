// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/MultiCoefficientEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , typename INT>
void MultiCoefficientEvaluation_Body( Polynomial<T> f , Polynomial<T> g , unordered_map<INT,T>& coeff , const INT& deg_max )
{

  assert( !coeff.empty() );
  int g_size = g.size();
  assert( f.size() <= g_size );

  if( g_size > deg_max + 1 ){

    g.resize( g_size = deg_max + 1 );

  }
  
  Polynomial<T> g_sym{};

  for( int d = 0 ; d < g_size ; d++ ){

    ( d & 1 ) == 0 ? g_sym[d] += g[d] : g_sym[d] -= g[d];

  }

  f *= g_sym;
  g *= g_sym;
  g_sym = g.zero();
  Polynomial<T> g_new{};

  for( int d = 0 ; d < g_size ; d++ ){

    g_new[d] = move( g[d << 1] );

  }

  g = move( g_new );
  g_new = g.zero();
  unordered_map<INT,T> coeff_even{};
  unordered_map<INT,T> coeff_odd{};
  INT deg_max_even = 0;
  INT deg_max_odd = 0;

  for( auto itr = coeff.begin() , end = coeff.end() ; itr != end ; itr++ ){

    INT d = itr->first >> 1;
    if( ( itr->first & 1 ) == 0 ){

      coeff_even[d];
      deg_max_even = max( deg_max_even , d );

    } else {

      coeff_odd[d];
      deg_max_odd = max( deg_max_odd , d );

    }

  }

  if( !coeff_even.empty() ){

    auto itr = coeff_even.begin();

    if( coeff_even.size() == 1 && itr->first == 0 ){

      itr->second = move( f[0] /= g[0] );

    } else {
	
      const int f_even_size = min( ll( ( f.size() + 1 ) >> 1 ) , deg_max_even + 1 );
      Polynomial<T> f_even{};

      for( int d = 0 ; d < f_even_size ; d++ ){

	f_even[d] = move( f[d << 1] );

      }

      if( !coeff_odd.empty() ){

	MultiCoefficientEvaluation_Body( move( f_even ) , g , coeff_even , deg_max_even );

      } else {

        f = g.zero();
	MultiCoefficientEvaluation_Body( move( f_even ) , move( g ) , coeff_even , deg_max_even );

      }

    }

    for( auto end = coeff_even.end() ; itr != end ; itr++ ){

      coeff[itr->first << 1] = move( itr->second );

    }

    coeff_even.clear();
      
  }

  if( !coeff_odd.empty() ){

    auto itr = coeff_odd.begin();

    if( coeff_odd.size() == 1 && itr->first == 0 ){

      itr->second = move( f[1] /= g[0] );

    } else {

      const int f_odd_size = min( ll( f.size() >> 1 ) , deg_max_odd + 1 );
      Polynomial<T> f_odd{};

      for( int d = 0 ; d < f_odd_size ; d++ ){

	f_odd[d] = move( f[( d << 1 ) | 1] );

      }

      f = g.zero();
      MultiCoefficientEvaluation_Body( move( f_odd ) , move( g ) , coeff_odd , deg_max_odd );

    }

    for( auto end = coeff_odd.end() ; itr != end ; itr++ ){

      coeff[( itr->first << 1 ) | 1] = move( itr->second );

    }

    coeff_odd.clear();

  }

  return;
  
}

template <typename T , typename INT>
void MultiCoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , unordered_map<INT,T>& coeff )
{

  if( coeff.empty() ){

    return;

  }

  INT deg_max = 0;

  for( auto& [d,c] : coeff ){

    deg_max = max( deg_max , d );

  }

  int f_size = f.size();

  if( f_size > deg_max + 1 ){

    f.resize( f_size = deg_max + 1 );

  }
  
  f.Reduce();
  f_size = f.size();

  if( f_size == 0 ){

    return;
    
  }

  int g_size = g.size();

  if( g_size > deg_max + 1 ){

    g.resize( g_size = deg_max + 1 );

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
  MultiCoefficientEvaluation_Body( move( f ) , move( g ) , coeff , deg_max );
  const int& f_div_size = f_div.size();

  if( f_div_size > 0 ){

    for( auto itr = coeff.begin() , end = coeff.end() ; itr != end ; itr++ ){

      if( itr->first < f_div_size ){
	
	itr->second += f_div[itr->first];

      }

    }

  }

  return;

}

