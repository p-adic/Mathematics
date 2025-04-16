// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline TrieTree<INT>::TrieTree() : m_count( 1 ) , m_edge( 1 ) {}

template <typename INT> template <typename V>
void TrieTree<INT>::insert( const V& v , const INT& count )
{

  if( count == 0 ){

    return;

  }

  assert( count > 0 );
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( node = edge[i] = m_count.size(); m_count.push_back( {0,0} ); m_edge.push_back( {} ) , m_count[node].second += count , m_count[node].first += count );

}

template <typename INT> template <typename V> inline void TrieTree<INT>::erase( const V& v ) { auto&& val = ToArray( v ); erase( val , count( val ).first ); }

template <typename INT> template <typename V>
void TrieTree<INT>::erase( const V& v , const INT& count )
{

  if( count == 0 ){

    return;

  }

  assert( count > 0 );
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( abort() , assert( ( m_count[node].second -= count ) >= 0 ) , assert( ( m_count[node].first -= count ) >= 0 ) );

}

template <typename INT> inline void TrieTree<INT>::clear() { m_count.resize( 1 ); m_count[0] = {0,0}; m_edge.resize( 1 ); m_edge[0].clear(); }

template <typename INT> inline bool TrieTree<INT>::empty() const noexcept { return size() == 0; }
template <typename INT> inline const INT& TrieTree<INT>::size() const noexcept { return m_count[0].second; }

template <typename INT> template <typename V>
pair<INT,INT> TrieTree<INT>::count( const V& v )
{

  bool found = true;
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( found = false; break , , );
  return found ? m_count[node] : pair<INT,INT>{0,0};

}

template <typename INT>
void TrieTree<INT>::Increment( vector<int>& v ) const
{

  int L = v.size();
  vector<int> node( L + 1 );
  
  for( int i = 0 ; i < L ; i++ ){

    node[i+1] = m_edge[node[i]].at( v[i] );

  }

  while( true ){

    auto& [count,count_is] = m_count[node[L]];
    assert( count <= count_is );
    
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

    if( m_count[node[L]].first > 0 ){

      return;

    }

  }

  auto& edge = m_edge[node[L]];
      
  for( auto itr = edge.begin() , end = edge.end() ; itr != end ; itr++ ){

    if( m_count[itr->second].second > 0 ){

      v.push_back( itr->first );
      int node_curr = itr->second;
      SetMinimum( v , node_curr );
      return;

    }

  }

  abort();

}

template <typename INT>
void TrieTree<INT>::Decrement( vector<int>& v ) const
{

  int L = v.size();
  vector<int> node( L + 1 );
  
  for( int i = 0 ; i < L ; i++ ){

    node[i+1] = m_edge[node[i]].at( v[i] );

  }

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

    if( m_count[node[L]].second > 0 ){

      break;

    }

  }

  SetMaximum( v , node[L] );
  return;

}

template <typename INT> template <typename RANGE>
void TrieTree<INT>::SetNextNode( const map<int,int>& edge , vector<int>& answer , int& node , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&> );
  bool found = false;

  for( auto [itr,end] = range( edge ) ; itr != end ; itr++ ){

    if( m_count[itr->second].second != 0 ){

      found = true;
      answer.push_back( itr->first );
      node = itr->second;
      break;

    }

  }

  assert( found );
  return;

}

template <typename INT> template <typename SEARCH , typename RANGE>
void TrieTree<INT>::SetMaximum_Body( vector<int>& answer , int& node , SEARCH search , RANGE range ) const
{

  static_assert( is_invocable_v<SEARCH,const pair<INT,INT>&> );

  while( true ){

    if( search( m_count[node] ) ){

      break;

    }

    SetNextNode( m_edge[node] , answer , node , range );

  }

  return;

}

template <typename INT> inline void TrieTree<INT>::SetMaximum( vector<int>& answer , int& node ) const { SetMaximum_Body( answer , node , [&]( const pair<INT,INT>& count ){ assert( count.first <= count.second ); return count.first == count.second; } , [&]( const map<int,int>& edge ){ return pair{ edge.rbegin() , edge.rend() }; } ); }
template <typename INT> inline void TrieTree<INT>::SetMinimum( vector<int>& answer , int& node ) const { SetMaximum_Body( answer , node , [&]( const pair<INT,INT>& count ){ assert( count.first <= count.second ); return count.first > 0; } , [&]( const map<int,int>& edge ){ return pair{ edge.begin() , edge.end() }; } ); }

template <typename INT> inline vector<int> TrieTree<INT>::Maximum() { vector<int> answer{}; int node = 0; SetMaximum( answer , node ); return answer; }
template <typename INT> inline vector<int> TrieTree<INT>::Minimum() { vector<int> answer{}; int node = 0; SetMinimum( answer , node ); return answer; }

template <typename INT> template <typename RANGE>
void TrieTree<INT>::SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , int& node , bool& lt , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&,const int&> );

  for( auto& i : v ){

    assert( i >= 0 );
    auto& edge = m_edge[node];
    bool found = false;
    
    for( auto [itr,end] = range( edge , i ) ; itr != end ; itr++ ){

      if( m_count[itr->second].second != 0 ){

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

template <typename INT> template <typename V>
vector<int> TrieTree<INT>::MaximumLeq( const V& v )
{

  auto&& val = ToArray( v );
  vector<int> answer = {};
  int node = 0;
  bool lt = false;
  SetMaximumLeq_Body( val , answer , node , lt , [&]( const map<int,int>& edge , const int& i ){ return pair{ reverse_iterator( edge.upper_bound( i ) ) , edge.rend() }; } );

  if( lt ){

    SetMaximum( answer , node );

  } else if( answer != vector{-1} && m_count[node].first == 0 ){

    Decrement( answer );

  }

  assert( answer == vector{-1} || val >= answer );
  return answer;

}

template <typename INT> template <typename V>
vector<int> TrieTree<INT>::MinimumGeq( const V& v )
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

    if( lt || m_count[node].first == 0 ){

      Increment( answer );

    }

  }

  assert( answer == vector{-1} || val <= answer );
  return answer;

}

template <typename INT> template <typename V> inline vector<int> TrieTree<INT>::MaximumLt( const V& v ) { auto&& val = ToArray( v ); vector<int> answer = MaximumLeq( val ); if( answer != vector{-1} &&  val == answer ){ Decrement( answer ); assert( answer == vector{-1} || val > answer ); } return answer; }
template <typename INT> template <typename V> inline vector<int> TrieTree<INT>::MinimumGt( const V& v ) { auto&& val = ToArray( v ); vector<int> answer = MinimumGeq( val ); if( answer != vector{-1} &&  val == answer ){ Increment( answer ); assert( answer == vector{-1} || val < answer ); } return answer; }

template <typename INT>
vector<int> TrieTree<INT>::ReversedMaximum( const vector<bool>& v )
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

template <typename INT> inline vector<int> TrieTree<INT>::ReversedMinimum( vector<bool> v ) { v.flip(); return ReversedMaximum( v ); }

template <typename INT> inline const vector<int>& TrieTree<INT>::ToArray( const vector<int>& v ) { return v; }

template <typename INT>
vector<int> TrieTree<INT>::ToArray( ll v , const int& M ) 
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

template <typename INT>
vector<int> TrieTree<INT>::ToArray( ll v , const int& M , const int& L )
{

  assert( v >= 0 );
  vector<int> answer( L );

  for( int i = 0 ; i < L ; i++ ){

    answer[L-1-i] =v % M;
    v /= M;

  }

  return answer;

}

template <typename INT> inline vector<int> TrieTree<INT>::ToArray( const char* const& v ) { return ToArray( string( v ) ); }

template <typename INT> template <typename V>
vector<int> TrieTree<INT>::ToArray( const V& v )
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

