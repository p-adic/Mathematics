// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/946106ÅiAdditiveTropicalSemirngÅj

template <typename MEET_SEMILATTICE , typename SEMIGROUP , typename U = inner_t<SEMIGROUP>>
class VirtualMeetSemirng :
  virtual public VirtualSemirng<MEET_SEMILATTICE,SEMIGROUP>
{

public:
  inline const U& Infty() const noexcept;
  inline U Meet( U u0 , const U& u1 );

};

template <typename SEMIGROUP , typename U = inner_t<SEMIGROUP>>
class AbstractTropicalSemirng :
  virtual public VirtualMeetSemirng<MinSemilattice<U>,SEMIGROUP> ,
  public AbstractSemirng<MinSemilattice<U>,SEMIGROUP>
{

public:
  inline AbstractTropicalSemirng( U infty_U , SEMIGROUP M );
  inline U Product( U u0 , const U& u1 );

};

template <typename U>
class AdditiveTropicalSemirng :
  public AbstractTropicalSemirng<AdditiveMagma<U>>
{

public:
  inline AdditiveTropicalSemirng( U infty_U );

};

template <typename U>
class MultiplicativeTropicalSemirng :
  public AbstractTropicalSemirng<MultiplicativeMagma<U>>
{

public:
  inline MultiplicativeTropicalSemirng( U infty_U );

};
