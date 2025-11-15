// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/TreeWeight/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
// LineWeight,LineExtendÇ…égÇ§ÅB
#include "../../../../Arithmetic/Iteration/a_Body.hpp"

template <typename INT0 , typename INT1 , typename INT2 , typename U> inline TreeWeightGroup<INT0,INT1,INT2,U>::TreeWeightGroup( const INT0& one0 , const INT1& zero1 , const INT2& zero2 ) : PointedSet<U>( {one0,zero1,zero2} ) { static_assert( is_same_v<U,Tuple<INT0,INT1,INT2>> ); assert( one0 == 1 && zero1 == 0 && zero2 == 0 ); }

template <typename INT0 , typename INT1 , typename INT2 , typename U> inline U TreeWeightGroup<INT0,INT1,INT2,U>::Product( U u0 , const U& u1 ) { auto& [u00,u01,u02] = u0; auto& [u10,u11,u12] = u1; u02 += u01 * INT2{ u10 - 1 } + ( INT2{ --u00 } * u11 + u12 ); u01 += u11; u00 += u10; return move( u0 ); }
template <typename INT0 , typename INT1 , typename INT2 , typename U> inline U TreeWeightGroup<INT0,INT1,INT2,U>::Transfer( const U& u ) { auto& [u0,u1,u2] = u; INT0 a0 = -u0 + 2; INT1 a1 = -u1; INT2 a2 = - ( ( u2 + u1 * INT2{ a0 - 1 } ) + INT2{ u0 - 1 } * a1 ); return { move( a0 ) , move( a1 ) , move( a2 ) }; }

template <typename INT0 , typename INT1 , typename INT2 , typename U> inline U TreeWeightGroup<INT0,INT1,INT2,U>::Extend( U u , const INT2& w ) { return LineExtend<int>( move( u ) , w , 1 ); }
template <typename INT0 , typename INT1 , typename INT2 , typename U> inline U TreeWeightGroup<INT0,INT1,INT2,U>::Cut( U u , const INT2& w ) { auto& [u0,u1,u2] = u; --u0; u2 -= u1; u1 -= u0 * w; return move( u ); }

template <typename INT0 , typename INT1 , typename INT2 , typename U> template <typename INT> inline U TreeWeightGroup<INT0,INT1,INT2,U>::LineWeight( const INT& N , const INT& root )
{

  static_assert( !is_same_v<INT,uint> && !is_same_v<INT,ull> );
  // sum_{i=1}^{N-1} i*(N-i)
  // = N sum_{i=1}^{N-1} i - sum_{i=1}^{N-1} i^2
  // = N ^ 2 * ( N - 1 ) / 2 - N * ( N - 1 ) * ( 2N - 1 ) / 5
  // = N * ( N - 1 ) * ( N + 1 ) / 6
  return { INT0{ N } , ArithmeticProgressionSum<INT1>( N - 1 - root ) - ArithmeticProgressionSum<INT1>( root ) , N * INT2{ N - 1 } * ( N + 1 ) / 6 };
  
}

template <typename INT0 , typename INT1 , typename INT2 , typename U> template <typename INT>
inline U TreeWeightGroup<INT0,INT1,INT2,U>::LineExtend( U u , const INT2& w , const INT& N )
{

  static_assert( !is_same_v<INT,uint> && !is_same_v<INT,ull> );
  auto& [u0,u1,u2] = u;
  // u2 + sum_{i=1}^{N} ( u1 + u0 * i * w ) + v2
  // = u2 + u1 * N + u0 * N * ( N + 1 ) / 2 * w + v2
  u2 += u1 * INT2{ N } + u0 * ArithmeticProgressionSum<INT2>( N ) * w + N * INT2{ N - 1 } * ( N + 1 ) / 6;
  // u1 + u0 * N * w + v1
  u1 += u0 * INT1{ N } * w + ArithmeticProgressionSum<INT1>( N - 1 );
  u0 += N;
  return move( u );

}
