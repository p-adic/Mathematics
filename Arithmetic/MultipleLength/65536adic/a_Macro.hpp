// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/MultipleLength/65536adic/a_Macro.hpp

#pragma once

#define DECLARATION_OF_ARITHMETIC_FOR_INT( OPR , EX )           \
  inline Int<w>& operator OPR ## =( const Int<w>& n ) EX;       \
  inline Int<w> operator OPR( const Int<w>& n ) const EX        \

#define DECLARATION_OF_BIT_OPERATOR_FOR_INT( OPR )              \
  inline Int<w>& operator OPR ## =( const Int<w>& n ) noexcept;	\
  inline Int<w> operator OPR( const Int<w>& n ) const noexcept	\

#define DEFINITION_OF_COMPARISON_FOR_INT( OPR )				\
  template <int w> inline bool Int<w>::operator OPR( const Int<w>& n ) const noexcept { return 0 OPR Comp( n ); } \
  template <int w , typename T> inline bool operator OPR( T n0 , const Int<w>& n1 ) noexcept { return Int<w>{ move( n0 ) } OPR n1; } \

#define DEFINITION_OF_ARITHMETIC_FOR_INT( OPR , EX )                    \
  template <int w> inline Int<w> Int<w>::operator OPR( const Int<w>& n ) const EX { return move( Int<w>{ *this } OPR ## = n ); } \
  template <int w , typename T> inline Int<w> operator OPR( T n0 , const Int<w>& n1 ) EX { return move( Int<w>{ move( n0 ) } OPR ## = n1 ); } \

#define DEFINITION_OF_ENTRYWISE_ACTION_FOR_INT( v , PRE , LINE , E )       \
  const int L0 = m_n.size();                                            \
  int L1 = v.size();                                                    \
  PRE;                                                                  \
                                                                        \
  for( int e = 0 ; e < L1 ; e++ ){                                      \
                                                                        \
    LINE;                                                               \
                                                                        \
  }                                                                     \
                                                                        \
  return Reduce( E );                                              \

