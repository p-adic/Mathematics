// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/Kruscal/MaximumDirectedForest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../../../Utility/Tuple/Wrap/a_Body.hpp"

#include "../../../../../../Utility/Vector/a_Body.hpp"

template <typename GRAPH , typename U , typename ABEL_GROUP , typename T> Tuple<vector<T2<T>>,vector<T>,U> AbstractMaximumDirectedSubforest( ABEL_GROUP M , GRAPH& G , const vector<U>& A )
{

  static_assert( is_same_v<U,inner_t<ABEL_GROUP>> && is_same_v<T,inner_t<GRAPH>> );
  const int N = A.size();
  vector<vector<tuple<int,U,int>>> de( N + 1 );
  vector<pair<int,int>> uv{};
  vector<U> w{};

  for( int i = 0 ; i < N ; i++ ){

    for( auto& p : G.Edge( G.Enumeration( i ) ) ){

      auto&& j = G.Enumeration_inv( G.Vertex( p ) );

      if( i > j ){

        w <<= M.Inverse( M.Sum( A[i] , A[j] ) );
        de[i] <<= {j,w.back(),len(uv)};
        uv <<= {i,j};

      }

    }

    w <<= M.Inverse( A[i] );
    de[N] <<= {i,w.back(),len(uv)};
    uv <<= {N,i};

  }
  
  Graph graph{ N + 1 , Get( de ) };
  auto [chosen_edge_num,cc_size] = Kruscal( graph , uv );
  vector<int> r{};
  vector<vector<int>> e( N );
  U sum = M.Zero();

  for( auto& m : chosen_edge_num ){

    auto& [i,j] = uv[m];

    if( i == N ){

      r <<= j;

    } else {

      e <<= {i,j};
      e <<= {j,i};
      
    }
    
    sum = M.Sum( move( sum ) , w[m] );

  }

  for( int i = 0 ; i < N ; i++ ){

    sum = M.Sum( move( sum ) , A[i] );

  }
  
  sum = M.Inverse( sum );
  vector<T2<T>> path{};
  vector<T> root( N );
  vector<bool> searched( N );

  for( auto& i : r ){

    root[i] = G.Enumeration( i );
    vector<int> dfs = {i};

    while( !dfs.empty() ){

      int j = pop( dfs );
      searched[j] = true;
      T t = G.Enumeration( j );

      for( auto& k : e[j] ){

        if( !searched[k] ){

          root[k] = root[i];
          dfs <<= k;
          path <<= {t,G.Enumeration(k)};

        }

      }

    }

  }

  return {path,root,sum};
  
}

template <typename GRAPH , typename U , typename T> inline Tuple<vector<T2<T>>,vector<T>,U> MaximumDirectedSubforest( GRAPH& G , const vector<U>& A ) { return AbstractMaximumDirectedSubforest( AdditiveGroup<U>() , G , A ); }
