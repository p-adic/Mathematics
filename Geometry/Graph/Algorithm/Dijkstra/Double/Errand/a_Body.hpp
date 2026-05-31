// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Errand/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../Linear/a_Body.hpp"

template <typename GRAPH , typename T> inline ErrandEnumeration<GRAPH,T>::ErrandEnumeration( GRAPH& G ) : m_p_G( &G ) {}
template <typename GRAPH , typename T> inline pair<int,T> ErrandEnumeration<GRAPH,T>::operator()( const int& i ) { const int& size = m_p_G->size(); return { i / size , m_p_G->Enumeration( i % size ) }; }

template <typename GRAPH , typename T> inline ErrandEnumeration_inv<GRAPH,T>::ErrandEnumeration_inv( GRAPH& G ) : m_p_G( &G ) {}
template <typename GRAPH , typename T> inline int ErrandEnumeration_inv<GRAPH,T>::operator()( const pair<int,T>& v ) { const int& size = m_p_G->size(); auto& [i,t] = v; return i * size + m_p_G->Enumeration_inv( t ); }


template <typename GRAPH , typename SUBGOAL , typename T , typename U> inline ErrandEdge<GRAPH,SUBGOAL,T,U>::ErrandEdge( GRAPH& G , SUBGOAL subgoal , const U& one , const int& goal_num ) : m_p_G( &G ) , m_subgoal( move( subgoal ) ) , m_one( one ) , m_goal_num( goal_num ) { static_assert( is_invocable_r_v<bool,SUBGOAL,int,T> ); }

template <typename GRAPH , typename SUBGOAL , typename T , typename U> inline vector<pair<pair<int,T>,U>> ErrandEdge<GRAPH,SUBGOAL,T,U>::operator()( const pair<int,T>& v ) { auto& [i,t] = v; const bool b = i < m_goal_num ? m_subgoal( i , t ) : false; auto&& e_t = m_p_G->Edge( t ); vector<pair<pair<int,T>,U>> answer{}; answer.reserve( e_t.size() + ( b ? 1 : 0 ) ); if( b ){ answer.push_back( { { i + 1 , t } , m_one } ); } for( auto&& p : e_t ){ answer.push_back( { { i , get<0>( p ) } , get<1>( p ) } ); } return answer; }


template <typename GRAPH , typename T> inline ErrandVertex<GRAPH,T>::ErrandVertex( GRAPH& G ) : m_p_G( &G ) , m_vertex() { static_assert( !is_same_v<GRAPH,MemorisationGraph<T,decldecay_t(declval<GRAPH>().edge())>> ); }
template <typename GRAPH , typename T> inline const vector<T>& ErrandVertex<GRAPH,T>::operator()( const int& ){ if( m_vertex.empty() ){ const int& size = m_p_G->size(); m_vertex.resize( size ); for( int i = 0 ; i < size ; i++ ){ m_vertex[i] = m_p_G->Enumeration( i ); } } return m_vertex; }


template <typename GRAPH , typename COMM_MONOID , typename SUBGOAL , typename T , typename U> inline ErrandDijkstra<GRAPH,COMM_MONOID,SUBGOAL,T,U>::ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const int& goal_num , const U& infty , const int& direction ) : DoubleDijkstra<LinearGraph,EnumerationGraph<pair<int,T>,ErrandEnumeration<GRAPH,T>,ErrandEnumeration_inv<GRAPH,T>,ErrandEdge<GRAPH,SUBGOAL,T,U>>,ErrandVertex<GRAPH,T>>( LinearGraph( goal_num , direction ) , EnumerationGraph<pair<int,T>,ErrandEnumeration<GRAPH,T>,ErrandEnumeration_inv<GRAPH,T>,ErrandEdge<GRAPH,SUBGOAL,T,U>>( G.size() * ( goal_num + 1 ) , ErrandEnumeration<GRAPH,T>( m_G ) , ErrandEnumeration_inv<GRAPH,T>( m_G ) , ErrandEdge<GRAPH,SUBGOAL,T,U>( m_G , move( subgoal ) , M.One() , goal_num ) ) , ErrandVertex<GRAPH,T>( m_G ) ) , m_G( move( G ) ) , m_M( move( M ) ) , m_infty( infty ) { static_assert( is_same_v<U,decldecay_t( declval<GRAPH>().Edge( declval<inner_t<GRAPH>>() ).front().second )> ); assert( direction == 1 || direction == 2 ); }

template <typename GRAPH , typename COMM_MONOID , typename SUBGOAL , typename T , typename U> inline const U& ErrandDijkstra<GRAPH,COMM_MONOID,SUBGOAL,T,U>::infty() const noexcept { return m_infty; }

template <typename GRAPH , typename COMM_MONOID , typename SUBGOAL , typename T , typename U> inline vector<U> ErrandDijkstra<GRAPH,COMM_MONOID,SUBGOAL,T,U>::GetDistance( const vector<T>& t_starts , const bool& many_edges ) { const int starts_size = t_starts.size(); vector<pair<int,T>> v_starts( starts_size ); for( int i = 0 ; i < starts_size ; i++ ){ v_starts[i] = { 0 , t_starts[i] }; } auto full =  DoubleDijkstra<int,LinearGraph,T,U,EnumerationGraph<pair<int,T>,ErrandEnumeration<GRAPH,T>,ErrandEnumeration_inv<GRAPH,T>,ErrandEdge<GRAPH,SUBGOAL,T,U>>,ErrandVertex<GRAPH,T>>::GetDistance( v_starts , m_M , m_infty , many_edges ); const int& size = m_G.size(); const int shift = full.size() - size; vector<U> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = move( full[shift + i] ); } return answer; }
