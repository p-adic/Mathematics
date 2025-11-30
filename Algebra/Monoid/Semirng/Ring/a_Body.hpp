// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename GROUP , typename MONOID , typename U> inline AbstractRing<GROUP,MONOID,U>::AbstractRing( GROUP R0 , MONOID R1 ) : AbstractSemirng<GROUP,MONOID>( move( R0 ) , move( R1 ) ) {}
template <typename U> inline Ring<U>::Ring( U one_U ) : AbstractRing<AdditiveGroup<U>,MultiplicativeMonoid<U>>( AdditiveGroup<U>() , MultiplicativeMonoid<U>( move( one_U ) ) ) {}

template <typename GROUP , typename MONOID , typename U> inline U AbstractRing<GROUP,MONOID,U>::Inverse( const U& u ) { return this->m_R0.Inverse( u ); }
template <typename GROUP , typename MONOID , typename U> inline const U& AbstractRing<GROUP,MONOID,U>::One() const noexcept { return this->m_R1.One(); }

template <typename GROUP , typename MONOID , typename U> inline GROUP& VirtualRing<GROUP,MONOID,U>::AdditiveGroup() noexcept { return this->AdditiveMonoid(); }
template <typename GROUP , typename MONOID , typename U> inline MONOID& VirtualRing<GROUP,MONOID,U>::MultiplicativeMonoid() noexcept { return this->MultiplicativeSemigroup(); }
