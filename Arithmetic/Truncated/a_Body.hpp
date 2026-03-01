// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Truncated/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline ll TruncatedSum( const ll& n , const ll& m , const INT& bound ) { assert( m >= 0 && bound >= 0 ); return n <= bound - m ? n + m : bound + 1; }
template <typename INT> inline ll TruncatedProduct( const ll& n , const ll& m , const INT& bound ) { assert( m >= 0 && bound >= 0 ); return m == 0 ? m : n <= bound / m ? n * m : bound + 1; }

