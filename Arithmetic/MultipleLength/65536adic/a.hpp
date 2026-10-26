// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/MultipleLength/65536adic/a.hpp

#pragma once
#include "a_Macro.hpp"

// 倍精度FFTで多倍長乗算を扱う。
// 2^16進法で2^20桁、およそ6*10^{1000004}程度の整数同士の乗算が可能。
// 例えば2^32未満の整数およそ500000個程度の総乗が計算可能。

template<int w> class Int;

template<int w>
class ConstantsForInt
{

  friend class Int<w>;

private:
  static constexpr const int mask = ( 1 << w ) - 1;

  ConstantsForInt() = delete;
  
};

template<int w = 16>
class Int
{

private:
  // 負ならtrue、非負ならfalse。
  bool m_neg;
  vector<int> m_n;

public:
  inline Int() noexcept;
  inline Int( const Int<w>& n ) noexcept;
  inline Int( Int<w>&& n ) noexcept;
  Int( bool neg , const vector<bool>& n ) noexcept;
  template <typename T> Int<w>( T n ) noexcept;

  inline Int<w>& operator=( Int<w> n ) noexcept;
  DECLARATION_OF_ARITHMETIC_FOR_INT( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_INT( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_INT( * , );
  Int<w> LongDivision( const Int<w>& n );
  DECLARATION_OF_ARITHMETIC_FOR_INT( / , );
  DECLARATION_OF_ARITHMETIC_FOR_INT( % , );
  // 符号を無視してbit演算を行う。
  DECLARATION_OF_BIT_OPERATOR_FOR_INT( ^ );
  DECLARATION_OF_BIT_OPERATOR_FOR_INT( & );
  DECLARATION_OF_BIT_OPERATOR_FOR_INT( | );
  Int<w>& operator<<=( int n );
  Int<w>& operator>>=( int n );

  inline Int<w>& operator++() noexcept;
  inline Int<w> operator++( int ) noexcept;
  inline Int<w>& operator--() noexcept;
  inline Int<w> operator--( int ) noexcept;

  inline bool operator==( const Int<w>& n ) const noexcept;
  inline bool operator!=( const Int<w>& n ) const noexcept;
  inline bool operator<( const Int<w>& n ) const noexcept;
  inline bool operator<=( const Int<w>& n ) const noexcept;
  inline bool operator>( const Int<w>& n ) const noexcept;
  inline bool operator>=( const Int<w>& n ) const noexcept;

  inline Int<w> operator-() const noexcept;

  inline Int<w> operator<<( int n ) const;
  inline Int<w> operator>>( int n ) const;

  // グローバルスコープでswapを定義するためのもの。
  inline void swap( Int<w>& n ) noexcept;

  ll Get() const;
  // 符号を無視して有限bit列に変換する。
  vector<bool> bit() const;
  
private:
  inline void RemoveRedundantZero() noexcept;
  Int<w>& Reduce( const int& e0 ) noexcept;
  inline Int<w>& AbsPlus( const vector<int>& n , const bool& neg ) noexcept;
  int AbsComp( const vector<int>& n ) const noexcept;
  inline int Comp( const Int<w>& n ) const noexcept;
  
};

template <int w> inline void swap( Int<w>& n0 , Int<w>& n1 ) noexcept;

template <int w>inline string to_string( Int<w> n ) noexcept;

template <class Traits , int w> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Int<w>& n );
template <class Traits , int w> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , Int<w> n );
