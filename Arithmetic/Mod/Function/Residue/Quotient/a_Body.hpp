// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Quotient/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../CRT/a_Body.hpp"

template <typename INT> inline pair<INT,ll> CoprimeFactorInverse( const ll& base , const INT& c ) { assert( base > 0 ); auto [u_0,u_1,g] = PartitionOfUnity<ll,ll>( base, c ); return { Residue( u_1 , base ) , move( g ) }; }

template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d , const bool& positive ) { auto [coef,gcd] = CoprimeFactorInverse( base , d ); return positive && n % base == 0 ? base / gcd : n % gcd == 0 ? Residue( n / gcd * coef , base / gcd ) : -1; }
