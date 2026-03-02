// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Utility/Set/Map/a_Body.hpp"
#include "../../../../Utility/Vector/a_Body.hpp"

template <typename T , typename GRAPH> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& external ) : m_G( G ) , m_external( external ) , m_initialised( false ) , m_next() , m_reached() , m_prev() { static_assert( is_same_v<inner_t<GRAPH>,T> ); }
template <typename T , typename GRAPH> template <typename Arg> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& external , Arg&& init ) : VirtualBreadthFirstSearch<T,GRAPH>( G , external ) { Initialise( forward<Arg>( init ) ); }

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise() { m_initialised = true; const int& V = size(); m_next.clear(); m_reached = vector<bool>( V ); m_prev = vector<T>( V , m_external ); }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( T init ) { Initialise(); m_next <<= { move( init ) , m_external }; }
template <typename T , typename GRAPH> template <template <typename...> typename VEC> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( VEC<T> inits ) { Initialise(); for( auto& init : inits ){ m_next <<= { move( init ) , m_external }; } }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( T init ) { if( m_initialised ){ m_next = { { move( init ) , m_external } }; } else { Initialise( move( init ) ); } }
template <typename T , typename GRAPH> template <template <typename...> typename VEC> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( VEC<T> inits ) { if( m_initialised ){ m_next.clear(); for( auto& init : inits ){ m_next <<= { move( init ) , m_external }; } } else { Initialise( move( inits ) ); } }

template <typename T , typename GRAPH> inline const int& VirtualBreadthFirstSearch<T,GRAPH>::size() const noexcept { return m_G.size(); }
template <typename T , typename GRAPH> inline vector<bool>::reference VirtualBreadthFirstSearch<T,GRAPH>::reached( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); if( !m_initialised ){ Initialise(); } return m_reached[i]; }
template <typename T , typename GRAPH> inline const T& VirtualBreadthFirstSearch<T,GRAPH>::prev( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }

template <typename T , typename GRAPH> inline T VirtualBreadthFirstSearch<T,GRAPH>::Next()
{

  if( m_next.empty() ){

    return m_external;

  }

  auto [t_curr,p] = m_next.front();
  m_next.pop_front();
  auto&& i = m_G.Enumeration_inv( t_curr );

  if( m_reached[i] ){

    return Next();

  }

  m_reached[i] = true;
  m_prev[i] = p;

  for( auto& t : m_G.Edge( t_curr ) ){

    Push( m_next , m_G.Vertex( t ) , t_curr );

  }

  return t_curr;

}

template <typename T , typename GRAPH>
tuple<vector<int>,vector<vector<T>>,int> VirtualBreadthFirstSearch<T,GRAPH>::GetConnectedComponent()
{

  static_assert( !is_same_v<GRAPH,MemorisationGraph<T,decldecay_t( m_G.edge() )>> );
  const int& V = size();
  vector cc_num( V , -1 );
  vector<vector<T>> cc_num_inv{};
  int count = 0;

  for( int i = 0 ; i < V ; i++ ){

    if( cc_num[i] == -1 ){

      Shift( m_G.Enumeration( i ) );
      T t = Next();

      if( t != m_external ){

        cc_num_inv <<= {};

        while( t != m_external ){

          cc_num_inv[cc_num[m_G.Enumeration_inv( t )] = count] <<= t;
          t = Next();

        }

        count++;

      }

    }

  }

  return { move( cc_num ) , move( cc_num_inv ) , count };

}


template <typename T , typename GRAPH>
vector<T> VirtualBreadthFirstSearch<T,GRAPH>::GetNodeEnumeration()
{

  vector<T> answer{};
  T t = Next();

  while( t != m_external ){

    answer <<= t;
    t = Next();
    
  }

  return answer;

}

template <typename T , typename GRAPH>
vector<T> VirtualBreadthFirstSearch<T,GRAPH>::GetReversedNodeEnumeration()
{

  vector<T> answer{} , next{};
  T t;
  bool searched;

  while( !( searched = ( t = Next() ) == m_external ) || !next.empty() ){

    while( !next.empty() && ( searched || next.back() != m_prev[m_G.Enumeration_inv( t )] ) ){

      answer <<= next.back();
      pop( next );

    }

    if( !searched ){
      
      next <<= t;

    }
    
  }

  return answer;

}

template <typename T , typename GRAPH> template <typename...Args> inline BreadthFirstSearch<T,GRAPH>::BreadthFirstSearch( GRAPH& G , const T& external , Args&&... args ) : VirtualBreadthFirstSearch<T,GRAPH>( G , external , forward<Args>( args )... ) {}

template <typename T , typename GRAPH> template <typename U>
auto BreadthFirstSearch<T,GRAPH>::GetDistance() -> enable_if_t<is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,Map<T,int>>
{

  Map<T,int> answer{};

  for( auto& [t,u] : this->m_next ){

    answer[t] = 0;

  }
  
  T t;
  
  while( ( t = this->Next() ) != this->m_external ){

    // 場合分けをしないとtが始点の時に問題となる。
    if( answer.count( t ) == 0 ){
      
      answer[t] = answer[this->m_prev[this->m_G.Enumeration_inv( t )]] + 1;

    }

  }

  return answer;
  
}

template <typename T , typename GRAPH> template <typename U>
auto BreadthFirstSearch<T,GRAPH>::GetDistance() -> enable_if_t<!is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,vector<int>>
{

  vector answer( this->size() , -1 );

  for( auto& [t,p] : this->m_next ){

    answer[m_G.Enumeration_inv( t )] = 0;

  }
  
  T t;
  
  while( ( t = this->Next() ) != this->m_external ){

    auto&& i = this->m_G.Enumeration_inv( t );
    // 場合分けをしないとtが始点の時に問題となる。
    answer[i] == -1 ? answer[i] = answer[this->m_G.Enumeration_inv( m_pthis->rev[i] )] + 1 : answer[i];

  }

  return answer;
  
}

template <typename T , typename GRAPH> inline void BreadthFirstSearch<T,GRAPH>::Push( list<pair<T,T>>& next , const T& t , const T& p ) { next <<= {t,p}; }
