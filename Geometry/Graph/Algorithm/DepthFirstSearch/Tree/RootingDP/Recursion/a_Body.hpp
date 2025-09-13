// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/RootingDP/Recursion/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename TREE , typename F>
ret_t<F> RecursionRootingDP_Body( TREE& T , F& f , const int& i , vector<bool>& checked )
{

  using U = ret_t<F>;
  static_assert( is_invocable_r_v<U,F,vector<U>,int> );
  checked[i] = true;
  auto& ei = T.Edge( i );
  const int ei_size = ei.size();
  vector<U> temp{};

  for( int m = 0 ; m < ei_size ; m++ ){

    auto&& j = T.Vertex( ei[m] );

    if( checked[j] ){

      continue;
      
    }

    temp.push_back( RootingDP_Body( T , f , j , checked ) );

  }
  
  return f( move( temp ) , i );

}

template <typename TREE , typename F> inline ret_t<F> RecursionRootingDP( TREE& T , F& f , const int& root ) { vector<bool> checked( T.size() ); return RecursionRootingDP_Body( T , f , root , checked ); }

template <typename TREE , typename VAL , typename RIGHT_ACTION>
ret_t<VAL,int> BinaryRootingDP_Body( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& i , vector<bool>& checked )
{

  using U = ret_t<VAL,int>;
  static_assert( is_invocable_r_v<U,RIGHT_ACTION,U,U,int,int> );
  checked[i] = true;
  auto& ei = T.Edge( i );
  const int ei_size = ei.size();
  U answer = val( i );

  for( int m = 0 ; m < ei_size ; m++ ){

    auto&& j = T.Vertex( ei[m] );

    if( checked[j] ){

      continue;
      
    }

    answer = prod( move( answer ) , BinaryRootingDP_Body( T , val , prod , j , checked ) , i , j );

  }
  
  return answer;

}

template <typename TREE , typename VAL , typename RIGHT_ACTION> inline ret_t<VAL,int> BinaryRootingDP( TREE& T , VAL& val , RIGHT_ACTION& prod , const int& root ) { vector<bool> checked( T.size() ); return BinaryRootingDP_Body( T , val , prod , root , checked ); }
