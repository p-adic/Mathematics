// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Quotient/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../CRT/a_Body.hpp"

template <typename INT> inline pair<INT,ll> CoprimeFactorInverse( const ll& base , const INT& c ) { assert( base > 0 ); auto [u_0,u_1,g] = PartitionOfUnity<ll,ll>( base, c ); return { Residue( u_1 , base ) , move( g ) }; }

template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d , const ll& coef , const ll& gcd ) { assert( 0 <= coef && coef < base && ( d % base * coef - gcd ) % base == 0 ); return n % gcd == 0 ? Residue( n / gcd % base * coef , base / gcd ) : -1; }
template <typename INT> inline INT ModularQuotient( const ll& base , const INT& n , const ll& d ) { auto [coef,gcd] = CoprimeFactorInverse( base , d ); return ModularQuotient( base , n , d , coef ,gcd ); }
