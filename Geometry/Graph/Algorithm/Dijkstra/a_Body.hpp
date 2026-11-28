// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename GRAPH , typename U , typename COMM_MONOID , typename T> inline AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( is_same_v<T,inner_t<GRAPH>> ); }
template <typename GRAPH , typename T> inline Dijkstra<GRAPH,T>::Dijkstra( GRAPH& G , const ll& infty ) : AbstractDijkstra<GRAPH,ll,AdditiveMonoid<>,T>( G , AdditiveMonoid<>() , infty ) {}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T>
U AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::GetDistance( const T& t_start , const T& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  DIJKSTRA_BODY( , if( i == i_final ){ break; } , );
  U answer{ move( weight[i_final] ) };
  return answer;

}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T>
vector<U> AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::GetDistance( const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  DIJKSTRA_BODY( , , );
  return weight;

}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T>
void AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::SetDistance( vector<U>& weight , vector<bool>& fixed , const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  assert( int( weight.size() ) == size );
  assert( int( fixed.size() ) == size );
  DIJKSTRA_BODY( , , );
  return;

}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T>
pair<U,list<pair<T,U>>> AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::GetPath( const T& t_start , const T& t_final , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  auto&& i_final = m_G.Enumeration_inv( t_final );
  using Vec = vector<pair<int,U>>;
  DIJKSTRA_BODY( Vec prev( size ) , if( i == i_final ){ break; } , prev[j].first = i; prev[j].second = w_ij );
  int i = i_final;
  list<pair<T,U>> path{};
  path.push_back( { t_final , one } );

  if( weight[i] != infty ){

    while( i != i_start ){

      auto& [j,w] = prev[i];
      path.push_front( { m_G.Enumeration( i = j ) , w } );

    }

  }

  U answer{ move( weight[i_final] ) };
  return { move( answer ) , move( path ) };

}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T> template <template <typename...> typename V> 
pair<vector<U>,vector<list<pair<T,U>>>> AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::GetPath( const T& t_start , const V<T>& t_finals , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  const U& infty = this->Infty();
  vector weight( size , infty );
  vector<bool> fixed( size );
  using Vec = vector<pair<int,U>>;
  DIJKSTRA_BODY( Vec prev( size ) , , prev[j].first = i; prev[j].second = w_ij );
  const int path_size = t_finals.size();
  vector<list<pair<T,U>>> path;
  path.reserve( path_size );

  for( auto& t_final : t_finals ){

    list<pair<T,U>> path_t{};
    path_t.push_back( { t_final , one } );
    int i = m_G.Enumeration_inv( t_final );

    if( weight[i] != infty ){

      while( i != i_start ){

        auto& [j,w] = prev[i];
        path_t.push_front( { m_G.Enumeration( i = j ) , w } );

      }

    }

    path.push_back( path_t );

  }

  return { move( weight ) , move( path ) };

}

template <typename GRAPH , typename U , typename COMM_MONOID , typename T>
pair<vector<U>,vector<list<pair<T,U>>>> AbstractDijkstra<GRAPH,U,COMM_MONOID,T>::GetPath( const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  vector<T> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals , many_edges , path_length );

}
