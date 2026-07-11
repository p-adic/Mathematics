// c:/Users/user/Documents/Programming/Mathematics/Game/FinalStateInvariant/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Set/Map/a_Body.hpp"

template <typename Edge , typename T , typename INVARIANT>
const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset )
{


  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,int> g{};
  static bool init = true;

  if( init ){

    DERR( "WinningConstantsOfをデバッグモードで実行します。" );
    DERR( "デバッグ出力以外に変更点はありません。" );
    init = false;

  }

  if( reset ){

    DERR( "WinningConstantsOfを初期化しました。" );
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& e = edge( t );
  int c = e.empty() ? ( 1 << invariant( t ) ) : 0;

  for( auto&& u : e ){

    int temp = WinningConstantsOf( edge , u , invariant );

    for( int d = 0 ; d <= 1 ; d++ ){

      c |= ( ( temp >> ( 1 ^ d ) ) & 1 ) << d;

    }

  }

  DERR( "WinningConstantsOf:" , t , "->" , c );
  return g[t] = c;

}
