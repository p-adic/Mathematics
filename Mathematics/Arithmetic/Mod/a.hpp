// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

// ������tempate <typename INT , INT M>�Ȃǂɂ��Ă��܂���operator+�Ȃǂ��Ăяo���ۂɌ^���_�Ɏ��s����B�����^��ς���������INT_TYPE_FOR_MOD�̌^�G�C���A�X��ύX����B
template <INT_TYPE_FOR_MOD M>
class Mod
{

protected:
  INT_TYPE_FOR_MOD m_n;

public:
  inline Mod() noexcept;
  inline Mod( const Mod<M>& n ) noexcept;
  inline Mod( Mod<M>& n ) noexcept;
  // INT_TYPE_FOR_MOD��int�Ȃ�΋��炭���s���x�ɉe�����Ȃ����O�̂��߁B
  inline Mod( Mod<M>&& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline Mod( T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline Mod( T&& n ) noexcept;

  inline Mod<M>& operator=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator/=( const Mod<M>& n );

  inline Mod<M>& operator++() noexcept;
  inline Mod<M> operator++( int ) noexcept;
  inline Mod<M>& operator--() noexcept;
  inline Mod<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / );

  inline Mod<M> operator-() const noexcept;
  inline Mod<M>& SignInvert() noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g�B
  inline Mod<M>& Invert();
  template <typename T> inline Mod<M>& PositivePower( T&& exponent ) noexcept;
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename T> inline Mod<M>& Power( T&& exponent );
  
  inline const INT_TYPE_FOR_MOD& Represent() const noexcept;
  inline void swap( Mod<M>& n ) noexcept;

  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;

private:
  static inline constexpr int BinaryDigitUpperBound() noexcept;
  static inline constexpr ull MontgomeryBasePower( ull&& exponent ) noexcept;
  static constexpr INT_TYPE_FOR_MOD g_M_minus = M - 1;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2 = M - 2;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2_neg = 2 - M;
  static constexpr const int g_Montgomery_digit = BinaryDigitUpperBound();
  // static constexpr const int g_Montgomery_digit = 32;
  static constexpr const ull g_Montgomery_base = ull( 1 ) << g_Montgomery_digit;
  static constexpr const uint g_Montgomery_base_minus = uint( g_Montgomery_base - 1 );
  static constexpr const uint g_Montgomery_M_neg_inverse = uint( ( g_Montgomery_base - MontgomeryBasePower( ( ull( 1 ) << ( g_Montgomery_digit - 1 ) ) - 1 ) ) & g_Montgomery_base_minus );
  static constexpr const uint g_Montgomery_base_square = uint( ( ( ( g_Montgomery_base % M ) * ( g_Montgomery_base % M ) ) % M ) & g_Montgomery_base_minus );
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound = 1000000;
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;
  static inline INT_TYPE_FOR_MOD MontgomeryForm( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline ull& MontgomeryReduction( ull& n ) noexcept;
  static inline INT_TYPE_FOR_MOD MontgomeryMultiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline INT_TYPE_FOR_MOD& Normalise( INT_TYPE_FOR_MOD& n ) noexcept;
  template <typename T> inline Mod<M>& Ref( T&& n ) noexcept;

};

// M���f���ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M> Mod<M> inline Inverse( const Mod<M>& n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename T> inline Mod<M> Power( const Mod<M>& n , const T& exponent );
template <typename T> inline Mod<2> Power( const Mod<2>& n , const T& p );

// ../Power/a_Body.hpp�ɂĒ�`�B
template <typename T> inline T Square( const T& t );
template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t );

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );
