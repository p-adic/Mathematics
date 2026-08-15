// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Set/a_Body.hpp"
#include "../../Utility/Tuple/Wrap/a_Body.hpp"
#include "../../Utility/Vector/a_Body.hpp"

template <typename U , typename ABEL_GROUP> inline TrieTree<U,ABEL_GROUP>::TrieTree( ABEL_GROUP M , int base , int length ) : m_M( move( M ) ) , m_count{{m_M.Zero(),m_M.Zero()}} , m_edge( 1 ) , m_base( move( base ) ) , m_length( move( length ) ) { static_assert( is_same_v<U,inner_t<ABEL_GROUP>> ); }

template <typename U , typename ABEL_GROUP> inline int TrieTree<U,ABEL_GROUP>::NodeNumber( const int& v , const int& node ) { auto& edge = m_edge.at( node ); return In( v , edge ) ? edge[v] : -1; }

template <typename U , typename ABEL_GROUP> template <typename V>
vector<int> TrieTree<U,ABEL_GROUP>::NodeSequence( const V& v )
{

  vector<int> answer = {0};

  for( auto& vi : v ){

    answer <<= m_edge[answer.back()].at( vi );

  }

  return answer;
    
}

template <typename U , typename ABEL_GROUP> template <typename V>
void TrieTree<U,ABEL_GROUP>::insert( const V& v , const U& count )
{

  const U& zero = m_M.Zero();
  
  if( count == zero ){

    return;

  }

  // push_backを<<=に変えると,が意図通りでなくパースされることに注意。
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( node = edge[i] = m_count.size(); m_count.push_back( {zero,zero} ); m_edge <<= {} , m_count[node][I] = m_M.Sum( move( m_count[node][I] ) , count ) , m_count[node][O] = m_M.Sum( move( m_count[node][O] ) , count ) );

}

template <typename U , typename ABEL_GROUP> template <typename V> inline void TrieTree<U,ABEL_GROUP>::erase( const V& v ) { auto&& val = ToArray( v ); erase( val , count( val )[O] ); }
template <typename U , typename ABEL_GROUP> template <typename V> inline void TrieTree<U,ABEL_GROUP>::erase( const V& v , const U& count ) { insert( v , m_M.Inverse( count ) ); }

template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::clear() { m_count.resize( 1 ); m_count[0] = {m_M.Zero(),m_M.Zero()}; m_edge.resize( 1 ); m_edge[0].clear(); }

template <typename U , typename ABEL_GROUP> inline bool TrieTree<U,ABEL_GROUP>::empty() const noexcept { return size() == m_M.Zero(); }
template <typename U , typename ABEL_GROUP> inline const U& TrieTree<U,ABEL_GROUP>::size() const noexcept { return m_count[0][I]; }

template <typename U , typename ABEL_GROUP> template <typename V>
T2<U> TrieTree<U,ABEL_GROUP>::count( const V& v )
{

  bool found = true;
  DEFINITION_OF_SEARCH_IN_TRIE_TREE( found = false; break , , );
  return found ? m_count[node] : T2<U>{m_M.Zero(),m_M.Zero()};

}

template <typename U , typename ABEL_GROUP> inline T2<U> TrieTree<U,ABEL_GROUP>::count( const int& node ) { return 0 <= node && node < len( m_count ) ? m_count[node] : T2<U>{m_M.Zero(),m_M.Zero()}; }

template <typename U , typename ABEL_GROUP> template <typename V>
U TrieTree<U,ABEL_GROUP>::InitialSegmentCount( const V& v_ulim )
{

  auto&& val = ToArray( v_ulim );
  int L = val.size();
  vector<int> node( L + 1 );
  
  for( int i = 0 ; i < L ; i++ ){

    auto itr = m_edge[node[i]].lower_bound( val[i] );

    // val[i]がkeyであるか否かを確認
    if( itr == m_edge[node[i]].end() || val[i] < itr->first ){

      L = i + 1;
      break;

    }

    node[i+1] = itr->second;

  }

  U answer = m_M.Zero();

  while( --L >= 0 ){

    for( auto itr = m_edge[node[L]].begin() , end = m_edge[node[L]].end() ; itr != end && itr->first < val[L] ; ++itr ){

      answer = m_M.Sum( move( answer ) , m_count[itr->second][I] );

    }

  }

  return answer;
  
}

template <typename U , typename ABEL_GROUP> template <typename V> inline U TrieTree<U,ABEL_GROUP>::IntervalCount( const V& v_min , const V& v_ulim ) { return v_min < v_ulim ? m_M.Sum( InitialSegmentCount( v_ulim ) , m_M.Inverse( InitialSegmentCount( v_min ) ) ) : m_M.Zero(); }

template <typename U , typename ABEL_GROUP>
T2<U> TrieTree<U,ABEL_GROUP>::Increment( vector<int>& v , vector<int>& node ) const
{

  int L = v.size();

  if( node.empty() ){

    node = NodeSequence( v );

  }

  const U& zero = m_M.Zero();

  while( true ){

    auto& [count,count_is] = m_count[node[L]];
    assert( !( count_is < count ) );

    // 深さ方向に進める場合
    if( count != count_is ){

      break;

    }

    // 幅方向に進めない（深さ方向に戻らなければならない）場合
    while( v[L-1] == m_edge[node[L-1]].rbegin()->first ){

      v.pop_back();
      node.pop_back();
      L--;

      if( L == 0 ){

        v = node = {-1};
        return {zero,zero};

      }

    }

    // 幅方向に進む
    auto&& [key,val] = *( m_edge[node[L-1]].upper_bound( v[L-1] ) );
    v[L-1] = key;
    node[L] = val;

    if( zero < m_count[val][O] ){

      return m_count[val];

    }

  }

  // 枝を幅方向に選択して深さ方向に1歩進む
  SetMinimum( v , node );
  assert( len( node ) == ++L );
  return m_count[node[L]];

}

template <typename U , typename ABEL_GROUP>
T2<U> TrieTree<U,ABEL_GROUP>::Decrement( vector<int>& v , vector<int>& node ) const
{

  int L = v.size();

  if( node.empty() ){

    node = NodeSequence( v );

  }

  const U& zero = m_M.Zero();

  do {

    // 幅方向に戻れない（深さ方向に戻らなければならない）場合
    while( v[L-1] == m_edge[node[L-1]].begin()->first ){

      v.pop_back();
      node.pop_back();
      L--;

      if( L == 0 ){

        v = node = {-1};
        return {zero,zero};

      }

    }

    // 幅方向に戻る
    auto&& [key,val] = *reverse_iterator( m_edge[node[L-1]].lower_bound( v[L-1] ) );
    v[L-1] = key;
    node[L] = val;

  } while( zero == m_count[node[L]][I] );

  // 枝を幅逆方向に選択して葉まで進む
  SetMaximum( v , node[L] );
  return m_count[node.back()];

}

// 枝のイテレータ範囲range(edge)内で、総和がMの単位元でない最初のイテレータが指す
// {枝番号,ノード番号}をvとnodeに設定する。
template <typename U , typename ABEL_GROUP> template <typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetNextNode( const map<int,int>& edge , vector<int>& v , vector<int>& node , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&> );
  const U& zero = m_M.Zero();

  for( auto [itr,end] = range( edge ) ; itr != end ; itr++ ){

    if( m_count[itr->second][I] != zero ){

      v <<= itr->first;
      node <<= itr->second;
      return;

    }

  }

  abort();

}

// 幅方向のイテレータ順指定方法rangeに従って深さ優先探索をし、条件searchを満たしかつ
// 総和がMの単位元でない最初のイテレータが指す{枝番号,node番号}をvとnodeに設定する。
template <typename U , typename ABEL_GROUP> template <typename SEARCH , typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetMaximum_Body( vector<int>& v , vector<int>& node , SEARCH search , RANGE range ) const
{

  static_assert( is_invocable_v<SEARCH,const T2<U>&> );

  while( !search( m_count[node.back()] ) ){

    SetNextNode( m_edge[node.back()] , v , node , range );

  }

  return;

}

// 幅逆方向で深さ優先探索をし、葉でありかつ値がMの単位元でない最初のイテレータが指す
// {枝番号,ノード番号}をvとnodeに設定する。
template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetMaximum( vector<int>& v , vector<int>& node ) const { SetMaximum_Body( v , node , [&]( const T2<U>& count ){ assert( !( count[I] < count[O] ) ); return count[O] == count[I]; } , [&]( const map<int,int>& edge ){ return pair{ edge.rbegin() , edge.rend() }; } ); }
// 幅方向で（深さ1で止まる深さ優先探索をし）、Mの単位元でない最初のイテレータが指す
// {枝番号,ノード番号}をvとnodeに設定する。
template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetMinimum( vector<int>& v , vector<int>& node ) const { SetMaximum_Body( v , node , [&]( const T2<U>& count ){ assert( !( count[I] < count[O] ) ); return m_M.Zero() < count[O]; } , [&]( const map<int,int>& edge ){ return pair{ edge.begin() , edge.end() }; } ); }

template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::Maximum() { vector<int> answer{}; int node = 0; SetMaximum( answer , node ); return answer; }
template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::Minimum() { vector<int> answer{}; int node = 0; SetMinimum( answer , node ); return answer; }

template <typename U , typename ABEL_GROUP> template <typename RANGE>
void TrieTree<U,ABEL_GROUP>::SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , vector<int>& node , bool& lt , RANGE range ) const
{

  static_assert( is_invocable_v<RANGE,const map<int,int>&,const int&> );
  const U& zero = m_M.Zero();

  for( auto& i : v ){

    assert( i >= 0 );
    auto& edge = m_edge[node.back()];
    bool found = false;
    
    for( auto [itr,end] = range( edge , i ) ; itr != end ; itr++ ){

      if( m_count[itr->second][I] != zero ){

        found = true;
        answer <<= itr->first;
        node <<= itr->second;
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
  vector<int> answer = {} , node = {0};
  bool lt = false;
  SetMaximumLeq_Body( val , answer , node , lt , [&]( const map<int,int>& edge , const int& i ){ return pair{ reverse_iterator( edge.upper_bound( i ) ) , edge.rend() }; } );

  if( lt ){

    SetMaximum( answer , node );

  } else if( answer != vector{-1} && m_count[node.back()][O] == m_M.Zero() ){

    Decrement( answer );

  }

  assert( answer == vector{-1} || val >= answer );
  return answer;

}

template <typename U , typename ABEL_GROUP> template <typename V>
vector<int> TrieTree<U,ABEL_GROUP>::MinimumGeq( const V& v )
{

  auto&& val = ToArray( v );
  vector<int> answer = {} , node = {0};
  bool gt = false;
  SetMaximumLeq_Body( val , answer , node , gt , [&]( const map<int,int>& edge , const int& i ){ return pair{ edge.lower_bound( i ) , edge.end() }; } );

  if( gt ){

    SetMinimum( answer , node );

  } else if( answer != vector{-1} ){

    const bool lt = answer < val;

    if( lt ){

      SetMaximum( answer , node );

    }

    if( lt || m_count[node.back()][O] == m_M.Zero() ){

      Increment( answer , node );

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
  vector<int> answer = {} , node = {0};
  bool lt = false;

  for( auto& reversed : v ){

    if( reversed ){

      SetNextNode( m_edge[node.back()] , answer , node , [&]( const map<int,int>& edge ){ return pair{ edge.begin() , edge.end() }; } );

    } else {

      SetNextNode( m_edge[node.back()] , answer , node , [&]( const map<int,int>& edge ){ return pair{ edge.rbegin() , edge.rend() }; } );

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

      node0 <<= edge[i] = m_count.size();
      m_count <<= {zero,zero};
      m_edge <<= {};

    } else {

      node0 <<= edge[i];

    }

  }
  
  vector<int> node1 = {0};

  for( auto& i : v1 ){

    auto& edge = m_edge[node1.back()];
    
    if( edge.count( i ) == 0 ){

      node1 <<= edge[i] = m_count.size();
      m_count <<= {zero,zero};
      m_edge <<= {};

    } else {

      node1 <<= edge[i];

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

template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetBase( const int& base ) { m_base = base; }
template <typename U , typename ABEL_GROUP> inline void TrieTree<U,ABEL_GROUP>::SetLength( const int& length ) { m_length = length; }

template <typename U , typename ABEL_GROUP> inline const vector<int>& TrieTree<U,ABEL_GROUP>::ToArray( const vector<int>& v ) { return v; }

template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::ToArray( const int& v ) { return ToArray( ll( v ) ); }
template <typename U , typename ABEL_GROUP> inline vector<int> TrieTree<U,ABEL_GROUP>::ToArray( ll v ) { assert( m_base >= 1 ); return m_length == -1 ? ToArray( v , m_base ) : ToArray( v , m_base , m_length ); }

template <typename U , typename ABEL_GROUP>
vector<int> TrieTree<U,ABEL_GROUP>::ToArray( ll v , const int& M ) 
{

  assert( v >= 0 );
  vector<int> answer{};

  while( v > 0 ){

    answer <<= v % M;
    v /= M;

  }

  Reverse( answer );
  return answer;

}

template <typename U , typename ABEL_GROUP>
vector<int> TrieTree<U,ABEL_GROUP>::ToArray( ll v , const int& M , const int& L )
{

  assert( 0 <= L && 0 <= v );
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

