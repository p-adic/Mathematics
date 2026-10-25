// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/Debug/a.hpp

#pragma once

// Mが正であることのassertを付けただけのもの。

// Mが正の時にnをMで割った非負の余りを返す。
template <uint M , typename INT> inline constexpr INT Residue( INT n ) noexcept;
// Mが正の時にnをMで割った非負の余りを返す。
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1 n , const INT2& M );

// nを998244353で割った非負の余りを返す。
// nが参照で渡されるのでnが変化することに注意。
template <typename INT> inline constexpr INT& Residue998244353( INT& n ) noexcept;
