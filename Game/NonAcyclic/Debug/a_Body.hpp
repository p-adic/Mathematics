// c:/Users/user/Documents/Programming/Mathematics/Game/NonAcyclic/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Vector/a_Body.hpp"

template <typename GRAPH>
vector<int> NonAcyclicGameGameState( GRAPH& G )
{

  DERR( "GameStateをデバッグモードで実行します。" );
  DERR( "デバッグ出力以外に変更点はありません。" );
  const int& N = G.size();
  vector<int> answer( N ) , deg( N ) , bfs{};
  vector e_inv( N , vector<int>() );
  
  for( int i = 0 ; i < N; i++ ){

    auto& ei = G.Edge( i );
    
    if( ( deg[i] = ei.size() ) == 0 ){

      answer[i] = -1;
      bfs <<= i;

    }

    for( auto& j : ei ){

      e_inv[j] <<= i;

    }
    
  }

  DERR( "初期値として状態" , bfs , "がP位置（必敗）判定されました。" );
  DERR( "" );

  while( !bfs.empty() ){

    int i = pop( bfs );
    assert( answer[i] != 0 );

    for( auto& j : e_inv[i] ){

      deg[j]--;

      if( answer[i] == -1 ){

        if( answer[j] == 0 ){

          answer[j] = 1;
          bfs <<= j;
          DERR( "状態" , j , "がN位置（必勝）判定されました。" );
          DERR( "e[" , j , "] =" , G.Edge( j ) );
          DERR( "" );

        }

      } else {

        if( answer[j] == 0 && deg[j] == 0 ){
          
          answer[j] = -1;
          bfs <<= j;
          DERR( "状態" , j , "がP位置（必敗）判定されました。" );
          DERR( "e[" , j , "] =" , G.Edge( j ) );
          DERR( "" );

        }

      }

    }

  }

  return answer;

}
