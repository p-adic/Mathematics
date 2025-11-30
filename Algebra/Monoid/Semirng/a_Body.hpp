// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename MONOID , typename SEMIGROUP , typename U> inline AbstractSemirng<MONOID,SEMIGROUP,U>::AbstractSemirng( MONOID R0 , SEMIGROUP R1 ) : m_R0( move( R0 ) ) , m_R1( move( R1 ) ) {}
template <typename U> inline Semirng<U>::Semirng() : AbstractSemirng<U,AdditiveMonoid<U>,MultiplicativeMagma<U>>( AdditiveMonoid<U>() , MultiplicativeMagma() ) {}

template <typename MONOID , typename SEMIGROUP , typename U> inline U AbstractSemirng<MONOID,SEMIGROUP,U>::Sum( U u0 , const U& u1 ) { return m_R0.Sum( move( u0 ) , u1 ); }
template <typename MONOID , typename SEMIGROUP , typename U> inline const U& AbstractSemirng<MONOID,SEMIGROUP,U>::Zero() const noexcept { return m_R0.Zero(); }
template <typename MONOID , typename SEMIGROUP , typename U> inline U AbstractSemirng<MONOID,SEMIGROUP,U>::Product( U u0 , const U& u1 ) { return m_R1.Product( move( u0 ) , u1 ); }
template <typename MONOID , typename SEMIGROUP , typename U> inline MONOID& AbstractSemirng<MONOID,SEMIGROUP,U>::AdditiveMonoid() noexcept { return m_R0; }
template <typename MONOID , typename SEMIGROUP , typename U> inline SEMIGROUP& AbstractSemirng<MONOID,SEMIGROUP,U>::MultiplicativeSemigroup() noexcept { return m_R1; }
