// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

// ���ɂ悭�o�O��̂ŁA�X�V������K��verify���邱�ƁI
// verify:
// https://yukicoder.me/submissions/959351
// �iDerepresent,+=,-=,*,Combination,one�j
// https://yukicoder.me/submissions/959510
// �iDerepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one�j

// M����̏ꍇ�ɂ̂݃T�|�[�g
template <INT_TYPE_FOR_MONTGOMERY M>
class Montgomery
{

private:
  INT_TYPE_FOR_MONTGOMERY m_n;

public:
  inline constexpr Montgomery() noexcept;
  inline constexpr Montgomery( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery( Montgomery<M>&& n ) noexcept;
  template <typename T> inline constexpr Montgomery( T n ) noexcept;

  inline constexpr Montgomery<M>& operator=( Montgomery<M> n ) noexcept;
  inline constexpr Montgomery<M>& operator+=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator-=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator*=( const Montgomery<M>& n ) noexcept;
  inline Montgomery<M>& operator/=( Montgomery<M> n );
  // n>=0�ł���ꍇ�̂݃T�|�[�g�Bn < g_memory_length�ł͋ς��v�Z��O(1)�ŁA
  // ��ʂɂ�O(log n)��2^n�{��Ԃ��B
  template <typename INT> inline constexpr Montgomery<M>& operator<<=( INT n );
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{����B
  template <typename INT> inline constexpr Montgomery<M>& operator>>=( INT n );

  inline constexpr Montgomery<M>& operator++() noexcept;
  inline constexpr Montgomery<M> operator++( int ) noexcept;
  inline constexpr Montgomery<M>& operator--() noexcept;
  inline constexpr Montgomery<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( == );
  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( != );
  
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( / , );
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename INT> inline constexpr Montgomery<M> operator^( INT exponent ) const;
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{����B
  template <typename INT> inline constexpr Montgomery<M> operator<<( INT n ) const;
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{����B
  template <typename INT> inline constexpr Montgomery<M> operator>>( INT n ) const;

  inline constexpr Montgomery<M> operator-() const noexcept;
  inline constexpr Montgomery<M>& SignInvert() noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g�B
  inline constexpr Montgomery<M>& Invert();
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
  template <typename INT> inline constexpr Montgomery<M>& Power( INT exponent );
  // �O���[�o���X�R�[�v��swap���`���邽�߂̂��́B
  inline constexpr void swap( Montgomery<M>& n ) noexcept;

  inline constexpr INT_TYPE_FOR_MONTGOMERY Represent() const noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B�萔�{�������̂��߂�assert�Ȃ��B
  static inline constexpr Montgomery<M> Derepresent( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& Inverse( const INT_TYPE_FOR_MONTGOMERY& n );

  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Mod<M>& TwoPower( const INT_TYPE_FOR_MOD& n );
  
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& Factorial( const INT_TYPE_FOR_MONTGOMERY& n );
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const Montgomery<M>& FactorialInverse( const INT_TYPE_FOR_MONTGOMERY& n );
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline Montgomery<M> Combination( const INT_TYPE_FOR_MONTGOMERY& n , const INT_TYPE_FOR_MONTGOMERY& i );

  static inline const Montgomery<M>& zero() noexcept;
  static inline const Montgomery<M>& one() noexcept;
  static inline const Montgomery<M>& two() noexcept;

  static inline constexpr INT_TYPE_FOR_MONTGOMERY GetModulo() noexcept;
  
private:
  static inline constexpr INT_TYPE_FOR_MONTGOMERY Form( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;
  static inline constexpr ull& Reduction( ull& n ) noexcept;
  static inline constexpr ull& ReducedMultiplication( ull& n , const INT_TYPE_FOR_MONTGOMERY& m ) noexcept;
  static inline constexpr uint BaseSquareTruncation( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  template <typename INT> inline constexpr Montgomery<M>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline constexpr Montgomery<M>& NonNegativePower( INT exponent ) noexcept;

  template <typename T> inline constexpr Montgomery<M>& Ref( T&& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MONTGOMERY& Normalise( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  using Constants = ConstantsForMontgomery<M>;

};

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <INT_TYPE_FOR_MONTGOMERY M , typename INT> inline constexpr Montgomery<M> Power( const Montgomery<M>& n , INT exponent );

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M> inline string to_string( const Montgomery<M>& n ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Montgomery<M>& n );
template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n );

#include "../../Hash/a.hpp"
template <INT_TYPE_FOR_MONTGOMERY M> DECLARATION_OF_HASH( Montgomery<M> );
