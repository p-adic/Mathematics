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
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound = 1000000;
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;

public:
  inline Mod() noexcept;
  inline Mod( const Mod<M>& n ) noexcept;
  inline Mod( Mod<M>&& n ) noexcept;
  inline Mod( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator=( Mod<M>&& n ) noexcept;
  inline Mod<M>& operator=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator+=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator-=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator*=( const INT_TYPE_FOR_MOD& n ) noexcept;

  // INT_TYPE_FOR_MOD�ł̊���Z�ł͂Ȃ����Ƃɒ���
  inline Mod<M>& operator/=( const Mod<M>& n );
  inline Mod<M>& operator/=( const INT_TYPE_FOR_MOD& n );
  
  inline Mod<M>& operator%=( const Mod<M>& n );
  inline Mod<M>& operator%=( const INT_TYPE_FOR_MOD& n );

  inline Mod<M> operator-() const noexcept;

  // �O�u++/--���g�����肪�Ȃ��̂Ō�u++/--�Ɠ������̂Ƃ��Ē�`����
  inline Mod<M>& operator++() noexcept;
  inline Mod<M>& operator++( int ) noexcept;
  inline Mod<M>& operator--() noexcept;
  inline Mod<M>& operator--( int ) noexcept;
  
  inline const INT_TYPE_FOR_MOD& Represent() const noexcept;
  // M���f���ł���ꍇ�̂݃T�|�[�g
  inline Mod<M>& Invert() noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( IsEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsNotEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsSmallerThan );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsSmallerThanOrEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsBiggerThan );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsBiggerThanOrEqualTo );

  inline void swap( Mod<M>& n ) noexcept;

  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_length�ł���ꍇ�̂݃T�|�[�g
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // M���f������n < g_memory_length�ł���ꍇ�̂݃T�|�[�g
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;

private:
  static inline Mod<M> error() noexcept;
  
};

DECLARATION_OF_OPERATOR_FOR_MOD( bool , == );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , != );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , < );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , <= );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , > );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , >= );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , + );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , - );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , * );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , / );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , % );

// M���f���ł���ꍇ�ɂ̂݃T�|�[�g
template <INT_TYPE_FOR_MOD M> Mod<M> inline Inverse( const Mod<M>& n );

// M���f���ł��邩p>=0�ł���ꍇ�ɂ̂݃T�|�[�g
template <INT_TYPE_FOR_MOD M> Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p );
template <> inline Mod<2> Power( const Mod<2>& n , const INT_TYPE_FOR_MOD& p );
// M�悪1�ɂȂ�悤��`����Ă��邱�Ƃɒ���
template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p );
template <> inline Mod<2> Power( const Mod<2>& n , const Mod<2>& p );

// ../Power/a_Body.hpp�ɂĒ�`
template <typename T> inline T Square( const T& t );
template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t );

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );
