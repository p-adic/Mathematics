// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/\a.hpp

#pragma once

// baseの羃乗をメモ化する。
template <typename INT>
class PowerMemoriser
{

private:
  vector<INT> m_base;
  vector<vector<INT>> m_val;

public:
  template <typename VEC> inline PowerMemoriser( const VEC& base );
  inline INT Get( const int& i , const int& j ) noexcept;

};

// メモ化しない繰り返し二乗法は
// ../IteratedArithmetic/
// に実装。
