// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/Rerooting/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename DFST , typename MONOID , typename F , typename G>
vector<inner_t<MONOID>> RerootingDP( DFST& dfst , MONOID M , F f , G g )
{

  using U = inner_t<MONOID>;
  static_assert( is_invocable_r_v<U,F,U,int> && is_invocable_r_v<U,G,U,bool,int,int> );
  const int& V = dfst.size();
  const U& e = M.Unit();

  // children_value[i][m]にiのm番目の子ノードjまでの計算値のfでの像を格納。
  vector<vector<U>> children_value( V );
  // l_sum[i][m]にchildren_value[i][0],...,children_value[i][m-1]の
  // gでの像のMに関する積を格納。
  vector<vector<U>> l_sum( V );
  // r_sum[i][m]にchildren_value[i][m+1],...,children_value[i][size_i-1]の
  // gでの像のMに関する積を格納。
  vector<vector<U>> r_sum( V );
  
  for( int i = 0 ; i < V ; i++ ){

    children_value[i].resize( dfst.Children( i ).size() );

  }
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n , true );
    const int size_i = children_value[i].size();

    U temp = e;
    l_sum[i].reserve( size_i + 1 );
    l_sum[i].push_back( temp );
    
    for( int m = 0 ; m < size_i ; m++ ){

      l_sum[i].push_back( temp = M.Product( temp , g( children_value[i][m] , true , i , dfst.Children( i )[m] ) ) );

    }
    
    const int& j = dfst.Parent( i );

    if( j != -1 ){
      
      children_value[j][dfst.ChildrenNumber( i )] = f( temp , i );

    }

    temp = e;
    r_sum[i].resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      r_sum[i][size_i - m] = temp;
      temp = M.Product( g( children_value[i][size_i - m] , true , i , dfst.Children( i )[size_i - m] ) , temp );

    }

  }

  // l_sum[i][m]にchildren_value[i][0],...,children_value[i][m-1]の
  // gでの像のMに関する積を格納していたが、さらにこれに親ノードの寄与も追加する。
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n );
    const int& j = dfst.Parent( i );
    const int& k = dfst.ChildrenNumber( i );
    const int size_i = r_sum[i].size();
    // children_value[j][0],...,children_value[j][k-1]のgでの像のMに関する積と
    // children_value[j][k+1],...,children_value[j][size_i-1]のgでの像のMに関する積の
    // Mに関する積のfでの像（iを根とする時のjの寄与）のgでの像。
    const U rest_i = g( f( M.Product( l_sum[j][k] , r_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // l_sum[i][m]にrest_i（ある意味dfst.Children( i )[-1]）と
      // children_value[i][0],...,children_value[i][m-1]の
      // gでの像のMに関する積を格納。
      l_sum[i][m] = M.Product( rest_i , l_sum[i][m] );

    }

  }

  vector<U> answer( V );

  for( int i = 0 ; i < V ; i++ ){

    // l_sum[i].back()は親の寄与（ある意味children_value[i][-1]）と
    // children_value[i][0],...,children_value[i][size_i-1]の
    // gでの像のMに関する積。
    answer[i] = f( l_sum[i].back() , i );

  }

  return answer;

}
