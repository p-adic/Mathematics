// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"
#include "../../../../../Utility/Set/Map/a_Body.hpp"
#include "../../../../../Utility/Vector/a_Body.hpp"

template <typename T , typename GRAPH> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& external ) : m_G( G ) , m_external( external ) , m_initialised( false ) , m_next() , m_reached() , m_prev() , m_ID()
{

  static_assert( is_same_v<inner_t<GRAPH>,T> );
  static int ID = 0;
  m_ID = to_string( ID++ );
  const int& V = m_G.size();
  DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")をデバッグモードで実行します。" );
  DERR( "各探索ステップの計算量がO(V)追加されることに注意してください。" );
  DERR( "グラフの頂点数Vは" , V , "です。" );

  bool empty = true;

  for( int i = 0 ; i < V ; i++ ){

    auto&& t = m_G.Enumeration( i );

    for( auto&& u : m_G.Edge( t ) ){

      if( empty ){

	empty = false;
	DERR( "有向辺が" );

      }

      DERR( t , " -> " , m_G.Vertex( u ) );

    }

  }

  if( empty ){

    DERR( "有向辺が1本もありません。" );

  } else {

    DERR( "と貼られています。" );

  }
  
  DERR( "" );

}

template <typename T , typename GRAPH> template <typename Arg> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& external , Arg&& init ) : VirtualBreadthFirstSearch<T,GRAPH>( G , external ) { Initialise( forward<Arg>( init ) ); }

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise()
{

  m_initialised = true;
  const int& V = size();
  DERR( "行番号:" , __LINE__ );
  DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")を初期化します。" );

  if( ! m_next.empty() ){

    DERR( "訪問予定の頂点リストを削除しました。" );
    DERR( "" );
    m_next.clear();

  }
  
  m_reached = vector<bool>( V );
  m_prev = vector<T>( V , m_external );

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( T init )
{

  auto&& i = m_G.Enumeration_inv( init );
  const int& V = size();
  assert( 0 <= i && i < V );
  DERR( "行番号:" , __LINE__ );
  DERRNS( "-> " );
  Initialise();
  m_next <<= { move( init ) , m_external };
  DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
  DERR( "訪問予定の頂点リストに" , init , "を追加しました。" );
  DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );
  DERRNS( "訪問済みの頂点リスト:" );

  for( int j = 0 ; j < V ; j++ ){

    if( m_reached[j] ){

      DERRNS( " " , m_G.Enumeration( j ) );

    }

  }
  
  DERR( "" );
  DERR( "" );

}

template <typename T , typename GRAPH> template <template <typename...> typename VEC> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( VEC<T> inits )
{

  DERR( "行番号:" , __LINE__ );
  DERRNS( "-> " );
  Initialise();

  for( auto& init : inits ){

    m_next <<= { move( init ) , m_external };

  }
  
  const int& V = size();

  DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
  DERR( "訪問予定の頂点リストに" , inits , "を追加しました。" );
  DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );
  DERRNS( "訪問済みの頂点リスト:" );

  for( int j = 0 ; j < V ; j++ ){

    if( m_reached[j] ){

      DERRNS( " " , m_G.Enumeration( j ) );

    }

  }
  
  DERR( "" );
  DERR( "" );

}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( T init )
{

  if( m_initialised ){

    const int& V = size();
    auto&& i = m_G.Enumeration_inv( init );
    assert( 0 <= i && i < V );
    m_next = { { move( init ) , m_external } };
    DERR( "行番号:" , __LINE__ );
    DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
    DERR( "訪問予定の頂点リストを削除し" , init , "を追加しました。" );
    DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );
    DERRNS( "訪問済みの頂点リスト:" );

    for( int j = 0 ; j < V ; j++ ){

      if( m_reached[j] ){

        DERRNS( " " , m_G.Enumeration( j ) );

      }

    }
  
    DERR( "" );

  } else {

    DERR( "行番号:" , __LINE__ );
    DERRNS( "-> " );
    Initialise( init );

  }

}

template <typename T , typename GRAPH> template <template <typename...> typename VEC> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( VEC<T> inits )
{

  if( m_initialised ){

    m_next.clear();
    const int& V = size();
    DERR( "行番号:" , __LINE__ );

    for( auto& init : inits ){

      m_next <<= { move( init ) , m_external };

    }

    if( m_next.empty() ){

      DERR( "行番号:" , __LINE__ );
      DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
      DERR( "訪問予定の頂点リストを削除しました。" );
      DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );

    } else {
      
      DERR( "行番号:" , __LINE__ );
      DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
      DERRNS( "訪問予定の頂点リストを削除し" );
      bool init = true;

      for( auto& [t,p] : m_next ){

        DERRNS( init ? "" : ", " , t );
        init = false;

      }

      DERR( "を追加しました。" );
      DERRNS( "訪問済みの頂点リスト:" );

      for( int j = 0 ; j < V ; j++ ){

	if( m_reached[j] ){

          DERRNS( " " , m_G.Enumeration( j ) );

        }

      }
  
      DERR( "" );

    }

    DERR( "" );

  } else {

    DERR( "行番号:" , __LINE__ );
    Initialise( move( inits ) );

  }

}

template <typename T , typename GRAPH> inline const int& VirtualBreadthFirstSearch<T,GRAPH>::size() const noexcept { return m_G.size(); }
template <typename T , typename GRAPH> inline vector<bool>::reference VirtualBreadthFirstSearch<T,GRAPH>::reached( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_reached[i]; }
template <typename T , typename GRAPH> inline const T& VirtualBreadthFirstSearch<T,GRAPH>::prev( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }

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

  if( m_G.Edge( t_curr ).empty() ){

    DERR( "行番号:" , __LINE__ );
    DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
    DERR( "訪問予定の頂点リストから" , t_curr , "を取り出しました。" );
    DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );

  } else {
    

    DERR( "行番号:" , __LINE__ );
    DERR( "幅／深さ探索優先探索(ID:" + m_ID + ")の" );
    DERR( "訪問予定の頂点リストから" , t_curr , "を取り出し" );
    bool init = true;

    for( auto& t : m_G.Edge( t_curr ) ){

      Push( m_next , m_G.Vertex( t ) , t_curr );
      DERRNS( init ? "" : ", " , t );
      init = false;

    }

    DERR( "を追加しました。" );
    DERR( "訪問予定の辺(終点,始点)リスト:" , m_next );
    DERR( "訪問済みの頂点リスト:" );
    const int& V = size();
  
    for( int j = 0 ; j < V ; j++ ){

      if( m_reached[j] ){

        DERRNS( " " , m_G.Enumeration( j ) );

      }

    }
  
    DERR( "" );

  }
  
  DERR( "" );
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

template <typename T , typename GRAPH> template <typename...Args> inline BreadthFirstSearch<T,GRAPH>::BreadthFirstSearch( GRAPH& G , const T& not_reached , Args&&... args ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_reached , forward<Args>( args )... ) {}

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

    answer[this->m_G.Enumeration_inv( t )] = 0;

  }
  
  T t;
  
  while( ( t = this->Next() ) != this->m_external ){

    auto&& i = this->m_G.Enumeration_inv( t );
    // 場合分けをしないとtが始点の時に問題となる。
    answer[i] == -1 ? answer[i] = answer[this->m_G.Enumeration_inv( this->m_prev[i] )] + 1 : answer[i];

  }

  return answer;
  
}

template <typename T , typename GRAPH> inline void BreadthFirstSearch<T,GRAPH>::Push( list<pair<T,T>>& next , const T& t , const T& p ) { next <<= {t,p}; }
