// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Macro.hpp

#pragma once

// static_assert����TruncatedPolynomial<Mod<M>>�ւ̃X�J���[�{�Ȃǂ�
// �]�v�ȃI�[�o�[���[�h��₪�����Ă��܂��s�K�B
#define SFINAE_FOR_MOD enable_if_t<is_constructible_v<INT_TYPE_FOR_MOD,decay_t<T>>>*

#define DECLARATION_OF_COMPARISON_FOR_MOD( OPR )			\
  inline constexpr bool operator OPR( const Mod<M>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_MOD( OPR , EX )		\
  inline constexpr Mod<M> operator OPR( Mod<M> n ) const EX;	\

#define DEFINITION_OF_COMPARISON_FOR_MOD( OPR )				\
  template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator OPR( const Mod<M>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MOD( OPR , EX , LEFT , OPR2 )	\
  template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator OPR( Mod<M> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <INT_TYPE_FOR_MOD M , typename T , SFINAE_FOR_MOD = nullptr> inline constexpr Mod<M> operator OPR( T n0 , const Mod<M>& n1 ) EX { return move( Mod<M>( move( n0 ) ) OPR ## = n1 ); } \


