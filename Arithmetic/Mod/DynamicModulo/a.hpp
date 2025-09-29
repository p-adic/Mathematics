// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Constant/a.hpp"

// verify:
// https://yukicoder.me/submissions/965301（+=,*,/,Power）
// https://yukicoder.me/submissions/965343（Derepresent,+=,-=,*,Combination,one）
// https://yukicoder.me/submissions/965376（Derepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one）

// 可逆な場合の逆元計算は法が素数でない場合にも有効で、
// (1) /=,/は法が素数かつ右辺が小さい場合にメモ化再帰、そうでない場合にユークリッドの互除法で処理する。
// (2) ^=,^はユークリッドの互除法で処理する。
// で処理する。
template <int NUM>
class DMods
{

private:
  uint m_n;

public:
  inline DMods() noexcept;
  inline DMods( const DMods<NUM>& n ) noexcept;
  inline DMods( DMods<NUM>&& n ) noexcept;
  template <typename T , SFINAE_FOR_DMOD = nullptr> inline DMods( T n ) noexcept;

  inline DMods<NUM>& operator=( DMods<NUM> n ) noexcept;
  inline DMods<NUM>& operator+=( const DMods<NUM>& n ) noexcept;
  inline DMods<NUM>& operator-=( const DMods<NUM>& n ) noexcept;
  inline DMods<NUM>& operator*=( const DMods<NUM>& n ) noexcept;
  inline DMods<NUM>& operator/=( DMods<NUM> n );
  // m_nが可逆であるかexponent>=0である場合にのみサポート。exponent乗する。
  inline DMods<NUM>& operator^=( ll exponent );
  // n>=0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^n倍する。
  inline DMods<NUM>& operator<<=( ll n );
  // n<0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^{-n}倍する。
  inline DMods<NUM>& operator>>=( ll n );

  inline DMods<NUM>& operator++() noexcept;
  inline DMods<NUM> operator++( int ) noexcept;
  inline DMods<NUM>& operator--() noexcept;
  inline DMods<NUM> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_DMOD( == );
  DECLARATION_OF_COMPARISON_FOR_DMOD( != );
  DECLARATION_OF_COMPARISON_FOR_DMOD( < );
  DECLARATION_OF_COMPARISON_FOR_DMOD( <= );
  DECLARATION_OF_COMPARISON_FOR_DMOD( > );
  DECLARATION_OF_COMPARISON_FOR_DMOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_DMOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DMOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DMOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DMOD( / , );
  // m_nが可逆であるかexponent>=0である場合にのみサポート。exponent乗する。
  inline DMods<NUM> operator^( ll exponent ) const;
  // n>=0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^n倍を返す。
  inline DMods<NUM> operator<<( ll n ) const;
  // n>=0かつMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^{-n}倍を返す。
  inline DMods<NUM> operator>>( ll n ) const;

  inline DMods<NUM> operator-() const noexcept;
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( DMods<NUM>& n ) noexcept;

  inline const uint& Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline DMods<NUM> Derepresent( uint n ) noexcept;
  
  // 0 <= nである場合のみサポート。
  static inline const DMods<NUM>& Factorial( const ll& n );
  // 0 <= n < MかつMが素数である場合のみサポート。
  static inline const DMods<NUM>& FactorialInverse( const ll& n );
  // Mが素数である場合のみサポート。
  static inline DMods<NUM> Combination( const ll& n , const ll& i );

  static inline const DMods<NUM>& zero() noexcept;
  static inline const DMods<NUM>& one() noexcept;

  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& M , const bool& M_is_prime  = false ) noexcept;
  
private:  // -1倍する。
  inline DMods<NUM>& SignInvert() noexcept;
  // -1乗する。
  inline DMods<NUM>& Invert();

  inline DMods<NUM>& PositivePower( ll exponent ) noexcept;
  inline DMods<NUM>& NonNegativePower( ll exponent ) noexcept;

  // M==1であるか、または0 < n < MかつnがMと互いに素である場合のみサポート。
  static inline const DMods<NUM>& Inverse( const int& n );
  // M==1であるか、または0 <= n < g_memory_lengthである場合のみサポート。
  static inline const DMods<NUM>& TwoPower( const int& n );
  // M==1であるか、または0 <= n < g_memory_lengthかつMが奇数である場合のみサポート。
  static inline const DMods<NUM>& TwoPowerInverse( const int& n );

  using Constants = ConstantsForDMods<NUM>;

};

#include "a_Alias.hpp"

// Mが素数でありnが0でない場合にのみサポート。
template <int NUM> inline DMods<NUM> Inverse( const DMods<NUM>& n );
// Mが素数であるかexponent>=0である場合にのみサポート。
template <int NUM> inline DMods<NUM> Power( DMods<NUM> n , ll exponent );

template <int NUM> inline void swap( DMods<NUM>& n0 , DMods<NUM>& n1 ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DMods<NUM>& n );

template <int NUM> inline string to_string( const DMods<NUM>& n ) noexcept;

#include "../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( DMods<NUM> );
