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
class DynamicMods
{

private:
  uint m_n;

public:
  inline DynamicMods() noexcept;
  inline DynamicMods( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods( DynamicMods<NUM>&& n ) noexcept;
  template <typename T , SFINAE_FOR_DMOD = nullptr> inline DynamicMods( T n ) noexcept;

  inline DynamicMods<NUM>& operator=( DynamicMods<NUM> n ) noexcept;
  inline DynamicMods<NUM>& operator+=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator-=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator*=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator/=( DynamicMods<NUM> n );
  // m_nが可逆であるかexponent>=0である場合にのみサポート。exponent乗する。
  inline DynamicMods<NUM>& operator^=( ll exponent );
  // n>=0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^n倍する。
  inline DynamicMods<NUM>& operator<<=( ll n );
  // n<0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^{-n}倍する。
  inline DynamicMods<NUM>& operator>>=( ll n );

  inline DynamicMods<NUM>& operator++() noexcept;
  inline DynamicMods<NUM> operator++( int ) noexcept;
  inline DynamicMods<NUM>& operator--() noexcept;
  inline DynamicMods<NUM> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( / , );
  // m_nが可逆であるかexponent>=0である場合にのみサポート。exponent乗する。
  inline DynamicMods<NUM> operator^( ll exponent ) const;
  // n>=0またはMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^n倍を返す。
  inline DynamicMods<NUM> operator<<( ll n ) const;
  // n>=0かつMが奇数である場合のみサポート。
  // n < g_memory_lengthでは均し計算量O(1)で、一般にはO(log n)で2^{-n}倍を返す。
  inline DynamicMods<NUM> operator>>( ll n ) const;

  inline DynamicMods<NUM> operator-() const noexcept;
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( DynamicMods<NUM>& n ) noexcept;

  inline const uint& Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline DynamicMods<NUM> Derepresent( uint n ) noexcept;
  
  // 0 <= nである場合のみサポート。
  static inline const DynamicMods<NUM>& Factorial( const ll& n );
  // 0 <= n < MかつMが素数である場合のみサポート。
  static inline const DynamicMods<NUM>& FactorialInverse( const ll& n );
  // Mが素数である場合のみサポート。
  static inline DynamicMods<NUM> Combination( const ll& n , const ll& i );

  static inline const DynamicMods<NUM>& zero() noexcept;
  static inline const DynamicMods<NUM>& one() noexcept;

  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& M , const bool& M_is_prime  = false ) noexcept;
  
private:  // -1倍する。
  inline DynamicMods<NUM>& SignInvert() noexcept;
  // -1乗する。
  inline DynamicMods<NUM>& Invert();

  inline DynamicMods<NUM>& PositivePower( ll exponent ) noexcept;
  inline DynamicMods<NUM>& NonNegativePower( ll exponent ) noexcept;

  // M==1であるか、または0 < n < MかつnがMと互いに素である場合のみサポート。
  static inline const DynamicMods<NUM>& Inverse( const int& n );
  // M==1であるか、または0 <= n < g_memory_lengthである場合のみサポート。
  static inline const DynamicMods<NUM>& TwoPower( const int& n );
  // M==1であるか、または0 <= n < g_memory_lengthかつMが奇数である場合のみサポート。
  static inline const DynamicMods<NUM>& TwoPowerInverse( const int& n );

  using Constants = ConstantsForDynamicMods<NUM>;

};

#include "a_Alias.hpp"

// Mが素数でありnが0でない場合にのみサポート。
template <int NUM> inline DynamicMods<NUM> Inverse( const DynamicMods<NUM>& n );
// Mが素数であるかexponent>=0である場合にのみサポート。
template <int NUM> inline DynamicMods<NUM> Power( DynamicMods<NUM> n , ll exponent );

template <int NUM> inline void swap( DynamicMods<NUM>& n0 , DynamicMods<NUM>& n1 ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DynamicMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DynamicMods<NUM>& n );

template <int NUM> inline string to_string( const DynamicMods<NUM>& n ) noexcept;

#include "../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( DynamicMods<NUM> );
