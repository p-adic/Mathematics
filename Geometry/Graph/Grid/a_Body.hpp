// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../Utility/StdStream/a_Body.hpp"

inline T2<int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const T2<int>& ij ) { auto& [i,j] = ij; return i * W + j; }

template <typename E> inline GridGraph<E>::GridGraph( E e ) : EnumerationGraph<T2<int>,T2<int>(&)(const int&),int(&)(const T2<int>&),E>( HW , EnumHW , EnumHW_inv , move( e ) ) { assert( HW >> 31 == 0 && H * W == HW ); }

vector<T2<int>> EdgeOnGrid( const T2<int>& v )
{

  vector<T2<int>> answer{};
  auto& [i,j] = v;

  if( grid[i][j] == walkable ){

    if( grid_edge_i_minus && i > 0 && grid[i-1][j] == walkable ){

      answer.push_back( {i-1,j} );

    }

    if( grid_edge_i_plus && i+1 < H && grid[i+1][j] == walkable ){

      answer.push_back( {i+1,j} );

    }

    if( grid_edge_j_minus && j > 0 && grid[i][j-1] == walkable ){

      answer.push_back( {i,j-1} );

    }

    if( grid_edge_j_plus && j+1 < W && grid[i][j+1] == walkable ){

      answer.push_back( {i,j+1} );

    }

  }

  return answer;

}

vector<pair<T2<int>,ll>> WEdgeOnGrid( const T2<int>& v ){

  vector<pair<T2<int>,ll>> answer{};
  auto& [i,j] = v;

  if( grid[i][j] == walkable ){
  
    if( grid_edge_i_minus && i>0 && grid[i-1][j] == walkable ){

      answer.push_back( {{i-1,j},1} );

    }

    if( grid_edge_i_plus && i+1 < H && grid[i+1][j] == walkable ){

      answer.push_back( {{i+1,j},1} );

    }

    if( grid_edge_j_minus && j>0 && grid[i][j-1] == walkable ){

      answer.push_back( {{i,j-1},1} );

    }

    if( grid_edge_i_plus && j+1 < W && grid[i][j+1] == walkable ){

      answer.push_back( {{i,j+1},1} );

    }

  }
  
  return answer;

}

inline void SetWallStringOnGrid(){ grid.resize( H ); for( int i = 0 ; i < H ; i++ ){ SET( grid[i] ); assert( int( grid[i].size() ) == W ); } }

inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h , const bool& xy_axis ) { return xy_axis ? i < k ? 1 : i > k ? 3 : j < h ? 0 : j > h ? 2 : -1 : i < k ? 2 : i > k ? 0 : j < h ? 1 : j > h ? 3 : -1; }
inline int DirectionNumberOnGrid( const T2<int>& v , const T2<int>& w , const bool& xy_axis ) { auto& [i,j] = v; auto& [k,h] = w; return DirectionNumberOnGrid( i , j , k , h ); }
inline int DirectionNumberOnGrid( const int& v , const int& w , const bool& xy_axis ) { return DirectionNumberOnGrid( EnumHW( v ) , EnumHW( w ) ); }
inline int DirectionNumberOnGrid( const char& c ) { return c == 'U' ? 0 : c == 'R' ? 1 : c == 'D' ? 2 : c == 'L' ? 3 : -1; }
inline int ReverseDirectionNumberOnGrid( const int& n ) { assert( 0 <= n && n < 4 ); return n ^ 2; }

inline T2<int> DirectionVectorOnGrid( const char& c , const bool& xy_axis ) { const int n = DirectionNumberOnGrid( c ); assert( n != -1 ); return T2<int>{ xy_axis ? n == 1 ? 1 : n == 3 ? -1 : 0 : n == 0 ? -1 : n == 2 ? 1 : 0 , xy_axis ? n == 0 ? 1 : n == 2 ? -1 : 0 : n == 1 ? 1 : n == 3 ? -1 : 0 }; }
