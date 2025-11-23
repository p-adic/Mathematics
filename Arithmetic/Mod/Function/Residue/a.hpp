// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/a.hpp

#pragma once

template <uint M , typename INT> inline constexpr INT Residue( INT n ) noexcept;
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1 n , const INT2& M ) noexcept;

// nが参照で渡されるのでnが変化することに注意。
template <typename INT> inline constexpr INT& Residue998244353( INT& n ) noexcept;

// 非負の余りを返す。
template <typename INT> inline constexpr INT PositiveBaseModulo( INT a , const INT& p );
template <typename INT> inline constexpr INT Modulo( INT a , const INT& p );

// 非負の余りと整合的な商を返す。
template <typename INT> inline constexpr INT PositiveBaseQuotient( INT a , const INT& p );
template <typename INT> inline constexpr INT Quotient( INT a , const INT& p );
