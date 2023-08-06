// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Residue/a.hpp

#pragma once

template <uint M , typename INT> inline constexpr INT Residue( const INT& n ) noexcept;
// n���Q�Ƃœn�����̂�n���ω����邱�Ƃɒ��ӁB
template <uint M , typename INT> inline constexpr INT Residue( INT& n ) noexcept;
template <uint M , typename INT> inline constexpr INT Residue( INT&& n ) noexcept;

template <typename INT1 , typename INT2> inline constexpr INT1 Residue( const INT1& n , const INT2& M ) noexcept;
// n���Q�Ƃœn�����̂�n���ω����邱�Ƃɒ��ӁB
template <typename INT1 , typename INT2> inline constexpr INT1& Residue( INT1& n , const INT2& M ) noexcept;
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1&& n , const INT2& M ) noexcept;

template <typename INT> inline constexpr INT& Residue998244353( INT& n ) noexcept;

