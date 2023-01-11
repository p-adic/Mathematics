// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Montgomery/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// M�͊�Ɍ���
template <INT_TYPE_FOR_MOD M>
class Montgomery :
  public Mod<M>
{

public:
  inline constexpr Montgomery() noexcept;
  inline constexpr Montgomery( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery( Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery( Montgomery<M>&& n ) noexcept;
  template <SFINAE_FOR_MONTGOMERY( = nullptr )> inline constexpr Montgomery( const T& n ) noexcept;
  template <SFINAE_FOR_MONTGOMERY( = nullptr )> inline constexpr Montgomery( T&& n ) noexcept;

  inline constexpr Montgomery<M>& operator=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator=( Montgomery<M>&& n ) noexcept;
  inline constexpr Montgomery<M>& operator+=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator-=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator*=( const Montgomery<M>& n ) noexcept;
  inline Montgomery<M>& operator/=( const Montgomery<M>& n );
  inline constexpr Montgomery<M>& operator<<=( int n ) noexcept;
  // M����ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Montgomery<M>& operator>>=( int n ) noexcept;

  inline constexpr Montgomery<M>& operator++() noexcept;
  inline constexpr Montgomery<M> operator++( int ) noexcept;
  inline constexpr Montgomery<M>& operator--() noexcept;
  inline constexpr Montgomery<M> operator--( int ) noexcept;

  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( + );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( - );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( * );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( / );
  inline constexpr Montgomery<M> operator<<( int n ) const noexcept;
  inline constexpr Montgomery<M> operator>>( int n ) const noexcept;

  inline constexpr Montgomery<M> operator-() const noexcept;
  inline constexpr Montgomery<M>& SignInvert() noexcept;
  inline constexpr Montgomery<M>& Double() noexcept;
  // M����ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Montgomery<M>& Halve() noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Montgomery<M>& Invert();
  template <typename T> inline constexpr Montgomery<M>& PositivePower( T&& exponent ) noexcept;
  template <typename T> inline constexpr Montgomery<M>& NonNegativePower( T&& exponent ) noexcept;
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename T> inline constexpr Montgomery<M>& Power( T&& exponent );

  inline constexpr INT_TYPE_FOR_MOD Represent() const noexcept;
  inline constexpr Mod<M> Reduce() const noexcept;

  // n < M�ł���ꍇ�̂݃T�|�[�g�B
  static inline constexpr Montgomery<M> Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& Formise( const INT_TYPE_FOR_MOD& n ) noexcept;
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Montgomery<M>& zero() noexcept;
  static inline const Montgomery<M>& one() noexcept;

private:
  static inline constexpr INT_TYPE_FOR_MOD Form( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr ull& Reduction( ull& n ) noexcept;
  static inline constexpr ull& ReducedMultiplication( ull& n , const INT_TYPE_FOR_MOD& m ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD Multiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline constexpr uint BaseSquareTruncation( INT_TYPE_FOR_MOD& n ) noexcept;

  template <typename T> inline constexpr Montgomery<M>& Ref( T&& n ) noexcept;

};

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Twice( const Montgomery<M>& n ) noexcept;
// M����ł���ꍇ�̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Half( const Montgomery<M>& n ) noexcept;

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Montgomery<M> Power( const Montgomery<M>& n , const T& exponent );
template <typename T> inline constexpr Montgomery<2> Power( const Montgomery<2>& n , const T& p );

// ../Power/a_Body.hpp�ɂĒ�`�B
template <typename T> inline constexpr T Square( const T& t );
template <> inline constexpr Montgomery<2> Square<Montgomery<2> >( const Montgomery<2>& t );

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Montgomery<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n );
