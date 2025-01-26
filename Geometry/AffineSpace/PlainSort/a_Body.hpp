// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainSort/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
void PlainSortBody( const vector<pair<INT,INT>>& xy , const pair<INT,INT>& xy_mid , const INT& L , vector<int>& index )
{

  if( L <= 2 || index.size() <= 4 ){

    return;
    
  }
  
  auto& [x_mid,y_mid] = xy_mid;
  vector<int> index_sub[2][2]{};

  for( auto& i : index ){

    auto& [x,y] = xy[i];
    index_sub[ x < x_mid ? 0 : 1 ][ y < y_mid ? 0 : 1 ].push_back( i );

  }

  int num = 0;

  // 非乱択版
  for( int px = 0 ; px < 2 ; px++ ){

    for( int py = 0 ; py < 2 ; py++ ){

      PlainSortBody( xy , pair<INT,INT>{ x_mid + ( ( px == 0 ? -L : L ) >> 1 ) , y_mid + ( ( py == 0 ? -L : L ) >> 1 )  } , L >> 1 , index_sub[px][py] );

      for( auto& i : index_sub[px][py] ){

  	index[num++] = i;

      }

      index_sub[px][py].clear();

    }

  }

  // ヒューリスティック用の乱択版
  // ((0,0),(0,1),(1,0),(1,1))のソート順に対応
  int rand = GetRand( 0 , 23 );
  list<pair<int,int>> rest = {{0,0},{0,1},{1,0},{1,1}};

  for( int b = 4 ; b > 0 ; b-- ){

    int r = rand % b; rand /= b;
    auto itr = rest.begin();

    while( r-- > 0 ){

      ++itr;

    }

    auto& [px,py] = *itr;
    PlainSortBody( xy , pair<INT,INT>{ x_mid + ( ( px == 0 ? -L : L ) >> 1 ) , y_mid + ( ( py == 0 ? -L : L ) >> 1 ) } , L >> 1 , index_sub[px][py] );

    for( auto& i : index_sub[px][py] ){

      index[num++] = i;

    }

    index_sub[px][py].clear();
    rest.erase( itr );

  }

  return;

}

template <typename INT> inline vector<int> PlainSort( const vector<pair<INT,INT>>& xy , const pair<INT,INT>& xy_mid , const INT& L ) { const int size = xy.size(); vector<int> index( size ); for( int i = 0 ; i < size ; i++ ){ index[i] = i; } PlainSortBody( xy , xy_mid , L , index ); return index; }
