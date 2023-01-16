// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Montgomery/Operator/a.hpp

#pragma once
#include "../../Operator/a.hpp"

// M����̏ꍇ�̂݃T�|�[�g�B
template <INT_TYPE_FOR_MOD M>
class OperatorsForMontgomery :
  public OperatorsForMod<M>
{

public:
  OperatorsForMontgomery() = delete;
  static inline constexpr INT_TYPE_FOR_MOD Express( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD Reduce( ull n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& Multiply( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline INT_TYPE_FOR_MOD& Devide( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 );
  
  static inline constexpr INT_TYPE_FOR_MOD& LIncrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD RIncrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& LDecrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD RDecrement( INT_TYPE_FOR_MOD& n ) noexcept;

  static inline constexpr INT_TYPE_FOR_MOD& Invert( INT_TYPE_FOR_MOD& n );

  template <typename T> static inline constexpr INT_TYPE_FOR_MOD& PositivePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept;
  template <typename T> static inline constexpr INT_TYPE_FOR_MOD& NonNegativePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept;
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename T> static inline constexpr NT_TYPE_FOR_MOD& Power( INT_TYPE_FOR_MOD& n , T&& exponent );

  static inline const INT_TYPE_FOR_MOD& Expression( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  using type = typename OperatorsForMod<M>::type;
  
};
