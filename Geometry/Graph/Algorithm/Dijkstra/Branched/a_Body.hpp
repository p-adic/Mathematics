// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Branched/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"
#include "../../../../../Algebra/Monoid/a_Body.hpp"
#include "../../../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../../../Utility/Set/a_Body.hpp"
#include "../../../../../Utility/Vector/a_Body.hpp"

template <typename GRAPH , typename U , typename COMM_SEMIGRP , typename T> inline AbstractBranchedDijkstra<GRAPH,U,COMM_SEMIGRP,T>::AbstractBranchedDijkstra( GRAPH& G , COMM_SEMIGRP M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( is_same_v<T,inner_t<GRAPH>> ); }
template <typename GRAPH , typename T> inline BranchedDijkstra<GRAPH,T>::BranchedDijkstra( GRAPH& G ,  const ll& infty ) : AbstractBranchedDijkstra<GRAPH,ll,AdditiveMonoid<>,T>( G , AdditiveMonoid<>() , infty ) {}

template <typename GRAPH , typename U , typename COMM_SEMIGRP , typename T> template <template <typename...> typename TUPLE , typename S>
vector<vector<Pair<U,S>>> AbstractBranchedDijkstra<GRAPH,U,COMM_SEMIGRP,T>::GetDistance( const vector<TUPLE<T,U,S>>& t_start , const int& length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , vector<Pair<U,S>>{} );
  vector<Set<S>> fixed( size );
  set<tuple<U,S,int>> vertex{};

  auto set = [&]( const int& i , const U& u , const S& s ){

    assert( u < infty );
    vertex <<= {u,s,i};
    auto& wi = weight[i];
    int L = wi.size() , l = -1;
    
    for( int j = 0 ; j < L ; j++ ){

      auto& [uij,sij] = wi[j];

       if( sij == s ){

         SetMin( uij  , u );
         l = j;
         break;

      }

    }

    if( l == -1 ){

      wi <<= {u,s};
      l = L++;

    }

    while( l > 0 && wi[l] < wi[l-1] ){

      swap( wi[l] , wi[l-1] );
      l--;

    }

    if( L > length ){

      pop( wi );

    }

  };

  for( auto& [t,u,s] : t_start ){

    auto&& i = m_G.Enumeration_inv( t );
    set( i , u , s );

  }
  
  while( ! vertex.empty() ){

    auto [ui,s,i] = pop_min( vertex );

    if( len( fixed[i] ) == length || In( s , fixed[i] ) ){

      continue;

    }
    
    fixed[i] <<= s;

    for( auto&& edge_ij : m_G.Edge( m_G.Enumeration( i ) ) ){

      auto&& j = m_G.Enumeration_inv( get<0>( edge_ij ) );
      
      if( len( fixed[j] ) < length && ! In( s , fixed[j] ) ){

        set( j , m_M.Product( ui , get<1>( edge_ij ) ) , s );

      }

    }

  }

  return weight;

}
