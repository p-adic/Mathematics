// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Signed/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

template <typename INT> inline constexpr INT Modulo( INT n , const INT& M ) { return Residue( move( n ) , abs( M ) ); }

template <typename INT> inline constexpr INT PositiveBaseQuotient( INT n , const INT& M ){ return move( ( n < 0 ? ++n -= M : n ) /= M ); }
template <typename INT> inline constexpr INT Quotient( INT n , const INT& M ){ return M < 0 ? -PositiveBaseQuotient( move( n ) , -M ) : PositiveBaseQuotient( move( n ) , M ); }
