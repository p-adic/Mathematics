// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename M_U , typename I_U> inline AbstractGroup<U,M_U,I_U>::AbstractGroup( M_U m_U , U e_U , I_U i_U ) : AbstractMonoid<U,M_U>( move( m_U ) , move( e_U ) ) , AbstractNSet<U,I_U>( move( i_U ) ) {}

template <typename U> inline U AdditiveGroup<U>::Transfer( const U& u ) { return -u; }
