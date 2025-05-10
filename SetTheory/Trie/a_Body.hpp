// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename ABEL_GROUP> inline TrieTree<U,ABEL_GROUP>::TrieTree( ABEL_GROUP M ) : m_M( move( M ) ) , m_count{{m_M.Zero(),m_M.Zero()}} , m_edge( 1 ) { static_assert( is_same_v<U,inner_t<ABEL_GROUP>> ); }

template <typename U , typename ABEL_GROUP> template <typename V>
void TrieTree<U,ABEL_GROUP>::insert( const V& v , const U& count )
{

  const U& zero = m_M.Zero();
  
  if( count == zero ){

    return;

  }

  DEFINITION_OF_SEARCH_IN_TRIE_TREE( node = edge[i] = m_count.size(); m_count.push_back( {zero,zero} ); m_edge.push_back( {} ) , m_count[node].second = m_M.Sum( move( m_count[node].second ) , count ) , m_count[node].first = m_M.Sum( move( m_count[node].first ) , count ) );

}

template <typename U , typename ABEL_GROUP> template <typename V> inline void TrieTree<U,ABEL_GROUP>::erase( const V& v ) { auto&& val = ToArray( v ); erase( val , count( val ).first ); }
template <typename U , typename ABEL_GROUP> template <typename V> inline void TrieTree<U,ABEL_GROUP>::erase( const V& v , const U& count ) { insert( v , m_M.Inverse( count ) ); }

template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::clear() { m_count.resize( 1 ); m_count[0] = {m_M.Zero(),m_M.Zero()}; m_edge.resize( 1 ); m_edge[0].clear(); }

template <typename U , typename ABEL_GROUP> inline bool TrieTree<U,ABEL_GROUP>::empty() const noexcept { return size() == m_M.Zero(); }
template <typename U , typename ABEL_GROUP> inline const U& TrieTree<U,ABEL_GROUP>::size() const noexcept { return m_count[0].second; }

template <typename U , typename ABEL_GROUP> template <typename V>
pair<U,U> TrieTree<U,ABEL_GROUP>::count( const V& v )
{

  bool found = true;
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( found = false; break , , );
  return found ? m_count[node] : pair<U,U>{m_M.Zero(),m_M.Zero()};

}

template <typename U , typename ABEL_GROUP>
void TrieTree<U,ABEL_GROUP>::Increment( vector<int>& v ) const
{

  int L = v.size();
  vector<int> node( L + 1 );
  
  for( int i = 0 ; i < L ; i++ ){

    node[i+1] = m_edge[node[i]].at( v[i] );

  }

  const U& zero = m_M.Zero();

  while( true ){

    auto& [count,count_is] = m_count[node[L]];
    assert( !( count_is < count ) );
    
    if( count != count_is ){

      break;

    }

    while( v[L-1] == m_edge[node[L-1]].rbegin()->first ){

      v.pop_back();
      node.pop_back();
      L--;

      if( L == 0 ){

        v = {-1};
        return;

      }

    }

    auto&& [key,val] = *( m_edge[node[L-1]].upper_bound( v[L-1] ) );
    v[L-1] = key;
    node[L] = val;

    if( zero < m_count[node[L]].first ){

      return;

    }

  }

  auto& edge = m_edge[node[L]];
      
  for( auto itr = edge.begin() , end = edge.end() ; itr != end ; itr++ ){

    if( zero < m_count[itr->second].second ){

      v.push_back( itr->first );
      int node_curr = itr->second;
      SetMinimum( v , node_curr );
      return;

    }

  }

  abort();

}

template <typename U , typename ABEL_GROUP>
void TrieTree<U,ABEL_GROUP>::Decrement( vector<int>& v ) const
{

  int L = v.size();
  vector<int> node( L + 1 );
  
  for( int i = 0 ; i < L ; i++ ){

    node[i+1] = m_edge[node[i]].at( v[i] );

  }

  const U& zero = m_M.Zero();

  while( true ){

    while( v[L-1] == m_edge[node[L-1]].begin()->first ){

      v.pop_back();
      node.pop_back();
      L--;

      if( L == 0 ){

        v = {-1};
        return;

      }

    }

    auto&& [key,val] = *reverse_iterator( m_edge[node[L-1]].lower_bound( v[L-1] ) );
    v[L-1] = key;
    node[L] = val;

    if( zero < m_count[node[L]].second ){

      break;

    }

  }

  SetMaximum( v , node[L] );
  return;

}

template <typename U , typename ABEL_GROUP> template <typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetNextNode( const map<int,int>& edge , vector<int>& answer , int& node , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&> );
  bool found = false;
  const U& zero = m_M.Zero();

  for( auto [itr,end] = range( edge ) ; itr != end ; itr++ ){

    if( m_count[itr->second].second != zero ){

      found = true;
      answer.push_back( itr->first );
      node = itr->second;
      break;

    }

  }

  assert( found );
  return;

}

template <typename U , typename ABEL_GROUP> template <typename SEARCH , typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetMaximum_Body( vector<int>& answer , int& node , SEARCH search , RANGE range ) const
{

  static_assert( is_invocable_v<SEARCH,const pair<U,U>&> );

  while( true ){

    if( search( m_count[node] ) ){

      break;

    }

    SetNextNode( m_edge[node] , answer , node , range );

  }

  return;

}

template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetMaximum( vector<int>& answer , int& node ) const { SetMaximum_Body( answer , node , [&]( const pair<U,U>& count ){ assert( !( count.second < count.first ) ); return count.first == count.second; } , [&]( const map<int,int>& edge ){ return pair{ edge.rbegin() , edge.rend() }; } ); }
template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetMinimum( vector<int>& answer , int& node ) const { SetMaximum_Body( answer , node , [&]( const pair<U,U>& count ){ assert( !( count.second , count.first ) ); return m_M.Zero() < count.first; } , [&]( const map<int,int>& edge ){ return pair{ edge.begin() , edge.end() }; } ); }

template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::Maximum() { vector<int> answer{}; int node = 0; SetMaximum( answer , node ); return answer; }
template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::Minimum() { vector<int> answer{}; int node = 0; SetMinimum( answer , node ); return answer; }

template <typename U , typename ABEL_GROUP> template <typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , int& node , bool& lt , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&,const int&> );
  const U& zero = m_M.Zero();

  for( auto& i : v ){

    assert( i >= 0 );
    auto& edge = m_edge[node];
    bool found = false;
    
    for( auto [itr,end] = range( edge , i ) ; itr != end ; itr++ ){

      if( m_count[itr->second].second != zero ){

        found = true;
        answer.push_back( itr->first );
        node = itr->second;
        lt = itr->first != i;
        break;

      }

    }

    if( !found || lt ){

      break;

    }

  }

  return;

}

template <typename U , typename ABEL_GROUP> template <typename V>
vector<int> TrieTree<U,ABEL_GROUP>::MaximumLeq( const V& v )
{

  auto&& val = ToArray( v );
  vector<int> answer = {};
  int node = 0;
  bool lt = false;
  SetMaximumLeq_Body( val , answer , node , lt , [&]( const map<int,int>& edge , const int& i ){ return pair{ reverse_iterator( edge.upper_bound( i ) ) , edge.rend() }; } );

  if( lt ){

    SetMaximum( answer , node );

  } else if( answer != vector{-1} && m_count[node].first == m_M.Zero() ){

    Decrement( answer );

  }

  assert( answer == vector{-1} || val >= answer );
  return answer;

}

template <typename U , typename ABEL_GROUP> template <typename V>
vector<int> TrieTree<U,ABEL_GROUP>::MinimumGeq( const V& v )
{

  auto&& val = ToArray( v );
  vector<int> answer = {};
  int node = 0;
  bool gt = false;
  SetMaximumLeq_Body( val , answer , node , gt , [&]( const map<int,int>& edge , const int& i ){ return pair{ edge.lower_bound( i ) , edge.end() }; } );

  if( gt ){

    SetMinimum( answer , node );

  } else if( answer != vector{-1} ){

    const bool lt = answer < val;

    if( lt ){

      SetMaximum( answer , node );

    }

    if( lt || m_count[node].first == m_M.Zero() ){

      Increment( answer );

    }

  }

  assert( answer == vector{-1} || val <= answer );
  return answer;

}

template <typename U , typename ABEL_GROUP> template <typename V> inline vector<int> TrieTree<U,ABEL_GROUP>::MaximumLt( const V& v ) { auto&& val = ToArray( v ); vector<int> answer = MaximumLeq( val ); if( answer != vector{-1} && val == answer ){ Decrement( answer ); assert( answer == vector{-1} || val > answer ); } return answer; }
template <typename U , typename ABEL_GROUP> template <typename V> inline vector<int> TrieTree<U,ABEL_GROUP>::MinimumGt( const V& v ) { auto&& val = ToArray( v ); vector<int> answer = MinimumGeq( val ); if( answer != vector{-1} && val == answer ){ Increment( answer ); assert( answer == vector{-1} || val < answer ); } return answer; }

template <typename U , typename ABEL_GROUP>
vector<int> TrieTree<U,ABEL_GROUP>::ReversedMaximum( const vector<bool>& v )
{

  if( empty() ){

    return {-1};

  }

  auto&& val = ToArray( v );
  vector<int> answer = {};
  int node = 0;
  bool lt = false;

  for( auto& reversed : v ){

    if( reversed ){

      SetNextNode( m_edge[node] , answer , node , [&]( const map<int,int>& edge ){ return pair{ edge.begin() , edge.end() }; } );

    } else {

      SetNextNode( m_edge[node] , answer , node , [&]( const map<int,int>& edge ){ return pair{ edge.rbegin() , edge.rend() }; } );

    }

  }

  return answer;

}

template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::ReversedMinimum( vector<bool> v ) { v.flip(); return ReversedMaximum( v ); }

template <typename U , typename ABEL_GROUP> template <typename V>
void TrieTree<U,ABEL_GROUP>::swap( const V& v0 , const V& v1 )
{

  const U& zero = m_M.Zero();
  vector<int> node0 = {0};

  for( auto& i : v0 ){

    auto& edge = m_edge[node0.back()];
    
    if( edge.count( i ) == 0 ){

      node0.push_back( edge[i] = m_count.size() );
      m_count.push_back( {zero,zero} );
      m_edge.push_back( {} );

    } else {

      node0.push_back( edge[i] );

    }

  }
  
  vector<int> node1 = {0};

  for( auto& i : v1 ){

    auto& edge = m_edge[node1.back()];
    
    if( edge.count( i ) == 0 ){

      node1.push_back( edge[i] = m_count.size() );
      m_count.push_back( {zero,zero} );
      m_edge.push_back( {} );

    } else {

      node1.push_back( edge[i] );

    }

  }

  m_edge[node0.back()].swap( m_edge[node1.back()] );
  U diff = m_M.Sum( m_count[node0.back()] , m_M.Inverse( m_count[node1.back()] ) );  

  for( auto& node : node1 ){

    m_count[node] = m_M.Sum( move( m_count[node] ) , diff );

  }

  diff = m_M.Inverse( diff );  

  for( auto& node : node0 ){

    m_count[node] = m_M.Sum( move( m_count[node] ) , diff );

  }

  return;

}

template <typename U , typename ABEL_GROUP> inline const vector<int>& TrieTree<U,ABEL_GROUP>::ToArray( const vector<int>& v ) { return v; }

template <typename U , typename ABEL_GROUP>
vector<int> TrieTree<U,ABEL_GROUP>::ToArray( ll v , const int& M ) 
{

  assert( v >= 0 );
  vector<int> answer{};

  while( v > 0 ){

    answer.push_back( v % M );
    v /= M;

  }

  int L = answer.size();
  int L_half = L >> 1;

  for( int i = 0 ; i < L_half ; i++ ){

    swap( answer[i] , answer[L-1-i] );

  }

  return answer;

}

template <typename U , typename ABEL_GROUP>
vector<int> TrieTree<U,ABEL_GROUP>::ToArray( ll v , const int& M , const int& L )
{

  assert( v >= 0 );
  vector<int> answer( L );

  for( int i = 0 ; i < L ; i++ ){

    answer[L-1-i] =v % M;
    v /= M;

  }

  return answer;

}

template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::ToArray( const char* const& v ) { return ToArray( string( v ) ); }

template <typename U , typename ABEL_GROUP> template <typename V>
vector<int> TrieTree<U,ABEL_GROUP>::ToArray( const V& v )
{

  const int L = v.size();
  vector<int> answer( L );

  for( int i = 0 ; i < L ; i++ ){

    if constexpr( is_same_v<V,string> ){

      answer[i] = v[i] - ( v[i] < 'a' ? 'A' : 'a' );

    } else {

      answer[i] = v[i];

    }

  }

  return answer;

}

