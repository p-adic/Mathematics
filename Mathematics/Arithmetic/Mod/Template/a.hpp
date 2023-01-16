// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

#include "Operator/a.hpp"

// Mod<M>�̃e���v���[�g���BMontgomery<M>�̈��k���̃t�@�C���e�ʂ��������ł���B
// ����Ŏ��s���Ԃ�1.2�{���x�ɖc��オ�邽�߃t�@�C���e�ʂƎ��s���Ԃ̃g���[�h�I�t�ł���B
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> >
class Mod
{
  
protected:
  INT_TYPE_FOR_MOD m_n;

public:
  inline constexpr Mod() noexcept;
  inline constexpr Mod( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod( Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod( Mod<M,OPR>&& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( const T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T&& n ) noexcept;

  inline constexpr Mod<M,OPR>& operator=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator=( Mod<M,OPR>&& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator+=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator-=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator*=( const Mod<M,OPR>& n ) noexcept;
  inline Mod<M,OPR>& operator/=( const Mod<M,OPR>& n );
  inline constexpr Mod<M,OPR>& operator<<=( int n ) noexcept;
  // M����ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Mod<M,OPR>& operator>>=( int n ) noexcept;

  inline constexpr Mod<M,OPR>& operator++() noexcept;
  inline constexpr Mod<M,OPR> operator++( int ) noexcept;
  inline constexpr Mod<M,OPR>& operator--() noexcept;
  inline constexpr Mod<M,OPR> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_MOD( != );

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / );
  inline constexpr Mod<M,OPR> operator<<( int n ) const noexcept;
  inline constexpr Mod<M,OPR> operator>>( int n ) const noexcept;

  inline constexpr Mod<M,OPR> operator-() const noexcept;
  inline constexpr Mod<M,OPR>& SignInvert() noexcept;
  inline constexpr Mod<M,OPR>& Double() noexcept;
  // M����ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Mod<M,OPR>& Halve() noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g�B
  inline Mod<M,OPR>& Invert();
  template <typename T> inline constexpr Mod<M,OPR>& PositivePower( T&& exponent ) noexcept;
  template <typename T> inline constexpr Mod<M,OPR>& NonNegativePower( T&& exponent ) noexcept;
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename T> inline Mod<M,OPR>& Power( T&& exponent );

  inline constexpr void swap( Mod<M,OPR>& n ) noexcept;

  inline constexpr conditional_t<is_same<OPR,OperatorsForMod<M> >::value,const INT_TYPE_FOR_MOD&,INT_TYPE_FOR_MOD> Represent() const noexcept;
  inline constexpr const INT_TYPE_FOR_MOD& Deconstruct() const noexcept;
  
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B
  static inline constexpr Mod<M,OPR> Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B
  static inline constexpr Mod<M,OPR> Construct( INT_TYPE_FOR_MOD n ) noexcept;
  
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline Mod<M,OPR> Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline Mod<M,OPR> Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline Mod<M,OPR> FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M,OPR>& zero() noexcept;
  static inline const Mod<M,OPR>& one() noexcept;
  
private:
  template <typename T> inline constexpr Mod<M,OPR>& Ref( T&& n ) noexcept;

};

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Twice( Mod<M,OPR> n ) noexcept;
// M����ł���ꍇ�̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Half( Mod<M,OPR> n ) noexcept;

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline Mod<M,OPR> Inverse( Mod<M,OPR> n );
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Inverse_constexpr( Mod<M,OPR> n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> , typename T> inline constexpr Mod<M,OPR> Power( Mod<M,OPR> n , const T& exponent );

// ../Power/a_Body.hpp�ɂĒ�`�B
template <typename T> inline constexpr T Square( const T& t );
template <> inline constexpr Mod<2> Square<Mod<2> >( const Mod<2>& n );

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr void swap( Mod<M,OPR>& n0 , Mod<M,OPR>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline string to_string( const Mod<M,OPR>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M,OPR>& n );
