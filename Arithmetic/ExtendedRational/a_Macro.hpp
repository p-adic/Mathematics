// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a_Macro.hpp

#pragma once

#define DECLARATION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )		\
  inline constexpr ExtendedRational<T,reducing>& operator OPR ## =( const ExtendedRational<T,reducing>& r ); \
  inline constexpr ExtendedRational<T,reducing> operator OPR( const ExtendedRational<T,reducing>& r ) const \

#define DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )	\
  template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing>& ExtendedRational<T,reducing>::operator OPR ## =( const ExtendedRational<T,reducing>& r ) { return *this = *this + r; }

#define DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( OPR )	\
  template <typename T , bool reducing , typename ARG> inline constexpr ExtendedRational<T,reducing> operator OPR( const ARG& t , const ExtendedRational<T,reducing>& r )


