// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DigitConcatenation/a.hpp

#pragma once

// Tはオーバーフローしない整数の型。
// 非負整数をbase進法表記で連結した時の各種値を管理する。

template <typename T>
class DigitConcatenationString
{

private:
  T m_base;
  T m_length;
  T m_sub; // 2 ^ m_length
  T m_power; // m_base ^ m_length
  T m_power_lsum; // 非空始切片のm_base ^ 長さの総和
  T m_power_sum; // 連続とも非空とも限らない部分列のm_base ^ 長さの総和
  T m_val;
  T m_lsum; // 非空始切片の総和
  T m_rsum; // 非空終切片の総和
  T m_csum; // 非空連続部分列の総和
  T m_sum; // 連続とは限らない非空部分列の総和

public:
  // DigitConcatenationString(0,base)は単位元でないことに注意。
  inline DigitConcatenationString( ll n , const ll& base );
  // DigitConcatenationString({},zero,base)が単位元となる。
  template <template <typename...> typename VEC , typename U> inline DigitConcatenationString( VEC<U> a , const U& zero , T base );
  DigitConcatenationString<T>& operator*=( const DigitConcatenationString<T>& n );
  inline DigitConcatenationString<T> operator*( const DigitConcatenationString<T>& n ) const;

  inline const T& val() const noexcept;
  inline const T& lsum() const noexcept;
  inline const T& rsum() const noexcept;
  inline const T& csum() const noexcept;
  inline const T& sum() const noexcept;

private:
  static vector<T> DigitExpansion( ll n , const ll& base );

};

