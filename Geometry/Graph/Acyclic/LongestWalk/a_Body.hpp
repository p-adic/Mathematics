// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/LongestWalk/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../Utility/Vector/a_Body.hpp"

template <typename ACYCLIC_GRAPH , typename MONOID , typename T , typename U> pair<U,vector<T>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M , const vector<T>& t_starts , const vector<T>& t_finals , U external )
{

  static_assert( is_same_v<T,inner_t<ACYCLIC_GRAPH>> );
  static_assert( is_same_v<U,inner_t<MONOID>> );
  const int& size = G.size();
  const U& one = M.One();
  vector<T> top_sort = TopologicalSort( G );
  vector<U> dp( size , external );
  vector<int> prev( size , -1 );

  for( auto& v : t_starts ){

    auto&& i = G.Enumeration_inv( v );
    dp[i] = one;
    
  }

  for( auto& v : top_sort ){

    auto&& i = G.Enumeration_inv( v );

    if( dp[i] == external ){

      continue;

    }

    for( auto& [t,u] : G.Edge( v ) ){

      auto&& j = G.Enumeration_inv( t );
      auto nu = M.Product( dp[i] , u );

      if( dp[j] == external || dp[j] < nu ){

	dp[j] = nu;
	prev[j] = i;

      }

    }

  }

  int j = -1;

  for( auto& t : t_finals ){

    auto&& i = G.Enumeration_inv( t );

    if( dp[i] != external && ( j == -1 || dp[j] < dp[i] ) ){

      j = i;

    }
    
  }

  int end_num = j;
  vector<T> path{};

  while( j != -1 ){

    path <<= G.Enumeration( j );
    j = prev[j];

  }

  Reverse( path );
  return { move( end_num == -1 ? external : dp[end_num] ) , move( path ) };

}

template <typename ACYCLIC_GRAPH , typename MONOID , typename U , typename T> inline pair<U,vector<T>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M , U external ) { const int& size = G.size(); vector<T> t_starts( size ); for( int i = 0 ; i < size ; i++ ){ t_starts[i] = G.Enumeration( i ); } return GetLongestWalk( G , move( M ) , t_starts , t_starts , move( external ) ); }
