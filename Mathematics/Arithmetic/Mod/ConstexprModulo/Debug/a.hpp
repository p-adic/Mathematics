// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../a_Alias.hpp"

#include "../Constant/a.hpp"

template <INT_TYPE_FOR_MOD M>
class Mod
{

private:
  // ����
  bool m_non_negative;
  // ���q
  INT_TYPE_FOR_MOD m_n;
  // ����
  INT_TYPE_FOR_MOD m_d;

public:
  inline constexpr Mod() noexcept;
  inline constexpr Mod( const Mod<M>& n ) noexcept;
  inline constexpr Mod( Mod<M>&& n ) noexcept;
  template <typename T> inline constexpr Mod( T n ) noexcept;

  inline constexpr Mod<M>& operator=( Mod<M> n ) noexcept;
  inline constexpr Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator/=( Mod<M> n );
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{����B
  template <typename INT> inline constexpr Mod<M>& operator<<=( INT n );
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{����B
  template <typename INT> inline constexpr Mod<M>& operator>>=( INT n );

  inline constexpr Mod<M>& operator++() noexcept;
  inline constexpr Mod<M> operator++( int ) noexcept;
  inline constexpr Mod<M>& operator--() noexcept;
  inline constexpr Mod<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / , );
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline constexpr Mod<M> operator^( INT exponent ) const;
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{��Ԃ��B
  template <typename INT> inline constexpr Mod<M> operator<<( INT n ) const;
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{��Ԃ��B
  template <typename INT> inline constexpr Mod<M> operator>>( INT n ) const;

  inline constexpr Mod<M> operator-() const noexcept;
  // -1�{����B
  inline constexpr Mod<M>& SignInvert() noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g�B-1�悷��B
  inline Mod<M>& Invert();
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline constexpr Mod<M>& Power( INT exponent );
  // �O���[�o���X�R�[�v��swap���`���邽�߂̂��́B
  inline constexpr void swap( Mod<M>& n ) noexcept;

  inline constexpr const bool& GetSign() const noexcept;
  inline constexpr const INT_TYPE_FOR_MOD& GetNumerator() const noexcept;
  inline constexpr const INT_TYPE_FOR_MOD& GetDenominator() const noexcept;
  // ��DEBUG���Ɍ^���Ⴄ�̂�auto&&�ȂǂŎ󂯎�邱�Ƃɒ��ӁB
  inline constexpr INT_TYPE_FOR_MOD Represent() const noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B�萔�{�������̂��߂�assert�Ȃ��B
  static inline constexpr Mod<M> Derepresent( INT_TYPE_FOR_MOD n ) noexcept;
  
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n );
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n );
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n );
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline Mod<M> Combination( const INT_TYPE_FOR_MOD& n , const INT_TYPE_FOR_MOD& i );

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;

private:
  template <typename INT> inline constexpr Mod<M>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline constexpr Mod<M>& NonNegativePower( INT exponent ) noexcept;

  static constexpr ull GCD( ull n0 , ull n1_) noexcept;

  using Constants = ConstantsForMod<M>;

};

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power( Mod<M> n , T exponent );

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n );
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );

#include "../../Hash/a.hpp"
template <INT_TYPE_FOR_MOD M> DECLARATION_OF_HASH( Mod<M> );
