// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a.hpp

#pragma once
#include "a_Macro.hpp"

// 入力の範囲内で要件
// - MはUの可換群構造である。
// を満たす場合にのみサポート。

// 以下文字の種類数をS、長さの上限をL、要素数をNと置く。

// 構築O(1)

// 全要素数取得O(1)

// 要素挿入O(L log S)
// 要素削除O(L log S)
// 特定の値に等しい要素数／特定の値を始切片に持つ要素数取得O(L log S)

// 要素のインクリメント、均しO(L)
// 要素のディクリメント、均しO(L)

// 最大要素取得、均しO(L log S)
// 最小要素取得、均しO(L log S)
// それらの亜種も同様

template <typename U , typename ABEL_GROUP>
class TrieTree
{

private:
  ABEL_GROUP m_M;
  // m_count[node]にnode番目に扱ったkeyをvとして{vでの値,vを始切片に持つkeyでの値の総和}を格納。
  vector<pair<U,U>> m_count;
  // m_edge[node][i]にnode番目に扱ったkeyの末尾にiを挿入したkeyを何番目に扱ったかを格納。
  vector<map<int,int>> m_edge;

public:
  inline TrieTree( ABEL_GROUP M );

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
  template <typename V> pair<U,U> count( const V& v );

  // ここからMがoperator<(const U&,const U&)に関する全順序可換群構造である場合のみサポート。

  // vより大きく値がMの単位元でない最小のkeyに置き換える。
  void Increment( vector<int>& v ) const;
  // vより小さく値がMの単位元でない最小のkeyに置き換える。
  void Decrement( vector<int>& v ) const;

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
  
  // vをM進法で列に変換する。
  static vector<int> ToArray( ll v , const int& M );
  static vector<int> ToArray( ll v , const int& M , const int& L );

private:
  static const vector<int>& ToArray( const vector<int>& v );
  static inline vector<int> ToArray( const char* const& v );
  template <typename V> static vector<int> ToArray( const V& v );

  template <typename RANGE> void SetNextNode( const map<int,int>& edge , vector<int>& answer , int& node , RANGE range ) const;

  template <typename SEARCH , typename RANGE> void SetMaximum_Body( vector<int>& answer , int& node , SEARCH search , RANGE range ) const;
  inline void SetMaximum( vector<int>& answer , int& node ) const;
  inline void SetMinimum( vector<int>& answer , int& node ) const;

  template <typename RANGE> void SetMaximumLeq_Body( const vector<int>& v , vector<int>& answer , int& node , bool& lt , RANGE range ) const;

};
template <typename ABEL_GROUP> TrieTree( ABEL_GROUP ) -> TrieTree<inner_t<ABEL_GROUP>,ABEL_GROUP>;

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

