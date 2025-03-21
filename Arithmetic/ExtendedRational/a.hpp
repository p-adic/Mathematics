// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../Utility/Set/a.hpp"

// verify:
// https://yukicoder.me/submissions/1058490（T=ll,reducing=true）
// https://yukicoder.me/submissions/1058489 (T=ll,reducing=false)
// https://yukicoder.me/submissions/1058491 (T=ll,reducing=true)
// https://yukicoder.me/submissions/1058484 (T=ll,reducing=false)

// Tは
// (1) 各種比較演算子と算術演算子
// (2) intからTへの型変換
// (3) GCD(const T&,const T&)
// が定義されている型。

// Tの商体に±∞を添加する。（+∞と-∞は区別され、1/0は+∞として評価することに注意）
template <typename T , bool reducing = true>
class ExtendedRational
{
  
  template <typename U , bool red> friend class ExtendedRational;

private:
  T m_n;
  T m_d;

public:
  inline constexpr ExtendedRational( T n = 0 , T d = 1 , const bool& reducingd = false );
  inline constexpr ExtendedRational( const ExtendedRational<T,reducing>& r );
  inline constexpr ExtendedRational( ExtendedRational<T,reducing>&& r );
  template <typename U , bool red> inline constexpr ExtendedRational( ExtendedRational<U,red> r );

  inline constexpr void Reduce();

  inline constexpr ExtendedRational<T,reducing>& operator=( ExtendedRational<T,reducing> r ) noexcept;

  inline constexpr bool operator==( const ExtendedRational<T,reducing>& r ) const;
  inline constexpr bool operator!=( const ExtendedRational<T,reducing>& r ) const;
  inline constexpr bool operator<=( const ExtendedRational<T,reducing>& r ) const;
  inline constexpr bool operator>=( const ExtendedRational<T,reducing>& r ) const;
  inline constexpr bool operator<( const ExtendedRational<T,reducing>& r ) const;
  inline constexpr bool operator>( const ExtendedRational<T,reducing>& r ) const;

  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( + );
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( - );
  inline constexpr ExtendedRational<T,reducing> operator-() const noexcept;
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( * );
  inline constexpr ExtendedRational<T,reducing> Inverse() const noexcept;
  DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( / );

  inline constexpr const T& GetNumerator() const noexcept;
  inline constexpr const T& GetDenominator() const noexcept;

private:
  static inline constexpr T DifferenceNumerator( const ExtendedRational<T,reducing>& r0 , const ExtendedRational<T,reducing>& r1 );
  
};

template <typename T , bool reducing> inline constexpr bool operator==( const T& n , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing> inline constexpr bool operator!=( const T& n , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing> inline constexpr bool operator<=( const T& n , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing> inline constexpr bool operator>=( const T& n , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing> inline constexpr bool operator<( const T& n , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing> inline constexpr bool operator>( const T& n , const ExtendedRational<T,reducing>& r );

DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( + );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( - );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( * );
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( / );

template <typename T , bool reducing , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , const ExtendedRational<T,reducing>& r );
template <typename T , bool reducing , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T,reducing>& r );


template <typename T , bool reducing> DECLARATION_OF_HASH( ExtendedRational<T,reducing> );

