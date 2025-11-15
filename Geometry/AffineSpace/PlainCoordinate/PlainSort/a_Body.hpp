// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainCoordinate/PlainSort/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , template <typename...> typename PAIR> inline int Quadrant( const PAIR<INT,INT>& xy ) { auto& [x,y] = xy; return x < 0 ? y > 0 ? 2 : 3 : x > 0 ? y < 0 ? 4 : 1 : y > 0 ? 2 : y < 0 ? 4 : 0; }

template <typename INT , template <typename...> typename PAIR>
vector<int> ArgumentSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& centre )
{

  const int N = xy.size();
  auto& [cx,cy] = centre;
  using T = tuple<int,ll,INT,ll,int>;
  vector<T> coord( N );

  for( int i = 0 ; i < N ; i++ ){

    auto [x,y] = xy[i];
    x -= cx;
    y -=cy; 
    coord[i] = { Quadrant( pair{ x , y } ) , abs( x ) , abs( y ) , ll( x ) * x + ll( y ) * y , i };

  }

  auto order = [&]( const T& t0 , const T& t1 ){

    auto& [q0,x0,y0,r0,i0] = t0;
    auto& [q1,x1,y1,r1,i1] = t1;

    if( q0 != q1 ){

      return q0 < q1;

    }

    if( q0 == 0 ){

      return false;

    }

    ll d0 , d1;
    if( ( q0 & 1 ) == 1 ){

      d0 = y0 * x1;
      d1 = x0 * y1;

    } else {

      d0 = x0 * y1;
      d1 = y0 * x1;

    }

    return tuple{ d0 , r0 , i0 } < tuple{ d1 , r1 , i1 };
    
  };
  
  sort( coord.begin() , coord.end() , order );
  vector<int> answer( N );

  for( int i = 0 ; i < N ; i++ ){

    answer[i] = get<4>( coord[i] );

  }

  return answer;
  
}

template <typename INT , template <typename...> typename PAIR>
void RecursiveDivisionBody( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& xy_mid , const INT& L , vector<int>& index )
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

      PlainSortBody( xy , PAIR<INT,INT>{ x_mid + ( ( px == 0 ? -L : L ) >> 1 ) , y_mid + ( ( py == 0 ? -L : L ) >> 1 )  } , L >> 1 , index_sub[px][py] );

      for( auto& i : index_sub[px][py] ){

  	index[num++] = i;

      }

      index_sub[px][py].clear();

    }

  }

  // ヒューリスティック用の乱択版
  // ((0,0),(0,1),(1,0),(1,1))のソート順に対応
  int rand = GetRand( 0 , 23 );
  list<PAIR<int,int>> rest = {{0,0},{0,1},{1,0},{1,1}};

  for( int b = 4 ; b > 0 ; b-- ){

    int r = rand % b; rand /= b;
    auto itr = rest.begin();

    while( r-- > 0 ){

      ++itr;

    }

    auto& [px,py] = *itr;
    PlainSortBody( xy , PAIR<INT,INT>{ x_mid + ( ( px == 0 ? -L : L ) >> 1 ) , y_mid + ( ( py == 0 ? -L : L ) >> 1 ) } , L >> 1 , index_sub[px][py] );

    for( auto& i : index_sub[px][py] ){

      index[num++] = i;

    }

    index_sub[px][py].clear();
    rest.erase( itr );

  }

  return;

}

template <typename INT , template <typename...> typename PAIR> inline vector<int> RecursiveDivisionSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& xy_mid , const INT& L ) { const int size = xy.size(); vector<int> index( size ); for( int i = 0 ; i < size ; i++ ){ index[i] = i; } RecursiveDivisionSortBody( xy , xy_mid , L , index ); return index; }
