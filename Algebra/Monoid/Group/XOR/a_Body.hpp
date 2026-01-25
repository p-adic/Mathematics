// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/XOR/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline XORGroup<U>::XORGroup{ U zero } : PointedSet<U>( move( zero ) ) {}
template <typename U> inline U XORGroup<U>::Product( U u0 , const U& u1 ) { return move( u0 ^= u1 ); }
template <typename U> inline U XORGroup<U>::Transfer( const U& u ) { return u; }
