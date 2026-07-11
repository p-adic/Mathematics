// c:/Users/user/Documents/Programming/Mathematics/Game/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SetTheory/Mex/Debug/a_Body.hpp"
#include "../../Utility/Set/Map/a_Body.hpp"

template <typename Edge , typename T>
const bool& IsWinningState( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,bool> g{};
  static bool init = true;

  if( init ){

    DERR( "IsWinningStateをデバッグモードで実行します。" );
    DERR( "デバッグ出力以外に変更点はありません。" );
    init = false;

  }

  if( reset ){

    DERR( "IsWinningStateを初期化しました。" );
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  bool b = false;

  for( auto&& u : edge( t ) ){

    b |= !IsWinningState( edge , u );
    
  }

  DERR( "IsWinningState:" , t , "->" , b );
  return ( g[t] = b );

}

template <typename Edge , typename T>
const int& GrundyNumber( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,int> g{};

  static bool init = true;

  if( init ){

    DERR( "GrundyNumberをデバッグモードで実行します。" );
    DERR( "デバッグ出力以外に変更点はありません。" );
    init = false;

  }
  
  if( reset ){

    DERR( "GrundyNumberを初期化しました。" );
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

  DERR( "GrundyNumber:" , t , "->" , S.mex() );
  return g[t] = S.mex();

}
