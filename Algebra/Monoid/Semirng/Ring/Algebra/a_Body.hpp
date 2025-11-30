// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/Algebra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Group/Module/a_Body.hpp"


template <typename R , typename GROUP , typename MONOID , typename O_U , typename U> inline AbstractAlgebra<R,GROUP,MONOID,O_U,U>::AbstractAlgebra( const R& dummy , GROUP R0 , MONOID R1 , O_U o_U ) : AbstractRing<U,GROUP,MONOID>( U{} , move( R0 ) , move( R1 ) ) , AbstractRSet<R,U,O_U>( move( o_U ) ) {}

template <typename R , typename U> inline Algebra<R,U>::Algebra( const R& dummy , U one ) : Ring<U>( move( one ) ) {}

template <typename R , typename U> inline U Algebra<R,U>::Action( const R& r , U u ) { return move( u *= r ); }
