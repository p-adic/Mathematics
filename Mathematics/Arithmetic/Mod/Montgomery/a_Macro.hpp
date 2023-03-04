// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Montgomery/a_Macro.hpp

#pragma once

#define SFINAE_FOR_MONTGOMERY( DEFAULT )					\
  typename T , enable_if_t<is_constructible<Mod<M>,decay_t<T> >::value>* DEFAULT \

// operator�̃e���v���[�g��SFINAE_FOR_MONTGOMERY���g���Ă��܂���Mod<M>�o�R��Montgomery<M>�̃C���X�^���X���\�z���邩���ڍ\�z���邩�B���ɂȂ邱�Ƃɒ��ӁB
#define DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( FUNC )			\
  inline Montgomery<M> operator FUNC( const Montgomery<M>& n ) const noexcept;	\
  template <SFINAE_FOR_MOD( = nullptr )> inline Montgomery<M> operator FUNC( T&& n ) const noexcept; \

#define DEFINITION_OF_COMPARISON_FOR_MONTGOMERY( FUNC )			\
  template <INT_TYPE_FOR_MOD M> inline bool Montgomery<M>::operator FUNC( const Montgomery<M>& n ) const noexcept { return m_n FUNC n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( FUNC , FORMULA ) \
  template <INT_TYPE_FOR_MOD M> inline Montgomery<M> Montgomery<M>::operator FUNC( const Montgomery<M>& n ) const noexcept { return move( Montgomery<M>( *this ) FUNC ## = n ); } \
  template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline Montgomery<M> Montgomery<M>::operator FUNC( T&& n ) const noexcept { return FORMULA; } \
  template <INT_TYPE_FOR_MOD M , SFINAE_FOR_MOD( = nullptr )> inline Montgomery<M> operator FUNC( T&& n0 , const Montgomery<M>& n1 ) noexcept { return move( Montgomery<M>( forward<T>( n0 ) ) FUNC ## = n1 ); } \


