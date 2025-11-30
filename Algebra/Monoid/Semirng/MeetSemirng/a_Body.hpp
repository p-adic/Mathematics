// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Semilattice/a_Body.hpp"

template <typename SEMIGROUP , typename U> inline AbstractTropicalSemirng<SEMIGROUP,U>::AbstractTropicalSemirng( U infty_U , SEMIGROUP M ) : AbstractSemirng<MinSemilattice<U>,SEMIGROUP>( MinSemilattice<U>( move( infty_U ) ) , move( M ) ) {}
template <typename U> inline AdditiveTropicalSemirng<U>::AdditiveTropicalSemirng( U infty_U ) : AbstractTropicalSemirng<AdditiveMagma<U>>( move( infty_U ) , AdditiveMagma<U>() ) {}
template <typename U> inline MultiplicativeTropicalSemirng<U>::MultiplicativeTropicalSemirng( U infty_U ) : AbstractTropicalSemirng<MultiplicativeMagma<U>>( move( infty_U ) , MultiplicativeMagma<U>() ) {}

template <typename MEET_SEMILATTICE , typename SEMIGROUP , typename U> inline const U& VirtualMeetSemirng<MEET_SEMILATTICE,SEMIGROUP,U>::Infty() const noexcept { return this->Zero(); }
template <typename MEET_SEMILATTICE , typename SEMIGROUP , typename U> inline U VirtualMeetSemirng<MEET_SEMILATTICE,SEMIGROUP,U>::Meet( U u0 , const U& u1 ) { return this->Sum( move( u0 ) , u1 ); }
template <typename SEMIGROUP , typename U> inline U AbstractTropicalSemirng<SEMIGROUP,U>::Product( U u0 , const U& u1 ) { const U& infty = this->Infty(); return u0 < infty && u1 < infty ? this->MultiplicativeSemigroup().Product( move( u0 ) , u1 ) : infty; }
