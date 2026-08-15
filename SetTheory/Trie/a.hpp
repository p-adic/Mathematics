// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1177230 (AdditiveGroup, count, NodeNumber)

#include "a_Macro.hpp"

// 入力の範囲内で要件
// - MはUの可換群構造である。
// を満たす場合にのみサポート。

// 以下文字の種類数をS、長さの上限をL、要素数をNと置く。

// 構築O(1)

// 全要素数取得O(1)
// 区間要素数取得O(LS)

// 要素挿入O(L log S)
// 要素削除O(L log S)
// 特定の値に等しい要素数／特定の値を始切片に持つ要素数などを取得O(L log S)

// 要素のインクリメント、均しO(L)（node指定時は均しO(E/V)）
// 要素のディクリメント、均しO(L)（node指定時は均しO(E/V)）

// 最大要素取得、均しO(L log S)
// 最小要素取得、均しO(L log S)
// それらの亜種も同様

template <typename U , typename ABEL_GROUP>
class TrieTree
{

private:
  ABEL_GROUP m_M;
  // m_count[node]にnode番目に扱ったkeyをvとして{vでの値,vを始切片に持つkeyでの値の総和}を格納。
  vector<T2<U>> m_count;
  // m_edge[node][i]にnode番目に扱ったkeyの末尾にiを挿入したkeyを何番目に扱ったかを格納。
  vector<map<int,int>> m_edge;

  int m_base;
  int m_length;

public:
  inline TrieTree( ABEL_GROUP M , int base = 0 , int length = -1 );

  // ノード番号nodeの枝vに対応するノード番号を返す。
  // 存在しない場合は-1を返す。
  inline int NodeNumber( const int& v , const int& node );
  // vに対応するノード番号列を返す。
  template <typename V> vector<int> NodeSequence( const V& v );
  
  // vをkeyとしてuを加算する。
  template <typename V> void insert( const V& v , const U& u );
  // vをkeyとする値を削除する（Mの単位元に置き換える）。
  template <typename V> inline void erase( const V& v );
  // vをkeyとしてuを減算する。
  template <typename V> inline void erase( const V& v , const U& u );
  inline void clear();

  // 全てのkeyをわたる値の総和がMの単位元であるかの真偽を取得する。
  inline bool empty() const noexcept;
  // 全てのkeyをわたる値の総和を取得する。
  inline const U& size() const noexcept;
  // {vをkeyとする値,vを始切片に持つkeyでの値の総和}
  template <typename V> T2<U> count( const V& v );
  // {nodeでの値,nodeの部分木での値の総和}
  inline T2<U> count( const int& node );
  // v_ulim未満における総和
  template <typename V> U InitialSegmentCount( const V& v_ulim );
  // 半開区間[v_min,v_ulim)における総和
  template <typename V> U IntervalCount( const V& v_min , const V& v_ulim );

  // ここからMがoperator<(const U&,const U&)に関する全順序可換群構造である場合のみサポート。

  // keyがleafとは限らないnodeも指すことに注意。
  // nodeは{}またはvに対応するノード番号列。
  // vより大きく値がMの単位元でない最小のkeyにvが置き換わり、nodeも対応して置き換わる。
  T2<U> Increment( vector<int>& v , vector<int>& node ) const;
  // vより小さく値がMの単位元でない最小のkeyに置き換わり、nodeも対応して置き換わる。
  T2<U> Decrement( vector<int>& v , vector<int>& node ) const;
  // 存在しない場合はどちらも{-1}に置き換える。
  // 返り値はnode.back()におけるm_countの値。 

  // 値がMの単位元でない最大のkeyを取得する。
  inline vector<int> Maximum();
  // 値がMの単位元でない最小のkeyを取得する。
  inline vector<int> Minimum();

  // v以下で値がMの単位元でない最大のkeyを返す。
  template <typename V> vector<int> MaximumLeq( const V& v );
  // v以上で値がMの単位元でない最小のkeyを返す。
  template <typename V> vector<int> MinimumGeq( const V& v );

  // vより小さく値がMの単位元でない最大のkeyを返す。
  template <typename V> inline vector<int> MaximumLt( const V& v );
  // vより大きく値がMの単位元でない最小のkeyを返す。
  template <typename V> inline vector<int> MinimumGt( const V& v );

  // v[i]=trueの時i桁目の順序を反転した上で、値がMの単位元でない最大のkeyを取得する。
  vector<int> ReversedMaximum( const vector<bool>& v );
  // v[i]=trueの時i桁目の順序を反転した上で、値がMの単位元でない最小のkeyを取得する。
  inline vector<int> ReversedMinimum( vector<bool> v );

  // ここまでMがoperator<(const U&,const U&)に関する全順序可換群構造である場合のみサポート。


  // 各keyの始切片v0をv1に、v1をv0に置き換える。
  template <typename V> void swap( const V& v0 , const V& v1 );

  inline void SetBase( const int& base );
  inline void SetLength( const int& length );

  // vをm_base進法で長さm_lengthの列に変換する。
  inline vector<int> ToArray( const int& v );
  inline vector<int> ToArray( ll v );
  // vをM進法で列に変換する。
  static vector<int> ToArray( ll v , const int& M );
  // vをM進法で長さLの列に変換する。
  static vector<int> ToArray( ll v , const int& M , const int& L );

private:
  static const vector<int>& ToArray( const vector<int>& v );
  static inline vector<int> ToArray( const char* const& v );
  template <typename V> static vector<int> ToArray( const V& v );

  template <typename RANGE> void SetNextNode( const map<int,int>& edge , vector<int>& v , vector<int>& node , RANGE range ) const;

  template <typename SEARCH , typename RANGE> void SetMaximum_Body( vector<int>& v , vector<int>& node , SEARCH search , RANGE range ) const;
  inline void SetMaximum( vector<int>& v , vector<int>& node ) const;
  inline void SetMinimum( vector<int>& v , vector<int>& node ) const;

  template <typename RANGE> void SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , vector<int>& node , bool& lt , RANGE range ) const;

};
template <typename ABEL_GROUP , typename... ARGS> TrieTree( ABEL_GROUP , ARGS... ) -> TrieTree<inner_t<ABEL_GROUP>,ABEL_GROUP>;

// - 要素数を管理したい場合
//   TrieTree trie( AdditiveGroup<int>() );
//   trie.insert( v , 1 );
//   trie.erase( v , 1 );
// - 総和を管理したい場合
//   TrieTree trie( AdditiveGroup<ll>() );
//   trie.insert( v , v );
//   trie.erase( v , v );
// - 要素数と総和を管理したい場合
//   TrieTree trie( AdditiveGroup<Pair<int,ll>>() );
//   trie.insert( v , {1,v}} );
//   trie.erase( v , {1,v} );

