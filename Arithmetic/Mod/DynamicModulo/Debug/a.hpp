// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../Constant/a.hpp"

template <int NUM>
class DMods
{

private:
  // ����
  bool m_non_negative;
  // ���q
  uint m_n;
  // ����
  uint m_d;

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
  // exponent�悷��B
  inline DMods<NUM>& operator^=( ll exponent );
  // n>=0�ł��邩M����ł���ꍇ�̂݃T�|�[�g�Bn < g_memory_length�ł͋ς��v�Z��O(1)�ŁA
  // ��ʂɂ�O(log n)��2^n�{����B
  inline DMods<NUM>& operator<<=( ll n );
  // n<0�ł��邩M����ł���ꍇ�̂݃T�|�[�g�Bn < g_memory_length�ł͋ς��v�Z��O(1)�ŁA
  // ��ʂɂ�O(log n)��2^{-n}�{����B
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
  // M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  inline DMods<NUM> operator^( ll exponent ) const;
  // n>=0�܂���M����ł���ꍇ�̂݃T�|�[�g�B
  // n < g_memory_length�ł͋ς��v�Z��O(1)�ŁA��ʂɂ�O(log n)��2^n�{��Ԃ��B
  inline DMods<NUM> operator<<( ll n ) const;
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B
  // n < g_memory_length�ł͋ς��v�Z��O(1)�ŁA��ʂɂ�O(log n)��2^{-n}�{��Ԃ��B
  inline DMods<NUM> operator>>( ll n ) const;

  inline DMods<NUM> operator-() const noexcept;
  // �O���[�o���X�R�[�v��swap���`���邽�߂̂��́B
  inline void swap( DMods<NUM>& n ) noexcept;

  inline const bool& GetSign() const noexcept;
  inline const uint& GetNumerator() const noexcept;
  inline const uint& GetDenominator() const noexcept;
  // ��DEBUG���Ɍ^���Ⴄ�̂�auto&&�ȂǂŎ󂯎�邱�Ƃɒ��ӁB
  inline uint Represent() const noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B�萔�{�������̂��߂�assert�Ȃ��B
  static inline DMods<NUM> Derepresent( uint n ) noexcept;

  // 0 <= n�ł���ꍇ�̂݃T�|�[�g�B
  static inline const DMods<NUM>& Factorial( const ll& n );
  // 0 <= n����M���f���ł���ꍇ�̂݃T�|�[�g�B
  static inline const DMods<NUM>& FactorialInverse( const ll& n );
  // M���f���ł���ꍇ�̂݃T�|�[�g�B
  static inline DMods<NUM> Combination( const ll& n , const ll& i );

  static inline const DMods<NUM>& zero() noexcept;
  static inline const DMods<NUM>& one() noexcept;

  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& M , const bool& M_is_prime = false ) noexcept;
  
private:
  // -1�{����B
  inline DMods<NUM>& SignInvert() noexcept;
  // -1�悷��B
  inline DMods<NUM>& Invert();
  inline DMods<NUM>& PositivePower( ll exponent ) noexcept;
  inline DMods<NUM>& NonNegativePower( ll exponent ) noexcept;

  // M==1�ł��邩�A�܂���0 < n < M����n��M�ƌ݂��ɑf�ł���ꍇ�̂݃T�|�[�g�B
  static inline const DMods<NUM>& Inverse( const int& n );
  // M==1�ł��邩�A�܂���0 <= n < g_memory_length�ł���ꍇ�̂݃T�|�[�g�B
  static inline const DMods<NUM>& TwoPower( const int& n );
  // M==1�ł��邩�A�܂���0 <= n < g_memory_length����M����ł���ꍇ�̂݃T�|�[�g�B
  static inline const DMods<NUM>& TwoPowerInverse( const int& n );

  using Constants = ConstantsForDMods<NUM>;
  
};

#include "../a_Alias.hpp"

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <int NUM> inline DMods<NUM> Inverse( const DMods<NUM>& n );

// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <int NUM> inline DMods<NUM> Power( DMods<NUM> n , ll exponent );

template <int NUM> inline void swap( DMods<NUM>& n0 , DMods<NUM>& n1 ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DMods<NUM>& n );

template <int NUM> inline string to_string( const DMods<NUM>& n ) noexcept;

#include "../../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( DMods<NUM> );
