// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/Transposition/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1131843

#include "../a.hpp"

template <typename T>
class TransposableGridRow
{

private:
  vector<vector<T>>* m_p_a;
  int m_i;
  bool m_transposed;

public:
  inline TransposableGridRow( vector<vector<T>>& a , const int& i );
  inline TransposableGridRow( const TransposableGridRow<T>& a );
  inline TransposableGridRow( TransposableGridRow<T>&& a );

  inline bool operator==( const TransposableGridRow<T>& v ) const;
  inline bool operator!=( const TransposableGridRow<T>& v ) const;

  // ポインタをメンバとしているのでconstメンバ関数にしてよい。
  inline T& operator[]( const int& j ) const;
  inline TransposableGridRow<T>& operator*();
  inline TransposableGridRow<T>& operator++();
  inline TransposableGridRow<T> operator++( int );
  inline TransposableGridRow<T>& operator--();
  inline TransposableGridRow<T> operator--( int );

};

template <typename T>
class TransposableGrid
{

private:
  vector<vector<T>> m_a;

public:
  inline TransposableGrid();
  inline TransposableGridRow<T> operator[]( const int& i );
  inline TransposableGridRow<T> begin();
  inline TransposableGridRow<T> end();

};

bool transposed = false;

inline void Transpose();
inline void ResolveTransposition();

template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const TransposableGridRow<T>& v );
// TransposableGridにはconstをつけない。
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , TransposableGrid<T>& a );
