// c:/Users/user/Documents/Programming/Utility/Vector/StdStream/a.hpp

#pragma once
#include "a_Macro.hpp"

// SFINAEだとstringと競合する。
DECLARATION_OF_COUT_FOR_VECTOR( vector );
DECLARATION_OF_COUT_FOR_VECTOR( list );
DECLARATION_OF_COUT_FOR_VECTOR( set );
DECLARATION_OF_COUT_FOR_VECTOR( unordered_set );
DECLARATION_OF_COUT_FOR_VECTOR( multiset );

inline void VariadicResize( const int& size );
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args );

