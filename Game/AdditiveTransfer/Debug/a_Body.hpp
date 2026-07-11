// c:/Users/user/Documents/Programming/Mathematics/Game/AdditiveTransfer/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../SetTheory/Mex/Debug/a_Body.hpp"
#include "../../../Utility/Set/Map/a_Body.hpp"

template <typename AEdge , typename T>
const int& AdditiveTransferGrundyNumber( AEdge& aedge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<AEdge,const T&> );
  static Map<T,int> g{};
  static bool init = true;

  if( init ){

    DERR( "AdditiveTransferGrundyNumberをデバッグモードで実行します。" );
    DERR( "デバッグ出力以外に変更点はありません。" );
    init = false;

  }

  if( reset ){

    DERR( "AdditiveTransferGrundyNumberを初期化しました。" );
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& next = aedge( t );
  MexSet S{ int( next.size() ) };

  for( auto&& a : next ){

    int temp = 0;

    for( auto&& u : a ){

      temp ^= GrundyNumber( aedge , u );

    }

    S.insert( temp );
    
  }

  DERR( "AdditiveTransferGrundyNumber:" , t , "->" , S.mex() );
  return g[t] = S.mex();

}



