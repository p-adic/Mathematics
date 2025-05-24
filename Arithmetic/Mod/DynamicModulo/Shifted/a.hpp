// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Shifted/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Constant/a.hpp"

// verify:
// https://yukicoder.me/submissions/977606�i+,*=,Factorial�j


// �񕉐����̓��l�֌Wx~y��
// - (x=y<K)�܂���(x>=K����y>=K����x-K��y-K(mod M))
// �ƒ�߂����̏�]�ނ������^�B
template <int NUM>
class ShiftedMods
{

private:
  uint m_n;

public:
  inline ShiftedMods() noexcept;
  inline ShiftedMods( const ShiftedMods<NUM>& n ) noexcept;
  inline ShiftedMods( ShiftedMods<NUM>&& n ) noexcept;
  template <typename T> inline ShiftedMods( T n ) noexcept;

  inline ShiftedMods<NUM>& operator=( ShiftedMods<NUM> n ) noexcept;
  inline ShiftedMods<NUM>& operator+=( const ShiftedMods<NUM>& n ) noexcept;
  inline ShiftedMods<NUM>& operator*=( const ShiftedMods<NUM>& n ) noexcept;
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{����B
  template <typename INT> inline ShiftedMods<NUM>& operator<<=( INT n );

  inline ShiftedMods<NUM>& operator++() noexcept;
  inline ShiftedMods<NUM> operator++( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_SHIFTED_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_SHIFTED_MOD( * , noexcept );
  // exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline ShiftedMods<NUM> operator^( INT exponent ) const;
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{��Ԃ��B
  template <typename INT> inline ShiftedMods<NUM> operator<<( INT n ) const;

  // exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline ShiftedMods<NUM>& Power( INT exponent );
  // �O���[�o���X�R�[�v��swap���`���邽�߂̂��́B
  inline void swap( ShiftedMods<NUM>& n ) noexcept;

  inline const uint& Represent() const noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B�萔�{�������̂��߂�assert�Ȃ��B
  static inline ShiftedMods<NUM> Derepresent( uint n ) noexcept;

  template <typename T> static inline T Residue( T n );
  
  // k!��0(mod n)�ł���ꍇ�̂݃T�|�[�g�B
  static inline const ShiftedMods<NUM>& Factorial( const int& n );

  static inline const ShiftedMods<NUM>& zero() noexcept;
  static inline const ShiftedMods<NUM>& one() noexcept;

  static inline const uint& GetShift() noexcept;
  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& K , const uint& M ) noexcept;
  
private:
  template <typename INT> inline ShiftedMods<NUM>& PositivePower( INT exponent ) noexcept;
  using Constants = ConstantsForShiftedMods<NUM>;

};

#include "a_Alias.hpp"

// exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <int NUM , typename T> inline ShiftedMods<NUM> Power( ShiftedMods<NUM> n , T exponent );

template <int NUM> inline void swap( ShiftedMods<NUM>& n0 , ShiftedMods<NUM>& n1 ) noexcept;

template <int NUM> inline string to_string( const ShiftedMods<NUM>& n ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ShiftedMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ShiftedMods<NUM>& n );

#include "../../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( ShiftedMods<NUM> );
