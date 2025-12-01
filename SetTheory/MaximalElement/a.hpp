// c:/Users/user/Documents/Programming/Mathematics/SetTheory/MaximalElement/a.hpp

#pragma once

// 入力の範囲内で要件
// - X,Vのoperator<は全順序である。
// を満たす場合にのみサポート。

// X×Vの部分集合を極大元のみスライド最大化の要領で管理する。

// 構築O(1)

// 極大要素数取得O(1)

// 極大要素のうちX成分最小または最大となる要素の挿入O(1)
// 極大要素のうちX成分最小または最大となる要素以下の全要素削除O(1)

template <typename X , typename V>
class MaximalElementSet
{

private:
  deque<pair<X,V>> m_S;

public:
  inline int size() const noexcept;
  inline bool empty() const noexcept;

  void push( const X& x , const V& v );

  // 極大要素の中でX成分最小の極大要素 = 極大要素の中でY成分最大の極大要素
  // = 全要素の中でY成分最大の極大要素
  inline const pair<X,V>& LeftMaximal() const;
  // 極大要素の中でX成分最大の極大要素 = 極大要素の中でY成分最小の極大要素
  inline const pair<X,V>& RightMaximal() const;
  
  inline pair<X,V> pop_left();
  inline pair<X,V> pop_right();
  inline void clear();

  inline typename deque<pair<X,V>>::const_iterator begin() const noexcept;
  inline typename deque<pair<X,V>>::const_iterator end() const noexcept;
  
};

template <class Traits , typename X , typename V> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MaximalElementSet<X,V>& mes );
