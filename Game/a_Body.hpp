// c:/Users/user/Documents/Programming/Mathematics/Game/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../SetTheory/Mex/a_Body.hpp"
#include "../Utility/Set/Map/a_Body.hpp"

template <typename Edge , typename T>
const bool& IsWinningState( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,bool> g{};

  if( reset ){

    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  bool b = false;

  for( auto&& u : edge( t ) ){

    if( ( b |= !IsWinningState( edge , u ) ) ){

      break;

    }

  }

  return ( g[t] = b );

}

template <typename Edge , typename T>
const int& GrundyNumber( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,int> g{};

  if( reset ){

    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& next = edge( t );
  MexSet S{ int( next.size() ) };

  for( auto&& u : next ){

    S.insert( GrundyNumber( edge , u ) );
    
  }

  return g[t] = S.mex();

}



