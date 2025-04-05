// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/ProductLength/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename MONOID , typename INT , typename TYPE> inline AbstractProductLengthMonoid<MONOID,INT,TYPE>::AbstractProductLengthMonoid( MONOID M ) : DirectProductMonoid<MONOID,AdditiveMonoid<INT>>( move( M ) ) { static_assert( is_same_v<TYPE,typename DirectProductMonoid<MONOID,INT>::type> ); }

template <typename U , typename INT> inline ProductLengthMonoid<U,INT,TYPE>::ProductLengthMonoid( U e_U ) : AbstractProductLengthMonoid<Multiplicative<U>,AdditiveMonoid<INT>>( MultiplicativeMonoid<U>( move( e_U ) ) ) {}

template <typename MONOID , typename INT , typename TYPE> TYPE AbstractProductLengthMonoid<MONOID,INT,TYPE>::ProductLength( typename MONOID::type t ) { return { move( t ) , 1 }; }
template <typename MONOID , typename INT , typename TYPE> inline TYPE AbstractProductLengthMonoid<MONOID,INT,TYPE>::SumLength( typename MONOID::type t ) { return ProductLength( move( t ) ); }
