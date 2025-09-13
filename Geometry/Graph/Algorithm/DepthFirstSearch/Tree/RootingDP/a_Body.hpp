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

  // children_value[i][m]‚Éi‚Ìm”Ô–Ú‚Ìqƒm[ƒhj‚Ü‚Å‚ÌŒvZ’l‚Ìf‚Å‚Ì‘œ‚ğŠi”[B
  vector<vector<U>> children_value( V );
  // l_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
  vector<vector<U>> l_sum( V );
  // r_sum[i][m]‚Échildren_value[i][m+1],...,children_value[i][size_i-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
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

  // l_sum[i][m]‚Échildren_value[i][0],...,children_value[i][m-1]‚Ì
  // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[‚µ‚Ä‚¢‚½‚ªA‚³‚ç‚É‚±‚ê‚Éeƒm[ƒh‚ÌŠñ—^‚à’Ç‰Á‚·‚éB
  for( int n = 1 ; n < V ; n++ ){
    
    const int& i = dfst.NodeNumber( n );
    const int& j = dfst.Parent( i );
    const int& k = dfst.ChildrenNumber( i );
    const int size_i = r_sum[i].size();
    // children_value[j][0],...,children_value[j][k-1]‚Ìg‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚Æ
    // children_value[j][k+1],...,children_value[j][size_i-1]‚Ìg‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚Ì
    // M‚ÉŠÖ‚·‚éÏ‚Ìf‚Å‚Ì‘œii‚ğª‚Æ‚·‚é‚Ìj‚ÌŠñ—^j‚Ìg‚Å‚Ì‘œB
    const U rest_i = g( f( M.Product( l_sum[j][k] , r_sum[j][k] ) , j ) , false , i , j );
    
    for( int m = 0 ; m <= size_i ; m++ ){

      // l_sum[i][m]‚Érest_ii‚ ‚éˆÓ–¡m_children[i][-1]j‚Æ
      // children_value[i][0],...,children_value[i][m-1]‚Ì
      // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏ‚ğŠi”[B
      l_sum[i][m] = M.Product( rest_i , l_sum[i][m] );

    }

  }

  vector<U> answer( V );

  for( int i = 0 ; i < V ; i++ ){

    // l_sum[i].back()‚Íe‚ÌŠñ—^i‚ ‚éˆÓ–¡children_value[i][-1]j‚Æ
    // children_value[i][0],...,children_value[i][size_i-1]‚Ì
    // g‚Å‚Ì‘œ‚ÌM‚ÉŠÖ‚·‚éÏB
    answer[i] = f( l_sum[i].back() , i );

  }

  return answer;

}
