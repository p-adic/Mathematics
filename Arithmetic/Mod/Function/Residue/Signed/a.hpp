// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Signed/a.hpp

#pragma once


// Mが非零の時にnをMで割った非負の余りを返す。
template <typename INT> inline constexpr INT Modulo( INT n , const INT& M );

// Mが非零の時にnをMで割った商をModuloと整合的に求める。
template <typename INT> inline constexpr INT PositiveBaseQuotient( INT n , const INT& M );
// Mが非零とは限らない時にnをMで割った商をModuloと整合的に求める。
template <typename INT> inline constexpr INT Quotient( INT n , const INT& M );
