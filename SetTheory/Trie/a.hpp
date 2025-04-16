// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Trie/a.hpp

#pragma once
#include "a_Macro.hpp"

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

template <typename INT = int>
class TrieTree
{

private:
  vector<pair<INT,INT>> m_count;
  vector<map<int,int>> m_edge;

public:
  inline TrieTree();

  template <typename V> void insert( const V& v , const INT& count = 1 );
  template <typename V> inline void erase( const V& v );
  template <typename V> void erase( const V& v , const INT& count );
  inline void clear();

  inline bool empty() const noexcept;
  inline const INT& size() const noexcept;
  // {vと等しい要素の個数,vを始切片に持つ要素の個数}
  template <typename V> pair<INT,INT> count( const V& v );

  void Increment( vector<int>& v ) const;
  void Decrement( vector<int>& v ) const;

  inline vector<int> Maximum();
  inline vector<int> Minimum();

  template <typename V> vector<int> MaximumLeq( const V& v );
  template <typename V> vector<int> MinimumGeq( const V& v );

  template <typename V> inline vector<int> MaximumLt( const V& v );
  template <typename V> inline vector<int> MinimumGt( const V& v );

  // v[i]=trueの時、i桁目の順序を反転する。
  vector<int> ReversedMaximum( const vector<bool>& v );
  inline vector<int> ReversedMinimum( vector<bool> v );

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
