// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFST , typename F>
ret_t<F> DepthFirstSearchOnTree<TREE>::RootingDP( DFST& dfst , F& f )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,vector<U>,int> );
  const int& V = dfst.size();
  vector<vector<U>> children_value( V );
  U temp;
  
  for( int n = 0 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n , true );
    const int& j = dfst.Parent( i );
    temp = f( move( children_value[i] ) , i );

    if( j != -1 ){

      children_value[j].push_back( move( temp ) );

    }

  }

  return temp;

}
  
template <typename DFST , typename MONOID , typename F , typename G>
vector<inner_t<MONOID>> DepthFirstSearchOnTree<TREE>::RerootingDP( DFST& dfst , MONOID M , F& f , G& g )
{

  using U = inner_t<MONOID>;
  static_assert( is_invocable_r_v<U,F,U,int> && is_invocable_r_v<U,G,U,bool,int,int> );
  
  if( ! m_set_children ){

    SetChildren();

  }
  
  const int& V = dfst.size();
  const U& e = M.Unit();

  // children_value[i][m]��i��m�Ԗڂ̎q�m�[�hj�܂ł̌v�Z�l��f�ł̑����i�[�B
  vector<vector<U>> children_value( V );
  // l_sum[i][m]��children_value[i][0],...,children_value[i][m-1]��
  // g�ł̑���M�Ɋւ���ς��i�[�B
  vector<vector<U>> l_sum( V );
  // r_sum[i][m]��children_value[i][m+1],...,children_value[i][size_i-1]��
  // g�ł̑���M�Ɋւ���ς��i�[�B
  vector<vector<U>> r_sum( V );
  
  for( int i = 0 ; i < V ; i++ ){

    children_value[i].resize( m_children[i].size() );

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
    
    const int& j = dsft.Parent( i );

    if( j != -1 ){
      
      children_value[j][dfst.ChildrenNumer( i )] = f( temp , i );

    }

    temp = e;
    r_sum[i].resize( size_i );

    for( int m = 1 ; m <= size_i ; m++ ){

      r_sum[i][size_i - m] = temp;
      temp = M.Product( g( children_value[i][size_i - m] , true , i , dfst.Children( i )[size_i - m] ) , temp );

    }

  }

  // l_sum[i][m]��children_value[i][0],...,children_value[i][m-1]��
  // g�ł̑���M�Ɋւ���ς��i�[���Ă������A����ɂ���ɐe�m�[�h�̊�^���ǉ�����B
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n );
    const int& j = dfst.Parent( i );
    const int& k = dfst.ChildrenNumber( i );
    const int size_i = r_sum[i].size();
    // children_value[j][0],...,children_value[j][k-1]��g�ł̑���M�Ɋւ���ς�
    // children_value[j][k+1],...,children_value[j][size_i-1]��g�ł̑���M�Ɋւ���ς�
    // M�Ɋւ���ς�f�ł̑��ii�����Ƃ��鎞��j�̊�^�j��g�ł̑��B
    const U rest_i = g( f( M.Product( l_sum[j][k] , r_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // l_sum[i][m]��rest_i�i����Ӗ�m_children[i][-1]�j��
      // children_value[i][0],...,children_value[i][m-1]��
      // g�ł̑���M�Ɋւ���ς��i�[�B
      l_sum[i][m] = M.Product( rest_i , l_sum[i][m] );

    }

  }

  vector<U> answer( V );

  for( int i = 0 ; i < V ; i++ ){

    // l_sum[i].back()�͐e�̊�^�i����Ӗ�children_value[i][-1]�j��
    // children_value[i][0],...,children_value[i][size_i-1]��
    // g�ł̑���M�Ɋւ���ρB
    answer[i] = f( l_sum[i].back() , i );

  }

  return answer;

}
